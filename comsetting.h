#ifndef COMSETTING_H
#define COMSETTING_H

#include <QObject>
#include "win_qextserialport.h"
#include <QSettings>
#include <QString>
#include <QStringList>

class comSetting : public QObject
{
    Q_OBJECT
public:
    explicit comSetting(QObject *parent = 0);
    ~comSetting();

    void copyFrom(comSetting *setting);

    void setComPort(QString _port);
    void setPortNum(int _portNum);
    void setBaud(BaudRateType _baud);
    void setParity(ParityType _parity);
    void setDataBit(DataBitsType _data_bit);
    void setStopBit(StopBitsType _stop_bit);

    QString getComPort();
    int getPortNum();
    BaudRateType getBaud();
    ParityType getParity();
    DataBitsType getDataBit();
    StopBitsType getStopBit();

//    QString getPortNameWin(int index, QString keyorvalue);
//    bool combreak();
signals:

public slots:


private:
    QString comPort;
    int portNum;
    BaudRateType baudRate;
    ParityType parity;
    DataBitsType data_bit;
    StopBitsType stop_bit;

//    HKEY hKey;
//    wchar_t keyName[256];   //键名数组
//    char    keyValue[256];  //键值数组
//    wchar_t subkey[80];
//    int indexnum;
//    DWORD keysize,type,valuesize;
};

#endif // COMSETTING_H
