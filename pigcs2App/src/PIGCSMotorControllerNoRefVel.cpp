/*
FILENAME...     PIGCSMotorControllerNoRefVel.cpp 

*************************************************************************
* Copyright (c) 2011-2013 Physik Instrumente (PI) GmbH & Co. KG
* This file is distributed subject to the EPICS Open License Agreement
* found in the file LICENSE that is included with this distribution.
*************************************************************************


Original Author: Jens Kapp 
Created: 06.04.2021
*/

#include "PIGCSMotorControllerNoRefVel.h"
#include "PIasynAxis.h"
#include "PIInterface.h"
#include <math.h>
#include <stdlib.h>

//#undef asynPrint
//#define asynPrint(user,reason,format...) 0



asynStatus PIGCSMotorControllerNoRefVel::referenceVelCts( PIasynAxis* pAxis, double velocity, int forwards)
{
	return referenceAxis(pAxis, forwards);
}


