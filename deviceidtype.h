#ifndef DEVICEIDTYPE_H
#define DEVICEIDTYPE_H
#include <QObject>
#include <QString>

class deviceIdType
{
public:
    deviceIdType();
    ~deviceIdType();

    quint32 firstId;
#if 0
    quint32 secondId;
    quint32 thirdId;
#endif /* 0 */

    bool operator ==(const deviceIdType &id) const;
    bool operator !=(const deviceIdType &id) const;

    QByteArray toByteArray();
    QString toString();

    static deviceIdType fromString(QString idstr, bool *okflag = 0);
};


#endif // DEVICEIDTYPE_H
