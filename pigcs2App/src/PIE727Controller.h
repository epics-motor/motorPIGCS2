/*
FILENAME...     PIE727Controller.h

*************************************************************************
* This file is distributed subject to the EPICS Open License Agreement
* found in the file LICENSE that is included with this distribution.
*************************************************************************


Original Author: Allan S. B. Bugyi
Created: 31.05.2019
*/

#ifndef PIE727CONTROLLER_H_
#define PIE727CONTROLLER_H_

#include "PIGCSController.h"
#include <asynDriver.h>

/**
 * Class representing PI's GCS2 digital piezo controllers.
 *
 * Main difference to motor controllers is the usage of absolute sensors.
 */
class PIE727Controller : public PIGCSController
{
public:
	PIE727Controller(PIInterface* pInterface, const char* szIDN)
	: PIGCSController(pInterface, szIDN)
	{
	}
	~PIE727Controller() {}

	virtual asynStatus init(void) { return PIGCSController::init(); }
	virtual asynStatus initAxis(PIasynAxis* pAxis);
	virtual asynStatus haltAxis(PIasynAxis* pAxis);
        virtual asynStatus getAxisPositionEGU(int inputSignalChannel, double& position);

    virtual asynStatus getStatus(PIasynAxis* pAxis, int& homing, int& moving, int& negLimit, int& posLimit, int& servoControl);
    virtual asynStatus getReferencedState(PIasynAxis* pAxis);


private:

};

#endif /* PIE727CONTROLLER_H_ */
