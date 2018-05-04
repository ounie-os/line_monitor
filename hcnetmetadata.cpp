#include "hcnetmetadata.h"

HcNetMetaData::HcNetMetaData()
{
}

HcNetMetaData::~HcNetMetaData()
{

}

QByteArray HcNetMetaData::toByteArray()
{
    QByteArray array;
    for(int i = 0 ; i < 8; i++)
    {
        array.append((this->id >> (8 * i)) & 0xff);
    }

    quint32 temp = *(quint32*)(&(this->CV));
    for(int i = 0 ; i < 4; i++)
    {
        array.append((temp >> (8 * i)) & 0xff);
    }

    if(this->isNormal)
    {
        array.append((char)0x01);
    }
    else
    {
        array.append((char)0x00);
    }

    return array;
}

QByteArray HcNetMetaData::assembleFrame(QList<HcNetMetaData> list)
{
    QByteArray frame;
    QByteArray message;
    static quint16 flowCode = 0x0000;

    for(int i = 0 ; i < list.length(); i++)
    {
        message.append(list.value(i).toByteArray());
    }

    quint16 frameLength = message.length() + 2 + 2 + 2 + 2 + 2 + 2;
    quint16 objNum = list.length();

    frame.append(0xAA);
    frame.append(0x55);

    frame.append(frameLength & 0xff);
    frame.append((frameLength >> 8) & 0xff);

    frame.append(flowCode & 0xff);
    frame.append((flowCode >> 8) & 0xff);

    frame.append(objNum & 0xff);
    frame.append((objNum >> 8) & 0xff);

    frame.append(message);

    uint16_t crc = comProtocol::crc16((uint8_t*)frame.constData(), frame.length());
    frame.append(crc & 0xff);
    frame.append((crc >> 8) & 0xff);

    frame.append(0xA5);
    frame.append(0x5A);

    return frame;
}
