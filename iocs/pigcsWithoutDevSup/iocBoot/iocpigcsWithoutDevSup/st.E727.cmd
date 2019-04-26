#!../../bin/linux-x86_64/pigcsWithoutDevSup

< envPaths

dbLoadDatabase("${TOP}/dbd/pigcsWithoutDevSup.dbd")
pigcsWithoutDevSup_registerRecordDeviceDriver(pdbbase)

drvAsynIPPortConfigure("tcpip_e727","10.0.9.74:50000",0,0,0)
asynOctetConnect("tcpip_e727", "tcpip_e727")
asynOctetSetInputEos("tcpip_e727",0,"\n")

PI_GCS2_CreateController("PIasyn3", "tcpip_e727",3, 0,0, 10, 250)

dbLoadTemplate("asynMotor.substitutions.e727")

#asynSetTraceIOMask("tcpip_e727", -1 , 0x2)
#asynSetTraceMask("tcpip_e727", -1, 0x09)

#asynReport 10 “PIasyn3”

iocInit

#asynSetTraceIOMask("tcpip_e727", -1 , 0x2)
#asynSetTraceMask("tcpip_e727", -1, 0x09)