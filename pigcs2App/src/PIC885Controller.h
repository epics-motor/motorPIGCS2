/*
FILENAME...     PIC885Controller.h

*************************************************************************
* Copyright (c) 2011-2013 Physik Instrumente (PI) GmbH & Co. KG
* This file is distributed subject to the EPICS Open License Agreement
* found in the file LICENSE that is included with this distribution.
*************************************************************************


Original Author: Steffen Rau 
Created: 15.12.2010
*/

#ifndef PIC885CONTROLLER_H_
#define PIC885CONTROLLER_H_

#include "PIGCSController.h"
#include <asynDriver.h>

/**
 * Class representing PI's GCS2 digital piezo controllers.
 *
 * Main difference to motor controllers is the usage of absolute sensors.
 */
class PIC885Controller : public PIGCSController
{
public:
	PIC885Controller(PIInterface* pInterface, const char* szIDN)
	: PIGCSController(pInterface, szIDN)
	{
	}
	~PIC885Controller() {}

	virtual asynStatus init(void) { return PIGCSController::init(); }
	virtual asynStatus initAxis(PIasynAxis* pAxis);
	virtual asynStatus haltAxis(PIasynAxis* pAxis);
	virtual asynStatus setEnableAxis(PIasynAxis* pAxis, int axisEnableState);
    virtual asynStatus getStatus(PIasynAxis* pAxis, int& homing, int& moving, int& negLimit, int& posLimit, int& servoControl);
	virtual asynStatus referenceVelCts( PIasynAxis* pAxis, double velocity, int forwards);
	virtual asynStatus hasReferenceSensor(PIasynAxis* pAxis);
    virtual asynStatus hasLimitSwitches(PIasynAxis* pAxis);


private:

};

#endif /* PIC885CONTROLLER_H_ */
