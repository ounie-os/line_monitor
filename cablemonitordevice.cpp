#include "cablemonitordevice.h"

CableMonitorDevice::CableMonitorDevice()
{

}

CableMonitorDevice::~CableMonitorDevice()
{

}

void CableMonitorDevice::setDeviceDeviceId(deviceIdType devid)
{
    this->deviceId = devid;
}

void CableMonitorDevice::setDeviceName(QString devname)
{
    this->deviceName = devname;
}

void CableMonitorDevice::setUserName(QString username)
{
    this->userName = username;
}

deviceIdType CableMonitorDevice::getDeviceId()
{
    return this->deviceId;
}

QString CableMonitorDevice::getDeviceName()
{
    return this->deviceName;
}

QString CableMonitorDevice::getUserName()
{
    return this->userName;
}
