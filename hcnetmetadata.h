#ifndef HCNETMETADATA_H
#define HCNETMETADATA_H

#include <QByteArray>
#include "dataconf.h"
#include "comprotocol.h"

class HcNetMetaData
{
public:
    HcNetMetaData();
    ~HcNetMetaData();

    quint64 id;
    float CV;
    bool isNormal;

    QByteArray toByteArray();
    static QByteArray assembleFrame(QList<HcNetMetaData> list);
};

#endif // HCNETMETADATA_H
