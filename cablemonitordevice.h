#ifndef CABLEMONITORDEVICE_H
#define CABLEMONITORDEVICE_H
#include "deviceidtype.h"

class CableMonitorDevice
{
public:
    CableMonitorDevice();
    ~CableMonitorDevice();

    void setDeviceDeviceId(deviceIdType devid);
    void setDeviceName(QString devname);
    void setUserName(QString username);

    deviceIdType getDeviceId();
    QString getDeviceName();
    QString getUserName();
private:
    deviceIdType deviceId;
    QString deviceName;
    QString userName;
};

#endif // CABLEMONITORDEVICE_H
