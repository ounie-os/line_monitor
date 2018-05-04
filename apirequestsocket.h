#ifndef APIREQUESTSOCKET_H
#define APIREQUESTSOCKET_H

#include <QObject>
#include <QTcpSocket>

#include "deviceidtype.h"

class ApiRequestSocket : public QObject
{
    Q_OBJECT
public:
    explicit ApiRequestSocket(QTcpSocket *socket = 0, QObject *parent = 0);
    ~ApiRequestSocket();
signals:
    void disconnected();
    void requestDataSignal(deviceIdType id);
public slots:
    void writeToNet(QString text);
private slots:
    void socketReadFromNet();
    void disconnectedSlot();
private:
    QTcpSocket *tcpSocket;
    QByteArray readBufferArray;
};

#endif // APIREQUESTSOCKET_H
