#!../../bin/linux-x86_64/pigcsWithoutDevSup

< envPaths

dbLoadDatabase("${TOP}/dbd/pigcsWithoutDevSup.dbd")
pigcsWithoutDevSup_registerRecordDeviceDriver(pdbbase)

drvAsynIPPortConfigure("tcpip_c867","10.0.9.72:50000",0,0,0)
asynOctetConnect("tcpip_c867", "tcpip_c867")
asynOctetSetInputEos("tcpip_c867",0,"\n")

< asynMotor.C-867.cmd

dbLoadTemplate("asynMotor.substitutions.c867")

#asynSetTraceMask("tcpip_c867",0,9)
#asynSetTraceIOMask("tcpip_c867",-1,0x2)

# Initialize the IOC and start processing records
iocInit()

asynSetTraceMask("tcpip_c867",0,9)
asynSetTraceIOMask("tcpip_c867",-1,0x2)

