/*
FILENAME...     PIGCSMotorController.cpp

*************************************************************************
* Copyright (c) 2011-2013 Physik Instrumente (PI) GmbH & Co. KG
* This file is distributed subject to the EPICS Open License Agreement
* found in the file LICENSE that is included with this distribution.
*************************************************************************


Original Author: Steffen Rau
Created: 15.12.2010
*/

#include "PIGCSMotorController.h"
#include "PIasynAxis.h"
#include "PIInterface.h"
#include <math.h>
#include <stdlib.h>

//#undef asynPrint
//#define asynPrint(user,reason,format...) 0


asynStatus PIGCSMotorController::initAxis(PIasynAxis* pAxis)
{
    asynStatus status = hasLimitSwitches(pAxis);
    if (asynSuccess != status)
    {
        return status;
    }
    status = hasReferenceSensor(pAxis);
    if (asynSuccess != status)
    {
        return status;
    }
    return PIGCSController::initAxis(pAxis);
}

asynStatus PIGCSMotorController::setAccelerationCts( PIasynAxis* pAxis, double accelerationCts)
{
    double acceleration = fabs(accelerationCts) * pAxis->m_CPUdenominator / pAxis->m_CPUnumerator;
    if (acceleration == pAxis->m_acceleration)
        return asynSuccess;
    if (pAxis->m_maxAcceleration < 0)
    {
        getMaxAcceleration(pAxis);
    }
    if (acceleration > pAxis->m_maxAcceleration)
        acceleration = pAxis->m_maxAcceleration;

    return setAcceleration(pAxis, acceleration);
}

asynStatus PIGCSMotorController::referenceVelCts( PIasynAxis* pAxis, double velocity, int forwards)
{
    if (velocity != 0)
    {
		char cmd[100];
        velocity = fabs(velocity) * pAxis->m_CPUdenominator / pAxis->m_CPUnumerator;
        sprintf(cmd,"SPA %s 0x50 %f", pAxis->m_szAxisName, velocity);
        m_pInterface->sendOnly(cmd);

		int errorCode = getGCSError();
		if (errorCode != 0)
		{
			asynPrint(m_pInterface->m_pCurrentLogSink, ASYN_TRACE_ERROR,
					"PIGCSMotorController::referenceVelCts() failed\n");
			epicsSnprintf(pAxis->m_pasynUser->errorMessage,pAxis->m_pasynUser->errorMessageSize,
				"PIGCSMotorController::referenceVelCts() failed - GCS Error %d\n",errorCode);
			return asynError;
		}	
    }
	
	return referenceAxis(pAxis, forwards);

}

asynStatus PIGCSMotorController::referenceAxis( PIasynAxis* pAxis, int forwards)
{
    asynStatus status = setServo(pAxis, 1);
    if (asynSuccess != status)
	{
        return status;
	}

    char cmd[100];
    if (pAxis->m_bHasReference)
    {
        // call FRF - find reference
        sprintf(cmd,"FRF %s", pAxis->m_szAxisName);
    }
    else if (pAxis->m_bHasLimitSwitches)
    {
        if (forwards)
        {
            // call FPL - find positive limit switch
            sprintf(cmd,"FPL %s", pAxis->m_szAxisName);
        }
        else
        {
            // call FNL - find negative limit switch
            sprintf(cmd,"FNL %s", pAxis->m_szAxisName);
        }
    }
    else
    {
        asynPrint(m_pInterface->m_pCurrentLogSink, ASYN_TRACE_ERROR,
                "PIGCSMotorController::referenceVelCts() failed - axis has no reference/limit switch\n");
        epicsSnprintf(pAxis->m_pasynUser->errorMessage,pAxis->m_pasynUser->errorMessageSize,
            "PIGCSMotorController::referenceVelCts() failed - axis has no reference/limit switch\n");
        return asynError;
    }
    status = m_pInterface->sendOnly(cmd);
    if (asynSuccess != status)
	{
        return status;
	}
	
    int errorCode = getGCSError();
    if (errorCode == 0)
    {
        return asynSuccess;
    }
	
    asynPrint(m_pInterface->m_pCurrentLogSink, ASYN_TRACE_ERROR,
            "PIGCSMotorController::referenceVelCts() failed\n");
    epicsSnprintf(pAxis->m_pasynUser->errorMessage,pAxis->m_pasynUser->errorMessageSize,
        "PIGCSMotorController::referenceVelCts() failed - GCS Error %d\n",errorCode);
    return asynError;
}

/**
 * Get encoder resolution from counts-per-unit (CPU) fraction of the axis.
 */
asynStatus PIGCSMotorController::getResolution(PIasynAxis* pAxis, double& resolution )
{
    // CPU is "Counts Per Unit"
    // this is stored as two integers in the controller
    double num, denom;
    asynStatus status = getGCSParameter(pAxis, PI_PARA_MOT_CPU_Z, num);
    if (status != asynSuccess)
    {
        return status;
    }
    status = getGCSParameter(pAxis, PI_PARA_MOT_CPU_N, denom);
    if (status != asynSuccess)
    {
        return status;
    }
    pAxis->m_CPUnumerator = num;
    pAxis->m_CPUdenominator = denom;
    resolution = double(pAxis->m_CPUdenominator) / double(pAxis->m_CPUnumerator) ;
    return status;

}

asynStatus PIGCSMotorController::getStatus(PIasynAxis* pAxis, int& homing, int& moving, int& negLimit, int& posLimit, int& servoControl)
{
    char buf[255];
    asynStatus status = m_pInterface->sendAndReceive(char(4), buf, 99);
    if (status != asynSuccess)
    {
        return status;
    }
    // TODO this is for C-863/867 controllers!!!!
    // TODO support other controllers which do not understand #4 or have different bit masks

    int idx = 2 + pAxis->getAxisNo()*4;
    buf[idx+4] = '\0';
    char* szMask = buf+idx;
    long mask = strtol(szMask, NULL, 16);
    getStatusFromBitMask (mask, homing, moving, negLimit, posLimit, servoControl);
    asynPrint(m_pInterface->m_pCurrentLogSink, ASYN_TRACE_FLOW,
               "PIGCSMotorController::getStatus() buf:%s moving %d, svo: %d\n",
               buf, moving, servoControl);

    return status;
}

asynStatus PIGCSMotorController::getMaxAcceleration(PIasynAxis* pAxis)
{
    if (!m_KnowsVELcommand)
    {
        return asynSuccess;
    }
    double maxAcc, maxDec;
    asynStatus status = getGCSParameter(pAxis, PI_PARA_MOT_MAX_ACCEL, maxAcc);
    if (asynSuccess != status)
        return status;
    status = getGCSParameter(pAxis, PI_PARA_MOT_MAX_DECEL, maxDec);
    if (asynSuccess != status)
        return status;

    if (maxAcc < maxDec)
    {
        pAxis->m_maxAcceleration = maxAcc;
    }
    else
    {
        pAxis->m_maxAcceleration = maxDec;
    }
    return status;
}

asynStatus PIGCSMotorController::setAcceleration( PIasynAxis* pAxis, double acceleration)
{
    if (!m_KnowsVELcommand)
    {
        return asynSuccess;
    }
    asynStatus status = setGCSParameter(pAxis, PI_PARA_MOT_CURR_ACCEL, acceleration);
    if (asynSuccess != status)
        return status;
    status = setGCSParameter(pAxis, PI_PARA_MOT_CURR_DECEL, acceleration);
    if (asynSuccess != status)
        return status;
    pAxis->m_acceleration = acceleration;
    return status;
}


