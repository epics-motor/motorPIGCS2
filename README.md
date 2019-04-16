# motorPIGCS2
EPICS motor drivers for [Physik Instrumente](https://www.physikinstrumente.com/) GCS2 (General Command Set) compatible controllers.

motorPIGCS2 is a submodule of [motor](https://github.com/epics-modules/motor).  When motorPIGCS2 is built in the ``motor/modules`` directory, no manual configuration is needed.

motorPIGCS2 can also be built outside of motor by copying it's ``EXAMPLE_RELEASE.local`` file to ``RELEASE.local`` and defining the paths to ``MOTOR`` and itself.

motorPIGCS2 contains an example IOC that is built if ``CONFIG_SITE.local`` sets ``BUILD_IOCS = YES``.  The example IOC can be built outside of driver module.
