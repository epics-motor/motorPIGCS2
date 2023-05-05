# motorPIGCS2 Releases

## __R1-2 (2023-05-05)__
R1-2 is a release based on the master branch.

### Changes since R1-1

#### New features
* Commit [70da0e8](https://github.com/epics-motor/motorPIGCS2/commit/70da0e81885652c14b6dcd5f9a6b938f909152c7): Steffen Rau added detection of E-518
* Commit [461e94b](https://github.com/epics-motor/motorPIGCS2/commit/461e94b5a36fc9a1797b5fbd13e4ec4c01dd4c68): [Jens Kapp](https://github.com/JensKappPI) added support for the E-873.3QTU controller
* Pull request [#10](https://github.com/epics-motor/motorPIGCS2/pull/10): [Augusto Horita](https://github.com/AugustoHorita) added closed loop control commands to the E-727 support.

#### Modifications to existing features
* Pull request [#6](https://github.com/epics-motor/motorPIGCS2/pull/6): Steffen Rau eliminated errors due to missing FRF, TRS and SRG commands for the PI E-518 controller.

#### Bug fixes
* Pull request [#15](https://github.com/epics-motor/motorPIGCS2/pull/15): Unconditionally check for non-closed-loop parameters in writeFloat64
* Pull request [#16](https://github.com/epics-motor/motorPIGCS2/pull/16): Fixed E-727 polling when the SRG command isn't supported
* Pull request [#19](https://github.com/epics-motor/motorPIGCS2/pull/19): Fixed a VxWorks build problem (pre-C++11 compilers)
* Pull request [#21](https://github.com/epics-motor/motorPIGCS2/pull/21): Set m_hasqSRG=false if SRG response is empty
* Pull request [#22](https://github.com/epics-motor/motorPIGCS2/pull/22): Corrected driver name in report output
* Pull request [#23](https://github.com/epics-motor/motorPIGCS2/pull/23): Eliminated compiler warnings

#### Documentation
* Pull request [#9](https://github.com/epics-motor/motorPIGCS2/pull/9): Added the list of supported controllers to the README.md

#### Continuous integration
* Added ci-scripts (v3.0.1)
* Switched from Travis CI to Github Actions

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
