#include "electriccablemetadata.h"

electricCableMetaData::electricCableMetaData()
{
}

electricCableMetaData::~electricCableMetaData()
{

}

QString electricCableMetaData::currentValue(float value)
{
    QString str;
    str.sprintf("%.2f A", value);
    return str;
}

QString electricCableMetaData::phaseValue(float value)
{
    QString str;
    str.sprintf("%.2f", value);
    return str;
}

QString electricCableMetaData::temperatureValue(float value)
{
    QString str;
    str.sprintf("%.2f ℃", value);
    return str;
}

QString electricCableMetaData::humidityValue(float value)
{
    QString str;
    str.sprintf("%7.2f %%RH", value);
    return str;
}

QString electricCableMetaData::voltValue(float value)
{
    QString str;
    str.sprintf("%.2f V", value);
    return str;
}

bool electricCableMetaData::operator ==(const electricCableMetaData &id) const
{
    if((id.datatype == this->datatype)&&(id.time == this->time)&&(id.value == this->value))
    {
        return true;
    }else
    {
        return false;
    }
}

bool electricCableMetaData::operator !=(const electricCableMetaData &id) const
{
    if((id.datatype != this->datatype)&&(id.time != this->time)&&(id.value != this->value))
    {
        return true;
    }else
    {
        return false;
    }
}

void electricCableMetaData::setDataType(dataType type)
{
    this->datatype = type;
}
