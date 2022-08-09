/*
FILENAME...     PIGCScontroller.h

*************************************************************************
* Copyright (c) 2011-2013 Physik Instrumente (PI) GmbH & Co. KG
* This file is distributed subject to the EPICS Open License Agreement
* found in the file LICENSE that is included with this distribution.
*************************************************************************


Original Author: Steffen Rau
Created: 15.12.2010
*/

#ifndef PIGCSCONTROLLER_H_
#define PIGCSCONTROLLER_H_

#include <asynDriver.h>
#include <string.h>
#include "picontrollererrors.h"


class PIasynAxis;
class asynMotorAxis;
class PIInterface;

/**
 * Base class for all PI GCS(2) controllers.
 *
 * Most functions will be implemented here, since for basic functionality
 * GCS commands are always the same.
 */
class PIGCSController
{
public:
	PIGCSController(PIInterface* pInterface, const char* szIDN);
	virtual ~PIGCSController();

	static PIGCSController* CreateGCSController(PIInterface* pInterface, const char* szIDN);

	virtual asynStatus init(void);
	virtual asynStatus initAxis(PIasynAxis* pAxis);

    bool getValue(const char* szMsg, double& value);
    bool getValue(const char* szMsg, int& value);
    bool getValue(const char* szMsg, unsigned int& value);
    bool getValue(const char* szMsg, bool& value);

    virtual asynStatus setVelocityCts( PIasynAxis* pAxis, double velocity );
	virtual asynStatus setAccelerationCts( PIasynAxis* pAxis, double acceleration)	{ return asynSuccess; }
	virtual asynStatus setAcceleration( PIasynAxis* pAxis, double acceleration)	{ return asynSuccess; }
	virtual asynStatus move( PIasynAxis* pAxis, double target);
	virtual asynStatus moveCts( PIasynAxis* pAxis, int target);
	virtual asynStatus moveCts( PIasynAxis** pAxesArray, int* pTargetCtsArray, int numAxes);
    virtual asynStatus referenceVelCts (PIasynAxis* pAxis, double velocity, int forwards) = 0;
	virtual asynStatus haltAxis(PIasynAxis* pAxis);


    virtual asynStatus setAxisPositionCts(PIasynAxis* pAxis, double positionCts);
    virtual asynStatus setAxisPosition(PIasynAxis* pAxis, double position);

    virtual asynStatus getAxisPosition(PIasynAxis* pAxis, double& position);
    virtual asynStatus getAxisVelocity(PIasynAxis* pAxis);
    virtual asynStatus getAxisPositionCts(PIasynAxis* pAxis);
    virtual asynStatus setServo(PIasynAxis* pAxis, int servoState);
    virtual asynStatus resetControlMode(PIasynAxis* pAxis){return asynSuccess;}
    virtual asynStatus getResolution(PIasynAxis* pAxis, double& resolution );
    virtual asynStatus getStatus(PIasynAxis* pAxis, int& homing, int& moving, int& negLimit, int& posLimit, int& servoControl) = 0;
    virtual asynStatus getGlobalState( asynMotorAxis** Axes, int numAxes ) { return asynSuccess; }
    virtual asynStatus getMoving(PIasynAxis* pAxis, int& homing);
    virtual asynStatus getBusy(PIasynAxis* pAxis, int& busy);
    virtual asynStatus getTravelLimits(PIasynAxis* pAxis, double& negLimit, double& posLimit);
    virtual asynStatus hasLimitSwitches(PIasynAxis* pAxis);
    virtual asynStatus hasReferenceSensor(PIasynAxis* pAxis);
    virtual asynStatus getReferencedState(PIasynAxis* axis);
	virtual asynStatus setEnableAxis(PIasynAxis* pAxis, int axisEnableState);
	virtual asynStatus getEnableAxis(PIasynAxis* pAxis, int& axisEnableState);

    virtual asynStatus SetPivotX(double value);
    virtual asynStatus SetPivotY(double value);
    virtual asynStatus SetPivotZ(double value);

    virtual double GetPivotX() { return 0.0; }
    virtual double GetPivotY() { return 0.0; }
    virtual double GetPivotZ() { return 0.0; }

    // Closed loop parameters
    virtual asynStatus setCLAxisParam( PIasynAxis* pAxis, unsigned int paramID,  double wantedValue ){return asynSuccess;} 
    virtual double getCLAxisParam( PIasynAxis* pAxis, unsigned int paramID){return 0.0;}

    virtual bool AcceptsNewTarget() { return true; }
    virtual bool CanCommunicateWhileHoming() { return true; }

    const char* getAxesID(size_t axisIdx) { return m_axesIDs[axisIdx]; }
    size_t getNrFoundAxes() { return m_nrFoundAxes; }

    virtual bool IsGCS2() { return m_IsGCS2; }
    virtual bool IsGCS21() { return m_IsGCS21; }

    int getGCSError();

    int GetLastError() { return m_LastError; }

    PIInterface* m_pInterface;
    static const size_t MAX_NR_AXES = 64;
	bool m_bAnyAxisMoving;

    static void getStatusFromBitMask(long mask, int& homing, int& moving, int& negLimit, int& posLimit, int& servoControl);

protected:
    asynStatus setGCSParameter(PIasynAxis* pAxis, unsigned int paramID, double value);
    asynStatus getGCSParameter(PIasynAxis* pAxis, unsigned int paramID, double& value);

    virtual asynStatus findConnectedAxes();

    static bool IsGCSVersion(PIInterface* pInterface, float version);

	char szIdentification[200];
	int m_nrAxesOnController;
	char* m_axesIDs[MAX_NR_AXES];
	size_t m_nrFoundAxes;
	char m_allAxesIDs[255];
	int m_LastError;

    bool m_KnowsVELcommand;
	bool m_IsGCS2;
	bool m_IsGCS21;

};

#endif /* PIGCSCONTROLLER_H_ */
