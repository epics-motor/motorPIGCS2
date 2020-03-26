/*
FILENAME...     PIC885Controller.cpp

*************************************************************************
* Copyright (c) 2011-2020 Physik Instrumente (PI) GmbH & Co. KG
* This file is distributed subject to the EPICS Open License Agreement
* found in the file LICENSE that is included with this distribution.
*************************************************************************


Original Author: Steffen Rau 
Created: 15.12.2010
*/

#include "PIC885Controller.h"
#include "PIasynAxis.h"
#include "PIInterface.h"
#include <math.h>
#include <stdlib.h>

//#undef asynPrint
//#define asynPrint(user,reason,format...) 0


asynStatus PIC885Controller::getStatus(PIasynAxis* pAxis, int& homing, int& moving, int& negLimit, int& posLimit, int& servoControl)
{
    char buf[255];
    asynStatus status = m_pInterface->sendAndReceive(char(4), buf, 99);
    if (status != asynSuccess)
    {
        return status;
    }

    int idx = 2 + pAxis->getAxisNo()*4;
    buf[idx+4] = '\0';
    char* szMask = buf+idx;
    long mask = strtol(szMask, NULL, 16);
    moving = (mask & 0x2000) ? 1 : 0;
    homing = (mask & 0x4000) ? 1 : 0;
    negLimit = (mask & 0x0001) ? 1 : 0;
    posLimit = (mask & 0x0004) ? 1 : 0;
    servoControl = (mask & 0x1000) ? 1 : 0;

    asynPrint(m_pInterface->m_pCurrentLogSink, ASYN_TRACE_FLOW,
               "PIC885Controller::getStatus() Axis: %s, buf:%s moving %d, svo: %d, homming: %d\n",
               pAxis->m_szAxisName, buf, moving, servoControl, homing);
    return status;

}

asynStatus PIC885Controller::initAxis(PIasynAxis* pAxis)
{
    pAxis->m_movingStateMask = pow(2.0, pAxis->getAxisNo());
	pAxis->m_bEnableAxisAfterHoming = true;
	pAxis->m_bSetServoAfterHoming = true;
	
    asynStatus status = hasReferenceSensor(pAxis);
    if (asynSuccess != status)
    {
        return status;
	}

	status = setEnableAxis(pAxis, 1);
	if (asynSuccess != status)
	{
		return status;
	}

	return asynSuccess;
}

/**
 *  Currenty no Piezo controller supports "HLT".
 *  use STP - which will stop all axes...
 */
asynStatus PIC885Controller::haltAxis(PIasynAxis* pAxis)
{
    asynStatus status = m_pInterface->sendOnly("STP");
    if (status != asynSuccess)
    {
    	return status;
    }
    int err = getGCSError();
	// controller will set error code to PI_CNTR_STOP (10)
    if (err != PI_CNTR_STOP)
    {
        asynPrint(m_pInterface->m_pCurrentLogSink, ASYN_TRACE_FLOW|ASYN_TRACE_ERROR,
        		"PIC885Controller::haltAxis() failed, GCS error %d", err);
        return asynError;
    }
    return status;
}

asynStatus PIC885Controller::setEnableAxis(PIasynAxis* pAxis, int axisEnableState)
{
	int isAxisEnabled;
	
    asynStatus status = getEnableAxis(pAxis, isAxisEnabled);
    if (asynSuccess != status)
    {
        return status;
	}
	
	if(axisEnableState == isAxisEnabled)
	{
		return asynSuccess;
	}

	status = PIGCSController::setEnableAxis(pAxis, axisEnableState);
	if (asynSuccess != status)
	{
		return status;
	}
	
	return asynSuccess;
}

asynStatus PIC885Controller::hasReferenceSensor(PIasynAxis* pAxis)
{
	pAxis->m_bHasReference = true;
    return asynSuccess;
}

asynStatus PIC885Controller::referenceVelCts( PIasynAxis* pAxis, double velocity, int forwards)
{
    char cmd[100];

    if (pAxis->m_bHasReference)
    {
        // call FRF - find reference
        sprintf(cmd,"FRF %s", pAxis->m_szAxisName);
    }
    else
    {
        asynPrint(m_pInterface->m_pCurrentLogSink, ASYN_TRACE_ERROR,
                "PIC885Controller::referenceVelCts() failed - axis has no reference/limit switch\n");
        epicsSnprintf(pAxis->m_pasynUser->errorMessage,pAxis->m_pasynUser->errorMessageSize,
            "PIC885Controller::referenceVelCts() failed - axis has no reference/limit switch\n");
        return asynError;
    }
	
    asynStatus status = m_pInterface->sendOnly(cmd);
    if (asynSuccess != status)
        return status;
    int errorCode = getGCSError();
    if (errorCode == 0)
    {
        return asynSuccess;
    }
    asynPrint(m_pInterface->m_pCurrentLogSink, ASYN_TRACE_ERROR,
            "PIC885Controller::referenceVelCts() failed\n");
    epicsSnprintf(pAxis->m_pasynUser->errorMessage,pAxis->m_pasynUser->errorMessageSize,
        "PIC885Controller::referenceVelCts() failed - GCS Error %d\n",errorCode);
    return asynError;

}


asynStatus PIC885Controller::hasLimitSwitches(PIasynAxis* pAxis)
{
	 pAxis->m_bHasLimitSwitches = false;
     return asynSuccess;
}
