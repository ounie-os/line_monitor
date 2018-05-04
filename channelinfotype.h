#ifndef CHANNELINFOTYPE_H
#define CHANNELINFOTYPE_H
#include "deviceidtype.h"

class ChannelInfoType
{
public:
    ChannelInfoType();
    ~ChannelInfoType();

    deviceIdType deviceId;
    int phase;

    bool operator ==(const ChannelInfoType &info) const;
    bool operator !=(const ChannelInfoType &info) const;

    QString toPhaseString();
};

#endif // CHANNELINFOTYPE_H
