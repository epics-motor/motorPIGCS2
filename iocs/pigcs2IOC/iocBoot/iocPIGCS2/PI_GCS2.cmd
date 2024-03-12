# PI GCS2 support

dbLoadTemplate("PI_GCS2.substitutions")

drvAsynIPPortConfigure("C867_ETH","192.168.1.75:50000",0,0,0)
# Turn on asyn trace
asynSetTraceMask("C867_ETH",0,3)
asynSetTraceIOMask("C867_ETH",0,1)

# PI_GCS2_CreateController(portName, asynPort, numAxes, priority, stackSize, movingPollingRate, idlePollingRate)
PI_GCS2_CreateController("C867", "C867_ETH",2, 0,0, 100, 1000)

# Turn off asyn trace
asynSetTraceMask("C867_ETH",0,1)
asynSetTraceIOMask("C867_ETH",0,0)

# asyn record for troubleshooting
#dbLoadRecords("$(ASYN)/db/asynRecord.db","P=pigcs2:,R=asyn_1,PORT=C867_ETH,ADDR=0,OMAX=256,IMAX=256")
