#include "deviceidtype.h"
#include <QStringList>
#include <QDebug>

deviceIdType::deviceIdType()
{
    this->firstId = 0;
    this->secondId = 0;
    this->thirdId = 0;
}

deviceIdType::~deviceIdType()
{

}

bool deviceIdType::operator ==(const deviceIdType &id) const
{

    if(this->firstId == id.firstId && this->secondId == id.secondId && this->thirdId == id.thirdId)
        return true;
    else
        return false;

}

bool deviceIdType::operator !=(const deviceIdType &id) const
{
    if(this->firstId == id.firstId && this->secondId == id.secondId && this->thirdId == id.thirdId)
        return false;
    else
        return true;
}

QByteArray deviceIdType::toByteArray()
{

    quint8 temp;
    QByteArray retArray;

    for(int i = 3; i >= 0; i--)
    {
        temp = (this->firstId >> i * 8);
        retArray.append((char)temp);
    }

    for(int i = 3; i >= 0; i--)
    {
        temp = (this->secondId >> i * 8);
        retArray.append((char)temp);
    }

    for(int i = 3; i >= 0; i--)
    {
        temp = (this->thirdId >> i * 8);
        retArray.append((char)temp);
    }

    return retArray;
}

QString deviceIdType::toString()
{
    QString retStr;

    retStr.sprintf("%.8x%.8x%.8x", this->firstId, this->secondId, this->thirdId);

    return retStr;
}

deviceIdType deviceIdType::fromString(QString idstr, bool *okflag)
{
    deviceIdType retId;
    QString subidstr;

    subidstr = idstr.right(8);
    if(subidstr.isEmpty())
        retId.thirdId = 0x0000;
    else
        retId.thirdId = subidstr.toUInt(okflag, 16);
    idstr.chop(8);

    subidstr = idstr.right(8);
    if(subidstr.isEmpty())
        retId.secondId = 0x0000;
    else
        retId.secondId = subidstr.toUInt(okflag, 16);
    idstr.chop(8);

    subidstr = idstr.right(8);
    if(subidstr.isEmpty())
        retId.firstId = 0x0000;
    else
        retId.firstId = subidstr.toUInt(okflag, 16);

    return retId;
}
