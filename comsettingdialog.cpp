#include "comsettingdialog.h"
#include "ui_comsettingdialog.h"

#include <QMessageBox>
#include <QSettings>

comSettingDialog::comSettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::comSettingDialog)
{
    ui->setupUi(this);
    this->_setting = new comSetting();
    QString tempStr;
    QStringList comList;

    QString path="HKEY_LOCAL_MACHINE\\HARDWARE\\DEVICEMAP\\SERIALCOMM";
    QSettings *settings=new QSettings(path,QSettings::NativeFormat);
    QStringList key=settings->allKeys();
    int kk = key.size();
    for(int i = 0; i < kk; i++)
    {
        comList << getPortNameWin(i, "value");
    }


    /*
    for(int i = 1 ; i <= 256; i++)
    {
        tempStr.sprintf("COM%d", i);
        comList.append(tempStr);
    }
    */

    this->ui->comPortComboBox->addItems(comList);
    connect(this->ui->comSettingSavePushButton, SIGNAL(clicked()), this, SLOT(comSettingSavePushButtonClickedSlot()));
    this->ui->pushButton_comControl->hide();

}

comSettingDialog::~comSettingDialog()
{
    delete ui;
    delete this->_setting;
}

void comSettingDialog::setupComSetting(comSetting *setting)
{
    this->_setting->copyFrom(setting);
    //this->ui->comPortComboBox->setCurrentIndex(this->_setting->getPortNum() - 1);
    int index = this->ui->comPortComboBox->findText(this->_setting->getComPort(), Qt::MatchExactly);
    this->ui->comPortComboBox->setCurrentIndex(index);

    switch (this->_setting->getBaud()) {
    case BAUD300:
        this->ui->buadRateComboBox->setCurrentIndex(0);
        break;
    case BAUD600:
        this->ui->buadRateComboBox->setCurrentIndex(1);
        break;
    case BAUD1200:
        this->ui->buadRateComboBox->setCurrentIndex(2);
        break;
    case BAUD2400:
        this->ui->buadRateComboBox->setCurrentIndex(3);
        break;
    case BAUD4800:
        this->ui->buadRateComboBox->setCurrentIndex(4);
        break;
    case BAUD9600:
        this->ui->buadRateComboBox->setCurrentIndex(5);
        break;
    case BAUD19200:
        this->ui->buadRateComboBox->setCurrentIndex(6);
        break;
    default:
        break;
    }

    switch (this->_setting->getDataBit()) {
    case DATA_5:
        this->ui->dataBitComboBox->setCurrentIndex(0);
        break;
    case DATA_6:
        this->ui->dataBitComboBox->setCurrentIndex(1);
        break;
    case DATA_7:
        this->ui->dataBitComboBox->setCurrentIndex(2);
        break;
    case DATA_8:
        this->ui->dataBitComboBox->setCurrentIndex(3);
        break;
    default:
        break;
    }

    switch (this->_setting->getStopBit()) {
    case STOP_1:
        this->ui->stopBitComboBox->setCurrentIndex(0);
        break;
    case STOP_2:
        this->ui->stopBitComboBox->setCurrentIndex(1);
        break;
    default:
        break;
    }

    switch(this->_setting->getParity()){
    case PAR_NONE:
        this->ui->parityComboBox->setCurrentIndex(0);
        break;
    case PAR_ODD:
        this->ui->parityComboBox->setCurrentIndex(1);
        break;
    case PAR_EVEN:
        this->ui->parityComboBox->setCurrentIndex(2);
        break;
    default:
        break;
    }

}

comSetting *comSettingDialog::getComSetting()
{
    return this->_setting;
}

void comSettingDialog::comSettingSavePushButtonClickedSlot()
{

    this->_setting->setComPort(this->ui->comPortComboBox->currentText());
    this->_setting->setPortNum(this->ui->comPortComboBox->currentIndex() + 1);

    switch(this->ui->buadRateComboBox->currentIndex())
    {
        case 0:
            this->_setting->setBaud(BAUD300);
            break;
        case 1:
            this->_setting->setBaud(BAUD600);
            break;
        case 2:
            this->_setting->setBaud(BAUD1200);
            break;
        case 3:
            this->_setting->setBaud(BAUD2400);
            break;
        case 4:
            this->_setting->setBaud(BAUD4800);
            break;
        case 5:
            this->_setting->setBaud(BAUD9600);
            break;
        case 6:
            this->_setting->setBaud(BAUD19200);
            break;
        default:
            this->_setting->setBaud(BAUD9600);
            break;
    }

    switch(this->ui->dataBitComboBox->currentIndex())
    {
        case 0:
            this->_setting->setDataBit(DATA_5);
            break;
        case 1:
            this->_setting->setDataBit(DATA_6);
            break;
        case 2:
            this->_setting->setDataBit(DATA_7);
            break;
        case 3:
            this->_setting->setDataBit(DATA_8);
            break;
        default:
            this->_setting->setDataBit(DATA_8);
            break;
    }

    switch(this->ui->stopBitComboBox->currentIndex())
    {
        case 0:
            this->_setting->setStopBit(STOP_1);
            break;
        case 1:
            this->_setting->setStopBit(STOP_2);
            break;
        default:
            this->_setting->setStopBit(STOP_1);
            break;
    }

    switch(this->ui->parityComboBox->currentIndex())
    {
        case 0:
            this->_setting->setParity(PAR_NONE);
            break;
        case 1:
            this->_setting->setParity(PAR_ODD);
            break;
        case 2:
            this->_setting->setParity(PAR_EVEN);
            break;
        default:
            break;
    }


    if(QMessageBox::Yes == QMessageBox::question(this, "信息", tr("是否保存设置"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
    {
        this->accept();
    }
    else
    {
        this->reject();
    }

}

QString comSettingDialog::getPortNameWin(int index, QString keyorvalue)
{
    QString commresult="";
        QString strkey="HARDWARE\\DEVICEMAP\\SERIALCOMM";//子键路径
        int a=strkey.toWCharArray(subkey);
        subkey[a]=L'\0';
        if(RegOpenKeyEx(HKEY_LOCAL_MACHINE,subkey,0,KEY_READ|KEY_QUERY_VALUE,&hKey)!=0)
        {
            QString error="Cannot open regedit!";
        }

        QString keymessage="";//键名
        QString message="";
        QString valuemessage="";//键值
        indexnum=index;//要读取键值的索引号

        keysize=sizeof(keyName);
        valuesize=sizeof(keyValue);

        if(::RegEnumValue(hKey,indexnum,keyName,&keysize,0,&type,(BYTE*)keyValue,&valuesize)==0)
        {
            //读取键名
            for(DWORD i=0;i<keysize;i++)
            {
                message=QString::fromStdWString(keyName);
                keymessage.append(message);
            }
            //读取键值
            for(DWORD j=0;j<valuesize;j++)
            {
                if(keyValue[j]!=0x00)
                {
                    valuemessage.append(keyValue[j]);
                }
            }

            if(keyorvalue=="key")
            {
                commresult=keymessage;
            }
            if(keyorvalue=="value")
            {
                commresult=valuemessage;
            }
        }
        else
        {
            commresult="nokey";
        }
        ::RegCloseKey(hKey);//关闭注册表
        return commresult;
}

void comSettingDialog::on_pushButton_comControl_clicked()
{

}
