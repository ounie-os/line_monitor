#ifndef TCPSERVERDEVICE_H
#define TCPSERVERDEVICE_H

#include <QTcpServer>
#include "tcpsocketdevice.h"
#include "dataconf.h"
#include "tcpclienttype.h"

class tcpServerDevice : public QTcpServer
{
    Q_OBJECT
public:
    explicit tcpServerDevice(QObject *parent = 0);
    ~tcpServerDevice();

protected:
    void incomingConnection(int socketDescriptor);

signals:
    void signal_client_newconnect_to_ui(int clientfd,QString ip,quint16 port);
    void signal_client_disconnect_to_ui(int clientfd);
    void signal_close_all_client();
    void signal_send_data_to_ui(int clientfd,QByteArray data);
    void signal_send_data_to_client(int clientfd,QByteArray data);

private slots:
    void slot_open_server();
    void slot_close_server();
    void slot_close_all_client();
    void slot_client_disconnect(int clientfd,QString str_ip,quint16 port);
    void slot_send_data_to_ui(int clientfd,QByteArray data);
    void slot_send_data_to_client(int clientfd,QByteArray data);

public slots:

private:
    QHash<int,tcpClientDevice *> hash_clientfd_client; //记录每一个客户端对应的文件描述符
    QHash<QString,int> hash_clientIP_clientfd;        //记录ip对应的客户端（防止同一客户端多次登录）
};

#endif // TCPSERVERDEVICE_H
