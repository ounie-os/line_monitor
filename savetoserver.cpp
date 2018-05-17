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
    this->close();
}

void SaveToServer::slot_open()
{
    this->connectToHost(this->ip,this->port);
    this->waitForConnected(1500);
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
        qDebug() << "网口发送数据 ：" << myHelper::ByteArrayToHexStr(data);
    }
}

void SaveToServer::slot_recv_data_from_server()
{
    QByteArray data = this->readAll();
    qDebug() << "网口接收数据 ：" << myHelper::ByteArrayToHexStr(data);
    if (data.length() >= 200)
    {
        if((0xAA == (uchar)data.at(0)) && (0xAA == (uchar)data.at(1)) 
            && (0x55 == (uchar)data.at(2)) && (0x55 == (uchar)data.at(3)))
            {
                emit signal_data_from_server_to_ui(data);
            }
        else
        {
            qDebug() << "帧头不正确";
        }
    }
    else
    {
        qDebug() << "接收报文长度不正确";
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
