# PI GCS2 support

dbLoadTemplate("PI_GCS2_hexapod.substitutions")

drvAsynIPPortConfigure("C887_ETH","10.32.4.52:4001")

# Turn on asyn trace
asynSetTraceMask("C887_ETH",0,3)
asynSetTraceIOMask("C887_ETH",0,1)

# PI_GCS2_CreateController(portName, asynPort, numAxes, priority, stackSize, movingPollingRate, idlePollingRate)
PI_GCS2_CreateController("C887", "C887_ETH",6, 0, 0, 100, 1000)

# Turn off asyn trace
asynSetTraceMask("C887_ETH",0,1)
asynSetTraceIOMask("C887_ETH",0,0)

# asyn record for troubleshooting
#dbLoadRecords("$(ASYN)/db/asynRecord.db","P=$(P),R=asyn_1,PORT=C887_ETH,ADDR=0,OMAX=256,IMAX=256")
