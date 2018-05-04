#ifndef APIREQUESTSERVER_H
#define APIREQUESTSERVER_H

#include <QThread>
#include <QTcpServer>
#include <QTcpSocket>
#include <QSqlDatabase>
#include <QDateTime>

#include "apirequestsocket.h"
#include "cablemonitordevice.h"
#include "electriccablemetadata.h"


class ApiRequestServer : public QThread
{
    Q_OBJECT
public:
    explicit ApiRequestServer(QObject *parent = 0);
    ~ApiRequestServer();

    void insertTempDataTable(QString id);
signals:

private slots:
    void newConnectionSetup();
    void connectionDestroy();

    void requestTempData(deviceIdType devid);
public slots:
    void dataUpdate(deviceIdType devid, electricCableMetaData data);
private:
    QTcpServer *netServer;
    QSqlDatabase db;
    int serverPort;
    void createTempDataTable(QString tablename);
    QList<dataType> list_dataType;
};

#endif // APIREQUESTSERVER_H
