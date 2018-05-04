#ifndef TCPSOCKETDEVICE_H
#define TCPSOCKETDEVICE_H

#include <QTcpSocket>
#include <QTimer>
#include <QHostAddress>
#include <QMutex>

class tcpClientDevice : public QTcpSocket
{
    Q_OBJECT
public:
    explicit tcpClientDevice(QObject *parent = 0);
    void set_clientfd(int clientfd);

signals:
    void signal_send_data_to_server(int,QByteArray);
    void signal_disconnect_to_server(int,QString,quint16);

private slots:
    void slot_read_data_from_client();
    void slot_close_client();
    void slot_client_disconnect();
    void slot_send_data_to_client(int clientfd,QByteArray data);
    void timer_send_data_to_client();
    void slot_send_data_success(qint64 size);
private:
    int clientfd;
    QList<QByteArray>list_send_data;
    QTimer *timer_send_data;
    void sleep(quint16 sec);

};
#endif // TCPSOCKETDEVICE_H
