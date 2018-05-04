#include "channelinfotype.h"

ChannelInfoType::ChannelInfoType()
{
}

ChannelInfoType::~ChannelInfoType()
{

}

bool ChannelInfoType::operator ==(const ChannelInfoType &info) const
{
    if(this->deviceId == info.deviceId && this->phase == info.phase)
        return true;
    else
        return false;
}

bool ChannelInfoType::operator !=(const ChannelInfoType &info) const
{
    if(this->deviceId == info.deviceId && this->phase == info.phase)
        return false;
    else
        return true;
}

QString ChannelInfoType::toPhaseString()
{
    QString str;
    switch (this->phase) {
    case 0:
        str = "主缆电流实时值";
        break;
    case 1:
        str = "主缆电流报警值";
        break;
    case 2:
        str = "A相电流实时值";
        break;
    case 3:
        str = "A相电流报警值";
        break;
    case 4:
        str = "B相电流实时值";
        break;
    case 5:
        str = "B相电流报警值";
        break;
    case 6:
        str = "C相电流实时值";
        break;
    case 7:
        str = "C相电流报警值";
        break;
    case 8:
        str = "N相电流实时值";
        break;
    case 9:
        str = "N相电流报警值";
        break;
    case 10:
        str = "A相温度实时值";
        break;
    case 11:
        str = "A相温度报警值";
        break;
    case 12:
        str = "B相温度实时值";
        break;
    case 13:
        str = "B相温度报警值";
        break;
    case 14:
        str = "C相温度实时值";
        break;
    case 15:
        str = "C相温度报警值";
        break;
    case 16:
        str = "N相温度实时值";
        break;
    case 17:
        str = "N相温度报警值";
        break;

    default:
        str = "Unknown";
        break;
    }

    return str;
}
