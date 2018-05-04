#ifndef SAVETOSERVER_H
#define SAVETOSERVER_H
#include <QTcpSocket>

class SaveToServer : public QTcpSocket
{
    Q_OBJECT
public:
    explicit SaveToServer(QObject *parent = 0);
    ~SaveToServer();
    QString get_ip();
    quint16 get_port();
private slots:
    void slot_open();
    void slot_close();
    void slot_send_data_to_server(QByteArray data);
    void set_ip(QString ip);
    void set_port(quint16 port);
private:
    QString ip;
    quint16 port;
};

#endif // SAVETOSERVER_H
