/*
FILENAME...     PICoordinateSystem.cpp

Original Author: Guilherme Rodrigues de Lima
Created: 05.03.2024
*/

#ifndef PICOORDINATESYSTEM_H_
#define PICOORDINATESYSTEM_H_

#include <string>
#include <iostream>
#include <algorithm>
#include "PIGCS2_HexapodController.h"
using namespace std;

class PICoordinateSystem : public PIGCS2_HexapodController
{
public:
	PICoordinateSystem(PIInterface* pInterface, const char* szIDN)
	: PIGCS2_HexapodController(pInterface, szIDN)
	{
	}
	~PICoordinateSystem() {}

	virtual asynStatus getStatus(PIasynAxis* pAxis, int& homing, int& moving, int& negLimit, int& posLimit, int& servoControl);
	
	virtual asynStatus setActivate(const char* value);
	virtual asynStatus getActivate(string &value);

	virtual asynStatus setLink(const char* value);
	virtual asynStatus getLink(string &value);

	virtual asynStatus setToolOffset(const char* value);
	virtual asynStatus setWorkOffset(const char* value);

	virtual asynStatus getTravelLimits(PIasynAxis* pAxis, double& negLimit, double& posLimit);

protected:

private:
};

#endif /* PICOORDINATESYSTEM_H_ */
