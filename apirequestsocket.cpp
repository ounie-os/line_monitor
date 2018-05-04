#include "apirequestsocket.h"

#include <QDebug>
#include <QHostAddress>
#include <QDomDocument>

ApiRequestSocket::ApiRequestSocket(QTcpSocket *socket ,QObject *parent) :
    QObject(parent)
{
    this->tcpSocket = socket;
    if(this->tcpSocket == NULL)
        return;

    connect(this->tcpSocket, SIGNAL(readyRead()), this, SLOT(socketReadFromNet()));
    connect(this->tcpSocket, SIGNAL(disconnected()), this, SLOT(disconnectedSlot()));
}

ApiRequestSocket::~ApiRequestSocket()
{

}

void ApiRequestSocket::writeToNet(QString text)
{
    this->tcpSocket->write(text.toUtf8());
}

void ApiRequestSocket::socketReadFromNet()
{
    QByteArray tempArray = this->tcpSocket->readAll();

    readBufferArray.append(tempArray);

    if(readBufferArray.endsWith(0xff))
    {
        readBufferArray.chop(1);
        QString str(readBufferArray);
        QDomDocument xmlDoc;
        QString error;
        int row, colum;
        if(xmlDoc.setContent(str, false, &error, &row, &colum) == false)
        {
            qWarning() << "Xml格式错误";
            qWarning() << error << "  at" << row << " : " << colum;
        }
        else
        {
            QDomElement root = xmlDoc.documentElement();
            qDebug() << root.tagName();
            if(root.tagName() == "request")
            {
                qDebug() << root.attribute("id");

                emit this->requestDataSignal(deviceIdType::fromString(root.attribute("id")));
            }
        }

        this->readBufferArray.clear();
    }
}

void ApiRequestSocket::disconnectedSlot()
{
    emit this->disconnected();
    qDebug() << this->tcpSocket->peerAddress().toString() << " 从API服务器断开";
}
