#include "savetoserver.h"
#include "myhelper.h"
SaveToServer::SaveToServer(QObject *parent)
    :QTcpSocket(parent)
{
    this->ip   = QString("120.24.14.110");
    this->port = 3005;
}

SaveToServer::~SaveToServer()
{
//    this->close();
}

void SaveToServer::slot_open()
{
    this->connectToHost(this->ip,this->port);
    myHelper::Delay_MSec(1000);
    if(this->ConnectedState)
    {
        qDebug()<<"连接远端服务器成功";
    }else
    {
        qDebug()<<"连接远端服务器失败";
    }
}

void SaveToServer::slot_close()
{
    this->close();
}

void SaveToServer::slot_send_data_to_server(QByteArray data)
{
    if(this->ConnectedState)
    {
        this->write(data);
    }
}

QString SaveToServer::get_ip()
{
    return this->ip;
}

void SaveToServer::set_ip(QString ip)
{
    this->ip = ip;
}

quint16 SaveToServer::get_port()
{
    return this->port;
}

void SaveToServer::set_port(quint16 port)
{
    this->port = port;
}
