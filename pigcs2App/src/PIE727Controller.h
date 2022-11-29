/*
FILENAME...     PIE727Controller.h

*************************************************************************
* Copyright (c) 2011-2013 Physik Instrumente (PI) GmbH & Co. KG
* This file is distributed subject to the EPICS Open License Agreement
* found in the file LICENSE that is included with this distribution.
*************************************************************************


Original Author: Steffen Rau 
*/

#ifndef PIE727CONTROLLER_H_
#define PIE727CONTROLLER_H_

#include "PIGCSPiezoController.h"
#include "PIGCS2PiezoCL.h"

#include <asynDriver.h>


/**
 * class representing PI E-727.
 *
 * These controllers share most of the parameters with digital piezo controllers.
 * Encoders for Nexline stages are often only incremental, so they need to be homed.
 * Homing works with "hard stops" and "Limit switches".
 * From an EPICS point of view this behaves more like a motor than a piezo controller.
 */
class PIE727Controller : public PIGCSPiezoController
{
	public:
		PIE727Controller(PIInterface* pInterface, const char* szIDN);

		~PIE727Controller() {}
		
// virtual asynStatus getStatus(PIasynAxis* pAxis, int& homing, int& moving, int& negLimit, int& posLimit, int& servoControl){return asynSuccess;} 

		virtual asynStatus setCLAxisParam( PIasynAxis* pAxis, unsigned int paramID,  double wantedValue );
		virtual double getCLAxisParam( PIasynAxis* pAxis, unsigned int paramID);
		
	private:

		asynStatus setGCSCmdLvl(unsigned int cmdLvl);
		
		unsigned int m_CCL_ADVANCED_ID;   // advanced user ID
		unsigned int m_CCL_DEFAULT_ID;   // default user ID

		char m_CCL_ADVANCED_PWD[9];   // advanced user password
};

#endif /* PIE727CONTROLLER_H_ */
