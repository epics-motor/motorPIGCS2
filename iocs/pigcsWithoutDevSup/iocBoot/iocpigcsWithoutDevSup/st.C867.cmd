#!../../bin/linux-x86_64/pigcsWithoutDevSup

< envPaths

dbLoadDatabase("${TOP}/dbd/pigcsWithoutDevSup.dbd")
pigcsWithoutDevSup_registerRecordDeviceDriver(pdbbase)

drvAsynIPPortConfigure("tcpip_c867","10.0.9.72:50000",0,0,0)
asynOctetConnect("tcpip_c867", "tcpip_c867")
asynOctetSetInputEos("tcpip_c867",0,"\n")

< asynMotor.c867.cmd

dbLoadTemplate("asynMotor.substitutions.c867")

#asynSetTraceIOMask("tcpip_c867", -1 , 0x2)
#asynSetTraceMask("tcpip_c867", -1, 0x09)

# Initialize the IOC and start processing records
iocInit()

dbpf "PIE727:m1:VELO.PROC" 1
dbpf "PIE727:m1:ACCL.PROC" 1

#asynSetTraceIOMask("tcpip_c867", -1 , 0x2)
#asynSetTraceMask("tcpip_c867", -1, 0x09)

