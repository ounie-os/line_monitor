#include "tcpsocketdevice.h"
#include "myhelper.h"
#include "dataconf.h"
#include <QThread>
extern uint32_t CNT_COM;

tcpClientDevice::tcpClientDevice(QObject *parent) : QTcpSocket(parent)
{
    connect(this,SIGNAL(readyRead()),this,SLOT(slot_read_data_from_client()));
    connect(this,SIGNAL(disconnected()),this,SLOT(slot_client_disconnect()));
    list_send_data.clear();
    this->timer_send_data = new QTimer();
    this->timer_send_data->setInterval(300);
    connect(this->timer_send_data,SIGNAL(timeout()),this,SLOT(timer_send_data_to_client()));
    this->timer_send_data->start();

//    connect(this,SIGNAL(disconnected()),this,SLOT(deleteLater()));
    connect(this, SIGNAL(bytesWritten(qint64)),
            this, SLOT(slot_send_data_success(qint64)));
}

void tcpClientDevice::set_clientfd(int clientfd)
{
    this->clientfd = clientfd;
}

void tcpClientDevice::slot_read_data_from_client()
{
    ushort crc16 = 0;
    uchar  len   = 0;
    QByteArray data=this->readAll();
    QByteArray deviceId;
    len   = data.at(3);
    if(data.length() >= 4)
    {
        if((0x5A == data.at(0))&&(0xA5 == (uchar)data.at(1))&&(0xAA == (uchar)data.at(6+len)))
        {
            uchar *dataTmp = (uchar *)data.data();
            crc16 = ((uchar)data.at(4+len)<<8)|((uchar)data.at(5+len));
            if(crc16 == myHelper::crc16(&dataTmp[4],len))
            {
//                qDebug() <<"crc16 成功";
                if(dataTmp[18] == MainCable_RT)
                {
                    if(CNT_COM >0)
                    {
                        CNT_COM--;
                    }
                }
                qDebug()<<"从"+ this->peerAddress().toString()+":"
                          +QString::number(this->peerPort())+":"
                          +"接收到数据："+myHelper::ByteArrayToHexStr(data);
                emit signal_send_data_to_server(this->clientfd,data);
            }
        }
    }
//    qDebug() << QString("tcpClientDevice thread id:") << QThread::currentThreadId();
}

void tcpClientDevice::slot_close_client()
{
    this->close();
    this->deleteLater();
}

void tcpClientDevice::slot_client_disconnect()
{
    QString ip = this->peerAddress().toString();
    quint16 port = this->peerPort();
    emit signal_disconnect_to_server(this->clientfd,ip,port);
}

void tcpClientDevice::slot_send_data_to_client(int clientfd, QByteArray data)
{
    if((this->clientfd == clientfd)&&(!list_send_data.contains(data)))
    {
        list_send_data.append(data);
    }
}

void tcpClientDevice::timer_send_data_to_client()
{
    if(list_send_data.length() != 0)
    {
        QByteArray data = list_send_data.at(0);
        this->write(data);
        //==========等待发送成功==============
//        if(this->waitForBytesWritten(10) == true)
//        {
            if(data.at(18) == MainCable_RT)
            {
//                CNT_COM++;
            }
            list_send_data.removeAt(0);
            qDebug()<<"向"+ this->peerAddress().toString()+":"
                                      +QString::number(this->peerPort())
                                      +"发送数据："+myHelper::ByteArrayToHexStr(data);
//        } else {
//            qDebug()<<"向"+ this->peerAddress().toString()+":"
//                                      +QString::number(this->peerPort())
//                                      +"发送数据失败";
//        }
//        qDebug() << QString("tcpClientDevice thread id:") << QThread::currentThreadId();
    }
}

void tcpClientDevice::slot_send_data_success(qint64 size)
{
//    qDebug()<<size;
    if(size == 30) {
        CNT_COM++;
    }
}

void tcpClientDevice::sleep(quint16 sec)
{
    QTime dieTime = QTime::currentTime().addMSecs(sec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
