#!../../bin/linux-x86_64/pigcsWithoutDevSup

< envPaths

dbLoadDatabase("${TOP}/dbd/pigcsWithoutDevSup.dbd")
pigcsWithoutDevSup_registerRecordDeviceDriver(pdbbase)

drvAsynIPPortConfigure("tcpip_e727","10.0.9.74:50000",0,0,0)
asynOctetConnect("tcpip_e727", "tcpip_e727")
asynOctetSetInputEos("tcpip_e727",0,"\n")

< asynMotor.E-727.cmd

dbLoadTemplate("asynMotor.substitutions.E-727")

#asynSetTraceIOMask("tcpip_e727", -1 , 0x2)
#asynSetTraceMask("tcpip_e727", -1, 0x09)

#asynReport 10 “PIasyn3”

iocInit
