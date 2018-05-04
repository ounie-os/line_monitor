#include "tcpserverdevice.h"
#include "myhelper.h"
#include <QThread>
#define TEST
/*!
 * \brief tcpServerDevice::tcpServerDevice
 * \param parent
 */
tcpServerDevice::tcpServerDevice(QObject *parent)
    :QTcpServer(parent)
{
    hash_clientfd_client.clear();
    hash_clientIP_clientfd.clear();
}

tcpServerDevice::~tcpServerDevice()
{
    hash_clientfd_client.clear();
    hash_clientIP_clientfd.clear();
}

void tcpServerDevice::incomingConnection(int socketDescriptor)
{
    tcpClientDevice *tcpclient =new tcpClientDevice();
    tcpclient->setSocketDescriptor(socketDescriptor);
    tcpclient->set_clientfd(socketDescriptor);
    QThread *thread_tcpclient = new QThread();
    connect(tcpclient,SIGNAL(destroyed(QObject*)),thread_tcpclient,SLOT(quit()));
    connect(thread_tcpclient,SIGNAL(finished()),thread_tcpclient,SLOT(deleteLater()));

    connect(this,SIGNAL(destroyed(QObject*)),tcpclient,SLOT(slot_close_client()));
    connect(this,SIGNAL(signal_close_all_client()),tcpclient,SLOT(slot_client_disconnect()));
    connect(tcpclient,SIGNAL(signal_disconnect_to_server(int,QString,quint16)),this,SLOT(slot_client_disconnect(int,QString,quint16)));
    connect(this,SIGNAL(signal_send_data_to_client(int,QByteArray)),tcpclient,SLOT(slot_send_data_to_client(int,QByteArray)));
    connect(tcpclient,SIGNAL(signal_send_data_to_server(int,QByteArray)),this,SLOT(slot_send_data_to_ui(int,QByteArray)));

    tcpclient->moveToThread(thread_tcpclient);
    thread_tcpclient->start();
    qDebug()<<"["+tcpclient->peerAddress().toString()+":"+QString::number(tcpclient->peerPort())+"]"+"上线";
#ifdef TEST
    QString ip   = tcpclient->peerAddress().toString();
    if(hash_clientIP_clientfd.contains(ip))
    {
        int clientfd = hash_clientIP_clientfd.value(ip);
        quint16 port = hash_clientfd_client.value(clientfd)->peerPort();
        slot_client_disconnect(clientfd,ip,port);
        hash_clientIP_clientfd.remove(ip);
        if(hash_clientfd_client.contains(clientfd))
        {
            hash_clientfd_client.remove(clientfd);
        }
    }
    hash_clientIP_clientfd.insert(ip,socketDescriptor);
#endif
    this->hash_clientfd_client.insert(socketDescriptor,tcpclient);
    emit signal_client_newconnect_to_ui(socketDescriptor,tcpclient->peerAddress().toString(),tcpclient->peerPort());
//    qDebug() << QString("tcpServerDevice thread id:") << QThread::currentThreadId();
}

void tcpServerDevice::slot_open_server()
{
    this->listen(QHostAddress::Any,8234);
//    qDebug()<<"打开连接tcpServerDevice"<<"端口号8234";
//    qDebug() << QString("tcpServerDevice thread id:") << QThread::currentThreadId();
}

void tcpServerDevice::slot_close_server()
{
    this->close();
//    qDebug()<<"关闭连接tcpServerDevice";
    slot_close_all_client();
//    qDebug() << QString("tcpServerDevice thread id:") << QThread::currentThreadId();
}

void tcpServerDevice::slot_close_all_client()
{
    emit signal_close_all_client();
}

void tcpServerDevice::slot_client_disconnect(int clientfd, QString str_ip, quint16 port)
{
    if(hash_clientfd_client.contains(clientfd))
    {
        qDebug()<<"["+str_ip+":"+QString::number(port)+"]"+"下线";
        hash_clientfd_client.value(clientfd)->deleteLater();
        this->hash_clientfd_client.remove(clientfd);
        emit signal_client_disconnect_to_ui(clientfd);
    }
    if(hash_clientIP_clientfd.contains(str_ip))
    {
        hash_clientIP_clientfd.remove(str_ip);
    }
}

void tcpServerDevice::slot_send_data_to_ui(int clientfd, QByteArray data)
{
    emit signal_send_data_to_ui(clientfd,data);
}

void tcpServerDevice::slot_send_data_to_client(int clientfd, QByteArray data)
{
    if(hash_clientfd_client.contains(clientfd))
    {
        emit signal_send_data_to_client(clientfd,data);
    }
}
