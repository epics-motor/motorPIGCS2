TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================
# Build the IOC application

PROD_IOC = pigcsWithoutDevSup

# pigcsWithoutDevSup.dbd will be created and installed
DBD += pigcsWithoutDevSup.dbd

# pigcsWithoutDevSup.dbd will be made up from these files:
pigcsWithoutDevSup_DBD += base.dbd
pigcsWithoutDevSup_DBD += asyn.dbd
pigcsWithoutDevSup_DBD += drvAsynIPPort.dbd
pigcsWithoutDevSup_DBD += drvAsynSerialPort.dbd
pigcsWithoutDevSup_DBD += motorSupport.dbd
pigcsWithoutDevSup_DBD += PI_GCS2Support.dbd

#pigcsWithoutDevSup_registerRecordDeviceDriver.cpp derives from pigcsWithoutDevSup.dbd
pigcsWithoutDevSup_SRCS += pigcsWithoutDevSup_registerRecordDeviceDriver.cpp

# Build the main IOC entry point on workstation OSs.
pigcsWithoutDevSup_SRCS_DEFAULT += pigcsWithoutDevSupMain.cpp
pigcsWithoutDevSup_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#pigcsWithoutDevSup_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# The following are compiled and added to the Support library

pigcsWithoutDevSup_LIBS += asyn
pigcsWithoutDevSup_LIBS += motor
pigcsWithoutDevSup_LIBS += PI_GCS2Support

# Finally link to the EPICS Base libraries
pigcsWithoutDevSup_LIBS += $(EPICS_BASE_IOC_LIBS)

#==================================================
include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

