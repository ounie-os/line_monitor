#include "cabledatawidget.h"
#include "ui_cabledatawidget.h"
#include "myhelper.h"
#include <QTableWidgetItem>
extern uint32_t CNT_COM;
/*!
 * \brief CableDataWidget::CableDataWidget
 * \param parent
 * 作者：刘峰
 * 日期：2017-08-17
 * 未完成部分：
 * 1.报警阀值设置、读取
 * 2.ct设置、读取(刷新程序后在校正)
 * 3.报警显示
 */
/*!
 * \brief CableDataWidget::CableDataWidget
 * \param parent
 * 作者：刘峰
 * 日期：2017-08-18
 * 未完成部分：
 * 读取采样数，报警值、CT变比跟新最新程序在校正
 * 显示曲线图
 * 保存数据到数据库
 * 向远端转发数据
 */
CableDataWidget::CableDataWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CableDataWidget)
{
    ui->setupUi(this);
    cableDataWidget_init();
    save_rt_data_row_count = 0;
    save_alarm_data_row_count = 0;
}
/*!
 * \brief CableDataWidget::~CableDataWidget
 */
CableDataWidget::~CableDataWidget()
{
    delete ui;
    delete this->autoGetDataTimer;
    delete this->autoGetAlarmDataTimer;
    delete this->autoGetStatisticTimer;
    delete this->sendDataTimer;
    delete this->sendDataToClient;
    for(int i=0;i<this->ui->tableWidget->columnCount();i++)
    {
        for(int j=0;j<this->ui->tableWidget->rowCount();j++)
        {
            delete this->ui->tableWidget->item(j,i);
        }
    }
    this->export_execel->deleteLater();
}
/*!
 * \brief CableDataWidget::cableDataWidget_init
 * 设备对应的界面初始化
 */
void CableDataWidget::cableDataWidget_init()
{
    list_display_Alarm_data.clear();
    list_display_rt_data.clear();
    //===============初始化设备保定状态=================
    this->sendData.clear();
    this->tcpClientID               = 0;
    this->clientIP                  = "";
    blindFlag                       = flag_undefined;   //<未绑定
    this->autogetDataFlag           = false;
    this->autogetStatisticFlag      = false;
    this->setDataFlag               = false;
    this->autogetAlarmDataFlag      = false;

    this->list_SendRtData.clear();
    this->list_SendSetData.clear();
    this->list_SendStatisticData.clear();

    //===============自动获取数据定时器=================
    this->autoGetDataTimer          = new QTimer;
    this->autoGetDataTimer->setInterval(3000);

    this->autoGetAlarmDataTimer     = new QTimer;
    this->autoGetAlarmDataTimer->setInterval(10000);

    this->autoGetStatisticTimer     = new QTimer;
    this->autoGetStatisticTimer->setInterval(60000);
//    this->autoGetStatisticTimer->setInterval(3000);
    this->sendDataTimer             = new QTimer;
    this->sendDataTimer->start(1);

    this->sendDataToClient          = new QTimer;
    this->sendDataToClient->setInterval(250);
//    this->sendDataToClient->start();
    connect(this->sendDataToClient,SIGNAL(timeout()),
            this,SLOT(sendDataToClient_slot()));
    connect(this->autoGetDataTimer,SIGNAL(timeout()),
            this,SLOT(autoGetData_slot()));
    connect(this->autoGetStatisticTimer,SIGNAL(timeout()),
            this,SLOT(autoGetStatistic_slot()));
    connect(this->sendDataTimer,SIGNAL(timeout()),
            this,SLOT(sendData_slot()));
    connect(this->autoGetAlarmDataTimer,SIGNAL(timeout()),
            this,SLOT(autoGetAlarmData_slot()));

    connect(this->autoGetDataTimer,SIGNAL(timeout()),
            this,SLOT(save_auto_get_Rt_data()));
    connect(this->autoGetAlarmDataTimer,SIGNAL(timeout()),
            this,SLOT(save_auto_get_Alarm_data()));

    this->export_execel = new Export_Execel();
    QThread * thread_export = new QThread();
    connect(export_execel,SIGNAL(destroyed(QObject*)),thread_export,SLOT(quit()));
    connect(thread_export,SIGNAL(finished()),thread_export,SLOT(deleteLater()));
//    connect(this,SIGNAL(signal_export_execel(int,QString,QStringList)),
//            export_execel,SLOT(export_data(int,QString,QStringList)));
    export_execel->moveToThread(thread_export);
    thread_export->start();
    //===============平均数据趋势图====================
    QList<QColor> colorList;
    colorList.append(Qt::darkBlue);
    colorList.append(Qt::darkRed);
    colorList.append(Qt::darkGreen);
    colorList.append(Qt::darkYellow);
    this->ui->tab_mainCable->initCurves(1, QStringList() << tr("MainCable AVG"), colorList);
    this->ui->tab_groundCable->initCurves(4, QStringList() << tr("GroundCable A AVG") <<
                                                     tr("GroundCable B AVG") << tr("GroundCable C AVG")
                                                     << tr("GroundCable N AVG"), colorList);
    //===============初始化数据显示表==================
    clear_rt_data();
    clear_alarm_data();
//    this->ui->phaseMainControlbitsCheckBox->setEnabled(false);
//    this->ui->phaseAControlbitsCheckBox->setEnabled(false);
//    this->ui->phaseBControlbitsCheckBox->setEnabled(false);
//    this->ui->phaseCControlbitsCheckBox->setEnabled(false);
//    this->ui->phaseNControlbitsCheckBox->setEnabled(false);
//    this->ui->channelControlReadPushButton->setEnabled(false);
//    this->ui->channelControlSetPushButton->setEnabled(false);
    this->ui->phaseMainControlbitsCheckBox->hide();
    this->ui->phaseAControlbitsCheckBox->hide();;
    this->ui->phaseBControlbitsCheckBox->hide();;
    this->ui->phaseCControlbitsCheckBox->hide();;
    this->ui->phaseNControlbitsCheckBox->hide();;
    this->ui->channelControlReadPushButton->hide();;
    this->ui->channelControlSetPushButton->hide();;

}
/*!
 * \brief CableDataWidget::cableThreshold_init
 * 报警值和CT变比初始化
 * 默认电流报警值100A
 * 默认温度报警值70℃
 * 默认CT变比100：1
 */
void CableDataWidget::cableThreshold_init()
{
    //===============报警值===========================
    QSettings *settingFile = new QSettings("./threshold.ini", QSettings::IniFormat, 0);
    settingFile->beginGroup(this->deviceID.getDeviceId().toString()+"_Threshold");
    if(settingFile->contains(tr("phase_Main_cable_eleCur_ThresholdValue")))
    {
        this->phase_Main_cable_eleCur_ThresholdValue = settingFile->value("phase_Main_cable_eleCur_ThresholdValue").toFloat();
    }else
    {
        this->phase_Main_cable_eleCur_ThresholdValue = 50;
        settingFile->setValue("phase_Main_cable_eleCur_ThresholdValue",50);
    }
    if(settingFile->contains(tr("phase_A_cable_eleCur_ThresholdValue")))
    {
        this->phase_A_cable_eleCur_ThresholdValue = settingFile->value("phase_A_cable_eleCur_ThresholdValue").toFloat();
    }else
    {
        this->phase_A_cable_eleCur_ThresholdValue = 50;
        settingFile->setValue("phase_A_cable_eleCur_ThresholdValue",50);
    }
    if(settingFile->contains(tr("phase_B_cable_eleCur_ThresholdValue")))
    {
        this->phase_B_cable_eleCur_ThresholdValue = settingFile->value("phase_B_cable_eleCur_ThresholdValue").toFloat();
    }else
    {
        this->phase_B_cable_eleCur_ThresholdValue = 50;
        settingFile->setValue("phase_B_cable_eleCur_ThresholdValue",50);
    }
    if(settingFile->contains(tr("phase_C_cable_eleCur_ThresholdValue")))
    {
        this->phase_C_cable_eleCur_ThresholdValue = settingFile->value("phase_C_cable_eleCur_ThresholdValue").toFloat();
    }else
    {
        this->phase_C_cable_eleCur_ThresholdValue = 50;
        settingFile->setValue("phase_C_cable_eleCur_ThresholdValue",50);
    }
    if(settingFile->contains(tr("phase_N_cable_eleCur_ThresholdValue")))
    {
        this->phase_N_cable_eleCur_ThresholdValue = settingFile->value("phase_N_cable_eleCur_ThresholdValue").toFloat();
    }else
    {
        this->phase_N_cable_eleCur_ThresholdValue = 50;
        settingFile->setValue("phase_N_cable_eleCur_ThresholdValue",50);
    }
    if(settingFile->contains(tr("main_Threshold")))
    {
        this->phase_A_cable_temp_ThresholdValue = settingFile->value("phase_A_cable_temp_ThresholdValue").toFloat();
    }else
    {
        this->phase_A_cable_temp_ThresholdValue = 50;
        settingFile->setValue("phase_A_cable_temp_ThresholdValue",50);
    }
    if(settingFile->contains(tr("phase_B_cable_temp_ThresholdValue")))
    {
        this->phase_B_cable_temp_ThresholdValue = settingFile->value("phase_B_cable_temp_ThresholdValue").toFloat();
    }else
    {
        this->phase_B_cable_temp_ThresholdValue = 50;
        settingFile->setValue("phase_B_cable_temp_ThresholdValue",50);
    }
    if(settingFile->contains(tr("phase_C_cable_temp_ThresholdValue")))
    {
        this->phase_C_cable_temp_ThresholdValue = settingFile->value("phase_C_cable_temp_ThresholdValue").toFloat();
    }else
    {
        this->phase_C_cable_temp_ThresholdValue = 50;
        settingFile->setValue("phase_C_cable_temp_ThresholdValue",50);
    }
    if(settingFile->contains(tr("phase_N_cable_temp_ThresholdValue")))
    {
        this->phase_N_cable_temp_ThresholdValue = settingFile->value("phase_N_cable_temp_ThresholdValue").toFloat();
    }else
    {
        this->phase_N_cable_temp_ThresholdValue = 50;
        settingFile->setValue("phase_N_cable_temp_ThresholdValue",50);
    }
    settingFile->endGroup();
    delete settingFile;
}
/*!
 * \brief CableDataWidget::setDeviceID
 * \param ID
 * 设置绑定设备ID
 */
void CableDataWidget::setDeviceID(CableMonitorDevice ID)
{
    this->deviceID = ID;
    cableThreshold_init();
}
/*!
 * \brief CableDataWidget::getDeviceID
 * \return
 * 获取绑定设备ID
 */
CableMonitorDevice CableDataWidget::getDeviceID()
{
    return this->deviceID;
}
/*!
 * \brief CableDataWidget::setTcpClientID
 * \param ID
 * 设置网络客户端端口号
 */
void CableDataWidget::setTcpClientID(int ID)
{
    this->tcpClientID = ID;
}
/*!
 * \brief CableDataWidget::getTcpClientID
 * \return
 * 获取网络客户端端口号
 */
int CableDataWidget::getTcpClientID()
{
    return this->tcpClientID;
}
/*!
 * \brief CableDataWidget::setLabelID
 * 显示设备ID，设备名称
 */
void CableDataWidget::setLabelID()
{
    this->ui->label_deviceID->setText(this->deviceID.getDeviceId().toString());
    this->ui->label_deviceName->setText(this->deviceID.getDeviceName());
}
/*!
 * \brief CableDataWidget::getBlindFlag
 * \return
 * 获取绑定状态（485通信，网络通信）
 */
FlagType CableDataWidget::getBlindFlag()
{
    return this->blindFlag;
}
/*!
 * \brief CableDataWidget::setBlindFlag
 * \param flag
 * 设置绑定状态
 */
void CableDataWidget::setBlindFlag(FlagType flag)
{
    this->blindFlag = flag;
}
/*!
 * \brief CableDataWidget::setClientIP
 * \param IP
 * 显示客户端IP地址
 */
void CableDataWidget::setClientIP(QString IP)
{
    this->clientIP = IP;
    this->ui->label_IP->setText(IP);
}
/*!
 * \brief CableDataWidget::getClientIP
 * \return
 * 获取客户端IP地址
 */
QString CableDataWidget::getClientIP()
{
    return this->clientIP;
}
/*!
 * \brief CableDataWidget::receiveDataFromDevice
 * \param data
 * 接受设备数据
 */
#if 0
void CableDataWidget::receiveDataFromDevice(QByteArray data)
{
    if(data.mid(5,12) == this->deviceID.getDeviceId().toByteArray())
    {
//        if(this->blindFlag == flag_undefined)
//        {
//            this->setBlindFlag(flag_485);
//        }
        ushort crc16 = 0;
        uchar  len   = (uchar)data.at(3);
        uchar  msgType = (uchar)data.at(4);
        if(data.length() >= 4)
        {
            if((0x5A == data.at(0))&&(0xA5 == (uchar)data.at(1))&&(0xAA == (uchar)data.at(6+len)))
            {
                uchar *dataTmp = (uchar *)data.data();
                deviceIdType deviceId;
                QList<electricCableMetaData> datalist;
                QDateTime rtcDateTime;
                uint8_t sampleSec,  statisticCycle,  statisticCount;
                uint8_t thresholdtype;
                float thresholdvalue;
                uint8_t cttype;
                float ctValue;
                bool okflag;
                enum configType configtype;
                crc16 = ((uchar)data.at(4+len)<<8)|((uchar)data.at(5+len));
                if(crc16 == myHelper::crc16(&dataTmp[4],len))
                {
//                    qDebug() <<"crc16 成功";
                    switch (msgType)
                    {
                    case rcvDataMessage:
                    case rcvAlarmMessage:
                        datalist = comProtocol::analysisDataMessage(&dataTmp[4], len, &deviceId);
                        for(int i = 0; i < datalist.length(); i++)
                        {
                            upData_UI(datalist.value(i));
                            emit DBsave(this->deviceID,datalist.value(i));
//                            emit sendDataToServer(this->deviceID.getDeviceId(),datalist.value(i));
//                            emit sendDataToXml(this->deviceID.getDeviceId(),datalist.value(i));
                        }
                        break;
                    case rcvConfigWriteMessage:
                    case rcvConfigReadMessage:
                        qDebug() << "接收到参数配置报文";
                        configtype = comProtocol::analysisConfigMessage(&dataTmp[4], len, &deviceId);
                        switch (configtype) {
                        case RtcTime_Set:
                            rtcDateTime = comProtocol::getRtcFromMessage(&dataTmp[4], len, &okflag);
                            this->ui->rtcReadDateTimeEdit->setDateTime(rtcDateTime);
                            qDebug() << "配置实时时钟：" <<  rtcDateTime.toString("yyyy-MM-dd hh:mm:ss");
                            //emit this->rtcReadFromDeviceSignal(deviceId, rtcDateTime);
                            break;
                        case StatisticArgument:
                            if(comProtocol::getStatisticArguemnt(&dataTmp[4], len, &sampleSec, &statisticCycle, &statisticCount))
                            {
                                this->ui->sampleSecSpinBox->setValue(sampleSec);
                                this->ui->statisticCycleSpinBox->setValue(statisticCycle);
                                this->ui->statisticCountSpinBox->setValue(statisticCount);
                                QString tempstr;
                                tempstr.sprintf("电流采样时间：%d秒 统计周期：%d分钟 统计个数：%d个 ", sampleSec, statisticCycle, statisticCount);
                                qDebug() << "配置统计参数：" << tempstr;
                                change_para("samp_time_cur",QString::number(sampleSec));
                                change_para("statistics_cycle_cur",QString::number(statisticCycle));
                                change_para("statistics_number_cur",QString::number(statisticCount));
                               // emit this->statisticArgumentReadFromDeviceSignal(deviceId, sampleSec, statisticCycle, statisticCount);
                            }
                            break;
                        case TemperatureMeasureCycle:
                            if(comProtocol::getStatisticArguemnt(&dataTmp[4], len, &sampleSec, &statisticCycle, &statisticCount))
                            {
                                this->ui->SpinBox_Temp_SampleSec->setValue(sampleSec);
                                this->ui->SpinBox_Temp_StatisticCycle->setValue(statisticCycle);
                                this->ui->SpinBox_Temp_StatisticCount->setValue(statisticCount);
                                QString tempstr;
                                tempstr.sprintf("温度 采样时间：%d秒 统计周期：%d分钟 统计个数：%d个 ", sampleSec, statisticCycle, statisticCount);
                                qDebug() << "配置统计参数：" << tempstr;
                                change_para("samp_time_temp",QString::number(sampleSec));
                                change_para("statistics_cycle_temp",QString::number(statisticCycle));
                                change_para("statistics_number_temp",QString::number(statisticCount));
                               // emit this->statisticArgumentReadFromDeviceSignal(deviceId, sampleSec, statisticCycle, statisticCount);
                            }
                            break;
                        case MainCable_Alarm_Threhold:
                        case GroundCablePhaseA_Alarm_Threhold:
                        case GroundCablePhaseB_Alarm_Threhold:
                        case GroundCablePhaseC_Alarm_Threhold:
                        case GroundCablePhaseN_Alarm_Threhold:
                            if(comProtocol::getThresholdValue(&dataTmp[4], len, &thresholdtype, &thresholdvalue))
                            {
                                this->ui->thresholdValueDoubleSpinBox->setValue(thresholdvalue/1000);
                                QString str = "";
                                switch (thresholdtype) {
                                case MainCable_Alarm_Threhold:
                                    this->phase_Main_cable_eleCur_ThresholdValue = thresholdvalue/1000;
                                    str = "主缆：";
                                    change_para("phase_Main_cable_eleCur_ThresholdValue",QString::number(this->phase_Main_cable_eleCur_ThresholdValue));
                                    break;
                                case GroundCablePhaseA_Alarm_Threhold:
                                    this->phase_A_cable_eleCur_ThresholdValue = thresholdvalue/1000;
                                    change_para("phase_A_cable_eleCur_ThresholdValue",QString::number(this->phase_A_cable_eleCur_ThresholdValue));
                                    str = "A相：";
                                    break;
                                case GroundCablePhaseB_Alarm_Threhold:
                                    this->phase_B_cable_eleCur_ThresholdValue = thresholdvalue/1000;
                                    change_para("phase_B_cable_eleCur_ThresholdValue",QString::number(this->phase_B_cable_eleCur_ThresholdValue));
                                    str = "B相：";
                                    break;
                                case GroundCablePhaseC_Alarm_Threhold:
                                    this->phase_C_cable_eleCur_ThresholdValue = thresholdvalue/1000;
                                    change_para("phase_C_cable_eleCur_ThresholdValue",QString::number(this->phase_C_cable_eleCur_ThresholdValue));
                                    str = "C相：";
                                    break;
                                case GroundCablePhaseN_Alarm_Threhold:
                                    this->phase_N_cable_eleCur_ThresholdValue = thresholdvalue/1000;
                                    change_para("phase_N_cable_eleCur_ThresholdValue",QString::number(this->phase_N_cable_eleCur_ThresholdValue));
                                    str = "N相：";
                                    break;
                                default:
                                    break;
                                }
                                qDebug() << "电流阀值：" << str << thresholdvalue/1000<<"A";
                                //emit this->thresholdValueReadFromDeviceSignal(deviceId, thresholdtype, thresholdvalue);
                            }
                            break;
                        case GroundCablePhaseATemperature_Alarm_Threshold:
                        case GroundCablePhaseBTemperature_Alarm_Threshold:
                        case GroundCablePhaseCTemperature_Alarm_Threshold:
                        case GroundCablePhaseNTemperature_Alarm_Threshold:
                            if(comProtocol::getThresholdValue(&dataTmp[4], len, &thresholdtype, &thresholdvalue))
                            {
                                this->ui->doubleSpinBox_Temp_Threshold->setValue(thresholdvalue/100);
                                QString str = "";
                                switch (thresholdtype) {
                                case GroundCablePhaseATemperature_Alarm_Threshold:
                                    this->phase_A_cable_temp_ThresholdValue = thresholdvalue/100;
                                    str = "A相：";
                                    change_para("phase_A_cable_temp_ThresholdValue",QString::number(this->phase_A_cable_temp_ThresholdValue));
                                    break;
                                case GroundCablePhaseBTemperature_Alarm_Threshold:
                                    this->phase_B_cable_temp_ThresholdValue = thresholdvalue/100;
                                    str = "B相：";
                                    change_para("phase_B_cable_temp_ThresholdValue",QString::number(this->phase_B_cable_temp_ThresholdValue));
                                    break;
                                case GroundCablePhaseCTemperature_Alarm_Threshold:
                                    this->phase_C_cable_temp_ThresholdValue = thresholdvalue/100;
                                    str = "C相：";
                                    change_para("phase_C_cable_temp_ThresholdValue",QString::number(this->phase_C_cable_temp_ThresholdValue));
                                    break;
                                case GroundCablePhaseNTemperature_Alarm_Threshold:
                                    this->phase_N_cable_temp_ThresholdValue = thresholdvalue/100;
                                    str = "N相：";
                                    change_para("phase_N_cable_temp_ThresholdValue",QString::number(this->phase_N_cable_temp_ThresholdValue));
                                    break;
                                default:
                                    break;
                                }
                                qDebug() << "温度阀值：" << str << thresholdvalue/100<<"℃";
                                //emit this->thresholdValueReadFromDeviceSignal(deviceId, thresholdtype, thresholdvalue);
                            }
                            break;
                        case MainCableCtValue_Set:
                        case GroundCablePhaseACtValue_Set:
                        case GroundCablePhaseBCtValue_Set:
                        case GroundCablePhaseCCtValue_Set:
                        case GroundCablePhaseNCtValue_Set:
                            if(comProtocol::getCtValue(&dataTmp[4], len,&cttype, &ctValue))
                            {
                                switch (cttype) {
                                case 0x0A:
                                    this->ui->ctValueDoubleSpinBox->setValue(ctValue);
//                                    this->phase_Main_cable_eleCur_CT = ctValue;
                                    change_para("phase_Main_ratio",QString::number(ctValue));
                                    break;
                                case 0x0B:
                                    this->ui->ctValueDoubleSpinBox->setValue(ctValue);
//                                    this->phase_A_cable_eleCur_CT = ctValue;
                                    change_para("phase_A_ratio",QString::number(ctValue));
                                    break;
                                case 0x0C:
                                    this->ui->ctValueDoubleSpinBox->setValue(ctValue);
//                                    this->phase_B_cable_eleCur_CT = ctValue;
                                    change_para("phase_B_ratio",QString::number(ctValue));
                                    break;
                                case 0x0D:
                                    this->ui->ctValueDoubleSpinBox->setValue(ctValue);
//                                    this->phase_C_cable_eleCur_CT = ctValue;
                                    change_para("phase_C_ratio",QString::number(ctValue));
                                    break;
                                case 0x0E:
                                    this->ui->ctValueDoubleSpinBox->setValue(ctValue);
//                                  this->phase_N_cable_eleCur_CT = ctValue;
                                    change_para("phase_N_ratio",QString::number(ctValue));
                                    break;
                                default:
                                    break;
                                }

                                this->ui->ctValueDoubleSpinBox->setValue(ctValue);
                                QString str = "";
                                switch (cttype) {
                                case MainCableCtValue_Set:
                                    str = "主缆：";
                                    break;
                                case GroundCablePhaseACtValue_Set:
                                    str = "A相：";
                                    break;
                                case GroundCablePhaseBCtValue_Set:
                                    str = "B相：";
                                    break;
                                case GroundCablePhaseCCtValue_Set:
                                    str = "C相：";
                                    break;
                                case GroundCablePhaseNCtValue_Set:
                                    str = "N相：";
                                    break;
                                default:
                                    break;
                                }
                                qDebug() << "配置CT变比：" << str << ctValue;
                                //emit this->ctValueReadFromDeviceSignal(deviceId, cttype, ctValue);
                            }
                            break;
                        case GroundCablePhaseAVibrationCount_Alarm_Threshold:
                        case GroundCablePhaseBVibrationCount_Alarm_Threshold:
                        case GroundCablePhaseCVibrationCount_Alarm_Threshold:
                        case GroundCablePhaseNVibrationCount_Alarm_Threshold:
                            if(comProtocol::getThresholdValue(&dataTmp[4], len, &thresholdtype, &thresholdvalue))
                            {
                                this->ui->doubleSpinBox_Vibrate_Threshold->setValue(thresholdvalue);
                                QString str = "";
                                switch (thresholdtype) {
                                case GroundCablePhaseAVibrationCount_Alarm_Threshold:
//                                    this->phase_A_cable_temp_ThresholdValue = thresholdvalue;
                                    str = "A相：";
                                    change_para("phase_A_vibrate_threshold_value",QString::number(thresholdvalue));
                                    break;
                                case GroundCablePhaseBVibrationCount_Alarm_Threshold:
//                                    this->phase_B_cable_temp_ThresholdValue = thresholdvalue;
                                    str = "B相：";
                                    change_para("phase_B_vibrate_threshold_value",QString::number(thresholdvalue));
                                    break;
                                case GroundCablePhaseCVibrationCount_Alarm_Threshold:
//                                    this->phase_C_cable_temp_ThresholdValue = thresholdvalue;
                                    str = "C相：";
                                    change_para("phase_C_vibrate_threshold_value",QString::number(thresholdvalue));
                                    break;
                                case GroundCablePhaseNVibrationCount_Alarm_Threshold:
//                                    this->phase_N_cable_temp_ThresholdValue = thresholdvalue;
                                    str = "N相：";
                                    change_para("phase_N_vibrate_threshold_value",QString::number(thresholdvalue));
                                    break;
                                default:
                                    break;
                                }
                                qDebug() << "振动阀值：" << str << thresholdvalue;
                                //emit this->thresholdValueReadFromDeviceSignal(deviceId, thresholdtype, thresholdvalue);
                            }
                            break;
                        case VibrationStatisticalCycle:
                            if(comProtocol::getVibrateStatisticValue(&dataTmp[4],len,&thresholdvalue))
                            {
                                this->ui->spinBox_VibrateStatisticTime->setValue(thresholdvalue);
                                qDebug() << "振动统计时间："<< thresholdvalue<<"秒";
                                change_para("vibrate_statistics_time",QString::number(thresholdvalue));
                                //emit this->thresholdValueReadFromDeviceSignal(deviceId, thresholdtype, thresholdvalue);
                            }
                            break;
                        case SetChangeRateStatistical:
                            if(comProtocol::getVibrateStatisticValue(&dataTmp[4],len,&thresholdvalue))
                            {
                                this->ui->spinBox_CurChangerateCycle->setValue(thresholdvalue);
                                qDebug() << "电流变化检测周期："<< thresholdvalue<<"分钟";
                                change_para("cur_change_cycle",QString::number(thresholdvalue));
                                //emit this->thresholdValueReadFromDeviceSignal(deviceId, thresholdtype, thresholdvalue);
                            }
                            break;
                        case ChangeRateStatisticalCycle:
                            if(comProtocol::getVibrateStatisticValue(&dataTmp[4],len,&thresholdvalue))
                            {
                                this->ui->label_CurChangerateWindowSize->setText(QString::number(thresholdvalue));
                                qDebug() << "电流变化率检测窗体大小："<< thresholdvalue;
                                //emit this->thresholdValueReadFromDeviceSignal(deviceId, thresholdtype, thresholdvalue);
                            }
                            break;
                        case GroundCablePhaseAChangeRate_Alarm_Threshold:
                        case GroundCablePhaseBChangeRate_Alarm_Threshold:
                        case GroundCablePhaseCChangeRate_Alarm_Threshold:
                        case GroundCablePhaseNChangeRate_Alarm_Threshold:
                            if(comProtocol::getThresholdValue(&dataTmp[4], len, &thresholdtype, &thresholdvalue))
                            {
                                this->ui->doubleSpinBox_CurChangeRate_Threshold->setValue(thresholdvalue);
                                QString str = "";
                                switch (thresholdtype) {
                                case GroundCablePhaseAChangeRate_Alarm_Threshold:
//                                    this->phase_A_cable_temp_ThresholdValue = thresholdvalue;
                                    str = "A相：";
                                    change_para("phase_A_cur_change_rate_threshold_value",QString::number(thresholdvalue));
                                    break;
                                case GroundCablePhaseBChangeRate_Alarm_Threshold:
//                                    this->phase_B_cable_temp_ThresholdValue = thresholdvalue;
                                    str = "B相：";
                                    change_para("phase_B_cur_change_rate_threshold_value",QString::number(thresholdvalue));
                                    break;
                                case GroundCablePhaseCChangeRate_Alarm_Threshold:
//                                    this->phase_C_cable_temp_ThresholdValue = thresholdvalue;
                                    str = "C相：";
                                    change_para("phase_C_cur_change_rate_threshold_value",QString::number(thresholdvalue));
                                    break;
                                case GroundCablePhaseNChangeRate_Alarm_Threshold:
//                                    this->phase_N_cable_temp_ThresholdValue = thresholdvalue;
                                    str = "N相：";
                                    change_para("phase_N_cur_change_rate_threshold_value",QString::number(thresholdvalue));
                                    break;
                                default:
                                    break;
                                }
                                qDebug() << "电流变化率阀值：" << str << thresholdvalue;
                                //emit this->thresholdValueReadFromDeviceSignal(deviceId, thresholdtype, thresholdvalue);
                            }
                            break;
                        case CurrentChannelControl:
                            if(comProtocol::getThresholdValue(&dataTmp[4], len, &thresholdtype, &thresholdvalue))
                            {
                                uint32_t var = thresholdvalue;
                                qDebug()<<"电流通道使能"<<QString::number(var,16);
                                if(var & 0x01)
                                {
                                    this->ui->phaseMainControlbitsCheckBox->setChecked(true);
                                }else
                                {
                                    this->ui->phaseMainControlbitsCheckBox->setChecked(false);
                                }
                                if(var & 0x02)
                                {
                                    this->ui->phaseAControlbitsCheckBox->setChecked(true);
                                }else
                                {
                                    this->ui->phaseAControlbitsCheckBox->setChecked(false);
                                }
                                if(var & 0x04)
                                {
                                    this->ui->phaseBControlbitsCheckBox->setChecked(true);
                                }else
                                {
                                    this->ui->phaseBControlbitsCheckBox->setChecked(false);
                                }
                                if(var & 0x08)
                                {
                                    this->ui->phaseCControlbitsCheckBox->setChecked(true);
                                }else
                                {
                                    this->ui->phaseCControlbitsCheckBox->setChecked(false);
                                }
                                if(var & 0x10)
                                {
                                    this->ui->phaseNControlbitsCheckBox->setChecked(true);
                                }else
                                {
                                    this->ui->phaseNControlbitsCheckBox->setChecked(false);
                                }
                            }
                            break;
                        case TemperatureChannelControl:
                            if(comProtocol::getThresholdValue(&dataTmp[4], len, &thresholdtype, &thresholdvalue))
                            {
                                uint32_t var = thresholdvalue;
                                qDebug()<<"温度通道使能"<<QString::number(var,16);
                                this->ui->phaseMainControlbitsCheckBox->setChecked(false);
                                if(var & 0x01)
                                {
                                    this->ui->phaseAControlbitsCheckBox->setChecked(true);
                                }else
                                {
                                    this->ui->phaseAControlbitsCheckBox->setChecked(false);
                                }
                                if(var & 0x02)
                                {
                                    this->ui->phaseBControlbitsCheckBox->setChecked(true);
                                }else
                                {
                                    this->ui->phaseBControlbitsCheckBox->setChecked(false);
                                }
                                if(var & 0x04)
                                {
                                    this->ui->phaseCControlbitsCheckBox->setChecked(true);
                                }else
                                {
                                    this->ui->phaseCControlbitsCheckBox->setChecked(false);
                                }
                                if(var & 0x08)
                                {
                                    this->ui->phaseNControlbitsCheckBox->setChecked(true);
                                }else
                                {
                                    this->ui->phaseNControlbitsCheckBox->setChecked(false);
                                }
                            }
                            break;
                        case VibrationChannelControl:
                            if(comProtocol::getThresholdValue(&dataTmp[4], len, &thresholdtype, &thresholdvalue))
                            {
                                uint32_t var = thresholdvalue;
                                qDebug()<<"振动通道使能"<<QString::number(var,16);
                                this->ui->phaseMainControlbitsCheckBox->setChecked(false);
                                if(var & 0x01)
                                {
                                    this->ui->phaseAControlbitsCheckBox->setChecked(true);
                                }else
                                {
                                    this->ui->phaseAControlbitsCheckBox->setChecked(false);
                                }
                                if(var & 0x02)
                                {
                                    this->ui->phaseBControlbitsCheckBox->setChecked(true);
                                }else
                                {
                                    this->ui->phaseBControlbitsCheckBox->setChecked(false);
                                }
                                if(var & 0x04)
                                {
                                    this->ui->phaseCControlbitsCheckBox->setChecked(true);
                                }else
                                {
                                    this->ui->phaseCControlbitsCheckBox->setChecked(false);
                                }
                                if(var & 0x08)
                                {
                                    this->ui->phaseNControlbitsCheckBox->setChecked(true);
                                }else
                                {
                                    this->ui->phaseNControlbitsCheckBox->setChecked(false);
                                }
                            }
                            break;
                        default:
                            break;
                        }
                        break;
                    case rcvHeartBeatMessage:
                        break;
                    default:
                        break;
                    }
                }
            }else
            {
                qDebug() <<"数据帧格式错误";
            }
        }

    }
    //接受到的数据需要匹配地址
}
#endif /* 0 */

#define FRAME_HEAD_OFFSET (0) // 帧头
#define FRAME_OPTIME_OFFSET (25) // 运行时间
#define FRAME_UPSVOL_OFFSET (29) // UPS电压
#define FRAME_ENVTEMP_OFFSET (31) // 环境温度
#define FRAME_GROUND_CURRENT_A_OFFSET (33) // A相接地电流
#define FRAME_GROUND_CURRENT_B_OFFSET (37) // B相接地电流
#define FRAME_GROUND_CURRENT_C_OFFSET (41) // C相接地电流
#define FRAME_CONNECTOR_TEMP_A_OFFSET (61) // A相接头温度
#define FRAME_CONNECTOR_TEMP_B_OFFSET (71) // B相接头温度
#define FRAME_CONNECTOR_TEMP_C_OFFSET (81) // C相接头温度
#define FRAME_A_X_AXIS_OFFSET (55) // A轴X姿态数据
#define FRAME_A_Y_AXIS_OFFSET (57) // A轴Y姿态数据
#define FRAME_A_Z_AXIS_OFFSET (59) // A轴Z姿态数据
#define FRAME_B_X_AXIS_OFFSET (65) // B轴X姿态数据
#define FRAME_B_Y_AXIS_OFFSET (67) // B轴Y姿态数据
#define FRAME_B_Z_AXIS_OFFSET (69) // B轴Z姿态数据
#define FRAME_C_X_AXIS_OFFSET (75) // C轴X姿态数据
#define FRAME_C_Y_AXIS_OFFSET (77) // C轴Y姿态数据
#define FRAME_C_Z_AXIS_OFFSET (79) // C轴Z姿态数据

void CableDataWidget::receiveDataFromDevice(QByteArray data)
{
    if(data.mid(20,4) == this->deviceID.getDeviceId().toByteArray())
    {
        union {uint uint_ground_current_A; float ground_current_A; }; //A相接地电流
        union {uint uint_ground_current_B; float ground_current_B; }; //B相接地电流
        union {uint uint_ground_current_C; float ground_current_C; }; //C相接地电流

        float connector_temp_A = 0; //A相接头温度
        float connector_temp_B = 0; //B相接头温度
        float connector_temp_C = 0; //C相接头温度

        int a_x_axis = 0;
        int a_y_axis = 0;
        int a_z_axis = 0;
        int b_x_axis = 0;
        int b_y_axis = 0;
        int b_z_axis = 0;
        int c_x_axis = 0;
        int c_y_axis = 0;
        int c_z_axis = 0;

        uchar *data_tmp = (uchar *)data.data();
        uint frame_head = data_tmp[FRAME_HEAD_OFFSET] | (data_tmp[FRAME_HEAD_OFFSET+1]<<8) | (data_tmp[FRAME_HEAD_OFFSET+2]<<16) | (data_tmp[FRAME_HEAD_OFFSET+3] << 24);
        if ((frame_head == 0x5555aaaa) && (data.length() > 200)) // 帧头匹配
        {
            comProtocol::getRunTime(&data_tmp[FRAME_OPTIME_OFFSET], 4); // 获取运行时间
            comProtocol::getUpsVoltage(&data_tmp[FRAME_UPSVOL_OFFSET], 2); // 获取UPS电压
            comProtocol::getDeviceTemp(&data_tmp[FRAME_ENVTEMP_OFFSET], 2); // 获取环境温度

            uint_ground_current_A = data_tmp[FRAME_GROUND_CURRENT_A_OFFSET] | (data_tmp[FRAME_GROUND_CURRENT_A_OFFSET+1] << 8) | (data_tmp[FRAME_GROUND_CURRENT_A_OFFSET+2] << 16) | (data_tmp[FRAME_GROUND_CURRENT_A_OFFSET+3] << 24);
            qDebug() << "A相接地电流： " << ground_current_A;
            uint_ground_current_B = data_tmp[FRAME_GROUND_CURRENT_B_OFFSET] | (data_tmp[FRAME_GROUND_CURRENT_B_OFFSET+1] << 8) | (data_tmp[FRAME_GROUND_CURRENT_B_OFFSET+2] << 16) | (data_tmp[FRAME_GROUND_CURRENT_B_OFFSET+3] << 24);
            qDebug() << "B相接地电流： " << ground_current_B;
            uint_ground_current_C = data_tmp[FRAME_GROUND_CURRENT_C_OFFSET] | (data_tmp[FRAME_GROUND_CURRENT_C_OFFSET+1] << 8) | (data_tmp[FRAME_GROUND_CURRENT_C_OFFSET+2] << 16) | (data_tmp[FRAME_GROUND_CURRENT_C_OFFSET+3] << 24);
            qDebug() << "C相接地电流： " << ground_current_C;

            connector_temp_A = (float)(((data_tmp[FRAME_CONNECTOR_TEMP_A_OFFSET] << 8) | data_tmp[FRAME_CONNECTOR_TEMP_A_OFFSET+1]) - 2731) / 10;
            qDebug() << "A相接头温度： " << connector_temp_A;
            connector_temp_B = (float)(((data_tmp[FRAME_CONNECTOR_TEMP_B_OFFSET] << 8) | data_tmp[FRAME_CONNECTOR_TEMP_B_OFFSET+1]) - 2731) / 10;
            qDebug() << "B相接头温度： " << connector_temp_B;
            connector_temp_C = (float)(((data_tmp[FRAME_CONNECTOR_TEMP_C_OFFSET] << 8) | data_tmp[FRAME_CONNECTOR_TEMP_C_OFFSET+1]) - 2731) / 10;
            qDebug() << "C相接头温度： " << connector_temp_C;

            a_x_axis = ((data_tmp[FRAME_A_X_AXIS_OFFSET] << 8) | data_tmp[FRAME_A_X_AXIS_OFFSET+1]) - 16000; //A相X轴姿态
            qDebug() << "A相X轴姿态： " << a_x_axis;
            a_y_axis = ((data_tmp[FRAME_A_Y_AXIS_OFFSET] << 8) | data_tmp[FRAME_A_Y_AXIS_OFFSET+1]) - 16000; //A相Y轴姿态
            qDebug() << "A相Y轴姿态： " << a_y_axis;
            a_z_axis = ((data_tmp[FRAME_A_Z_AXIS_OFFSET] << 8) | data_tmp[FRAME_A_Z_AXIS_OFFSET+1]) - 16000; //A相Z轴姿态
            qDebug() << "A相Z轴姿态： " << a_z_axis;
            b_x_axis = ((data_tmp[FRAME_B_X_AXIS_OFFSET] << 8) | data_tmp[FRAME_B_X_AXIS_OFFSET+1]) - 16000; //B相X轴姿态
            qDebug() << "B相X轴姿态： " << b_x_axis;
            b_y_axis = ((data_tmp[FRAME_B_Y_AXIS_OFFSET] << 8) | data_tmp[FRAME_B_Y_AXIS_OFFSET+1]) - 16000; //B相Y轴姿态
            qDebug() << "B相Y轴姿态： " << b_y_axis;
            b_z_axis = ((data_tmp[FRAME_B_Z_AXIS_OFFSET] << 8) | data_tmp[FRAME_B_Z_AXIS_OFFSET+1]) - 16000; //B相Z轴姿态
            qDebug() << "B相Z轴姿态： " << b_z_axis;
            c_x_axis = ((data_tmp[FRAME_C_X_AXIS_OFFSET] << 8) | data_tmp[FRAME_C_X_AXIS_OFFSET+1]) - 16000; //C相X轴姿态
            qDebug() << "C相X轴姿态： " << c_x_axis;
            c_y_axis = ((data_tmp[FRAME_C_Y_AXIS_OFFSET] << 8) | data_tmp[FRAME_C_Y_AXIS_OFFSET+1]) - 16000; //C相Y轴姿态
            qDebug() << "C相Y轴姿态： " << c_y_axis;
            c_z_axis = ((data_tmp[FRAME_C_Z_AXIS_OFFSET] << 8) | data_tmp[FRAME_C_Z_AXIS_OFFSET+1]) - 16000; //C相Z轴姿态
            qDebug() << "C相Z轴姿态： " << c_z_axis;
            //this->ui->tableWidget->item(0,0)->setText(QString::number(ground_current_A, 'f', 3)+" A");

        }
    }
}
/*!
 * \brief CableDataWidget::upData_UI
 * \param data
 * 更新UI
 */
void CableDataWidget::upData_UI(electricCableMetaData data)
{
    switch (data.datatype)
    {
    case MainCable_RT:
        qDebug()<< "主缆电流实时值"<< data.value;
        this->ui->tableWidget->item(0,0)->setText(QString::number(data.value, 'f', 3)+" A");
        if(this->phase_Main_cable_eleCur_ThresholdValue <= data.value)
        {
            this->itemAlarm(0,0);
        }else
        {
            this->itemNormal(0,0);
        }
        break;
    case MainCable_AVG:
        qDebug()<< "主缆电流平均值"<< data.value;
        this->ui->tableWidget->item(1,0)->setText(QString::number(data.value, 'f', 3)+" A");
        this->itemNormal(1,0);
        this->ui->tab_mainCable->addData(0,data.time,data.value);
        break;
    case MainCable_MAX:
        qDebug()<< "主缆电流最大值"<< data.value;
        this->ui->tableWidget->item(2,0)->setText(QString::number(data.value, 'f', 3)+" A");
        this->itemNormal(2,0);
        break;
    case MainCable_MIN:
        qDebug()<< "主缆电流最小值"<< data.value;
        this->ui->tableWidget->item(3,0)->setText(QString::number(data.value, 'f', 3)+" A");
        this->itemNormal(3,0);
        break;
    case GroundCablePhaseA_RT:
        qDebug()<< "A相电流实时值"<< data.value;
        this->ui->tableWidget->item(0,1)->setText(QString::number(data.value, 'f', 3)+" A");
        if(this->phase_A_cable_eleCur_ThresholdValue <= data.value)
        {
            this->itemAlarm(0,1);
        }else
        {
            this->itemNormal(0,1);
        }
        break;
    case GroundCablePhaseA_AVG:
        qDebug()<< "A相电流平均值"<< data.value;
        this->ui->tableWidget->item(1,1)->setText(QString::number(data.value, 'f', 3)+" A");
        this->itemNormal(1,1);
        this->ui->tab_groundCable->addData(0,data.time,data.value);
        break;
    case GroundCablePhaseA_MAX:
        qDebug()<< "A相电流最大值"<< data.value;
        this->ui->tableWidget->item(2,1)->setText(QString::number(data.value, 'f', 3)+" A");
        this->itemNormal(2,1);
        break;
    case GroundCablePhaseA_MIN:
        qDebug()<< "A相电流最小值"<< data.value;
        this->ui->tableWidget->item(3,1)->setText(QString::number(data.value, 'f', 3)+" A");
        this->itemNormal(3,1);
        break;
    case GroundCablePhaseB_RT:
        qDebug()<< "B相电流实时值"<< data.value;
        this->ui->tableWidget->item(0,2)->setText(QString::number(data.value, 'f', 3)+" A");
        if(this->phase_B_cable_eleCur_ThresholdValue <= data.value)
        {
            this->itemAlarm(0,2);
        }else
        {
            this->itemNormal(0,2);
        }
        break;
    case GroundCablePhaseB_AVG:
        qDebug()<< "B相电流平均值"<< data.value;
        this->ui->tableWidget->item(1,2)->setText(QString::number(data.value, 'f', 3)+" A");
         this->itemNormal(1,2);
        this->ui->tab_groundCable->addData(1,data.time,data.value);
        break;
    case GroundCablePhaseB_MAX:
        qDebug()<< "B相电流最大值"<< data.value;
        this->ui->tableWidget->item(2,2)->setText(QString::number(data.value, 'f', 3)+" A");
         this->itemNormal(2,2);
        break;
    case GroundCablePhaseB_MIN:
        qDebug()<< "B相电流最小值"<< data.value;
        this->ui->tableWidget->item(3,2)->setText(QString::number(data.value, 'f', 3)+" A");
         this->itemNormal(3,2);
        break;
    case GroundCablePhaseC_RT:
        qDebug()<< "C相电流实时值"<< data.value;
        this->ui->tableWidget->item(0,3)->setText(QString::number(data.value, 'f', 3)+" A");
        if(this->phase_C_cable_eleCur_ThresholdValue <= data.value)
        {
             this->itemAlarm(0,3);
        }else
        {
             this->itemNormal(0,3);
        }
        break;
    case GroundCablePhaseC_AVG:
        qDebug()<< "C相电流平均值"<< data.value;
        this->ui->tableWidget->item(1,3)->setText(QString::number(data.value, 'f', 3)+" A");
        this->itemNormal(1,3);
        this->ui->tab_groundCable->addData(2,data.time,data.value);
        break;
    case GroundCablePhaseC_MAX:
        qDebug()<< "C相电流最大值"<< data.value;
        this->ui->tableWidget->item(2,3)->setText(QString::number(data.value, 'f', 3)+" A");
        this->itemNormal(2,3);
        break;
    case GroundCablePhaseC_MIN:
        qDebug()<< "C相电流最小值"<< data.value;
        this->ui->tableWidget->item(3,3)->setText(QString::number(data.value, 'f', 3)+" A");
        this->itemNormal(3,3);
        break;
    case GroundCablePhaseN_RT:
        qDebug()<< "N相电流实时值"<< data.value;
        this->ui->tableWidget->item(0,4)->setText(QString::number(data.value, 'f', 3)+" A");
        if(this->phase_N_cable_eleCur_ThresholdValue <= data.value)
        {
            this->itemAlarm(0,4);
        }else
        {
            this->itemNormal(0,4);
        }
        break;
    case GroundCablePhaseN_AVG:
        qDebug()<< "N相电流平均值"<< data.value;
        this->ui->tableWidget->item(1,4)->setText(QString::number(data.value, 'f', 3)+" A");
        this->itemNormal(1,4);
        this->ui->tab_groundCable->addData(3,data.time,data.value);
        break;
    case GroundCablePhaseN_MAX:
        qDebug()<< "A相电流最大值"<< data.value;
        this->ui->tableWidget->item(2,4)->setText(QString::number(data.value, 'f', 3)+" A");
        this->itemNormal(2,4);
        break;
    case GroundCablePhaseN_MIN:
        qDebug()<< "A相电流最小值"<< data.value;
        this->ui->tableWidget->item(3,4)->setText(QString::number(data.value, 'f', 3)+" A");
        this->itemNormal(3,4);
        break;
    case GroundCablePhaseA_Temp_RT:
        qDebug()<< "A相温度实时值"<< data.value;
        this->ui->tableWidget->item(4,1)->setText(QString::number(data.value, 'f', 2)+" ℃");
        if(this->phase_A_cable_temp_ThresholdValue <= data.value)
        {
            this->itemAlarm(4,1);
        }else
        {
            if(data.value <= -500)
            {
                this->itemFault(4,1);
            }else
            {
                this->itemNormal(4,1);
            }
        }
        break;
    case GroundCablePhaseA_Temp_AVG:
        qDebug()<< "A相温度平均值"<< data.value;
        this->ui->tableWidget->item(5,1)->setText(QString::number(data.value, 'f', 2)+" ℃");
        this->itemNormal(5,1);
        break;
    case GroundCablePhaseA_Temp_MAX:
        qDebug()<< "A相温度最大值"<< data.value;
        this->ui->tableWidget->item(6,1)->setText(QString::number(data.value, 'f', 2)+" ℃");
        if(data.value <= -500)
        {
            this->itemFault(6,1);
        }else
        {
            this->itemNormal(6,1);
        }
        break;
    case GroundCablePhaseA_Temp_MIN:
        qDebug()<< "A相温度最小值"<< data.value;
        this->ui->tableWidget->item(7,1)->setText(QString::number(data.value, 'f', 2)+" ℃");
        if(data.value <= -500)
        {
            this->itemFault(7,1);
        }else
        {
            this->itemNormal(7,1);
        }
        break;
    case GroundCablePhaseB_Temp_RT:
        qDebug()<< "B相温度实时值"<< data.value;
        this->ui->tableWidget->item(4,2)->setText(QString::number(data.value, 'f', 2)+" ℃");
        if(this->phase_B_cable_temp_ThresholdValue <= data.value)
        {
            this->itemAlarm(4,2);
        }else
        {
            if(data.value <= -500)
            {
                this->itemFault(4,2);
            }else
            {
                this->itemNormal(4,2);
            }
        }
        break;
    case GroundCablePhaseB_Temp_AVG:
        qDebug()<< "B相温度平均值"<< data.value;
        this->ui->tableWidget->item(5,2)->setText(QString::number(data.value, 'f', 2)+" ℃");
        this->itemNormal(5,2);
        break;
    case GroundCablePhaseB_Temp_MAX:
        qDebug()<< "B相温度最大值"<< data.value;
        this->ui->tableWidget->item(6,2)->setText(QString::number(data.value, 'f', 2)+" ℃");
        if(data.value <= -500)
        {
            this->itemFault(6,2);
        }else
        {
            this->itemNormal(6,2);
        }
        break;
    case GroundCablePhaseB_Temp_MIN:
        qDebug()<< "B相温度最小值"<< data.value;
        this->ui->tableWidget->item(7,2)->setText(QString::number(data.value, 'f', 2)+" ℃");
        if(data.value <= -500)
        {
            this->itemFault(7,2);
        }else
        {
            this->itemNormal(7,2);
        }
        break;
    case GroundCablePhaseC_Temp_RT:
        qDebug()<< "C相温度实时值"<< data.value;
        this->ui->tableWidget->item(4,3)->setText(QString::number(data.value, 'f', 2)+" ℃");
        if(this->phase_C_cable_temp_ThresholdValue <= data.value)
        {
            this->itemAlarm(4,3);
        }else
        {
            if(data.value <= -500)
            {
                this->itemFault(4,3);
            }else
            {
                this->itemNormal(4,3);
            }
        }
        break;
    case GroundCablePhaseC_Temp_AVG:
        qDebug()<< "C相温度平均值"<< data.value;
        this->ui->tableWidget->item(5,3)->setText(QString::number(data.value, 'f', 2)+" ℃");
        this->itemNormal(5,3);
        break;
    case GroundCablePhaseC_Temp_MAX:
        qDebug()<< "C相温度最大值"<< data.value;
        this->ui->tableWidget->item(6,3)->setText(QString::number(data.value, 'f', 2)+" ℃");
        if(data.value <= -500)
        {
            this->itemFault(6,3);
        }else
        {
            this->itemNormal(6,3);
        }
        break;
    case GroundCablePhaseC_Temp_MIN:
        qDebug()<< "C相温度最小值"<< data.value;
        this->ui->tableWidget->item(7,3)->setText(QString::number(data.value, 'f', 2)+" ℃");
        if(data.value <= -500)
        {
            this->itemFault(7,3);
        }else
        {
            this->itemNormal(7,3);
        }
        break;
    case GroundCablePhaseN_Temp_RT:
        qDebug()<< "N相温度实时值"<< data.value;
        this->ui->tableWidget->item(4,4)->setText(QString::number(data.value, 'f', 2)+" ℃");
        if(this->phase_N_cable_temp_ThresholdValue <= data.value)
        {
            this->itemAlarm(4,4);
        }else
        {
            if(data.value <= -500)
            {
                this->itemFault(4,4);
            }else
            {
                this->itemNormal(4,4);
            }
        }
        break;
    case GroundCablePhaseN_Temp_AVG:
        qDebug()<< "N相温度平均值"<< data.value;
        this->ui->tableWidget->item(5,4)->setText(QString::number(data.value, 'f', 2)+" ℃");
        this->itemNormal(5,4);
        break;
    case GroundCablePhaseN_Temp_MAX:
        qDebug()<< "N相温度最大值"<< data.value;
        this->ui->tableWidget->item(6,4)->setText(QString::number(data.value, 'f', 2)+" ℃");
        if(data.value <= -500)
        {
            this->itemFault(6,4);
        }else
        {
            this->itemNormal(6,4);
        }
        break;
    case GroundCablePhaseN_Temp_MIN:
        qDebug()<< "N相温度最小值"<< data.value;
        this->ui->tableWidget->item(7,4)->setText(QString::number(data.value, 'f', 2)+" ℃");
        if(data.value <= -500)
        {
            this->itemFault(7,4);
        }else
        {
            this->itemNormal(7,4);
        }
        break;

    case GroundCablePhaseA_Load_RT:
        qDebug()<< "A相电流负荷"<< data.value;
        this->ui->tableWidget->item(8,1)->setText(QString::number(data.value, 'f', 2)+"%");
        this->itemNormal(8,1);
        break;
    case GroundCablePhaseB_Load_RT:
        qDebug()<< "B相电流负荷"<< data.value;
        this->ui->tableWidget->item(8,2)->setText(QString::number(data.value, 'f', 2)+"%");
        this->itemNormal(8,2);
        break;
    case GroundCablePhaseC_Load_RT:
        qDebug()<< "C相电流负荷"<< data.value;
        this->ui->tableWidget->item(8,3)->setText(QString::number(data.value, 'f', 2)+"%");
        this->itemNormal(8,3);
        break;
    case GroundCablePhaseN_Load_RT:
        qDebug()<< "N相电流负荷"<< data.value;
        this->ui->tableWidget->item(8,4)->setText(QString::number(data.value, 'f', 2)+"%");
        this->itemNormal(8,4);
        break;

    case GroundCablePhaseA_Ratio_RT:
        qDebug()<< "A相电流比值"<< data.value;
        this->ui->tableWidget->item(9,1)->setText(QString::number(data.value, 'f', 2));
        this->itemNormal(9,1);
        break;
    case GroundCablePhaseB_Ratio_RT:
        qDebug()<< "B相电流比值"<< data.value;
        this->ui->tableWidget->item(9,2)->setText(QString::number(data.value, 'f', 2));
        this->itemNormal(9,2);
        break;
    case GroundCablePhaseC_Ratio_RT:
        qDebug()<< "C相电流比值"<< data.value;
        this->ui->tableWidget->item(9,3)->setText(QString::number(data.value, 'f', 2));
        this->itemNormal(9,3);
        break;
    case GroundCablePhaseN_Ratio_RT:
        qDebug()<< "N相电流比值"<< data.value;
        this->ui->tableWidget->item(9,4)->setText(QString::number(data.value, 'f', 2));
        this->itemNormal(9,4);
        break;
//==================================报警值显示========================================================
    case MainCable_Alarm:
        qDebug()<< "主缆电流报警值"<< data.value;
        this->ui->tableWidget_alarm_value->item(0,0)->setText(QString::number(data.value, 'f', 3)+"A");
        this->item_alarm_table(0,0);
        this->item_time_table(0,1,data.time);
        break;
    case GroundCablePhaseA_Alarm:
        qDebug()<< "A相电流报警值"<< data.value;
        this->ui->tableWidget_alarm_value->item(1,0)->setText(QString::number(data.value, 'f', 3)+"A");
        this->item_alarm_table(1,0);
        this->item_time_table(1,1,data.time);
        break;

    case GroundCablePhaseB_Alarm:
        qDebug()<< "B相电流报警值"<< data.value;
        this->ui->tableWidget_alarm_value->item(2,0)->setText(QString::number(data.value, 'f', 3)+"A");
        this->item_alarm_table(2,0);
        this->item_time_table(2,1,data.time);
        break;
    case GroundCablePhaseC_Alarm:
        qDebug()<< "C相电流报警值"<< data.value;
        this->ui->tableWidget_alarm_value->item(3,0)->setText(QString::number(data.value, 'f', 3)+"A");
        this->item_alarm_table(3,0);
        this->item_time_table(3,1,data.time);
        break;
    case GroundCablePhaseN_Alarm:
        qDebug()<< "N相电流报警值"<< data.value;
        this->ui->tableWidget_alarm_value->item(4,0)->setText(QString::number(data.value, 'f', 3)+"A");
        this->item_alarm_table(4,0);
        this->item_time_table(4,1,data.time);
        break;

    case GroundCablePhaseA_Temp_Alarm:
        qDebug()<< "A相温度报警值"<< data.value;
        this->ui->tableWidget_alarm_value->item(5,0)->setText(QString::number(data.value, 'f', 2)+"℃");
        this->item_alarm_table(5,0);
        this->item_time_table(5,1,data.time);
    case GroundCablePhaseB_Temp_Alarm:
        qDebug()<< "B相温度报警值"<< data.value;
        this->ui->tableWidget_alarm_value->item(6,0)->setText(QString::number(data.value, 'f', 2)+"℃");
        this->item_alarm_table(6,0);
        this->item_time_table(6,1,data.time);
        break;
    case GroundCablePhaseC_Temp_Alarm:
        qDebug()<< "C相温度报警值"<< data.value;
        this->ui->tableWidget_alarm_value->item(7,0)->setText(QString::number(data.value, 'f', 2)+"℃");
        this->item_alarm_table(7,0);
        this->item_time_table(7,1,data.time);
        break;
    case GroundCablePhaseN_Temp_Alarm:
        qDebug()<< "N相温度报警值"<< data.value;
        this->ui->tableWidget_alarm_value->item(8,0)->setText(QString::number(data.value, 'f', 2)+"℃");
        this->item_alarm_table(8,0);
        this->item_time_table(8,1,data.time);
        break;

    case GroundCablePhaseAVibrationCount_Alarm:
        qDebug()<< "A相振动报警值"<< data.value;
        this->ui->tableWidget_alarm_value->item(9,0)->setText(QString::number(data.value, 'f', 2));
        if(data.value == -1)
        {
            this->item_fault_table(9,0);
        }else
        {
            this->item_alarm_table(9,0);
        }
        this->item_time_table(9,1,data.time);

    case GroundCablePhaseBVibrationCount_Alarm:
        qDebug()<< "B相振动报警值"<< data.value;
        this->ui->tableWidget_alarm_value->item(10,0)->setText(QString::number(data.value, 'f', 2));
        if(data.value == -1)
        {
            this->item_fault_table(10,0);
        }else
        {
            this->item_alarm_table(10,0);
        }
        this->item_time_table(10,1,data.time);
        break;
    case GroundCablePhaseCVibrationCount_Alarm:
        qDebug()<< "C相振动报警值"<< data.value;
        this->ui->tableWidget_alarm_value->item(11,0)->setText(QString::number(data.value, 'f', 2));
        if(data.value == -1)
        {
            this->item_fault_table(11,0);
        }else
        {
            this->item_alarm_table(11,0);
        }
        this->item_time_table(11,1,data.time);
        break;
    case GroundCablePhaseNVibrationCount_Alarm:
        qDebug()<< "N相振动报警值"<< data.value;
        this->ui->tableWidget_alarm_value->item(12,0)->setText(QString::number(data.value, 'f', 2));
        if(data.value == -1)
        {
            this->item_fault_table(12,0);
        }else
        {
            this->item_alarm_table(12,0);
        }
        this->item_time_table(12,1,data.time);
        break;

    case GroundCablePhaseA_Load_Alarm:
        qDebug()<< "A相电流负荷报警值"<< data.value;
        this->ui->tableWidget_alarm_value->item(13,0)->setText(QString::number(data.value, 'f', 2)+"%");
        this->item_alarm_table(13,0);
        this->item_time_table(13,1,data.time);
    case GroundCablePhaseB_Load_Alarm:
        qDebug()<< "B相电流负荷报警值"<< data.value;
        this->ui->tableWidget_alarm_value->item(14,0)->setText(QString::number(data.value, 'f', 2)+"%");
        this->item_alarm_table(14,0);
        this->item_time_table(14,1,data.time);
        break;
    case GroundCablePhaseC_Load_Alarm:
        qDebug()<< "C相电流负荷报警值"<< data.value;
        this->ui->tableWidget_alarm_value->item(15,0)->setText(QString::number(data.value, 'f', 2)+"%");
        this->item_alarm_table(15,0);
        this->item_time_table(15,1,data.time);
        break;
    case GroundCablePhaseN_Load_Alarm:
        qDebug()<< "N相电流负荷报警值"<< data.value;
        this->ui->tableWidget_alarm_value->item(16,0)->setText(QString::number(data.value, 'f', 2)+"%");
        this->item_alarm_table(16,0);
        this->item_time_table(16,1,data.time);
        break;

    case GroundCablePhaseA_Ratio_Alarm:
        qDebug()<< "A相电流大小比报警值"<< data.value;
        this->ui->tableWidget_alarm_value->item(17,0)->setText(QString::number(data.value, 'f', 2));
        this->item_alarm_table(17,0);
        this->item_time_table(17,1,data.time);
    case GroundCablePhaseB_Ratio_Alarm:
        qDebug()<< "B相电流大小比报警值"<< data.value;
        this->ui->tableWidget_alarm_value->item(18,0)->setText(QString::number(data.value, 'f', 2));
        this->item_alarm_table(18,0);
        this->item_time_table(18,1,data.time);
        break;
    case GroundCablePhaseC_Ratio_Alarm:
        qDebug()<< "C相电流大小比报警值"<< data.value;
        this->ui->tableWidget_alarm_value->item(19,0)->setText(QString::number(data.value, 'f', 2));
        this->item_alarm_table(19,0);
        this->item_time_table(19,1,data.time);
        break;
    case GroundCablePhaseN_Ratio_Alarm:
        qDebug()<< "N相电流大小比报警值"<< data.value;
        this->ui->tableWidget_alarm_value->item(20,0)->setText(QString::number(data.value, 'f', 2));
        this->item_alarm_table(20,0);
        this->item_time_table(20,1,data.time);
        break;

    case MainCableChangeRate_Alarm:
        qDebug()<< "主缆电流变化率报警值"<< data.value;
        this->ui->tableWidget_alarm_value->item(21,0)->setText(QString::number(data.value, 'f', 3) + "A");
        this->item_alarm_table(21,0);
        this->item_time_table(21,1,data.time);
    case GroundCablePhaseAChangeRate_Alarm:
        qDebug()<< "A相电流变化率报警值"<< data.value;
        this->ui->tableWidget_alarm_value->item(22,0)->setText(QString::number(data.value, 'f', 3) + "A");
        this->item_alarm_table(22,0);
        this->item_time_table(22,1,data.time);
    case GroundCablePhaseBChangeRate_Alarm:
        qDebug()<< "B相电流变化率报警值"<< data.value;
        this->ui->tableWidget_alarm_value->item(23,0)->setText(QString::number(data.value, 'f', 3) + "A");
        this->item_alarm_table(23,0);
        this->item_time_table(23,1,data.time);
        break;
    case GroundCablePhaseCChangeRate_Alarm:
        qDebug()<< "C相电流变化率报警值"<< data.value;
        this->ui->tableWidget_alarm_value->item(24,0)->setText(QString::number(data.value, 'f', 3) + "A");
        this->item_alarm_table(24,0);
        this->item_time_table(24,1,data.time);
        break;
    case GroundCablePhaseNChangeRate_Alarm:
        qDebug()<< "N相电流变化率报警值"<< data.value;
        this->ui->tableWidget_alarm_value->item(25,0)->setText(QString::number(data.value, 'f', 3) + "A");
        this->item_alarm_table(25,0);
        this->item_time_table(25,1,data.time);
        break;

    case InputVolt:
        qDebug()<< "输入电压："<< data.value<<"V";
        this->ui->label_InputVol->setText(QString::number(data.value, 'f', 3)+"V");
        break;
    default:
        break;
    }
}

void CableDataWidget::itemAlarm(uint row, uint col)
{
    this->ui->tableWidget->item(row,col)->setBackgroundColor(Qt::red);
}

void CableDataWidget::itemFault(uint row, uint col)
{
    this->ui->tableWidget->item(row,col)->setText("传感器故障");
    this->ui->tableWidget->item(row,col)->setBackgroundColor(Qt::yellow);
}

void CableDataWidget::itemNormal(uint row, uint col)
{
    this->ui->tableWidget->item(row,col)->setBackgroundColor(Qt::green);
}

void CableDataWidget::item_fault_table(uint row, uint col)
{
    this->ui->tableWidget_alarm_value->item(row,col)->setText("传感器故障");
    this->ui->tableWidget_alarm_value->item(row,col)->setBackgroundColor(Qt::yellow);
    this->ui->tableWidget_alarm_value->item(row,col+1)->setBackgroundColor(Qt::yellow);
}

void CableDataWidget::item_alarm_table(uint row, uint col)
{
    this->ui->tableWidget_alarm_value->item(row,col)->setBackgroundColor(Qt::red);
    this->ui->tableWidget_alarm_value->item(row,col+1)->setBackgroundColor(Qt::red);
}

void CableDataWidget::item_time_table(uint row, uint col,QDateTime data)
{
    this->ui->tableWidget_alarm_value->item(row,col)->setText(data.toString("yyyy-MM-dd hh:mm:ss"));
}
/*!
 * \brief CableDataWidget::autoGetData_slot
 * 自动获取实时数据
 */
void CableDataWidget::autoGetData_slot()
{
    this->autogetDataFlag =true;
}

void CableDataWidget::on_pushButton_read_alarm_value_clicked()
{
    this->autogetAlarmDataFlag = true;
}

void CableDataWidget::on_checkBox_alarm_value_clicked(bool checked)
{
    if(checked == true)
    {
        this->autoGetAlarmDataTimer->setInterval(this->ui->spinBox_alarm_value->text().toInt()*1000);
        this->autoGetAlarmDataTimer->start();
    }else
    {
        this->autoGetAlarmDataTimer->stop();
    }
}
void CableDataWidget::autoGetAlarmData_slot()
{
    this->autogetAlarmDataFlag = true;
}
/*!
 * \brief CableDataWidget::autoGetStatistic_slot
 * 自动获取统计数据
 */
void CableDataWidget::autoGetStatistic_slot()
{
    this->autogetStatisticFlag = true;
}
/*!
 * \brief CableDataWidget::sendDataFrame
 * \param data
 * 选择发送数据模式
 */
void CableDataWidget::sendDataFrame(QByteArray data)
{
    if(this->blindFlag != flag_network)
    {
        emit sendDataToDevice(data);
    }else if(this->blindFlag == flag_network)
    {
        if((this->tcpClientID != 0)&&(this->clientIP != ""))
        {
            emit sendDataToDevice(this->tcpClientID,data);
//            if((data.at(18) == MainCable_RT)&&(data.mid(5,12) == this->deviceID.getDeviceId().toByteArray()))
//            {
//                CNT_COM++;
//            }
        }
    }
}
/*!
 * \brief CableDataWidget::sendData_slot
 * 按队列发送数据
 */
void CableDataWidget::sendData_slot()
{
    if(this->setDataFlag == true)
    {
        this->autoGetDataTimer->stop();
        this->autoGetStatisticTimer->stop();
        this->autoGetAlarmDataTimer->stop();
        this->autogetStatisticFlag = false;
        this->autogetStatisticFlag = false;        
        this->autogetAlarmDataFlag = false;
        if(this->ui->checkBox->isChecked())
        {
            this->autoGetDataTimer->start();

        }
        if(this->ui->checkBox_alarm_value->isChecked())
        {
            this->autoGetAlarmDataTimer->start();
        }
        if(this->ui->checkBox_statistics_value->isChecked())
        {
            this->autoGetStatisticTimer->start();
        }
        this->setDataFlag = false;
        if(this->sendData.count() !=0)
        {
            this->sendDataFrame(this->sendData);
        }
    }else if(this->autogetStatisticFlag == true)
    {
        this->autogetStatisticFlag = false;
        if(this->blindFlag == flag_485)
        {
            emit sendDataToDevice(comProtocol::assembleStatisticalAndAlarmDataRequestFrame(this->deviceID.getDeviceId()));
            emit sendDataToDevice(comProtocol::assembleStatisticalTempRequestFrame(this->deviceID.getDeviceId()));
        }else if(this->blindFlag == flag_network)
        {
            if((this->tcpClientID != 0)&&(this->clientIP != ""))
            {
                emit sendDataToDevice(this->tcpClientID,comProtocol::assembleStatisticalAndAlarmDataRequestFrame(this->deviceID.getDeviceId()));
//                myHelper::Delay_MSec(150);
                emit sendDataToDevice(this->tcpClientID,comProtocol::assembleStatisticalTempRequestFrame(this->deviceID.getDeviceId()));
//                  this->list_SendDataToClient.append(comProtocol::assembleStatisticalAndAlarmDataRequestFrame(this->deviceID.getDeviceId()));
//                  this->list_SendDataToClient.append(comProtocol::assembleStatisticalTempRequestFrame(this->deviceID.getDeviceId()));
            }
        }
    }else if(this->autogetDataFlag == true)
    {
        this->autogetDataFlag = false;
        this->sendDataFrame(comProtocol::assembleRtDataRequestFrame(this->deviceID.getDeviceId()));
//        myHelper::Delay_MSec(100);
#if 0
        this->sendDataFrame(comProtocol::assembleReadRTDataRequestFrame(this->deviceID.getDeviceId()));
#endif /* 0 */
    }else if(this->autogetAlarmDataFlag ==true)
    {
        this->autogetAlarmDataFlag = false;
        this->autogetDataFlag = false;
        this->sendDataFrame(comProtocol::assembleAlarmDataRequestFrame(this->deviceID.getDeviceId()));
//        myHelper::Delay_MSec(100);
        this->sendDataFrame(comProtocol::assembleAlarmData1RequestFrame(this->deviceID.getDeviceId()));
    }
}

void CableDataWidget::clear_rt_data()
{
    for(int i=0;i<this->ui->tableWidget->columnCount();i++)
    {
        for(int j=0;j<this->ui->tableWidget->rowCount();j++)
        {
            QTableWidgetItem *item = new QTableWidgetItem(tr("无信息"));
            this->ui->tableWidget->setItem(j,i,item);
            if(list_display_rt_data.length() != 5*this->ui->tableWidget->rowCount())
            list_display_rt_data.append(QString("无信息"));
        }
    }
}

void CableDataWidget::clear_alarm_data()
{
    for(int i=0;i<this->ui->tableWidget_alarm_value->rowCount();i++)
    {
        this->ui->tableWidget_alarm_value->item(i,0)->setText("无信息");
        this->ui->tableWidget_alarm_value->item(i,1)->setText("无信息");
        if(list_display_Alarm_data.length() != this->ui->tableWidget_alarm_value->rowCount()*2)
        {
            list_display_Alarm_data.append(QString("无信息"));
            list_display_Alarm_data.append(QString("无信息"));
        }
    }
}

void CableDataWidget::save_Rt_data()
{
    QDir tmp;
    QString filePath = QString("/data/设备%1").arg(this->deviceID.getDeviceId().toString());
    filePath = QCoreApplication::applicationDirPath() + filePath;
    if(tmp.exists(filePath))
    {
    }else
    {
        if(!tmp.mkdir(filePath))
        {
            QMessageBox::warning(this,tr("错误信息"),tr("创建目录%1失败").arg(filePath),tr("确认"));
            return;
        }
    }
    QString str_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss");
    filePath = filePath + QString("/实时数据%1.xlsx").arg(str_time);
    filePath = filePath.replace("/", "\\");//路径需要’\’反斜杠
    QAxObject *work_book = NULL;
    QAxObject excel("Excel.Application");
    excel.setProperty("Visible", false);
    excel.setProperty("DisplayAlerts", false);//不显示任何警告信息
    QAxObject *work_books = excel.querySubObject("WorkBooks");
    QFile xlsFile(filePath);
    if (xlsFile.exists()) {
        work_book = work_books->querySubObject("Open(const QString &)", filePath);
    }
    else {
        work_books->dynamicCall("Add");
        work_book = excel.querySubObject("ActiveWorkBook");
    }
    QAxObject *work_sheets = work_book->querySubObject("Sheets");
    QAxObject *first_sheet = work_sheets->querySubObject("Item(int)", 1);
    QAxObject *cell = first_sheet->querySubObject("Cells(int,int)", 1, 1);
    cell->setProperty("Value", "设备实时数据");
    cell = first_sheet->querySubObject("Cells(int,int)", 1, 2);
    cell->setProperty("Value", "主缆");
    cell = first_sheet->querySubObject("Cells(int,int)", 1, 3);
    cell->setProperty("Value", "A相");
    cell = first_sheet->querySubObject("Cells(int,int)", 1, 4);
    cell->setProperty("Value", "B相");
    cell = first_sheet->querySubObject("Cells(int,int)", 1, 5);
    cell->setProperty("Value", "C相");
    cell = first_sheet->querySubObject("Cells(int,int)", 1, 6);
    cell->setProperty("Value", "N相");

    for(int i=0; i<this->ui->tableWidget->rowCount();i++)
    {
        cell = first_sheet->querySubObject("Cells(int,int)", 2+i, 1);
        cell->setProperty("Value", ui->tableWidget->verticalHeaderItem(i)->text());
        cell->setProperty("ColumnWidth", 15);  //设置单元格列宽
        cell = first_sheet->querySubObject("Cells(int,int)", 2+i, 2);
        cell->setProperty("Value", ui->tableWidget->item(i,0)->text());
        cell->setProperty("ColumnWidth", 15);  //设置单元格列宽
        cell = first_sheet->querySubObject("Cells(int,int)", 2+i, 3);
        cell->setProperty("Value", ui->tableWidget->item(i,1)->text());
        cell->setProperty("ColumnWidth", 15);  //设置单元格列宽
        cell = first_sheet->querySubObject("Cells(int,int)", 2+i, 4);
        cell->setProperty("Value", ui->tableWidget->item(i,2)->text());
        cell->setProperty("ColumnWidth", 15);  //设置单元格列宽
        cell = first_sheet->querySubObject("Cells(int,int)", 2+i, 5);
        cell->setProperty("Value", ui->tableWidget->item(i,3)->text());
        cell->setProperty("ColumnWidth", 15);  //设置单元格列宽
        cell = first_sheet->querySubObject("Cells(int,int)", 2+i, 6);
        cell->setProperty("Value", ui->tableWidget->item(i,4)->text());
        cell->setProperty("ColumnWidth", 15);  //设置单元格列宽
    }

    work_book->dynamicCall("SaveAs(const QString &)", QDir::toNativeSeparators(filePath)); //转换路径不可少，否则会崩溃
    work_book->dynamicCall("Close(Boolean)", false);  //关闭文件
    excel.dynamicCall("Quit(void)");  //退出
    QMessageBox::information(this, tr("信息"),tr("保存%1完成").arg(filePath),tr("确认"));
}

void CableDataWidget::save_Alarm_data()
{
    QDir tmp;
    QString filePath = QString("/data/设备%1").arg(this->deviceID.getDeviceId().toString());
    filePath = QCoreApplication::applicationDirPath() + filePath;
    if(tmp.exists(filePath))
    {
    }else
    {
        if(!tmp.mkdir(filePath))
        {
            QMessageBox::warning(this,tr("错误信息"),tr("创建目录%1失败").arg(filePath),tr("确认"));
            return;
        }
    }
    QString str_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss");
    filePath = filePath + QString("/报警数据%1.xlsx").arg(str_time);
    filePath = filePath.replace("/", "\\");//路径需要’\’反斜杠
    QAxObject *work_book = NULL;
    QAxObject excel("Excel.Application");
    excel.setProperty("Visible", false);
    excel.setProperty("DisplayAlerts", false);//不显示任何警告信息
    QAxObject *work_books = excel.querySubObject("WorkBooks");
    QFile xlsFile(filePath);
    if (xlsFile.exists()) {
        work_book = work_books->querySubObject("Open(const QString &)", filePath);
    }
    else {
        work_books->dynamicCall("Add");
        work_book = excel.querySubObject("ActiveWorkBook");
    }
    QAxObject *work_sheets = work_book->querySubObject("Sheets");
    QAxObject *first_sheet = work_sheets->querySubObject("Item(int)", 1);
    QAxObject *cell = first_sheet->querySubObject("Cells(int,int)", 1, 1);
    cell->setProperty("Value", "设备报警数据");
    cell = first_sheet->querySubObject("Cells(int,int)", 1, 2);
    cell->setProperty("Value", "报警值");
    cell = first_sheet->querySubObject("Cells(int,int)", 1, 3);
    cell->setProperty("Value", "报警时间");

    for(int i=0; i<this->ui->tableWidget->rowCount();i++)
    {
        cell = first_sheet->querySubObject("Cells(int,int)", 2+i, 1);
        cell->setProperty("Value", ui->tableWidget_alarm_value->verticalHeaderItem(i)->text());
        cell->setProperty("ColumnWidth", 20);  //设置单元格列宽
        cell = first_sheet->querySubObject("Cells(int,int)", 2+i, 2);
        cell->setProperty("Value", ui->tableWidget_alarm_value->item(i,0)->text());
        cell->setProperty("ColumnWidth", 15);  //设置单元格列宽
        cell = first_sheet->querySubObject("Cells(int,int)", 2+i, 3);
        cell->setProperty("Value", ui->tableWidget_alarm_value->item(i,1)->text());
        cell->setProperty("ColumnWidth", 15);  //设置单元格列宽
    }

    work_book->dynamicCall("SaveAs(const QString &)", QDir::toNativeSeparators(filePath)); //转换路径不可少，否则会崩溃
    work_book->dynamicCall("Close(Boolean)", false);  //关闭文件
    excel.dynamicCall("Quit(void)");  //退出
    QMessageBox::information(this, tr("信息"),tr("保存%1完成").arg(filePath),tr("确认"));
}

void CableDataWidget::init_para()
{
    QDir tmp;
    QString filePath = QString("/device_config/设备%1").arg(this->deviceID.getDeviceId().toString());
    filePath = QCoreApplication::applicationDirPath() + filePath;
    if(tmp.exists(filePath))
    {
    }else
    {
        if(!tmp.mkdir(filePath))
        {
            QMessageBox::warning(this,tr("错误信息"),tr("创建目录%1失败").arg(filePath),tr("确认"));
            return;
        }
    }
    filePath = filePath + QString("/设备配置参数.ini");
    QSettings *settingFile = new QSettings(filePath, QSettings::IniFormat, 0);
    settingFile->beginGroup(QString("device-%1").arg(this->deviceID.getDeviceId().toString()));
    if(settingFile->contains("device_ID"))
    {
    }else
    {
        settingFile->setValue("device_ID",this->deviceID.getDeviceId().toString());
    }
    if(settingFile->contains("device_name"))
    {
    }else
    {
        settingFile->setValue("device_name",this->deviceID.getDeviceName());
    }
    if(settingFile->contains("device_IP"))
    {
    }else
    {
        settingFile->setValue("device_IP",this->clientIP);
    }

    if(settingFile->contains("samp_time_cur"))
    {
    }else
    {
        settingFile->setValue("samp_time_cur",5);
    }
    if(settingFile->contains("statistics_cycle_cur"))
    {
    }else
    {
        settingFile->setValue("statistics_cycle_cur",1);
    }
    if(settingFile->contains("statistics_number_cur"))
    {
    }else
    {
        settingFile->setValue("statistics_number_cur",1);
    }

    if(settingFile->contains("samp_time_temp"))
    {
    }else
    {
        settingFile->setValue("samp_time_temp",10);
    }
    if(settingFile->contains("statistics_cycle_temp"))
    {
    }else
    {
        settingFile->setValue("statistics_cycle_temp",1);
    }
    if(settingFile->contains("statistics_number_temp"))
    {
    }else
    {
        settingFile->setValue("statistics_number_temp",1);
    }

    if(settingFile->contains("phase_Main_cable_eleCur_ThresholdValue"))
    {
    }else
    {
        settingFile->setValue("phase_Main_cable_eleCur_ThresholdValue",100);
    }
    if(settingFile->contains("phase_A_cable_eleCur_ThresholdValue"))
    {
    }else
    {
        settingFile->setValue("phase_A_cable_eleCur_ThresholdValue",50);
    }
    if(settingFile->contains("phase_B_cable_eleCur_ThresholdValue"))
    {
    }else
    {
        settingFile->setValue("phase_B_cable_eleCur_ThresholdValue",50);
    }
    if(settingFile->contains("phase_C_cable_eleCur_ThresholdValue"))
    {
    }else
    {
        settingFile->setValue("phase_C_cable_eleCur_ThresholdValue",50);
    }
    if(settingFile->contains("phase_N_cable_eleCur_ThresholdValue"))
    {
    }else
    {
        settingFile->setValue("phase_N_cable_eleCur_ThresholdValue",50);
    }
    if(settingFile->contains("phase_A_cable_temp_ThresholdValue"))
    {
    }else
    {
        settingFile->setValue("phase_A_cable_temp_ThresholdValue",50);
    }
    if(settingFile->contains("phase_B_cable_temp_ThresholdValue"))
    {
    }else
    {
        settingFile->setValue("phase_B_cable_temp_ThresholdValue",50);
    }
    if(settingFile->contains("phase_C_cable_temp_ThresholdValue"))
    {
    }else
    {
        settingFile->setValue("phase_C_cable_temp_ThresholdValue",50);
    }
    if(settingFile->contains("phase_N_cable_temp_ThresholdValue"))
    {
    }else
    {
        settingFile->setValue("phase_N_cable_temp_ThresholdValue",50);
    }
    if(settingFile->contains("cur_change_cycle"))
    {
    }else
    {
        settingFile->setValue("cur_change_cycle",10);
    }

    if(settingFile->contains("phase_A_cur_change_rate_threshold_value"))
    {
    }else
    {
        settingFile->setValue("phase_A_cur_change_rate_threshold_value",0);
    }
    if(settingFile->contains("phase_B_cur_change_rate_threshold_value"))
    {
    }else
    {
        settingFile->setValue("phase_B_cur_change_rate_threshold_value",0);
    }
    if(settingFile->contains("phase_C_cur_change_rate_threshold_value"))
    {
    }else
    {
        settingFile->setValue("phase_C_cur_change_rate_threshold_value",0);
    }
    if(settingFile->contains("phase_N_cur_change_rate_threshold_value"))
    {
    }else
    {
        settingFile->setValue("phase_N_cur_change_rate_threshold_value",0);
    }

    if(settingFile->contains("phase_A_vibrate_threshold_value"))
    {
    }else
    {
        settingFile->setValue("phase_A_vibrate_threshold_value",50);
    }
    if(settingFile->contains("phase_B_vibrate_threshold_value"))
    {
    }else
    {
        settingFile->setValue("phase_B_vibrate_threshold_value",50);
    }
    if(settingFile->contains("phase_C_vibrate_threshold_value"))
    {
    }else
    {
        settingFile->setValue("phase_C_vibrate_threshold_value",50);
    }
    if(settingFile->contains("phase_N_vibrate_threshold_value"))
    {
    }else
    {
        settingFile->setValue("phase_N_vibrate_threshold_value",50);
    }
    if(settingFile->contains("vibrate_statistics_time"))
    {
    }else
    {
        settingFile->setValue("vibrate_statistics_time",5);
    }

    if(settingFile->contains("phase_Main_ratio"))
    {
    }else
    {
        settingFile->setValue("phase_Main_ratio",400);
    }
    if(settingFile->contains("phase_A_ratio"))
    {
    }else
    {
        settingFile->setValue("phase_A_ratio",40);
    }
    if(settingFile->contains("phase_B_ratio"))
    {
    }else
    {
        settingFile->setValue("phase_B_ratio",40);
    }
    if(settingFile->contains("phase_C_ratio"))
    {
    }else
    {
        settingFile->setValue("phase_C_ratio",40);
    }
    if(settingFile->contains("phase_N_ratio"))
    {
    }else
    {
        settingFile->setValue("phase_N_ratio",40);
    }
    settingFile->endGroup();
    delete settingFile;
}

void CableDataWidget::change_para(QString type, QString value)
{
    QString filePath = QString("/device_config/设备%1").arg(this->deviceID.getDeviceId().toString());
    filePath = QCoreApplication::applicationDirPath() + filePath;
    filePath = filePath + QString("/设备配置参数.ini");
    QSettings *settingFile = new QSettings(filePath, QSettings::IniFormat, 0);
    settingFile->beginGroup(QString("device-%1").arg(this->deviceID.getDeviceId().toString()));
    if(settingFile->contains(type))
    {
        if(settingFile->value(type) != value)
        {
            settingFile->setValue(type,value);
        }
    }
    settingFile->endGroup();
    delete settingFile;
}

void CableDataWidget::save_auto_get_Rt_data()
{
    QDir tmp;
    QString filePath = QString("/autogetdata/设备%1").arg(this->deviceID.getDeviceId().toString());
    filePath = QCoreApplication::applicationDirPath() + filePath;
    if(tmp.exists(filePath))
    {
    }else
    {
        if(!tmp.mkdir(filePath))
        {
            QMessageBox::warning(this,tr("错误信息"),tr("创建目录%1失败").arg(filePath),tr("确认"));
            return;
        }
    }
    if(save_rt_data_row_count == 0)
    {
        this->filePath_auto_save_rt_data = filePath + QString("/实时数据%1.xlsx").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss"));
    }else
    {
        if(save_rt_data_row_count > 9999)
        {
            this->save_rt_data_row_count = 0;
        }
    }
    this->filePath_auto_save_rt_data =  this->filePath_auto_save_rt_data.replace("/", "\\");//路径需要’\’反斜杠
    QStringList list_data;
    if(this->save_rt_data_row_count == 0)
    {
        list_data.append("时间");
        for(int i =0;i<this->ui->tableWidget->rowCount();i++)
        {
            for(int j=0;j<this->ui->tableWidget->columnCount();j++)
            {
                list_data.append(ui->tableWidget->horizontalHeaderItem(j)->text() + ui->tableWidget->verticalHeaderItem(i)->text());
            }
        }
    }else
    {
        list_data.append(QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss"));
        for(int i =0;i<this->ui->tableWidget->rowCount();i++)
        {
            for(int j=0;j<this->ui->tableWidget->columnCount();j++)
            {
                list_data.append(ui->tableWidget->item(i,j)->text());
            }
        }
    }
    emit signal_export_execel(save_rt_data_row_count,this->filePath_auto_save_rt_data,list_data);
    save_rt_data_row_count++;
}


void CableDataWidget::save_auto_get_Alarm_data()
{
    QDir tmp;
    QString filePath = QString("/autogetdata/设备%1").arg(this->deviceID.getDeviceId().toString());
    filePath = QCoreApplication::applicationDirPath() + filePath;
    if(tmp.exists(filePath))
    {
    }else
    {
        if(!tmp.mkdir(filePath))
        {
            QMessageBox::warning(this,tr("错误信息"),tr("创建目录%1失败").arg(filePath),tr("确认"));
            return;
        }
    }
    if(save_alarm_data_row_count == 0)
    {
        this->filePath_auto_save_alarm_data = filePath + QString("/报警数据%1.xlsx").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss"));
    }else
    {
        if(save_alarm_data_row_count > 9999)
        {
            this->save_alarm_data_row_count = 0;
        }
    }
    this->filePath_auto_save_alarm_data =  this->filePath_auto_save_alarm_data.replace("/", "\\");//路径需要’\’反斜杠
    QStringList list_data;
    if(this->save_alarm_data_row_count == 0)
    {
        list_data.append("时间");
        for(int i =0;i<this->ui->tableWidget_alarm_value->rowCount();i++)
        {
            for(int j=0;j<this->ui->tableWidget_alarm_value->columnCount();j++)
            {
                if(j/1)
                {
                    list_data.append(ui->tableWidget_alarm_value->horizontalHeaderItem(j)->text());
                }else
                {
                    list_data.append(ui->tableWidget_alarm_value->verticalHeaderItem(i)->text());
                }

            }
        }
    }else
    {
        list_data.append(QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss"));
        for(int i =0;i<this->ui->tableWidget_alarm_value->rowCount();i++)
        {
            for(int j=0;j<this->ui->tableWidget_alarm_value->columnCount();j++)
            {
                list_data.append(ui->tableWidget_alarm_value->item(i,j)->text());
            }
        }
    }
    emit signal_export_execel(save_alarm_data_row_count,this->filePath_auto_save_alarm_data,list_data);
    save_alarm_data_row_count++;
}
/*!
 * \brief CableDataWidget::on_checkBox_toggled
 * \param checked
 * 启动或关闭自动获取
 */
void CableDataWidget::on_checkBox_toggled(bool checked)
{
    if(checked)
    {
        this->autoGetDataTimer->setInterval(this->ui->spinBox->text().toInt()*1000);
        this->autoGetDataTimer->start();
    }else
    {
        this->autoGetDataTimer->stop();
    }
}
/*!
 * \brief CableDataWidget::on_rtcTimingPushButton_clicked
 * 时钟校时
 */
void CableDataWidget::on_rtcTimingPushButton_clicked()
{
    this->setDataFlag = true;
    this->ui->rtcTimingPushButton->setEnabled(false);
    this->sendDataFrame(comProtocol::assembleTimeSetFrame(this->deviceID.getDeviceId(),QDateTime::currentDateTime()));
    myHelper::Delay_MSec(200);
    this->ui->rtcTimingPushButton->setEnabled(true);
}
/*!
 * \brief CableDataWidget::on_rtcReadPushButton_clicked
 * 读取设备时钟
 */
void CableDataWidget::on_rtcReadPushButton_clicked()
{
    this->setDataFlag = true;
    this->sendDataFrame(comProtocol::assembleConfigReadFrame(this->deviceID.getDeviceId(),RtcTime_Set));
}
/*!
 * \brief CableDataWidget::on_statisticArgumentSetPushButton_clicked
 * 设置统计时间，周期，次数
 */
void CableDataWidget::on_statisticArgumentSetPushButton_clicked()
{
    this->ui->statisticArgumentSetPushButton->setEnabled(false);
    this->setDataFlag = true;
    this->sendDataFrame(comProtocol::assembleStatisticalArgumentFrame(this->deviceID.getDeviceId(),
                                                                      this->ui->sampleSecSpinBox->text().toInt(),
                                                                      this->ui->statisticCycleSpinBox->text().toInt(),
                                                                      this->ui->statisticCountSpinBox->text().toInt()));
    myHelper::Delay_MSec(200);
    this->ui->statisticArgumentSetPushButton->setEnabled(true);
}
/*!
 * \brief CableDataWidget::on_statisticArgumentReadPushButton_clicked
 * 读取统计参数
 */
void CableDataWidget::on_statisticArgumentReadPushButton_clicked()
{
    this->setDataFlag = true;
    this->sendDataFrame(comProtocol::assembleConfigReadFrame(this->deviceID.getDeviceId(),StatisticArgument));
}
/*!
 * \brief CableDataWidget::on_thresholdSetPushButton_clicked
 * 设置报警阀值
 */
void CableDataWidget::on_thresholdSetPushButton_clicked()
{
    this->ui->thresholdSetPushButton->setEnabled(false);
    this->setDataFlag = true;
    this->sendDataFrame(comProtocol::assembleThresholdFrame(this->deviceID.getDeviceId(),
                                                            this->ui->thresholdTypeComboBox->currentIndex()+ MainCable_Alarm_Threhold,
                                                            this->ui->thresholdValueDoubleSpinBox->text().toFloat()*1000));
    myHelper::Delay_MSec(200);
    this->ui->thresholdSetPushButton->setEnabled(true);
}
/*!
 * \brief CableDataWidget::on_thresholdReadPushButton_clicked
 * 读取报警阀值
 */
void CableDataWidget::on_thresholdReadPushButton_clicked()
{
    this->setDataFlag = true;
    this->sendDataFrame(comProtocol::assembleConfigReadFrame(this->deviceID.getDeviceId(),
                                                             this->ui->thresholdTypeComboBox->currentIndex()+MainCable_Alarm_Threhold));
}

void CableDataWidget::on_pushButton_setTempThreashold_clicked()
{
    this->ui->pushButton_setTempThreashold->setEnabled(false);
    this->setDataFlag = true;
    this->sendDataFrame(comProtocol::assembleThresholdFrame(this->deviceID.getDeviceId(),
                                                            this->ui->comboBox_TempThresholdType->currentIndex()+ GroundCablePhaseATemperature_Alarm_Threshold,
                                                            this->ui->doubleSpinBox_Temp_Threshold->text().toFloat()*100));
    myHelper::Delay_MSec(200);
    this->ui->pushButton_setTempThreashold->setEnabled(true);
}

void CableDataWidget::on_pushButton_readTempThreshold_clicked()
{
    this->setDataFlag = true;
    this->sendDataFrame(comProtocol::assembleConfigReadFrame(this->deviceID.getDeviceId(),
                                                             this->ui->comboBox_TempThresholdType->currentIndex()+GroundCablePhaseATemperature_Alarm_Threshold));
}

void CableDataWidget::sendDataToClient_slot()
{
    if((this->list_SendDataToClient.length() !=0)&&(this->blindFlag == flag_network))
    {
        emit sendDataToDevice(this->tcpClientID,this->list_SendDataToClient.at(0));
        list_SendDataToClient.removeAt(0);
    }
}
/*!
 * \brief CableDataWidget::on_ctSetPushButton_clicked
 * 是值CT变比值
 */
void CableDataWidget::on_ctSetPushButton_clicked()
{
    this->ui->ctSetPushButton->setEnabled(false);
    this->setDataFlag = true;
    this->sendDataFrame(comProtocol::assembleCtFrame(this->deviceID.getDeviceId(),
                                                     this->ui->ctTypeComboBox->currentIndex()+MainCableCtValue_Set,
                                                     this->ui->ctValueDoubleSpinBox->text().toFloat()));
    myHelper::Delay_MSec(200);
    this->ui->ctSetPushButton->setEnabled(true);
}
/*!
 * \brief CableDataWidget::on_ctReadPushButton_clicked
 * 读取CT变比值
 */
void CableDataWidget::on_ctReadPushButton_clicked()
{
    this->setDataFlag = true;
    this->sendDataFrame(comProtocol::assembleConfigReadFrame(this->deviceID.getDeviceId(),
                                                             this->ui->ctTypeComboBox->currentIndex()+MainCableCtValue_Set));
}
/*!
 * \brief CableDataWidget::on_spinBox_valueChanged
 * \param arg1
 * 更改自动获取间隔时间
 */
void CableDataWidget::on_spinBox_valueChanged(const QString &arg1)
{
    bool ok;
    uint32_t tmp = arg1.toUInt(&ok);
    if(ok)
    {
        this->autoGetDataTimer->setInterval(tmp*1000);
    }
}

void CableDataWidget::on_pushButton_clarChart_clicked()
{
    this->ui->tab_mainCable->clearAllCurves();
    this->ui->tab_groundCable->clearAllCurves();
}

void CableDataWidget::on_pushButton_ReadRtData_clicked()
{
    this->autogetDataFlag = true;
}

void CableDataWidget::on_pushButton_InputVol_clicked()
{
    this->setDataFlag = true;
    this->sendDataFrame(comProtocol::assembleReadInputVolRequestFrame(this->deviceID.getDeviceId()));
}

void CableDataWidget::on_PushButton_Temp_SetStatisticArgument_clicked()
{
    this->ui->PushButton_Temp_SetStatisticArgument->setEnabled(false);
    this->setDataFlag = true;
    this->sendDataFrame(comProtocol::assembleTempStatisticalArgumentFrame(this->deviceID.getDeviceId(),
                                                                      this->ui->SpinBox_Temp_SampleSec->text().toInt(),
                                                                      this->ui->SpinBox_Temp_StatisticCycle->text().toInt(),
                                                                      this->ui->SpinBox_Temp_StatisticCount->text().toInt()));
    myHelper::Delay_MSec(200);
    this->ui->PushButton_Temp_SetStatisticArgument->setEnabled(true);
}

void CableDataWidget::on_PushButton_Read_StatisticArgument_clicked()
{
    this->setDataFlag = true;
    this->sendDataFrame(comProtocol::assembleConfigReadFrame(this->deviceID.getDeviceId(),
                                                             TemperatureMeasureCycle));
}

void CableDataWidget::on_pushButton_SetVibrate_Threshold_clicked()
{
    this->ui->pushButton_SetVibrate_Threshold->setEnabled(false);
    this->setDataFlag = true;
    this->sendDataFrame(comProtocol::assembleSetVibrateThreshildFrame(this->deviceID.getDeviceId(),
                                                                      this->ui->comboBox_Vibate_Threshold->currentIndex() + GroundCablePhaseAVibrationCount_Alarm_Threshold,
                                                                      this->ui->doubleSpinBox_Vibrate_Threshold->text().toFloat()));
    myHelper::Delay_MSec(200);
    this->ui->pushButton_SetVibrate_Threshold->setEnabled(true);
}

void CableDataWidget::on_pushButton_ReadVibrate_Threshold_clicked()
{
    this->setDataFlag = true;
    this->sendDataFrame(comProtocol::assembleConfigReadFrame(this->deviceID.getDeviceId(),
                                                             this->ui->comboBox_Vibate_Threshold->currentIndex()+GroundCablePhaseAVibrationCount_Alarm_Threshold));
}

void CableDataWidget::on_pushButton_Read_VibrateStatisticTime_clicked()
{
    this->setDataFlag = true;
    this->sendDataFrame(comProtocol::assembleConfigReadFrame(this->deviceID.getDeviceId(),
                                                             VibrationStatisticalCycle));
}

void CableDataWidget::on_pushButton_Set_VibrateStatisticTime_clicked()
{
    this->ui->pushButton_Set_VibrateStatisticTime->setEnabled(false);
    this->setDataFlag = true;
    this->sendDataFrame(comProtocol::assembleSetVibrateTimeFrame(this->deviceID.getDeviceId(),
                                                                 this->ui->spinBox_VibrateStatisticTime->text().toInt()));
    myHelper::Delay_MSec(200);
    this->ui->pushButton_Set_VibrateStatisticTime->setEnabled(true);
}


void CableDataWidget::on_pushButton_SetCurChangeRate_Threshold_clicked()
{
    this->ui->pushButton_SetCurChangeRate_Threshold->setEnabled(false);
    this->setDataFlag = true;
    this->sendDataFrame(comProtocol::assembleSetCurChangerateThreshildFrame(this->deviceID.getDeviceId(),
                                                                      this->ui->comboBox_CurChangeRate_Threshold->currentIndex() + GroundCablePhaseAChangeRate_Alarm_Threshold,
                                                                      this->ui->doubleSpinBox_CurChangeRate_Threshold->text().toFloat()));
    myHelper::Delay_MSec(200);
    this->ui->pushButton_SetCurChangeRate_Threshold->setEnabled(true);
}

void CableDataWidget::on_pushButton_ReadCurChangeRate_Threshold_clicked()
{
    this->setDataFlag = true;
    this->sendDataFrame(comProtocol::assembleConfigReadFrame(this->deviceID.getDeviceId(),
                                                                  this->ui->comboBox_CurChangeRate_Threshold->currentIndex() + GroundCablePhaseAChangeRate_Alarm_Threshold));
}

void CableDataWidget::on_pushButton_Set_CurChangerateCycle_clicked()
{
    this->ui->pushButton_Set_CurChangerateCycle->setEnabled(false);
    this->setDataFlag = true;
    this->sendDataFrame(comProtocol::assembleSetCurChangerateCycleFrame(this->deviceID.getDeviceId(),
                                                                 this->ui->spinBox_CurChangerateCycle->text().toInt()));
    myHelper::Delay_MSec(200);
    this->ui->pushButton_Set_CurChangerateCycle->setEnabled(true);
}

void CableDataWidget::on_pushButton_Read_CurChangerateCycle_clicked()
{
    this->setDataFlag = true;
//    this->sendDataFrame(comProtocol::assembleConfigReadFrame(this->deviceID.getDeviceId(),ChangeRateStatisticalCycle));
    this->sendDataFrame(comProtocol::assembleConfigReadFrame(this->deviceID.getDeviceId(),SetChangeRateStatistical));
}

void CableDataWidget::on_pushButton_Read_CurChangerateWindowSize_clicked()
{
    this->setDataFlag = true;
    this->sendDataFrame(comProtocol::assembleConfigReadFrame(this->deviceID.getDeviceId(),ChangeRateStatisticalCycle));
}

void CableDataWidget::on_spinBox_alarm_value_valueChanged(int arg1)
{
    this->autoGetAlarmDataTimer->setInterval(arg1*1000);
}

void CableDataWidget::on_pushButton_clear_alarm_value_clicked()
{
    clear_alarm_data();
}

void CableDataWidget::on_pushButton_clear_rt_data_clicked()
{
    clear_rt_data();
}
void CableDataWidget::on_pushButton_save_rt_data_clicked()
{
    save_Rt_data();
}

void CableDataWidget::on_pushButton_save_alarm_value_clicked()
{
    save_Alarm_data();
}

void CableDataWidget::on_checkBox_statistics_value_clicked(bool checked)
{
    if(checked == true)
    {
        this->autoGetStatisticTimer->setInterval(this->ui->spinBox_statistics_value->text().toInt()*1000);
        this->autoGetStatisticTimer->start();
    }else
    {
        this->autoGetStatisticTimer->stop();
    }
}

void CableDataWidget::on_pushButton_statistics_value_clicked()
{
    this->autogetStatisticFlag = true;
}

void CableDataWidget::on_spinBox_statistics_value_valueChanged(int arg1)
{
     this->autoGetStatisticTimer->setInterval(arg1*1000);
}

void CableDataWidget::on_supperRootOperationPushButton_clicked()
{
    Dialog_InputPassWord * dialog = new Dialog_InputPassWord(this);
    dialog->show();
    if(dialog->exec())
    {
        this->ui->phaseMainControlbitsCheckBox->show();
        this->ui->phaseAControlbitsCheckBox->show();
        this->ui->phaseBControlbitsCheckBox->show();
        this->ui->phaseCControlbitsCheckBox->show();
        this->ui->phaseNControlbitsCheckBox->show();
        this->ui->channelControlReadPushButton->show();
        this->ui->channelControlSetPushButton->show();
    }else
    {
        this->ui->phaseMainControlbitsCheckBox->hide();
        this->ui->phaseAControlbitsCheckBox->hide();
        this->ui->phaseBControlbitsCheckBox->hide();
        this->ui->phaseCControlbitsCheckBox->hide();
        this->ui->phaseNControlbitsCheckBox->hide();
        this->ui->channelControlReadPushButton->hide();
        this->ui->channelControlSetPushButton->hide();
    }

    dialog->close();
    delete dialog;

}

void CableDataWidget::on_channelControlSetPushButton_clicked()
{
    quint8 controltype = 0x00;
    quint8 controlbits = 0x00;
    switch (this->ui->channelTypeComboBox->currentIndex())
    {
    case 0:
        controltype = CurrentChannelControl;
        break;
    case 1:
        controltype = TemperatureChannelControl;
        break;
    case 2:
        controltype = VibrationChannelControl;
        break;
    default:
        break;
    }
    if(controltype == CurrentChannelControl)
    {
        if(this->ui->phaseMainControlbitsCheckBox->isChecked()) {
            controlbits |= (1 << 0);
        }
        if(this->ui->phaseAControlbitsCheckBox->isChecked()) {
            controlbits |= (1 << 1);
        }
        if(this->ui->phaseBControlbitsCheckBox->isChecked()) {
            controlbits |= (1 << 2);
        }

        if(this->ui->phaseCControlbitsCheckBox->isChecked()) {
            controlbits |= (1 << 3);
        }

        if(this->ui->phaseNControlbitsCheckBox->isChecked()) {
            controlbits |= (1 << 4);
        }
//        controlbits |= (1 << 0);
    }else if(controltype == TemperatureChannelControl)
    {
        if(this->ui->phaseAControlbitsCheckBox->isChecked())
        {
            controlbits |= (1 << 0);
        }

        if(this->ui->phaseBControlbitsCheckBox->isChecked())
        {
            controlbits |= (1 << 1);
        }

        if(this->ui->phaseCControlbitsCheckBox->isChecked())
        {
            controlbits |= (1 << 2);
        }

        if(this->ui->phaseNControlbitsCheckBox->isChecked())
        {
            controlbits |= (1 << 3);
        }
    }else if(controltype == VibrationChannelControl)
    {
        if(this->ui->phaseAControlbitsCheckBox->isChecked())
        {
            controlbits |= (1 << 0);
        }

        if(this->ui->phaseBControlbitsCheckBox->isChecked())
        {
            controlbits |= (1 << 1);
        }

        if(this->ui->phaseCControlbitsCheckBox->isChecked())
        {
            controlbits |= (1 << 2);
        }

        if(this->ui->phaseNControlbitsCheckBox->isChecked())
        {
            controlbits |= (1 << 3);
        }
    }
    this->ui->channelControlSetPushButton->setEnabled(false);
    this->setDataFlag = true;
    this->sendDataFrame(comProtocol::assembleChannelControlFrame(
                            this->deviceID.getDeviceId(),controltype,controlbits));
    myHelper::Delay_MSec(200);
    this->ui->channelControlSetPushButton->setEnabled(true);
}

void CableDataWidget::on_channelControlReadPushButton_clicked()
{
    quint8 controltype = 0x00;
    switch (this->ui->channelTypeComboBox->currentIndex())
    {
    case 0:
        controltype = CurrentChannelControl;
        break;
    case 1:
        controltype = TemperatureChannelControl;
        break;
    case 2:
        controltype = VibrationChannelControl;
        break;
    default:
        break;
    }
    this->setDataFlag = true;
    this->sendDataFrame(comProtocol::assembleConfigReadFrame(this->deviceID.getDeviceId(),controltype));
}

void CableDataWidget::slot_auto_get_RT_time(bool flag, qint32 time)
{
    if(this->ui->checkBox->isChecked() != flag)
    {
        this->ui->checkBox->setChecked(flag);
    }
    if(this->ui->spinBox->value() != time)
    {
        this->ui->spinBox->setValue(time);
    }
}

void CableDataWidget::slot_auto_get_ST_time(bool flag, qint32 time)
{
    if(this->ui->checkBox_statistics_value->isChecked() != flag)
    {
        this->ui->checkBox_statistics_value->setChecked(flag);
    }
    if(this->ui->spinBox_statistics_value->value() != time)
    {
        this->ui->spinBox_statistics_value->setValue(time);
    }
}

void CableDataWidget::slot_auto_get_AL_time(bool flag, qint32 time)
{
    if(this->ui->checkBox_alarm_value->isChecked() != flag)
    {
        this->ui->checkBox_alarm_value->setChecked(flag);
    }
    if(this->ui->spinBox_alarm_value->value() != time)
    {
        this->ui->spinBox_alarm_value->setValue(time);
    }
}

void CableDataWidget::slot_stop_get_data()
{
    this->ui->checkBox->setChecked(false);
    this->ui->checkBox_statistics_value->setChecked(false);
    this->ui->checkBox_alarm_value->setChecked(false);
}

void CableDataWidget::on_checkBox_statistics_value_toggled(bool checked)
{
    if(checked)
    {

        this->autoGetStatisticTimer->setInterval(this->ui->spinBox_statistics_value->text().toInt()*1000);
        this->autoGetStatisticTimer->start();
    }else
    {
        this->autoGetStatisticTimer->stop();
    }
}

void CableDataWidget::on_checkBox_alarm_value_toggled(bool checked)
{
    if(checked)
    {
        this->autoGetAlarmDataTimer->setInterval(this->ui->spinBox_alarm_value->text().toInt()*1000);
        this->autoGetAlarmDataTimer->start();
    }else
    {
        this->autoGetAlarmDataTimer->stop();
    }
}
