#ifndef COMTHREAD_H
#define COMTHREAD_H

#include <QThread>
#include "comsetting.h"
#include "win_qextserialport.h"
#include <QTimer>
#include <QMutex>

class comThread : public QThread
{
    Q_OBJECT
public:
    explicit comThread(QObject *parent = 0);
    ~comThread();

    void setComSetting(comSetting *_setting);
    comSetting *getComSetting();

    bool comConnect(comSetting _setting);
    bool comConnect();
    void comDisconnect();

    bool isComConnected();

    QTimer *timeBreak;

signals:
    void receiveDataFromDevice(QByteArray data);

protected:
    void run();
private slots:
    void comReadSlot();
    void sendDataToDevice_slot(QByteArray data);
    void checkComBreak();
public slots:
    void get_timeout_value(int data);
    void timeout_timer_start();
private:
    QByteArray readBufferArray;
    Win_QextSerialPort *comPort;
    comSetting *setting;
    QString showByteArray(QByteArray array);
    QList<QByteArray>sendData;
    QMutex mutex_send_data;

};

#endif // COMTHREAD_H
