#!../../bin/linux-x86_64/pigcs2

< envPaths

cd "${TOP}"

## Register all support components
dbLoadDatabase "dbd/pigcs2.dbd"
pigcs2_registerRecordDeviceDriver pdbbase

cd "${TOP}/iocBoot/${IOC}"

## motorUtil (allstop & alldone)
dbLoadRecords("$(MOTOR)/db/motorUtil.db", "P=pigcs2:")

##
< PI_GCS2.cmd

iocInit

## motorUtil (allstop & alldone)
motorUtilInit("pigcs2:")

# Boot complete
