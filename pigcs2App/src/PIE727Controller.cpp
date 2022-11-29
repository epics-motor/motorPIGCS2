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

#include "PIE727Controller.h"
#include "PIasynController.h"
#include "PIasynAxis.h"
#include "PIInterface.h"
#include <math.h>
#include <stdlib.h>


PIE727Controller::PIE727Controller(PIInterface* pInterface, const char* szIDN)
: PIGCSPiezoController (pInterface, szIDN)
{
    this->m_CCL_ADVANCED_ID = 1;   // advanced user ID
    this->m_CCL_DEFAULT_ID  = 0;   // default user ID
    strcpy(this->m_CCL_ADVANCED_PWD, "advanced");   // advanced user password
    
    this->m_hasqFRF=false; ///< is "FRF?" command available
    this->m_hasqTRS=false; ///< is "TRS?" command available
    this->m_hasqSRG=false;
}


asynStatus PIE727Controller::setGCSCmdLvl(unsigned int cmdLvl)
{
	char cmd[100];
	
	if (cmdLvl == m_CCL_ADVANCED_ID)
	{
    	sprintf(cmd, "CCL %d %s", cmdLvl, m_CCL_ADVANCED_PWD);
	}
	else if (cmdLvl == m_CCL_DEFAULT_ID)
	{
		sprintf(cmd, "CCL %d", cmdLvl);
	}

    asynStatus status = m_pInterface->sendOnly(cmd);

    return status;
}

//----------------------------------------------------------------------------
// setAxisKp: Method to set the Integrative gain (Ki) of an Axis
//
//  Param:
//      pAxis: identify Axis to be modified
//      paramID: which closed loop parameter will be set
//      wantedKp: Integrative gain to be set
//
//  Return:
//      asynStatus: check if gain was succesfully set
//
//----------------------------------------------------------------------------
asynStatus PIE727Controller::setCLAxisParam( PIasynAxis* pAxis, unsigned int paramID,  double wantedValue )
{
    
    // Set the CCL to advanced -> necessary to modify Kp
    asynStatus status = setGCSCmdLvl(1);

    if (asynSuccess != status)
        return status;

    // Set the wanted parameter into the volatile memory
    status = setGCSParameter(pAxis, paramID, wantedValue);
    // printf("PIGCSPiezoController::setCLAxisParam(), param: 0x%.8x \r\n",paramID);

    asynPrint(m_pInterface->m_pCurrentLogSink, ASYN_TRACE_FLOW,
              "PIGCSPiezoController::setCLAxisParam(), param: 0x%.8x \r\n",paramID);

    if (asynSuccess != status)
    {
        setGCSCmdLvl(0);
        return status;
    }

    status = setGCSCmdLvl(0);

    return status;
}

double PIE727Controller::getCLAxisParam( PIasynAxis* pAxis , unsigned int paramID)
{
    double pValue=0;

    if (pAxis != NULL)
    {
        getGCSParameter(pAxis, paramID , pValue);
    }

    // printf("getCLAxisParam() axis %d, param: 0x%.8x  = %f\r\n",pAxis->getAxisNo(), paramID, pValue);

    return pValue;
}
