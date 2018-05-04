#ifndef TCPCLIENTTYPE_H
#define TCPCLIENTTYPE_H
#include <QObject>

class TcpClientType
{
public:
    TcpClientType();
    int clientfd;
    QString ip;
    quint16 port;

    bool operator ==(const TcpClientType &type) const;
    bool operator !=(const TcpClientType &type) const;
};

#endif // TCPCLIENTTYPE_H
