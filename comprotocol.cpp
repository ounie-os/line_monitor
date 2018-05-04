#include "comprotocol.h"
#include <QDebug>
static const unsigned char auchCRCHi[] = {			//CRC校验高位字节表
0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,0x01,0xC0,0x80,0x41,0x00,
0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,0x40,0x00,0xC1,
0x81,0x40,0x01,0xC0,0x80,0x41,0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,
0x40,0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,0x40,
0x01,0xC0,0x80,0x41,0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,0x40,0x01,
0xC0,0x80,0x41,0x00,0xC1,0x81,0x40,0x00,0xC1,0x81,0x40,0x01,0xC0,
0x80,0x41,0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,0x01,0xC0,0x80,
0x41,0x00,0xC1,0x81,0x40,0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,
0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,0x00,
0xC1,0x81,0x40,0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,0x01,0xC0,
0x80,0x41,0x00,0xC1,0x81,0x40,0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,
0x41,0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,0x01,0xC0,0x80,0x41,
0x00,0xC1,0x81,0x40,0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,0x01,
0xC0,0x80,0x41,0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,0x00,0xC1,
0x81,0x40,0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,
0x40,0x01,0xC0,0x80,0x41,0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,0x40,
0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,0x40,0x00,0xC1,0x81,0x40,0x01,
0xC0,0x80,0x41,0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,0x40,0x00,0xC1,
0x81,0x40,0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,0x40,0x01,0xC0,0x80,
0x41,0x01,0xC0,0x80,0x41,0x00,0xC1,0x81,0x40} ;

static const unsigned char auchCRCLo[] = {		//CRC校验低位字节表
0x00,0xC0,0xC1,0x01,0xC3,0x03,0x02,0xC2,0xC6,0x06,0x07,0xC7,0x05,
0xC5,0xC4,0x04,0xCC,0x0C,0x0D,0xCD,0x0F,0xCF,0xCE,0x0E,0x0A,0xCA,
0xCB,0x0B,0xC9,0x09,0x08,0xC8,0xD8,0x18,0x19,0xD9,0x1B,0xDB,0xDA,
0x1A,0x1E,0xDE,0xDF,0x1F,0xDD,0x1D,0x1C,0xDC,0x14,0xD4,0xD5,0x15,
0xD7,0x17,0x16,0xD6,0xD2,0x12,0x13,0xD3,0x11,0xD1,0xD0,0x10,0xF0,
0x30,0x31,0xF1,0x33,0xF3,0xF2,0x32,0x36,0xF6,0xF7,0x37,0xF5,0x35,
0x34,0xF4,0x3C,0xFC,0xFD,0x3D,0xFF,0x3F,0x3E,0xFE,0xFA,0x3A,0x3B,
0xFB,0x39,0xF9,0xF8,0x38,0x28,0xE8,0xE9,0x29,0xEB,0x2B,0x2A,0xEA,
0xEE,0x2E,0x2F,0xEF,0x2D,0xED,0xEC,0x2C,0xE4,0x24,0x25,0xE5,0x27,
0xE7,0xE6,0x26,0x22,0xE2,0xE3,0x23,0xE1,0x21,0x20,0xE0,0xA0,0x60,
0x61,0xA1,0x63,0xA3,0xA2,0x62,0x66,0xA6,0xA7,0x67,0xA5,0x65,0x64,
0xA4,0x6C,0xAC,0xAD,0x6D,0xAF,0x6F,0x6E,0xAE,0xAA,0x6A,0x6B,0xAB,
0x69,0xA9,0xA8,0x68,0x78,0xB8,0xB9,0x79,0xBB,0x7B,0x7A,0xBA,0xBE,
0x7E,0x7F,0xBF,0x7D,0xBD,0xBC,0x7C,0xB4,0x74,0x75,0xB5,0x77,0xB7,
0xB6,0x76,0x72,0xB2,0xB3,0x73,0xB1,0x71,0x70,0xB0,0x50,0x90,0x91,
0x51,0x93,0x53,0x52,0x92,0x96,0x56,0x57,0x97,0x55,0x95,0x94,0x54,
0x9C,0x5C,0x5D,0x9D,0x5F,0x9F,0x9E,0x5E,0x5A,0x9A,0x9B,0x5B,0x99,
0x59,0x58,0x98,0x88,0x48,0x49,0x89,0x4B,0x8B,0x8A,0x4A,0x4E,0x8E,
0x8F,0x4F,0x8D,0x4D,0x4C,0x8C,0x44,0x84,0x85,0x45,0x87,0x47,0x46,
0x86,0x82,0x42,0x43,0x83,0x41,0x81,0x80,0x40};


comProtocol::comProtocol()
{
}

comProtocol::~comProtocol()
{

}

uint16_t comProtocol::crc16(uint8_t *array, int len)
{
    uint8_t uchCRCHi;                // high byte of CRC initialized
    uint8_t uchCRCLo;                // low byte of CRC initialized
    uint32_t uIndex;                       // will index into CRC lookup table

    uchCRCHi = 0xFF;
    uchCRCLo = 0xFF;

    while(len--) {
       uIndex = uchCRCHi^(unsigned char)(*array++);		// calculate the CRC

       uchCRCHi = uchCRCLo^auchCRCHi[uIndex];
       uchCRCLo = auchCRCLo[uIndex];
    }

    return ((uchCRCHi<<8)|uchCRCLo);
}

bool comProtocol::frameCheck(uint8_t *frame, int frameLen, int *msgLen, messageType *msgType, deviceIdType *devid)
{
    int messageLen = 0;
    *msgLen = 0;
    if(frameLen <= 19)
    {
        qDebug() << "frame len error";
        return false;
    }
    if(frame[0] != 0x5A || frame[1] != 0xA5)
    {
        qDebug() << "frame head error";
        return false;
    }
    messageLen = (frame[2] << 8) | (frame[3]);
    if(messageLen +  7 != frameLen || messageLen <= 0)
    {
        qDebug() << "message len error";
        return false;
    }
    if(frame[frameLen - 1] != 0xAA)
    {
        qDebug() << "tail error";
        return false;
    }
    uint16_t CRCCode = 0x0000;
    CRCCode = crc16(&frame[4], messageLen);

    uint16_t frameCRCCode;
    frameCRCCode = (frame[frameLen - 3] << 8) | (frame[frameLen - 2]);

    if(CRCCode != frameCRCCode)
    {
        qDebug() << QString::number(CRCCode, 16) << " != " << QString::number(frameCRCCode, 16);
        return false;
    }

    *msgLen = messageLen;
    *msgType = (enum messageType)frame[4];

    int msgCnt = 5;
    devid->firstId = (frame[msgCnt] << 24) | (frame[msgCnt + 1] << 16) | (frame[msgCnt + 2] << 8) | (frame[msgCnt + 3]);
    msgCnt += 4;
    devid->secondId = (frame[msgCnt] << 24) | (frame[msgCnt + 1] << 16) | (frame[msgCnt + 2]<< 8) | (frame[msgCnt + 3]);
    msgCnt += 4;
    devid->thirdId = (frame[msgCnt] << 24) | (frame[msgCnt + 1] << 16) | (frame[msgCnt + 2]<< 8) | (frame[msgCnt + 3]);
    msgCnt += 4;
    return true;
}

QList<electricCableMetaData> comProtocol::analysisDataMessage(uint8_t *message, int msgLen, deviceIdType *deviceId)
{
    QList<electricCableMetaData> dataList;
    float value;
    int msgCnt = 0;
    if(msgLen <= 0)
        return dataList;

    if(message[msgCnt] != rcvDataMessage && message[msgCnt] != rcvAlarmMessage)
        return dataList;

    msgCnt++;

    if(msgCnt + 12 > msgLen)
        return dataList;

    //对ID进行存储
    deviceIdType devid;
    devid.firstId = (message[msgCnt] << 24) | (message[msgCnt + 1] << 16) | (message[msgCnt + 2] << 8) | (message[msgCnt + 3]);
    msgCnt += 4;
    devid.secondId = (message[msgCnt] << 24) | (message[msgCnt + 1] << 16) | (message[msgCnt + 2]<< 8) | (message[msgCnt + 3]);
    msgCnt += 4;
    devid.thirdId = (message[msgCnt] << 24) | (message[msgCnt + 1] << 16) | (message[msgCnt + 2]<< 8) | (message[msgCnt + 3]);
    msgCnt += 4;
    *deviceId = devid;

    int dataNum = message[msgCnt];
    msgCnt++;

    for(int i = 0 ; i < dataNum; i++)
    {
        enum dataType datatype = (enum dataType)message[msgCnt];
        msgCnt++;

        QDateTime frameTime;
        uint32_t secPassed = (message[msgCnt] << 24) | (message[msgCnt + 1] << 16) | (message[msgCnt + 2] << 8) | (message[msgCnt + 3]);
        frameTime.setTime_t(secPassed);
        msgCnt += 4;


        if((datatype == GroundCablePhaseA_Temp_RT) || (datatype == GroundCablePhaseA_Temp_Alarm) || (datatype == GroundCablePhaseB_Temp_RT) || (datatype == GroundCablePhaseB_Temp_Alarm)
                        || (datatype == GroundCablePhaseC_Temp_RT) || (datatype == GroundCablePhaseC_Temp_Alarm) || (datatype == GroundCablePhaseN_Temp_RT) || (datatype == GroundCablePhaseN_Temp_Alarm)
                ||(datatype == GroundCablePhaseA_Temp_AVG) || (datatype == GroundCablePhaseA_Temp_MAX) || (datatype == GroundCablePhaseA_Temp_MIN)
                ||(datatype == GroundCablePhaseB_Temp_AVG) || (datatype == GroundCablePhaseB_Temp_MAX) || (datatype == GroundCablePhaseB_Temp_MIN)
                ||(datatype == GroundCablePhaseC_Temp_AVG) || (datatype == GroundCablePhaseC_Temp_MAX) || (datatype == GroundCablePhaseC_Temp_MIN)
                ||(datatype == GroundCablePhaseN_Temp_AVG) || (datatype == GroundCablePhaseN_Temp_MAX) || (datatype == GroundCablePhaseN_Temp_MIN))
        {
            value = (int32_t)((message[msgCnt] << 24) | (message[msgCnt + 1] << 16) | (message[msgCnt + 2] << 8) | (message[msgCnt + 3]))*0.01;
        }else if((datatype == GroundCablePhaseAVibrationCount_Alarm) || (datatype == GroundCablePhaseBVibrationCount_Alarm) || (datatype == GroundCablePhaseCVibrationCount_Alarm)|| (datatype == GroundCablePhaseNVibrationCount_Alarm))
        {
            value = ((message[msgCnt] << 24) | (message[msgCnt + 1] << 16) | (message[msgCnt + 2] << 8) | (message[msgCnt + 3]));
        }else
        {
            value = (uint32_t)((message[msgCnt] << 24) | (message[msgCnt + 1] << 16) | (message[msgCnt + 2] << 8) | (message[msgCnt + 3])) * 0.001;
        }
         msgCnt += 4;
//        float value = (uint32_t)((message[msgCnt] << 24) | (message[msgCnt + 1] << 16) | (message[msgCnt + 2] << 8) | (message[msgCnt + 3])) * 0.001;
//        msgCnt += 4;

        electricCableMetaData data;
        data.datatype = datatype;
        data.time = frameTime;
        data.value = value;

        dataList.append(data);
    }

    return dataList;

}

configType comProtocol::analysisConfigMessage(uint8_t *message, int msgLen, deviceIdType *deviceId)
{
    enum configType configtype = ConfigReserved;
    int msgCnt = 0;
    if(msgLen <= 0)
        return configtype;

    if(message[msgCnt] != rcvConfigReadMessage && message[msgCnt] != rcvConfigWriteMessage)
        return configtype;

    msgCnt++;

    if(msgCnt + 12 > msgLen)
        return configtype;

    //对ID进行存储
    deviceIdType devid;
    devid.firstId = (message[msgCnt] << 24) | (message[msgCnt + 1] << 16) | (message[msgCnt + 2] << 8) | (message[msgCnt + 3]);
    msgCnt += 4;
    devid.secondId = (message[msgCnt] << 24) | (message[msgCnt + 1] << 16) | (message[msgCnt + 2]<< 8) | (message[msgCnt + 3]);
    msgCnt += 4;
    devid.thirdId = (message[msgCnt] << 24) | (message[msgCnt + 1] << 16) | (message[msgCnt + 2]<< 8) | (message[msgCnt + 3]);
    msgCnt += 4;
    *deviceId = devid;
    int dataNum = message[msgCnt];
    msgCnt++;

    if(dataNum != 1)
        return configtype;

    configtype = (enum configType)message[msgCnt];
    return configtype;
}

QDateTime comProtocol::getRtcFromMessage(uint8_t *message, int msgLen, bool *okflag)
{
    QDateTime datetime;
    if(msgLen < 19)
    {
        *okflag = false;
        return datetime;
    }

    if(message[14] != RtcTime_Set)
    {
        *okflag = false;
        return datetime;
    }

    uint32_t passedUtcTime;
    passedUtcTime = (message[15] << 24) | (message[16] << 16) | (message[17] << 8) |(message[18]);

    datetime.setTime_t(passedUtcTime);

    return datetime;
}

bool comProtocol::getStatisticArguemnt(uint8_t *message, int msgLen, uint8_t *sampleSec, uint8_t *statisticCycle, uint8_t *statisticCount)
{
    if(msgLen < 19)
    {
        return false;
    }

    if((message[14] != StatisticArgument)&&(message[14] != TemperatureMeasureCycle))
    {
        return false;
    }

    *sampleSec = message[15];
    *statisticCycle = message[16];
    *statisticCount = message[17];
    return true;
}

bool comProtocol::getThresholdValue(uint8_t *message, int msgLen, uint8_t *thresholdType, float *value)
{
    if(msgLen < 19)
    {
        return false;
    }

    *thresholdType = message[14];

    uint32_t temp = (message[15] << 24) | (message[16] << 16) | (message[17] << 8) |(message[18]);
//    memcpy(value, &temp,sizeof(uint32_t));
//    float tmp = *(float *)&temp ;
//    *value = tmp;
    *value = temp * 1.0;
    return true;
}

bool comProtocol::getCtValue(uint8_t *message, int msgLen, uint8_t *cttype, float *value)
{
    if(msgLen < 19)
    {
        return false;
    }

    if(message[14] != MainCableCtValue_Set
            && message[14] != GroundCablePhaseACtValue_Set
            && message[14] != GroundCablePhaseBCtValue_Set
            && message[14] != GroundCablePhaseCCtValue_Set
            && message[14] != GroundCablePhaseNCtValue_Set)
    {
        return false;
    }

    *cttype = message[14];
    uint32_t temp = (message[15] << 24) | (message[16] << 16) | (message[17] << 8) |(message[18]);
//    memcpy(value, &temp,sizeof(uint32_t));
//    *value = *(float *)&temp;
    *value = temp * 1.0;
    return true;
}

bool comProtocol::analysisHeartBeatMessage(uint8_t *message, int msgLen, deviceIdType *deviceId)
{
    QList<electricCableMetaData> dataList;
    int msgCnt = 0;
    if(msgLen <= 0)
        return false;

    if(message[msgCnt] != rcvHeartBeatMessage)
        return false;

    msgCnt++;

    if(msgCnt + 12 > msgLen)
        return false;

    //对ID进行存储
    deviceIdType devid;
    devid.firstId = (message[msgCnt] << 24) | (message[msgCnt + 1] << 16) | (message[msgCnt + 2] << 8) | (message[msgCnt + 3]);
    msgCnt += 4;
    devid.secondId = (message[msgCnt] << 24) | (message[msgCnt + 1] << 16) | (message[msgCnt + 2]<< 8) | (message[msgCnt + 3]);
    msgCnt += 4;
    devid.thirdId = (message[msgCnt] << 24) | (message[msgCnt + 1] << 16) | (message[msgCnt + 2]<< 8) | (message[msgCnt + 3]);
    msgCnt += 4;
    *deviceId = devid;

    return true;
}

bool comProtocol::getVibrateStatisticValue(uint8_t *message, int msgLen, float *value)
{
    if(msgLen < 19)
    {
        return false;
    }

    if((message[14] != VibrationStatisticalCycle)&&(message[14] != SetChangeRateStatistical)&&(message[14] != ChangeRateStatisticalCycle))
    {
        return false;
    }
    uint32_t temp = (message[15] << 24) | (message[16] << 16) | (message[17] << 8) |(message[18]);
    *value = temp * 1.0;
//    *value = *(float *)temp;

    return true;
}

int comProtocol::getFrameLength(uint8_t *frame, int framelen)
{
    int messageLen = 0;
    if(framelen < 4)
        return messageLen;

    messageLen = (frame[2] << 8) | (frame[3]);

    return messageLen + 7;
}

QByteArray comProtocol::assembleAlarmDataRequestFrame(deviceIdType devid)
{
    QByteArray frameArray;
    QByteArray messageArray;

    messageArray.append((char)sndDataMessage);
    messageArray.append(devid.toByteArray());
    messageArray.append((char)0x0d);
    messageArray.append((char)MainCable_Alarm);
    messageArray.append((char)GroundCablePhaseA_Alarm);
    messageArray.append((char)GroundCablePhaseB_Alarm);
    messageArray.append((char)GroundCablePhaseC_Alarm);
    messageArray.append((char)GroundCablePhaseN_Alarm);

    messageArray.append((char)GroundCablePhaseA_Temp_Alarm);
    messageArray.append((char)GroundCablePhaseB_Temp_Alarm);
    messageArray.append((char)GroundCablePhaseC_Temp_Alarm);
    messageArray.append((char)GroundCablePhaseN_Temp_Alarm);

    messageArray.append((char)GroundCablePhaseAVibrationCount_Alarm);
    messageArray.append((char)GroundCablePhaseBVibrationCount_Alarm);
    messageArray.append((char)GroundCablePhaseCVibrationCount_Alarm);
    messageArray.append((char)GroundCablePhaseNVibrationCount_Alarm);

    uint16_t crc = crc16((uint8_t*)messageArray.constData(), messageArray.length());

    frameArray.append(0x5A);
    frameArray.append(0xA5);

    uint16_t msglen = messageArray.length();
    frameArray.append((char)(msglen >> 8));
    frameArray.append((char)(msglen & 0xff));
    frameArray.append(messageArray);
    frameArray.append((char)(crc >> 8));
    frameArray.append((char)(crc & 0xff));
    frameArray.append((char)0xAA);

    return frameArray;
}

QByteArray comProtocol::assembleAlarmData1RequestFrame(deviceIdType devid)
{
    QByteArray frameArray;
    QByteArray messageArray;

    messageArray.append((char)sndDataMessage);
    messageArray.append(devid.toByteArray());
    messageArray.append((char)0x0d);
    messageArray.append((char)GroundCablePhaseA_Load_Alarm);
    messageArray.append((char)GroundCablePhaseB_Load_Alarm);
    messageArray.append((char)GroundCablePhaseC_Load_Alarm);
    messageArray.append((char)GroundCablePhaseN_Load_Alarm);

    messageArray.append((char)GroundCablePhaseA_Ratio_Alarm);
    messageArray.append((char)GroundCablePhaseB_Ratio_Alarm);
    messageArray.append((char)GroundCablePhaseC_Ratio_Alarm);
    messageArray.append((char)GroundCablePhaseN_Ratio_Alarm);

    messageArray.append((char)MainCableChangeRate_Alarm);
    messageArray.append((char)GroundCablePhaseAChangeRate_Alarm);
    messageArray.append((char)GroundCablePhaseBChangeRate_Alarm);
    messageArray.append((char)GroundCablePhaseCChangeRate_Alarm);
    messageArray.append((char)GroundCablePhaseNChangeRate_Alarm);

    uint16_t crc = crc16((uint8_t*)messageArray.constData(), messageArray.length());

    frameArray.append(0x5A);
    frameArray.append(0xA5);

    uint16_t msglen = messageArray.length();
    frameArray.append((char)(msglen >> 8));
    frameArray.append((char)(msglen & 0xff));
    frameArray.append(messageArray);
    frameArray.append((char)(crc >> 8));
    frameArray.append((char)(crc & 0xff));
    frameArray.append((char)0xAA);

    return frameArray;
}

QByteArray comProtocol::assembleRtDataRequestFrame(deviceIdType devid)
{
#if 0
    QByteArray frameArray;
    QByteArray messageArray;

    messageArray.append((char)sndDataMessage);
    messageArray.append(devid.toByteArray());
    messageArray.append((char)0x09);
    messageArray.append((char)MainCable_RT);
    messageArray.append((char)GroundCablePhaseA_RT);
    messageArray.append((char)GroundCablePhaseB_RT);
    messageArray.append((char)GroundCablePhaseC_RT);
    messageArray.append((char)GroundCablePhaseN_RT);

    messageArray.append((char)GroundCablePhaseA_Temp_RT);
    messageArray.append((char)GroundCablePhaseB_Temp_RT);
    messageArray.append((char)GroundCablePhaseC_Temp_RT);
    messageArray.append((char)GroundCablePhaseN_Temp_RT);

    uint16_t crc = crc16((uint8_t*)messageArray.constData(), messageArray.length());

    frameArray.append(0x5A);
    frameArray.append(0xA5);

    uint16_t msglen = messageArray.length();
    frameArray.append((char)(msglen >> 8));
    frameArray.append((char)(msglen & 0xff));
    frameArray.append(messageArray);
    frameArray.append((char)(crc >> 8));
    frameArray.append((char)(crc & 0xff));
    frameArray.append((char)0xAA);

    return frameArray;
#endif /* 0 */

    QByteArray frameArray;
    QByteArray messageArray;

    messageArray.append((char)0x81);
    messageArray.append((char)0xA0);
    
    messageArray.append((char)0x38);
    messageArray.append((char)0x04);
    messageArray.append((char)0x11);
    messageArray.append((char)0x40);
    
    messageArray.append((char)0x00);
    messageArray.append((char)0x00);
    messageArray.append((char)0x00);
    messageArray.append((char)0x00);
    
    messageArray.append((char)0x01);
    messageArray.append((char)0x00);
    
    messageArray.append((char)0x00);
    messageArray.append((char)0x00);
    
    messageArray.append((char)0xff);
    messageArray.append((char)0xff);
    messageArray.append((char)0xff);
    messageArray.append((char)0xff);
    messageArray.append((char)0x12);
    messageArray.append((char)0x34);
    messageArray.append((char)0x56);
    messageArray.append((char)0x78);
    messageArray.append((char)0x05);
    messageArray.append((char)0x00);
    messageArray.append((char)0x00);
    messageArray.append((char)0x00);
    messageArray.append((char)0x00);
    messageArray.append((char)0x00);
    messageArray.append((char)0x00);
    messageArray.append((char)0x00);
    messageArray.append((char)0x00);
    messageArray.append((char)0x00);
    messageArray.append((char)0x00);
    messageArray.append((char)0x00);
    messageArray.append((char)0x00);
    messageArray.append((char)0x00);
    messageArray.append((char)0x00);
    messageArray.append((char)0x00);
    messageArray.append((char)0x00);
    messageArray.append((char)0x00);
    messageArray.append((char)0x00);
    messageArray.append((char)0x00);
    messageArray.append((char)0x00);
    messageArray.append((char)0x00);
    messageArray.append((char)0x00);
    messageArray.append((char)0x00);
    messageArray.append((char)0x00);
    messageArray.append((char)0x00);
    messageArray.append((char)0x00);
    messageArray.append((char)0x00);
    uint16_t crc = crc16((uint8_t*)messageArray.constData(), messageArray.length());

    frameArray.append(0xAA);
    frameArray.append(0xAA);
    frameArray.append(0x55);
    frameArray.append(0x55);

    uint16_t msglen = messageArray.length();
    frameArray.append((char)0x40);
    frameArray.append((char)0x00);
    frameArray.append(messageArray);
    frameArray.append((char)0x8f);
    frameArray.append((char)0x38);
    frameArray.append((char)0xe8);
    frameArray.append((char)0x58);
    frameArray.append((char)0xA5);
    frameArray.append((char)0x5A);
    frameArray.append((char)0xA5);
    frameArray.append((char)0x5A);

    return frameArray;

}

QByteArray comProtocol::assembleStatisticalDataRequestFrame(deviceIdType devid)
{
    QByteArray frameArray;
    QByteArray messageArray;

    messageArray.append((char)sndDataMessage);
    messageArray.append(devid.toByteArray());
    messageArray.append((char)0x0F);

    messageArray.append((char)MainCable_AVG);
    messageArray.append((char)MainCable_MAX);
    messageArray.append((char)MainCable_MIN);

    messageArray.append((char)GroundCablePhaseA_AVG);
    messageArray.append((char)GroundCablePhaseA_MAX);
    messageArray.append((char)GroundCablePhaseA_MIN);


    messageArray.append((char)GroundCablePhaseB_AVG);
    messageArray.append((char)GroundCablePhaseB_MAX);
    messageArray.append((char)GroundCablePhaseB_MIN);


    messageArray.append((char)GroundCablePhaseC_AVG);
    messageArray.append((char)GroundCablePhaseC_MAX);
    messageArray.append((char)GroundCablePhaseC_MIN);

    messageArray.append((char)GroundCablePhaseN_AVG);
    messageArray.append((char)GroundCablePhaseN_MAX);
    messageArray.append((char)GroundCablePhaseN_MIN);

    uint16_t crc = crc16((uint8_t*)messageArray.constData(), messageArray.length());

    frameArray.append(0x5A);
    frameArray.append(0xA5);

    uint16_t msglen = messageArray.length();
    frameArray.append((char)(msglen >> 8));
    frameArray.append((char)(msglen & 0xff));
    frameArray.append(messageArray);
    frameArray.append((char)(crc >> 8));
    frameArray.append((char)(crc & 0xff));
    frameArray.append((char)0xAA);

    return frameArray;
}

QByteArray comProtocol::assembleStatisticalAndAlarmDataRequestFrame(deviceIdType devid)
{
    QByteArray frameArray;
    QByteArray messageArray;

    messageArray.append((char)sndDataMessage);
    messageArray.append(devid.toByteArray());
    messageArray.append((char)0x0F);

    messageArray.append((char)MainCable_AVG);
    messageArray.append((char)MainCable_MAX);
    messageArray.append((char)MainCable_MIN);

    messageArray.append((char)GroundCablePhaseA_AVG);
    messageArray.append((char)GroundCablePhaseA_MAX);
    messageArray.append((char)GroundCablePhaseA_MIN);

    messageArray.append((char)GroundCablePhaseB_AVG);
    messageArray.append((char)GroundCablePhaseB_MAX);
    messageArray.append((char)GroundCablePhaseB_MIN);

    messageArray.append((char)GroundCablePhaseC_AVG);
    messageArray.append((char)GroundCablePhaseC_MAX);
    messageArray.append((char)GroundCablePhaseC_MIN);

    messageArray.append((char)GroundCablePhaseN_AVG);
    messageArray.append((char)GroundCablePhaseN_MAX);
    messageArray.append((char)GroundCablePhaseN_MIN);

    uint16_t crc = crc16((uint8_t*)messageArray.constData(), messageArray.length());

    frameArray.append(0x5A);
    frameArray.append(0xA5);

    uint16_t msglen = messageArray.length();
    frameArray.append((char)(msglen >> 8));
    frameArray.append((char)(msglen & 0xff));
    frameArray.append(messageArray);
    frameArray.append((char)(crc >> 8));
    frameArray.append((char)(crc & 0xff));
    frameArray.append((char)0xAA);

    return frameArray;
}

QByteArray comProtocol::assembleTimeSetFrame(deviceIdType devid, QDateTime time)
{
    QByteArray frameArray;
    QByteArray messageArray;

    messageArray.append((char)sndConfigWriteMessage);
    messageArray.append(devid.toByteArray());
    messageArray.append((char)0x01);

    messageArray.append((char)RtcTime_Set);

    uint32_t settime = time.toTime_t();
    messageArray.append((char)(settime >> 24));
    messageArray.append((char)(settime >> 16));
    messageArray.append((char)(settime >> 8));
    messageArray.append((char)(settime & 0xff));

    uint16_t crc = crc16((uint8_t*)messageArray.constData(), messageArray.length());

    frameArray.append(0x5A);
    frameArray.append(0xA5);

    uint16_t msglen = messageArray.length();
    frameArray.append((char)(msglen >> 8));
    frameArray.append((char)(msglen & 0xff));
    frameArray.append(messageArray);
    frameArray.append((char)(crc >> 8));
    frameArray.append((char)(crc & 0xff));
    frameArray.append((char)0xAA);

    return frameArray;
}

QByteArray comProtocol::assembleStatisticalArgumentFrame(deviceIdType devid, uint8_t sampleSec, uint8_t statisticCycle, uint8_t statisticCount)
{
    QByteArray frameArray;
    QByteArray messageArray;

    messageArray.append((char)sndConfigWriteMessage);
    messageArray.append(devid.toByteArray());
    messageArray.append((char)0x01);

    messageArray.append((char)StatisticArgument);

    messageArray.append((char)(sampleSec));
    messageArray.append((char)(statisticCycle));
    messageArray.append((char)(statisticCount));
    messageArray.append((char)(0x00));

    uint16_t crc = crc16((uint8_t*)messageArray.constData(), messageArray.length());

    frameArray.append(0x5A);
    frameArray.append(0xA5);

    uint16_t msglen = messageArray.length();
    frameArray.append((char)(msglen >> 8));
    frameArray.append((char)(msglen & 0xff));
    frameArray.append(messageArray);
    frameArray.append((char)(crc >> 8));
    frameArray.append((char)(crc & 0xff));
    frameArray.append((char)0xAA);

    return frameArray;
}

QByteArray comProtocol::assembleThresholdFrame(deviceIdType devid, uint8_t thresholdType, float thresholdValue)
{
    QByteArray frameArray;
    QByteArray messageArray;

    messageArray.append((char)sndConfigWriteMessage);
    messageArray.append(devid.toByteArray());
    messageArray.append((char)0x01);

    messageArray.append((char)thresholdType);

    uint32_t temp = (uint32_t)thresholdValue;
//    uint32_t temp = 0;
//    memcpy(&temp, &thresholdValue, sizeof(float));
    messageArray.append((char)(temp >> 24));
    messageArray.append((char)(temp >> 16));
    messageArray.append((char)(temp >> 8));
    messageArray.append((char)(temp & 0xff));

    uint16_t crc = crc16((uint8_t*)messageArray.constData(), messageArray.length());

    frameArray.append(0x5A);
    frameArray.append(0xA5);

    uint16_t msglen = messageArray.length();
    frameArray.append((char)(msglen >> 8));
    frameArray.append((char)(msglen & 0xff));
    frameArray.append(messageArray);
    frameArray.append((char)(crc >> 8));
    frameArray.append((char)(crc & 0xff));
    frameArray.append((char)0xAA);

    return frameArray;
}

QByteArray comProtocol::assembleCtFrame(deviceIdType devid, uint8_t cttype, float value)
{
    QByteArray frameArray;
    QByteArray messageArray;

    messageArray.append((char)sndConfigWriteMessage);
    messageArray.append(devid.toByteArray());
    messageArray.append((char)0x01);

    messageArray.append((char)cttype);

    uint32_t temp = (uint32_t )value;
//    uint32_t temp = 0;
//    memcpy(&temp, &value, sizeof(float));
    messageArray.append((char)(temp >> 24));
    messageArray.append((char)(temp >> 16));
    messageArray.append((char)(temp >> 8));
    messageArray.append((char)(temp & 0xff));

    uint16_t crc = crc16((uint8_t*)messageArray.constData(), messageArray.length());

    frameArray.append(0x5A);
    frameArray.append(0xA5);

    uint16_t msglen = messageArray.length();
    frameArray.append((char)(msglen >> 8));
    frameArray.append((char)(msglen & 0xff));
    frameArray.append(messageArray);
    frameArray.append((char)(crc >> 8));
    frameArray.append((char)(crc & 0xff));
    frameArray.append((char)0xAA);

    return frameArray;
}

QByteArray comProtocol::assembleChannelControlFrame(deviceIdType devid, uint8_t controltype, uint8_t controlbits)
{
    QByteArray frameArray;
    QByteArray messageArray;

    messageArray.append((char)sndConfigWriteMessage);
    messageArray.append(devid.toByteArray());
    messageArray.append((char)0x01);

    messageArray.append((char)controltype);

    messageArray.append((char)(0x00));
    messageArray.append((char)(0x00));
    messageArray.append((char)(0x00));
    messageArray.append((char)(controlbits));

    uint16_t crc = crc16((uint8_t*)messageArray.constData(), messageArray.length());

    frameArray.append(0x5A);
    frameArray.append(0xA5);

    uint16_t msglen = messageArray.length();
    frameArray.append((char)(msglen >> 8));
    frameArray.append((char)(msglen & 0xff));
    frameArray.append(messageArray);
    frameArray.append((char)(crc >> 8));
    frameArray.append((char)(crc & 0xff));
    frameArray.append((char)0xAA);

    return frameArray;
}

QByteArray comProtocol::assembleConfigReadFrame(deviceIdType devid, uint8_t configtype)
{
    QByteArray frameArray;
    QByteArray messageArray;

    messageArray.append((char)sndConfigReadMessage);
    messageArray.append(devid.toByteArray());
    messageArray.append((char)0x01);

    messageArray.append((char)configtype);

    uint16_t crc = crc16((uint8_t*)messageArray.constData(), messageArray.length());

    frameArray.append(0x5A);
    frameArray.append(0xA5);

    uint16_t msglen = messageArray.length();
    frameArray.append((char)(msglen >> 8));
    frameArray.append((char)(msglen & 0xff));
    frameArray.append(messageArray);
    frameArray.append((char)(crc >> 8));
    frameArray.append((char)(crc & 0xff));
    frameArray.append((char)0xAA);

    return frameArray;
}

QByteArray comProtocol::assembleResetFrame(deviceIdType devid)
{
    QByteArray frameArray;
    QByteArray messageArray;

    messageArray.append((char)sndConfigWriteMessage);
    messageArray.append(devid.toByteArray());
    messageArray.append((char)0x01);

    messageArray.append((char)ResetSystem);

    uint16_t crc = crc16((uint8_t*)messageArray.constData(), messageArray.length());

    frameArray.append(0x5A);
    frameArray.append(0xA5);

    uint16_t msglen = messageArray.length();
    frameArray.append((char)(msglen >> 8));
    frameArray.append((char)(msglen & 0xff));
    frameArray.append(messageArray);
    frameArray.append((char)(crc >> 8));
    frameArray.append((char)(crc & 0xff));
    frameArray.append((char)0xAA);

    return frameArray;
}

QByteArray comProtocol::assembleNetConfigFrame(deviceIdType devid, quint32 ipaddress, quint16 port)
{
    QByteArray frameArray;
    QByteArray messageArray;

    messageArray.append((char)sndConfigWriteMessage);
    messageArray.append(devid.toByteArray());
    messageArray.append((char)0x02);
    messageArray.append((char)SERVERIP_Address);
    messageArray.append((char)(ipaddress >> 24));
    messageArray.append((char)(ipaddress >> 16));
    messageArray.append((char)(ipaddress >> 8));
    messageArray.append((char)(ipaddress & 0xff));
    messageArray.append((char)SERVERIP_Port);
    messageArray.append((char)0x00);
    messageArray.append((char)0x00);
    messageArray.append((char)(port >> 8));
    messageArray.append((char)(port & 0xff));

    uint16_t crc = crc16((uint8_t*)messageArray.constData(), messageArray.length());

    frameArray.append(0x5A);
    frameArray.append(0xA5);

    uint16_t msglen = messageArray.length();
    frameArray.append((char)(msglen >> 8));
    frameArray.append((char)(msglen & 0xff));
    frameArray.append(messageArray);
    frameArray.append((char)(crc >> 8));
    frameArray.append((char)(crc & 0xff));
    frameArray.append((char)0xAA);

    return frameArray;
}

QByteArray comProtocol::assembleIAPRequestFrame(deviceIdType devid, quint16 port)
{
    QByteArray frameArray;
    QByteArray messageArray;

    messageArray.append((char)sndConfigWriteMessage);
    messageArray.append(devid.toByteArray());
    messageArray.append((char)0x01);
    messageArray.append((char)IAPUpdate);
    messageArray.append((char)0x00);
    messageArray.append((char)0x00);
    messageArray.append((char)(port >> 8));
    messageArray.append((char)(port & 0xff));

    uint16_t crc = crc16((uint8_t*)messageArray.constData(), messageArray.length());

    frameArray.append(0x5A);
    frameArray.append(0xA5);

    uint16_t msglen = messageArray.length();
    frameArray.append((char)(msglen >> 8));
    frameArray.append((char)(msglen & 0xff));
    frameArray.append(messageArray);
    frameArray.append((char)(crc >> 8));
    frameArray.append((char)(crc & 0xff));
    frameArray.append((char)0xAA);

    return frameArray;
}

QByteArray comProtocol::assembleStatisticalTempRequestFrame(deviceIdType devid)
{
    QByteArray frameArray;
    QByteArray messageArray;

    messageArray.append((char)sndDataMessage);
    messageArray.append(devid.toByteArray());
    messageArray.append((char)0x0C);

    messageArray.append((char)GroundCablePhaseA_Temp_AVG);
    messageArray.append((char)GroundCablePhaseA_Temp_MAX);
    messageArray.append((char)GroundCablePhaseA_Temp_MIN);


    messageArray.append((char)GroundCablePhaseB_Temp_AVG);
    messageArray.append((char)GroundCablePhaseB_Temp_MAX);
    messageArray.append((char)GroundCablePhaseB_Temp_MIN);


    messageArray.append((char)GroundCablePhaseC_Temp_AVG);
    messageArray.append((char)GroundCablePhaseC_Temp_MAX);
    messageArray.append((char)GroundCablePhaseC_Temp_MIN);

    messageArray.append((char)GroundCablePhaseN_Temp_AVG);
    messageArray.append((char)GroundCablePhaseN_Temp_MAX);
    messageArray.append((char)GroundCablePhaseN_Temp_MIN);

    uint16_t crc = crc16((uint8_t*)messageArray.constData(), messageArray.length());

    frameArray.append(0x5A);
    frameArray.append(0xA5);

    uint16_t msglen = messageArray.length();
    frameArray.append((char)(msglen >> 8));
    frameArray.append((char)(msglen & 0xff));
    frameArray.append(messageArray);
    frameArray.append((char)(crc >> 8));
    frameArray.append((char)(crc & 0xff));
    frameArray.append((char)0xAA);

    return frameArray;
}

QByteArray comProtocol::assembleCURLoadRequestFrame(deviceIdType devid)
{
    QByteArray frameArray;
    QByteArray messageArray;

    messageArray.append((char)sndDataMessage);
    messageArray.append(devid.toByteArray());
    messageArray.append((char)0x04);

    messageArray.append((char)GroundCablePhaseA_Load_RT);
    messageArray.append((char)GroundCablePhaseB_Load_RT);
    messageArray.append((char)GroundCablePhaseC_Load_RT);
    messageArray.append((char)GroundCablePhaseN_Load_RT);

//    messageArray.append((char)GroundCablePhaseA_Temp_AVG);
//    messageArray.append((char)GroundCablePhaseA_Temp_MAX);
//    messageArray.append((char)GroundCablePhaseA_Temp_MIN);


//    messageArray.append((char)GroundCablePhaseB_Temp_AVG);
//    messageArray.append((char)GroundCablePhaseB_Temp_MAX);
//    messageArray.append((char)GroundCablePhaseB_Temp_MIN);


//    messageArray.append((char)GroundCablePhaseC_Temp_AVG);
//    messageArray.append((char)GroundCablePhaseC_Temp_MAX);
//    messageArray.append((char)GroundCablePhaseC_Temp_MIN);

//    messageArray.append((char)GroundCablePhaseN_Temp_AVG);
//    messageArray.append((char)GroundCablePhaseN_Temp_MAX);
//    messageArray.append((char)GroundCablePhaseN_Temp_MIN);

    uint16_t crc = crc16((uint8_t*)messageArray.constData(), messageArray.length());

    frameArray.append(0x5A);
    frameArray.append(0xA5);

    uint16_t msglen = messageArray.length();
    frameArray.append((char)(msglen >> 8));
    frameArray.append((char)(msglen & 0xff));
    frameArray.append(messageArray);
    frameArray.append((char)(crc >> 8));
    frameArray.append((char)(crc & 0xff));
    frameArray.append((char)0xAA);

    return frameArray;
}

QByteArray comProtocol::assembleCURatioRequestFrame(deviceIdType devid)
{
    QByteArray frameArray;
    QByteArray messageArray;

    messageArray.append((char)sndDataMessage);
    messageArray.append(devid.toByteArray());
    messageArray.append((char)0x04);

    messageArray.append((char)GroundCablePhaseA_Ratio_RT);
    messageArray.append((char)GroundCablePhaseB_Ratio_RT);
    messageArray.append((char)GroundCablePhaseC_Ratio_RT);
    messageArray.append((char)GroundCablePhaseN_Ratio_RT);

//    messageArray.append((char)GroundCablePhaseA_Temp_AVG);
//    messageArray.append((char)GroundCablePhaseA_Temp_MAX);
//    messageArray.append((char)GroundCablePhaseA_Temp_MIN);


//    messageArray.append((char)GroundCablePhaseB_Temp_AVG);
//    messageArray.append((char)GroundCablePhaseB_Temp_MAX);
//    messageArray.append((char)GroundCablePhaseB_Temp_MIN);


//    messageArray.append((char)GroundCablePhaseC_Temp_AVG);
//    messageArray.append((char)GroundCablePhaseC_Temp_MAX);
//    messageArray.append((char)GroundCablePhaseC_Temp_MIN);

//    messageArray.append((char)GroundCablePhaseN_Temp_AVG);
//    messageArray.append((char)GroundCablePhaseN_Temp_MAX);
//    messageArray.append((char)GroundCablePhaseN_Temp_MIN);

    uint16_t crc = crc16((uint8_t*)messageArray.constData(), messageArray.length());

    frameArray.append(0x5A);
    frameArray.append(0xA5);

    uint16_t msglen = messageArray.length();
    frameArray.append((char)(msglen >> 8));
    frameArray.append((char)(msglen & 0xff));
    frameArray.append(messageArray);
    frameArray.append((char)(crc >> 8));
    frameArray.append((char)(crc & 0xff));
    frameArray.append((char)0xAA);

    return frameArray;
}

QByteArray comProtocol::assembleCURateRequestFrame(deviceIdType devid)
{
    QByteArray frameArray;
    QByteArray messageArray;

    messageArray.append((char)sndDataMessage);
    messageArray.append(devid.toByteArray());
    messageArray.append((char)0x04);

    messageArray.append((char)GroundCablePhaseAChangeRate_Alarm);
    messageArray.append((char)GroundCablePhaseBChangeRate_Alarm);
    messageArray.append((char)GroundCablePhaseCChangeRate_Alarm);
    messageArray.append((char)GroundCablePhaseNChangeRate_Alarm);

//    messageArray.append((char)GroundCablePhaseA_Temp_AVG);
//    messageArray.append((char)GroundCablePhaseA_Temp_MAX);
//    messageArray.append((char)GroundCablePhaseA_Temp_MIN);


//    messageArray.append((char)GroundCablePhaseB_Temp_AVG);
//    messageArray.append((char)GroundCablePhaseB_Temp_MAX);
//    messageArray.append((char)GroundCablePhaseB_Temp_MIN);


//    messageArray.append((char)GroundCablePhaseC_Temp_AVG);
//    messageArray.append((char)GroundCablePhaseC_Temp_MAX);
//    messageArray.append((char)GroundCablePhaseC_Temp_MIN);

//    messageArray.append((char)GroundCablePhaseN_Temp_AVG);
//    messageArray.append((char)GroundCablePhaseN_Temp_MAX);
//    messageArray.append((char)GroundCablePhaseN_Temp_MIN);

    uint16_t crc = crc16((uint8_t*)messageArray.constData(), messageArray.length());

    frameArray.append(0x5A);
    frameArray.append(0xA5);

    uint16_t msglen = messageArray.length();
    frameArray.append((char)(msglen >> 8));
    frameArray.append((char)(msglen & 0xff));
    frameArray.append(messageArray);
    frameArray.append((char)(crc >> 8));
    frameArray.append((char)(crc & 0xff));
    frameArray.append((char)0xAA);

    return frameArray;
}

QByteArray comProtocol::assembleCURVibrationRequestFrame(deviceIdType devid)
{
    QByteArray frameArray;
    QByteArray messageArray;

    messageArray.append((char)sndDataMessage);
    messageArray.append(devid.toByteArray());
    messageArray.append((char)0x04);

    messageArray.append((char)GroundCablePhaseAVibrationCount_Alarm);
    messageArray.append((char)GroundCablePhaseBVibrationCount_Alarm);
    messageArray.append((char)GroundCablePhaseCVibrationCount_Alarm);
    messageArray.append((char)GroundCablePhaseNVibrationCount_Alarm);

//    messageArray.append((char)GroundCablePhaseA_Temp_AVG);
//    messageArray.append((char)GroundCablePhaseA_Temp_MAX);
//    messageArray.append((char)GroundCablePhaseA_Temp_MIN);


//    messageArray.append((char)GroundCablePhaseB_Temp_AVG);
//    messageArray.append((char)GroundCablePhaseB_Temp_MAX);
//    messageArray.append((char)GroundCablePhaseB_Temp_MIN);


//    messageArray.append((char)GroundCablePhaseC_Temp_AVG);
//    messageArray.append((char)GroundCablePhaseC_Temp_MAX);
//    messageArray.append((char)GroundCablePhaseC_Temp_MIN);

//    messageArray.append((char)GroundCablePhaseN_Temp_AVG);
//    messageArray.append((char)GroundCablePhaseN_Temp_MAX);
//    messageArray.append((char)GroundCablePhaseN_Temp_MIN);

    uint16_t crc = crc16((uint8_t*)messageArray.constData(), messageArray.length());

    frameArray.append(0x5A);
    frameArray.append(0xA5);

    uint16_t msglen = messageArray.length();
    frameArray.append((char)(msglen >> 8));
    frameArray.append((char)(msglen & 0xff));
    frameArray.append(messageArray);
    frameArray.append((char)(crc >> 8));
    frameArray.append((char)(crc & 0xff));
    frameArray.append((char)0xAA);

    return frameArray;
}

QByteArray comProtocol::assembleReadInputVolRequestFrame(deviceIdType devid)
{
    QByteArray frameArray;
    QByteArray messageArray;

    messageArray.append((char)sndDataMessage);
    messageArray.append(devid.toByteArray());
    messageArray.append((char)0x01);

    messageArray.append((char)InputVolt);

//    messageArray.append((char)GroundCablePhaseA_Temp_AVG);
//    messageArray.append((char)GroundCablePhaseA_Temp_MAX);
//    messageArray.append((char)GroundCablePhaseA_Temp_MIN);


//    messageArray.append((char)GroundCablePhaseB_Temp_AVG);
//    messageArray.append((char)GroundCablePhaseB_Temp_MAX);
//    messageArray.append((char)GroundCablePhaseB_Temp_MIN);


//    messageArray.append((char)GroundCablePhaseC_Temp_AVG);
//    messageArray.append((char)GroundCablePhaseC_Temp_MAX);
//    messageArray.append((char)GroundCablePhaseC_Temp_MIN);

//    messageArray.append((char)GroundCablePhaseN_Temp_AVG);
//    messageArray.append((char)GroundCablePhaseN_Temp_MAX);
//    messageArray.append((char)GroundCablePhaseN_Temp_MIN);

    uint16_t crc = crc16((uint8_t*)messageArray.constData(), messageArray.length());

    frameArray.append(0x5A);
    frameArray.append(0xA5);

    uint16_t msglen = messageArray.length();
    frameArray.append((char)(msglen >> 8));
    frameArray.append((char)(msglen & 0xff));
    frameArray.append(messageArray);
    frameArray.append((char)(crc >> 8));
    frameArray.append((char)(crc & 0xff));
    frameArray.append((char)0xAA);

    return frameArray;
}

QByteArray comProtocol::assembleReadRTDataRequestFrame(deviceIdType devid)
{
    QByteArray frameArray;
    QByteArray messageArray;

    messageArray.append((char)sndDataMessage);
    messageArray.append(devid.toByteArray());
    messageArray.append((char)0x08);

    messageArray.append((char)GroundCablePhaseA_Load_RT);
    messageArray.append((char)GroundCablePhaseB_Load_RT);
    messageArray.append((char)GroundCablePhaseC_Load_RT);
    messageArray.append((char)GroundCablePhaseN_Load_RT);

    messageArray.append((char)GroundCablePhaseA_Ratio_RT);
    messageArray.append((char)GroundCablePhaseB_Ratio_RT);
    messageArray.append((char)GroundCablePhaseC_Ratio_RT);
    messageArray.append((char)GroundCablePhaseN_Ratio_RT);

//    messageArray.append((char)GroundCablePhaseAChangeRate_Alarm);
//    messageArray.append((char)GroundCablePhaseBChangeRate_Alarm);
//    messageArray.append((char)GroundCablePhaseCChangeRate_Alarm);
//    messageArray.append((char)GroundCablePhaseNChangeRate_Alarm);

//    messageArray.append((char)GroundCablePhaseAVibrationCount_Alarm);
//    messageArray.append((char)GroundCablePhaseBVibrationCount_Alarm);
//    messageArray.append((char)GroundCablePhaseCVibrationCount_Alarm);
//    messageArray.append((char)GroundCablePhaseNVibrationCount_Alarm);


    uint16_t crc = crc16((uint8_t*)messageArray.constData(), messageArray.length());

    frameArray.append(0x5A);
    frameArray.append(0xA5);

    uint16_t msglen = messageArray.length();
    frameArray.append((char)(msglen >> 8));
    frameArray.append((char)(msglen & 0xff));
    frameArray.append(messageArray);
    frameArray.append((char)(crc >> 8));
    frameArray.append((char)(crc & 0xff));
    frameArray.append((char)0xAA);

    return frameArray;
}

QByteArray comProtocol::assembleTempStatisticalArgumentFrame(deviceIdType devid, uint8_t sampleSec, uint8_t statisticCycle, uint8_t statisticCount)
{
    QByteArray frameArray;
    QByteArray messageArray;

    messageArray.append((char)sndConfigWriteMessage);
    messageArray.append(devid.toByteArray());
    messageArray.append((char)0x01);

    messageArray.append((char)TemperatureMeasureCycle);

    messageArray.append((char)(sampleSec));
    messageArray.append((char)(statisticCycle));
    messageArray.append((char)(statisticCount));
    messageArray.append((char)(0x00));

    uint16_t crc = crc16((uint8_t*)messageArray.constData(), messageArray.length());

    frameArray.append(0x5A);
    frameArray.append(0xA5);

    uint16_t msglen = messageArray.length();
    frameArray.append((char)(msglen >> 8));
    frameArray.append((char)(msglen & 0xff));
    frameArray.append(messageArray);
    frameArray.append((char)(crc >> 8));
    frameArray.append((char)(crc & 0xff));
    frameArray.append((char)0xAA);

    return frameArray;
}

QByteArray comProtocol::assembleSetVibrateThreshildFrame(deviceIdType devid, uint8_t cttype, float value)
{
    QByteArray frameArray;
    QByteArray messageArray;

    messageArray.append((char)sndConfigWriteMessage);
    messageArray.append(devid.toByteArray());
    messageArray.append((char)0x01);

    messageArray.append((char)cttype);

    uint32_t temp = (uint32_t)value;
    messageArray.append((char)(temp >> 24));
    messageArray.append((char)(temp >> 16));
    messageArray.append((char)(temp >> 8));
    messageArray.append((char)(temp & 0xff));

    uint16_t crc = crc16((uint8_t*)messageArray.constData(), messageArray.length());

    frameArray.append(0x5A);
    frameArray.append(0xA5);

    uint16_t msglen = messageArray.length();
    frameArray.append((char)(msglen >> 8));
    frameArray.append((char)(msglen & 0xff));
    frameArray.append(messageArray);
    frameArray.append((char)(crc >> 8));
    frameArray.append((char)(crc & 0xff));
    frameArray.append((char)0xAA);

    return frameArray;
}

QByteArray comProtocol::assembleSetVibrateTimeFrame(deviceIdType devid, float value)
{
    QByteArray frameArray;
    QByteArray messageArray;

    messageArray.append((char)sndConfigWriteMessage);
    messageArray.append(devid.toByteArray());
    messageArray.append((char)0x01);

    messageArray.append((char)VibrationStatisticalCycle);

    uint32_t temp = (uint32_t)value;
    messageArray.append((char)(temp >> 24));
    messageArray.append((char)(temp >> 16));
    messageArray.append((char)(temp >> 8));
    messageArray.append((char)(temp & 0xff));

    uint16_t crc = crc16((uint8_t*)messageArray.constData(), messageArray.length());

    frameArray.append(0x5A);
    frameArray.append(0xA5);

    uint16_t msglen = messageArray.length();
    frameArray.append((char)(msglen >> 8));
    frameArray.append((char)(msglen & 0xff));
    frameArray.append(messageArray);
    frameArray.append((char)(crc >> 8));
    frameArray.append((char)(crc & 0xff));
    frameArray.append((char)0xAA);

    return frameArray;
}

QByteArray comProtocol::assembleSetCurChangerateThreshildFrame(deviceIdType devid, uint8_t cttype, float value)
{
    QByteArray frameArray;
    QByteArray messageArray;

    messageArray.append((char)sndConfigWriteMessage);
    messageArray.append(devid.toByteArray());
    messageArray.append((char)0x01);

    messageArray.append((char)cttype);

    uint32_t temp = (uint32_t)value;
    messageArray.append((char)(temp >> 24));
    messageArray.append((char)(temp >> 16));
    messageArray.append((char)(temp >> 8));
    messageArray.append((char)(temp & 0xff));

    uint16_t crc = crc16((uint8_t*)messageArray.constData(), messageArray.length());

    frameArray.append(0x5A);
    frameArray.append(0xA5);

    uint16_t msglen = messageArray.length();
    frameArray.append((char)(msglen >> 8));
    frameArray.append((char)(msglen & 0xff));
    frameArray.append(messageArray);
    frameArray.append((char)(crc >> 8));
    frameArray.append((char)(crc & 0xff));
    frameArray.append((char)0xAA);

    return frameArray;
}

QByteArray comProtocol::assembleSetCurChangerateCycleFrame(deviceIdType devid, float value)
{
    QByteArray frameArray;
    QByteArray messageArray;

    messageArray.append((char)sndConfigWriteMessage);
    messageArray.append(devid.toByteArray());
    messageArray.append((char)0x01);

    messageArray.append((char)SetChangeRateStatistical);

    uint32_t temp = (uint32_t)value;
    messageArray.append((char)(temp >> 24));
    messageArray.append((char)(temp >> 16));
    messageArray.append((char)(temp >> 8));
    messageArray.append((char)(temp & 0xff));

    uint16_t crc = crc16((uint8_t*)messageArray.constData(), messageArray.length());

    frameArray.append(0x5A);
    frameArray.append(0xA5);

    uint16_t msglen = messageArray.length();
    frameArray.append((char)(msglen >> 8));
    frameArray.append((char)(msglen & 0xff));
    frameArray.append(messageArray);
    frameArray.append((char)(crc >> 8));
    frameArray.append((char)(crc & 0xff));
    frameArray.append((char)0xAA);

    return frameArray;
}
