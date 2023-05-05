# motorPIGCS2
EPICS motor drivers for [Physik Instrumente](https://www.physikinstrumente.com/) GCS2 (General Command Set) compatible controllers, including the following:<br>
C-663, C-702, C-863, C-867, C-884, C-885, C-887, E-517, E-518, E-753, E-754, E-709, E-712, E-725, E-727, E-755, E-861, E-871, E-873, E-873.3QTU, F-206, F-HEX, and M-8

[![Build Status](https://github.com/epics-motor/motorPIGCS2/actions/workflows/ci-scripts-build.yml/badge.svg)](https://github.com/epics-motor/motorPIGCS2/actions/workflows/ci-scripts-build.yml)
<!--[![Build Status](https://travis-ci.org/epics-motor/motorPIGCS2.png)](https://travis-ci.org/epics-motor/motorPIGCS2)-->

motorPIGCS2 is a submodule of [motor](https://github.com/epics-modules/motor).  When motorPIGCS2 is built in the ``motor/modules`` directory, no manual configuration is needed.

motorPIGCS2 can also be built outside of motor by copying it's ``EXAMPLE_RELEASE.local`` file to ``RELEASE.local`` and defining the paths to ``MOTOR`` and itself.

motorPIGCS2 contains an example IOC that is built if ``CONFIG_SITE.local`` sets ``BUILD_IOCS = YES``.  The example IOC can be built outside of driver module.
