#include "comthread.h"
#include <QDebug>
#include "myhelper.h"
#include "dataconf.h"

extern uint32_t CNT_COM;
comThread::comThread(QObject *parent) :
    QThread(parent)
{
    this->comPort = new Win_QextSerialPort("COM1", QextSerialBase::EventDriven);
    this->setting = new comSetting();
    this->sendData.clear();
//    timeBreak = new QTimer(this);
//    timeBreak->setInterval(5000);
    connect(this->comPort, SIGNAL(readyRead()), this, SLOT(comReadSlot()));
//    connect(this->timeBreak,SIGNAL(timeout()),this,SLOT(checkComBreak()));
}

comThread::~comThread()
{
    this->comDisconnect();

    delete this->comPort;
    delete this->setting;
}

void comThread::setComSetting(comSetting *_setting)
{
    this->setting->copyFrom(_setting);
}

comSetting *comThread::getComSetting()
{
    return this->setting;
}

bool comThread::comConnect(comSetting _setting)
{
    this->setting->copyFrom(&_setting);

    this->comPort->setPortName(this->setting->getComPort());
    this->comPort->setBaudRate(this->setting->getBaud());
    this->comPort->setFlowControl(FLOW_OFF);
    this->comPort->setTimeout(3000);
    this->comPort->setDataBits(this->setting->getDataBit());
    this->comPort->setStopBits(this->setting->getStopBit());
    this->comPort->setParity(this->setting->getParity());

    return this->comPort->open(QIODevice::ReadWrite);
}

bool comThread::comConnect()
{
    bool flag;

    this->comPort->setPortName("\\\\.\\" +  this->setting->getComPort());
    flag = this->comPort->open(QIODevice::ReadWrite);
    if(flag)
    {
        this->comPort->flush();
        this->comPort->setBaudRate(this->setting->getBaud());
        this->comPort->setFlowControl(FLOW_OFF);
        this->comPort->setTimeout(10);
        this->comPort->setDataBits(this->setting->getDataBit());
        this->comPort->setStopBits(this->setting->getStopBit());
        this->comPort->setParity(this->setting->getParity());
    }
    return flag;
}

void comThread::comDisconnect()
{
    if(this->comPort->isOpen())
    {
       this->comPort->close();
    }
}

bool comThread::isComConnected()
{
    return this->comPort->isOpen();
}

void comThread::run()
{

    qDebug() << "com thread start";
    while(1)
    {
        if((this->sendData.length() !=0)&&(this->comPort->isOpen()))
        {
            this->comPort->write(this->sendData.at(0));
//            if(this->comPort->waitForBytesWritten(10000) == true) {
                if(this->sendData.at(0).at(18) == MainCable_RT)
                {
                    CNT_COM++;
                }
                qDebug()<<"向485端口发送数据:"+ myHelper::ByteArrayToHexStr(this->sendData.at(0));
                this->mutex_send_data.lock();
                this->sendData.removeOne(this->sendData.at(0));
                this->mutex_send_data.unlock();
                msleep(300);
//            } else {
//                this->mutex_send_data.lock();
//                this->sendData.removeOne(this->sendData.at(0));
//                this->mutex_send_data.unlock();
//                qDebug()<<"向485端口发送数据失败";
//            }
        }
        msleep(10);
    }
    exec();
    qDebug() << "com thread quit";
}

void comThread::comReadSlot()
{
#if 0
    if(this->comPort->bytesAvailable() > 0)
    {
        ushort crc16 = 0;
        uchar  len   = 0;
        QByteArray data = this->comPort->readAll();
        this->readBufferArray.append(data);
        if((0x5A != this->readBufferArray.at(0)) && (0xA5 != (uchar)this->readBufferArray.at(1))) {
            this->readBufferArray.clear();
        }
        if(this->readBufferArray.length() >= 18)
        {
            len = this->readBufferArray.at(3);
            if(this->readBufferArray.length() >= (7+len))
            {
                qDebug()<<"485端口接收数据："+myHelper::ByteArrayToHexStr(this->readBufferArray);
                if((0x5A == this->readBufferArray.at(0))&&(0xA5 == (uchar)this->readBufferArray.at(1))&&(0xAA == (uchar)this->readBufferArray.at(6+len)))
                {
                    uchar *dataTmp = (uchar *)this->readBufferArray.data();
                    crc16 = ((uchar)this->readBufferArray.at(4+len)<<8)|((uchar)this->readBufferArray.at(5+len));
                    if(crc16 == myHelper::crc16(&dataTmp[4],len))
                    {
                        if(this->readBufferArray.at(18) == MainCable_RT)
                        {
                            if(CNT_COM >0)
                            {
                                CNT_COM--;
                            }
                        }
                        emit this->receiveDataFromDevice(this->readBufferArray);
                    }
                }
                this->readBufferArray.clear();
            }
        }

//        len   = data.at(3);
//        if(data.length() >= 4)
//        {
//            if((0x5A == data.at(0))&&(0xA5 == (uchar)data.at(1))&&(0xAA == (uchar)data.at(6+len)))
//            {
//                uchar *dataTmp = (uchar *)data.data();
//                crc16 = ((uchar)data.at(4+len)<<8)|((uchar)data.at(5+len));
//                if(crc16 == myHelper::crc16(&dataTmp[4],len))
//                {
//    //                qDebug() <<"crc16 成功";
//                    qDebug()<<"从"+ this->peerAddress().toString()+":"
//                              +QString::number(this->peerPort())+":"
//                              +"接收到数据："+myHelper::ByteArrayToHexStr(data);
//                    emit tcpClientReadData_signal(this->tcpClientID,data);
//                }
//            }
//        }
//        if(this->readBufferArray.count()>= 6)
//        {
//            qDebug()<<"485端口接收数据："+myHelper::ByteArrayToHexStr(this->readBufferArray);
//            emit this->receiveDataFromDevice(this->readBufferArray);
//            this->readBufferArray.clear();
//        }
    }
#endif /* 0 */
    if(this->comPort->bytesAvailable() > 0)
    {
        ushort crc16 = 0;
        uchar  len   = 0;
        QByteArray data = this->comPort->readAll();
        this->readBufferArray.append(data);
        if((0xAA != this->readBufferArray.at(0)) && (0xAA != (uchar)this->readBufferArray.at(1))
            && (0x55 != (uchar)this->readBufferArray.at(2)) && (0x55 != (uchar)this->readBufferArray.at(3))) {
            this->readBufferArray.clear();
        }
        if(this->readBufferArray.length() >= 18)
        {
            len = this->readBufferArray.at(4);
            //if(this->readBufferArray.length() >= (7+len))
            {
                qDebug()<<"485端口接收数据："+myHelper::ByteArrayToHexStr(this->readBufferArray);
                if((0x5A == (uchar)this->readBufferArray.at(len - 1)) && 0xA5 == (uchar)this->readBufferArray.at(len - 2)
                    && (0x5A == (uchar)this->readBufferArray.at(len - 3)) && (0xA5 == (uchar)this->readBufferArray.at(len - 4)))
                {
                    uchar *dataTmp = (uchar *)this->readBufferArray.data();
                    //crc16 = ((uchar)this->readBufferArray.at(4+len)<<8)|((uchar)this->readBufferArray.at(5+len));
                    //if(crc16 == myHelper::crc16(&dataTmp[4],len))
                    {
                        //if(this->readBufferArray.at(18) == MainCable_RT)
                        {
                            //if(CNT_COM >0)
                            {
                                //CNT_COM--;
                            }
                        }
                        emit this->receiveDataFromDevice(this->readBufferArray);
                    }
                }
                this->readBufferArray.clear();
            }
        }
    }
}

void comThread::sendDataToDevice_slot(QByteArray data)
{
    this->mutex_send_data.lock();
    if(this->sendData.contains(data))
    {
        return;
    }else
    {
        this->sendData.append(data);
    }
    this->mutex_send_data.unlock();
}

void comThread::checkComBreak()
{
}

QString comThread::showByteArray(QByteArray array)
{
    QString showstr;

    for(int i = 0 ; i < array.length(); i++)
    {
        QString str;
        str.sprintf("%.2x ", (unsigned char)(array.at(i)));
        showstr += str;
    }

    return showstr;
}