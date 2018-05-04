#include "comsetting.h"

comSetting::comSetting(QObject *parent) :
    QObject(parent)
{
    this->comPort = "COM1";
    this->portNum = 1;
    this->baudRate = BAUD19200;
    this->parity = PAR_NONE;
    this->data_bit = DATA_8;
    this->stop_bit = STOP_1;
}

comSetting::~comSetting()
{

}

void comSetting::copyFrom(comSetting *setting)
{
    this->comPort = setting->getComPort();
    this->portNum = setting->getPortNum();
    this->baudRate = setting->getBaud();
    this->parity = setting->getParity();
    this->stop_bit = setting->getStopBit();
    this->data_bit = setting->getDataBit();
}


void comSetting::setComPort(QString _port)
{
    this->comPort = _port;
}

void comSetting::setPortNum(int _portNum)
{
    this->portNum = _portNum;
}

void comSetting::setBaud(BaudRateType _baud)
{
    this->baudRate = _baud;
}

void comSetting::setParity(ParityType _parity)
{
    this->parity = _parity;
}

void comSetting::setDataBit(DataBitsType _data_bit)
{
    this->data_bit = _data_bit;
}

void comSetting::setStopBit(StopBitsType _stop_bit)
{
    this->stop_bit = _stop_bit;
}

QString comSetting::getComPort()
{
    return this->comPort;
}

int comSetting::getPortNum()
{
    return this->portNum;
}

BaudRateType comSetting::getBaud()
{
    return this->baudRate;
}

ParityType comSetting::getParity()
{
    return this->parity;
}

DataBitsType comSetting::getDataBit()
{
    return this->data_bit;
}

StopBitsType comSetting::getStopBit()
{
    return this->stop_bit;
}

//QString comSetting::getPortNameWin(int index, QString keyorvalue)
//{
//    QString commresult="";
//    QString strkey="HARDWARE\\DEVICEMAP\\SERIALCOMM";//子键路径
//    int a=strkey.toWCharArray(subkey);
//    subkey[a]=L'\0';
//    if(RegOpenKeyEx(HKEY_LOCAL_MACHINE,subkey,0,KEY_READ|KEY_QUERY_VALUE,&hKey)!=0)
//    {
//        QString error="Cannot open regedit!";
//    }

//    QString keymessage="";//键名
//    QString message="";
//    QString valuemessage="";//键值
//    indexnum=index;//要读取键值的索引号

//    keysize=sizeof(keyName);
//    valuesize=sizeof(keyValue);

//    if(::RegEnumValue(hKey,indexnum,keyName,&keysize,0,&type,(BYTE*)keyValue,&valuesize)==0)
//    {
//        //读取键名
//        for(DWORD i=0;i<keysize;i++)
//        {
//            message=QString::fromStdWString(keyName);
//            keymessage.append(message);
//        }
//        //读取键值
//        for(DWORD j=0;j<valuesize;j++)
//        {
//            if(keyValue[j]!=0x00)
//            {
//                valuemessage.append(keyValue[j]);
//            }
//        }

//        if(keyorvalue=="key")
//        {
//            commresult=keymessage;
//        }
//        if(keyorvalue=="value")
//        {
//            commresult=valuemessage;
//        }
//    }
//    else
//    {
//        commresult="nokey";
//    }
//    ::RegCloseKey(hKey);//关闭注册表
//    return commresult;
//}

//bool comSetting::combreak()
//{
//    QStringList comList;

//    QString path="HKEY_LOCAL_MACHINE\\HARDWARE\\DEVICEMAP\\SERIALCOMM";
//    QSettings *settings=new QSettings(path,QSettings::NativeFormat);
//    QStringList key=settings->allKeys();
//    int kk = key.size();
//    for(int i = 0; i < kk; i++)
//    {
//        comList << getPortNameWin(i, "value");
//    }
//    return comList.contains(this->comPort);
//}
