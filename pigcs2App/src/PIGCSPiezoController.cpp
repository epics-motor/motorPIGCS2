/*
FILENAME...     PIGCSPiezoController.cpp

*************************************************************************
* Copyright (c) 2011-2013 Physik Instrumente (PI) GmbH & Co. KG
* This file is distributed subject to the EPICS Open License Agreement
* found in the file LICENSE that is included with this distribution.
*************************************************************************


Original Author: Steffen Rau 
Created: 15.12.2010
*/

#include "PIGCSPiezoController.h"
#include "PIasynAxis.h"
#include "PIInterface.h"
#include <math.h>
#include <stdlib.h>

//#undef asynPrint
//#define asynPrint(user,reason,format...) 0


asynStatus PIGCSPiezoController::getStatus(PIasynAxis* pAxis, int& homing, int& moving, int& negLimit, int& posLimit, int& servoControl)
{
    asynStatus status = getMoving(pAxis, moving);
    if (status != asynSuccess)
    {
    	return status;
    }

   	homing = 0;
   	negLimit = 0;
   	posLimit = 0;

    return status;
}

asynStatus PIGCSPiezoController::getReferencedState(PIasynAxis* pAxis)
{
    if (m_hasqFRF)
    {
        asynStatus status = PIGCSController::getReferencedState (pAxis);
        if (asynSuccess == status)
        {
            return status;
        }
        if (getGCSError () != PI_CNTR_UNKNOWN_COMMAND__2)
        {
            return asynError;
        }
        m_hasqFRF = false;
    }
	pAxis->m_homed = 1;
	return asynSuccess;
}

asynStatus PIGCSPiezoController::initAxis(PIasynAxis* pAxis)
{
    pAxis->m_bHasReference = false;
    if (m_hasqTRS)
    {
        asynStatus status = hasReferenceSensor (pAxis);
        if (asynSuccess != status)
        {
            if (getGCSError () != PI_CNTR_UNKNOWN_COMMAND__2)
            {
                return asynError;
            }
            m_hasqTRS = false;
        }
    }

    pAxis->m_movingStateMask = pow(2.0, pAxis->getAxisNo());

	return setServo(pAxis, 1);
}

/**
 *  Currenty no Piezo controller supports "HLT".
 *  use STP - which will stop all axes...
 */
asynStatus PIGCSPiezoController::haltAxis(PIasynAxis* pAxis)
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
        		"PIGCSPiezoController::haltAxis() failed, GCS error %d", err);
        return asynError;
    }
    return status;
}

asynStatus PIGCSPiezoController::referenceVelCts (PIasynAxis* pAxis, double velocity, int forwards)
{
    if (!m_hasqFRF)
    {
        // device does not know how to reference, many piezo stages have absolute sensors
        return asynSuccess;
    }

    asynStatus status = setServo(pAxis, 0); // piezo controllers need the servo to be disabled
    if (asynSuccess != status)
        return status;

    char cmd[100];
    if (pAxis->m_bHasReference)
    {
        // call FRF - find reference
        sprintf(cmd,"FRF %s", pAxis->m_szAxisName);
    }
    else
    {
        asynPrint(m_pInterface->m_pCurrentLogSink, ASYN_TRACE_ERROR,
                  "PIGCSPiezoController::referenceVelCts() failed - axis has no reference switch\n");
        epicsSnprintf(pAxis->m_pasynUser->errorMessage,pAxis->m_pasynUser->errorMessageSize,
                      "PIGCSPiezoController::referenceVelCts() failed - axis has no reference switch\n");
        return asynError;
    }
    status = m_pInterface->sendOnly(cmd);
    if (asynSuccess != status)
        return status;
    int errorCode = getGCSError();
    if (errorCode == 0)
    {
        return asynSuccess;
    }
    asynPrint(m_pInterface->m_pCurrentLogSink, ASYN_TRACE_ERROR,
              "PIGCSPiezoController::referenceVelCts() failed\n");
    epicsSnprintf(pAxis->m_pasynUser->errorMessage,pAxis->m_pasynUser->errorMessageSize,
                  "PIGCSPiezoController::referenceVelCts() failed - GCS Error %d\n",errorCode);
    return asynError;

}

