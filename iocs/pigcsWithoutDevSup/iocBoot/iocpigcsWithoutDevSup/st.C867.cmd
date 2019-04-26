#!../../bin/linux-x86_64/pigcsWithoutDevSup

< envPaths

dbLoadDatabase("${TOP}/dbd/pigcsWithoutDevSup.dbd")
pigcsWithoutDevSup_registerRecordDeviceDriver(pdbbase)

drvAsynIPPortConfigure("tcpip_c867","10.0.9.72:50000",0,0,0)
asynOctetConnect("tcpip_c867", "tcpip_c867")
asynOctetSetInputEos("tcpip_c867",0,"\n")

PI_GCS2_CreateController("PIasyn2", "tcpip_c867", 2, 0,0, 10, 250)

dbLoadTemplate("asynMotor.substitutions.c867")

#asynSetTraceIOMask("tcpip_c867", -1 , 0x2)
#asynSetTraceMask("tcpip_c867", -1, 0x09)

# Initialize the IOC and start processing records
iocInit()

#asynSetTraceIOMask("tcpip_c867", -1 , 0x2)
#asynSetTraceMask("tcpip_c867", -1, 0x09)

