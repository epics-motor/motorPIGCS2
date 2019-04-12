TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

# The following are used for debugging messages.
#!USR_CXXFLAGS += -DDEBUG

#=============================
# Build the IOC application

PROD_IOC = pigcs2
# pigcs2.dbd will be created and installed
DBD += pigcs2.dbd

# pigcs2.dbd will be made up from these files:
pigcs2_DBD += base.dbd

# Include dbd files from all support applications:
#ifdef ASYN
pigcs2_DBD += asyn.dbd
pigcs2_DBD += drvAsynSerialPort.dbd
pigcs2_DBD += drvAsynIPPort.dbd
#endif
pigcs2_DBD += motorSupport.dbd
pigcs2_DBD += PI_GCS2Support.dbd

# Add all the support libraries needed by this IOC
pigcs2_LIBS += PI_GCS2Support
pigcs2_LIBS += motor
#ifdef ASYN
pigcs2_LIBS += asyn
#endif
#ifdef SNCSEQ
pigcs2_LIBS += seq pv
#endif

# pigcs2_registerRecordDeviceDriver.cpp derives from pigcs2.dbd
pigcs2_SRCS += pigcs2_registerRecordDeviceDriver.cpp

# Build the main IOC entry point on workstation OSs.
pigcs2_SRCS_DEFAULT += pigcs2Main.cpp
pigcs2_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#pigcs2_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Finally link to the EPICS Base libraries
pigcs2_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

