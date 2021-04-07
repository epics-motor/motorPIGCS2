/*
FILENAME...     PIGCSMotorControllerNoRefVel.h

*************************************************************************
* Copyright (c) 2011-2013 Physik Instrumente (PI) GmbH & Co. KG
* This file is distributed subject to the EPICS Open License Agreement
* found in the file LICENSE that is included with this distribution.
*************************************************************************


Original Author: Jens Kapp 
Created: 06.04.2021
*/

#ifndef PIGCSMOTORCONTROLLERNOREFVEL_H_
#define PIGCSMOTORCONTROLLERNOREFVEL_H_

#include "PIGCSMotorController.h"
#include <asynDriver.h>

/**
 * class representing PI GCS2 motor controllers.
 *
 * "motor" does not strictly restrict the driving principle to DC stages or
 * stepper but includes other controller families (e.g. for piezo motors) also.
 */
class PIGCSMotorControllerNoRefVel : public PIGCSMotorController
{
public:
	PIGCSMotorControllerNoRefVel(PIInterface* pInterface, const char* szIDN)
	: PIGCSMotorController(pInterface, szIDN)
	{
	}
	~PIGCSMotorControllerNoRefVel() {}
	virtual asynStatus referenceVelCts( PIasynAxis* pAxis, double velocity, int forwards);

};

#endif /* PIGCSMOTORCONTROLLERNOREFVEL_H_ */
