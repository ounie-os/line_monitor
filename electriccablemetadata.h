#ifndef ELECTRICCABLEMETADATA_H
#define ELECTRICCABLEMETADATA_H

#include <QString>
#include <QDateTime>

#include "dataconf.h"

class electricCableMetaData
{
public:
    electricCableMetaData();
    ~electricCableMetaData();

    static QString currentValue(float value);
    static QString phaseValue(float value);
    static QString temperatureValue(float value);
    static QString humidityValue(float value);
    static QString voltValue(float value);

    bool operator ==(const electricCableMetaData &id) const;
    bool operator !=(const electricCableMetaData &id) const;

    dataType datatype;
    QDateTime time;
    float value;

    void setDataType(dataType type);
};

#endif // ELECTRICCABLEMETADATA_H
