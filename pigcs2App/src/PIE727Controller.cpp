/*
FILENAME...     PIE727Controller.cpp

*************************************************************************
* This file is distributed subject to the EPICS Open License Agreement
* found in the file LICENSE that is included with this distribution.
*************************************************************************


Original Author: Allan S. B. Bugyi
Created: 31.05.2019
*/

#include "PIE727Controller.h"
#include "PIasynAxis.h"
#include "PIInterface.h"
#include <math.h>
#include <stdlib.h>

//#undef asynPrint
//#define asynPrint(user,reason,format...) 0


asynStatus PIE727Controller::getStatus(PIasynAxis* pAxis, int& homing, int& moving, int& negLimit, int& posLimit, int& servoControl)
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

asynStatus PIE727Controller::getReferencedState(PIasynAxis* pAxis)
{
	pAxis->m_homed = 1;
	return asynSuccess;
}

asynStatus PIE727Controller::initAxis(PIasynAxis* pAxis)
{
    pAxis->m_movingStateMask = pow(2.0, pAxis->getAxisNo());

	return setServo(pAxis, 1);
}

/**
 *  Currenty no PIE727 controller supports "HLT".
 *  use STP - which will stop all axes...
 */
asynStatus PIE727Controller::haltAxis(PIasynAxis* pAxis)
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
        		"PIE727Controller::haltAxis() failed, GCS error %d", err);
        return asynError;
    }
    return status;
}

asynStatus PIE727Controller::getAxisPositionEGU(int inputSignalChannel, double& position)
{
    const char* szIdentification = (char*) this->szIdentification;
    if(strstr(szIdentification, "E-727") != NULL){
	char cmd[100];
	char buf[255];
	sprintf(cmd, "TSP? %d", (inputSignalChannel+1));
	asynStatus status = m_pInterface->sendAndReceive(cmd, buf, 99);
	if (status != asynSuccess)
	{
		return status;
	}
	if (!getValue(buf, position))
	{
		status = asynError;
	}
	return status;
    }
    return asynSuccess;
}


