#ifndef CABLEDATAWIDGET_H
#define CABLEDATAWIDGET_H

#include <QWidget>
#include "deviceidtype.h"
#include "cablemonitordevice.h"
#include "comprotocol.h"
#include <QThread>
#include <QAxObject>
#include <QMetaType>
#include "export_execel.h"
#include "dialog_inputpassword.h"
enum FlagType
{
    flag_undefined = 0x00,
    flag_485       = 0x01,
    flag_network   = 0x02
};

class CableCurrent;

namespace Ui {
class CableDataWidget;
}

class CableDataWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CableDataWidget(QWidget *parent = 0);
    ~CableDataWidget();
    void cableDataWidget_init();
    void cableThreshold_init();
    void setDeviceID(CableMonitorDevice ID);
    CableMonitorDevice getDeviceID();
    void setTcpClientID(int ID);
    int getTcpClientID();
    void setLabelID();
    void setLabelIP(QString ip);
    FlagType getBlindFlag();
    void setBlindFlag(FlagType flag);
    void setClientIP(QString IP);
    QString getClientIP();
    void sendDataFrame(QByteArray data);
    void upData_UI(electricCableMetaData data);
    void itemAlarm(uint row,uint col);
    void itemFault(uint row,uint col);
    void itemNormal(uint row,uint col);

    void item_fault_table(uint row,uint col);
    void item_alarm_table(uint row,uint col);
    void item_time_table(uint row,uint col,QDateTime data);
    void init_para();
    float calc_current_rate(float new_current, float old_currnet);
signals:
    void sendDataToDevice(int clientID,QByteArray data);
    void sendDataToDevice(QByteArray data);
    void sendDataToServer(QByteArray data);
    void DBsave(CableMonitorDevice ID,electricCableMetaData data);
    void DBsave(CableMonitorDevice ID,CableCurrent data);
    void sendDataToServer(deviceIdType ID,electricCableMetaData data);
    void sendDataToXml(deviceIdType ID,electricCableMetaData data);
    void signal_export_execel(int row,QString path,QStringList str_data);
private slots:
    void receiveDataFromDevice(QByteArray data);
    void connect_server_status(bool flag);
    void get_server_ip(QString ip);

    void autoGetData_slot();
    void autoGetAlarmData_slot();
    void autoGetStatistic_slot();
    void sendData_slot();
    void clear_rt_data();
    void clear_alarm_data();

    void save_auto_get_Rt_data();
    void save_auto_get_Alarm_data();
    void save_Rt_data();
    void save_Alarm_data();
    void change_para(QString type,QString value);


    void on_checkBox_toggled(bool checked);

    void on_rtcTimingPushButton_clicked();

    void on_rtcReadPushButton_clicked();

    void on_statisticArgumentSetPushButton_clicked();

    void on_statisticArgumentReadPushButton_clicked();

    void on_thresholdSetPushButton_clicked();

    void on_thresholdReadPushButton_clicked();

    void on_ctSetPushButton_clicked();

    void on_ctReadPushButton_clicked();
    void on_spinBox_valueChanged(const QString &arg1);

    void on_pushButton_ReadRtData_clicked();

    void on_pushButton_setTempThreashold_clicked();

    void on_pushButton_readTempThreshold_clicked();

    void sendDataToClient_slot();

    void on_PushButton_Temp_SetStatisticArgument_clicked();

    void on_PushButton_Read_StatisticArgument_clicked();

    void on_pushButton_SetVibrate_Threshold_clicked();

    void on_pushButton_Read_VibrateStatisticTime_clicked();

    void on_pushButton_Set_VibrateStatisticTime_clicked();

    void on_pushButton_ReadVibrate_Threshold_clicked();

    void on_pushButton_SetCurChangeRate_Threshold_clicked();

    void on_pushButton_ReadCurChangeRate_Threshold_clicked();

    void on_pushButton_Set_CurChangerateCycle_clicked();

    void on_pushButton_Read_CurChangerateCycle_clicked();

    void on_pushButton_read_alarm_value_clicked();

    void on_checkBox_alarm_value_clicked(bool checked);

    void on_spinBox_alarm_value_valueChanged(int arg1);

    void on_pushButton_clear_alarm_value_clicked();

    void on_pushButton_save_alarm_value_clicked();

    void on_supperRootOperationPushButton_clicked();

    void on_channelControlSetPushButton_clicked();

    void on_channelControlReadPushButton_clicked();

    void slot_auto_get_RT_time(bool flag, qint32 time);
    //void slot_auto_get_ST_time(bool flag, qint32 time);
    void slot_auto_get_AL_time(bool flag, qint32 time);
    void slot_stop_get_data();    
    //void on_checkBox_statistics_value_toggled(bool checked);

    void on_checkBox_alarm_value_toggled(bool checked);

    void on_tab_mainCable_destroyed();

    void on_label_34_linkActivated(const QString &link);

private:
    Ui::CableDataWidget *ui;
    QByteArray sendData;

    int tcpClientID;
    QString clientIP;
    CableMonitorDevice deviceID;
    FlagType blindFlag;

    bool is_connected_to_server;
    QString server_ip;

    QTimer *sendDataTimer;
    QTimer *autoGetDataTimer;//<自动获取实时数据定时器
    QTimer *autoGetAlarmDataTimer;//<自动获取报警数据定时器
    QTimer *autoGetStatisticTimer;//<自动获取统计数据（最大值，最小值，平均值）
    QTimer *sendDataToClient;

    bool   autogetDataFlag;
    bool   autogetStatisticFlag;
    bool   autogetAlarmDataFlag;
    bool   setDataFlag;

    float phase_Main_cable_eleCur_ThresholdValue;
    float phase_A_cable_eleCur_ThresholdValue;
    float phase_B_cable_eleCur_ThresholdValue;
    float phase_C_cable_eleCur_ThresholdValue;
    float phase_N_cable_eleCur_ThresholdValue;

    float phase_Main_cable_temp_ThresholdValue;
    float phase_A_cable_temp_ThresholdValue;
    float phase_B_cable_temp_ThresholdValue;
    float phase_C_cable_temp_ThresholdValue;
    float phase_N_cable_temp_ThresholdValue;

    float phase_Main_cable_eleCur_CT;
    float phase_A_cable_eleCur_CT;
    float phase_B_cable_eleCur_CT;
    float phase_C_cable_eleCur_CT;
    float phase_N_cable_eleCur_CT;

    union {uint uint_ground_current_A; float ground_current_A; }; //A相接地电流
    union {uint uint_ground_current_B; float ground_current_B; }; //B相接地电流
    union {uint uint_ground_current_C; float ground_current_C; }; //C相接地电流
    union {uint uint_ground_current_ALL; float ground_current_ALL; }; //总接地电流
    union {uint uint_op_current; float op_current; }; //运行电流

    float connector_temp_A; //A相接头温度
    float connector_temp_B; //B相接头温度
    float connector_temp_C; //C相接头温度
    
    int a_x_axis;
    int a_y_axis;
    int a_z_axis;
    int b_x_axis;
    int b_y_axis;
    int b_z_axis;
    int c_x_axis;
    int c_y_axis;
    int c_z_axis;

    uint runtime_in_seconds;
    float ups_vol;
    float env_temp;
    float dev_temp;
    float env_humidity;

    uint start_recv_rt_data;

    QList<QByteArray>list_SendDataToClient;
    QList<QByteArray>list_SendRtData;
    QList<QByteArray>list_SendStatisticData;
    QList<QByteArray>list_SendSetData;

    QStringList list_display_rt_data;
    QStringList list_display_Alarm_data;

    uint32_t save_rt_data_row_count;
    QString filePath_auto_save_rt_data;
    uint32_t save_alarm_data_row_count;
    QString filePath_auto_save_alarm_data;
    Export_Execel *export_execel;
};

class CableCurrent
{
public:
    CableCurrent();
    CableCurrent(float value, enum current_type type);

    enum current_type type;
    float ground_current;
    QDateTime time;
};

#endif // CABLEDATAWIDGET_H
