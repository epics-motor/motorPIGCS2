# motorPIGCS2 Releases

## __R1-1 (2020-05-12)__
R1-1 is a release based on the master branch.  

### Changes since R1-0

#### New features
* Commit [498e72b](https://github.com/epics-motor/motorPIGCS2/commit/498e72b550a988150defba974cbb5ed99e1ca866): Jens Kapp added support for the E-754 and C-885 controllers
* Pull request [#4](https://github.com/epics-motor/motorPIGCS2/pull/4): Allow incremental encoders to be used with piezo stages

#### Modifications to existing features
* None

#### Bug fixes
* Commit [98d3613](https://github.com/epics-motor/motorPIGCS2/commit/98d36131b2d57ebc1cd29bb344df21bf4f0d932a): Include ``$(MOTOR)/modules/RELEASE.$(EPICS_HOST_ARCH).local`` instead of ``$(MOTOR)/configure/RELEASE``

## __R1-0 (2019-04-18)__
R1-0 is a release based on the master branch.  

### Changes since motor-6-11

motorPIGCS2 is now a standalone module, as well as a submodule of [motor](https://github.com/epics-modules/motor)

#### New features
* motorPIGCS2 can be built outside of the motor directory
* motorPIGCS2 has a dedicated example IOC that can be built outside of motorPIGCS2

#### Modifications to existing features
* None

#### Bug fixes
* None
