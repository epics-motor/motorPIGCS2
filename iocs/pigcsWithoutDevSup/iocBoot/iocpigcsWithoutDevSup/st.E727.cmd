#!../../bin/linux-x86_64/pigcsWithoutDevSup

< envPaths

dbLoadDatabase("${TOP}/dbd/pigcsWithoutDevSup.dbd")
pigcsWithoutDevSup_registerRecordDeviceDriver(pdbbase)

drvAsynIPPortConfigure("tcpip_e727","10.0.9.74:50000",0,0,0)
asynOctetConnect("tcpip_e727", "tcpip_e727")
asynOctetSetInputEos("tcpip_e727",0,"\n")

< asynMotor.e727.cmd

dbLoadTemplate("asynMotor.substitutions.e727")

#asynSetTraceIOMask("tcpip_e727", -1 , 0x2)
#asynSetTraceMask("tcpip_e727", -1, 0x09)

#asynReport 10 “PIasyn3”

iocInit

dbpf "PIE727:m1:VELO.PROC" 1
dbpf "PIE727:m1:ACCL.PROC" 1

#asynSetTraceIOMask("tcpip_e727", -1 , 0x2)
#asynSetTraceMask("tcpip_e727", -1, 0x09)