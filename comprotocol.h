#ifndef COMPROTOCOL_H
#define COMPROTOCOL_H

#include "dataconf.h"
#include "electriccablemetadata.h"
#include "deviceidtype.h"

class comProtocol
{
public:
    comProtocol();
    ~comProtocol();

    static uint16_t crc16(uint8_t *array, int len);
    static bool frameCheck(uint8_t *frame, int frameLen, int *msgLen, enum messageType *msgType, deviceIdType *devid);
    static QList<electricCableMetaData> analysisDataMessage(uint8_t *message, int msgLen, deviceIdType *deviceId);
    static enum configType analysisConfigMessage(uint8_t *message, int msgLen, deviceIdType *deviceId);
    static QDateTime getRtcFromMessage(uint8_t *message, int msgLen, bool *okflag);
    static bool getStatisticArguemnt(uint8_t *message, int msgLen, uint8_t *sampleSec, uint8_t *statisticCycle, uint8_t *statisticCount);
    static bool getThresholdValue(uint8_t *message, int msgLen, uint8_t *thresholdType, float *value);
    static bool getCtValue(uint8_t *message, int msgLen, uint8_t *cttype, float *value);
    static bool analysisHeartBeatMessage(uint8_t *message, int msgLen, deviceIdType *deviceId);

    static bool getVibrateStatisticValue(uint8_t *message, int msgLen,float *value);

    static int getFrameLength(uint8_t *frame, int framelen);

    static QByteArray assembleAlarmDataRequestFrame(deviceIdType devid);
    static QByteArray assembleAlarmData1RequestFrame(deviceIdType devid);
    static QByteArray assembleRtDataRequestFrame(deviceIdType devid);
    static QByteArray assembleStatisticalDataRequestFrame(deviceIdType devid);
    static QByteArray assembleStatisticalAndAlarmDataRequestFrame(deviceIdType devid);
    static QByteArray assembleTimeSetFrame(deviceIdType devid, QDateTime time);
    static QByteArray assembleStatisticalArgumentFrame(deviceIdType devid, uint8_t sampleSec, uint8_t statisticCycle, uint8_t statisticCount);
    static QByteArray assembleThresholdFrame(deviceIdType devid, uint8_t thresholdType ,float thresholdValue);
    static QByteArray assembleCtFrame(deviceIdType devid, uint8_t cttype, float value);
    static QByteArray assembleChannelControlFrame(deviceIdType devid, uint8_t controltype, uint8_t controlbits);

    static QByteArray assembleConfigReadFrame(deviceIdType devid, uint8_t configtype);
    static QByteArray assembleResetFrame(deviceIdType devid);
    static QByteArray assembleNetConfigFrame(deviceIdType devid, quint32 ipaddress, quint16 port);
    static QByteArray assembleIAPRequestFrame(deviceIdType devid, quint16 port);

    static QByteArray assembleStatisticalTempRequestFrame(deviceIdType devid);
    static QByteArray assembleCURLoadRequestFrame(deviceIdType devid);
    static QByteArray assembleCURatioRequestFrame(deviceIdType devid);
    static QByteArray assembleCURateRequestFrame(deviceIdType devid);
    static QByteArray assembleCURVibrationRequestFrame(deviceIdType devid);
    static QByteArray assembleReadInputVolRequestFrame(deviceIdType devid);

    static QByteArray assembleReadRTDataRequestFrame(deviceIdType devid);
    static QByteArray assembleTempStatisticalArgumentFrame(deviceIdType devid, uint8_t sampleSec, uint8_t statisticCycle, uint8_t statisticCount);
    static QByteArray assembleSetVibrateThreshildFrame(deviceIdType devid, uint8_t cttype, float value);
    static QByteArray assembleSetVibrateTimeFrame(deviceIdType devid,float value);
    static QByteArray assembleSetCurChangerateThreshildFrame(deviceIdType devid, uint8_t cttype, float value);
    static QByteArray assembleSetCurChangerateCycleFrame(deviceIdType devid,float value);
};

#endif // COMPROTOCOL_H
