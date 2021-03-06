#ifndef MONITORMAINWINDOW_H
#define MONITORMAINWINDOW_H

#include <QMainWindow>
#include <QVariant>
#include <QMetaType>
#include "myhelper.h"
#include "cabledatawidget.h"
#include "cablehistorydatawidget.h"
#include "tcpserverdevice.h"
#include "comthread.h"
#include "comsetting.h"
#include "comsettingdialog.h"
#include "deviceregisterdialog.h"
#include "QTreeWidget"
#include "databasemanager.h"
#include "comprotocol.h"
#include "hcnetmetadata.h"
#include "hcsystemmappingregisterdialog.h"
#include "hcsystemnetconfigdialog.h"
#include "apirequestserver.h"
#include "tcpclienttype.h"
#include "savetoserver.h"
#include "dialog_versions.h"
#include "dialog_set_interval_time.h"

namespace Ui {
class MonitorMainWindow;
}

class MonitorMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MonitorMainWindow(QWidget *parent = 0);
    ~MonitorMainWindow();
    void init();
    uint32_t getCnt_ComFaile();
    void setCnt_ComFaile(uint32_t cnt);

signals:
    void sendDataToDevice_signal(QByteArray data);
    void receiveDataToDevice_signal(QByteArray data);

    void sendDataToDevice_signal(int clientID,QByteArray data);
    void receiveDataToDevice_signal(int clientID,QByteArray data);

    void signal_open_server();
    void signal_close_server();

    void signal_connect_to_remote_server();
    void signal_disconnect_to_remote_server();
    void signal_send_data_to_remote_server(QByteArray data);
    void signal_set_ip_to_remote_server(QString ip);
    void signal_set_port_to_remote_server(quint16 port);
    void signal_close_DB();

    void signal_auto_get_RT_time(bool flag, qint32 time);
    void signal_auto_get_ST_time(bool flag, qint32 time);
    void signal_auto_get_AL_time(bool flag, qint32 time);
    void signal_stop_get_data();
    void signal_recv_data_to_ui(QByteArray data);
    void signal_remote_server(bool flag);
    void signal_DBdel(void);
    void signal_send_ip_to_monitor(QString ip);
    void signal_start_time_out();
private slots:
    void printDebug(int type, QString text);

    void on_action_connect_485_triggered();
    void on_action_connect_network_triggered();
    void on_action_register_device_triggered();
    void on_action_show_info_triggered();
    void on_action_data_triggered();
    void on_action_history_triggered();
    void on_action_clearLog_triggered();

    void newClientConnet_solt(int clientID,QString ip,quint16 port);
    void receiveDataFromDevice_slot(QByteArray data);
    void receiveDatFromDevice_slot(int clientID,QByteArray data);
    void sendDataToDevice_slot(int clientID,QByteArray data);
    void sendDataToDevice_slot(QByteArray data);

    void insertCableDevice(CableMonitorDevice device);
    void removeCableDevice(deviceIdType deviceid);
    void updateCableDevice(CableMonitorDevice device);

    void deviceListTreeWidgetItemClicked(QTreeWidgetItem *item, int col);//<点击设备列表 
    void on_queryPushButton_clicked();

    void on_clearCurvesPushButton_clicked();

    void on_clearDBPushButton_clicked();

    void on_action_set_map_triggered();

    void on_action_connet_server_triggered();
    //=============远端服务器=============
    void hcSendDataToServer();
    void hcSocketConnectedToServer();
    void hcSocketDisconnectedFromServer();
    void sendDataToServer_slot(deviceIdType ID,electricCableMetaData data);

    HcNetMetaData electricCableMetaData2HcNetMetaData(deviceIdType devid,electricCableMetaData data, bool *flag);

    void cnt_comFailed_slot();

    void on_action_clearCnt_triggered();

    void save_log();
    void auto_save_log();

    void slot_list_clientfd_insert(int clientfd);
    void slot_list_clientfd_remove(int clientfd);

    void slot_close_led();
    void on_action_CableMonitor_triggered();

    void slot_auto_connect();
    void on_action_auto_get_data_triggered();

    void send_rt_data_to_server(QByteArray data);
    void recv_data_from_server(QByteArray data);

    void on_scrollAreaWidgetContents_destroyed();

    void on_page_2_destroyed();

    void on_page_3_destroyed();

    void change_device_online_status(bool b_connected, QByteArray data);

private:
    Ui::MonitorMainWindow *ui;
    QList<QColor> colorList;
    int currentColorIndex;
    //=======================数据库=========================
    DataBaseManager *DBManager;
    //=====================================================
    QHash<QByteArray, CableMonitorDevice> *cableMonitorsTable; //所有设备地址
    QHash<QByteArray, CableDataWidget> *cableMonitorsTableUnbound;//未绑定设备地址和显示界面组件widget
    QList<deviceIdType> *list_unboundID;
    QList<deviceIdType> *list_unboundIDTmp;
    QHash<QByteArray, QTreeWidgetItem*> *cableMonitorItemTable;
    QHash<QTreeWidgetItem*, CableDataWidget*> *cableMonitorWidgetTable;
    QHash<QString,QTreeWidgetItem*> *cableMonitorTcpClientTable;
    //==========================================================================
    tcpServerDevice *serverDevice;
    QList<int>list_clientfd;
    QHash<int,TcpClientType>hash_client;
    //==========================================================================
    comThread *comDevice;
    QThread *comDeviceThread;
    bool com_485_Flag;
    bool network_Flag;
    bool b_reconnect;

    //=============远端服务器=============
    SaveToServer *socket_save_to_server;

    QHash<quint64, ChannelInfoType> *hcIdMappingTable;
    QList<HcNetMetaData> hcDataList;
    QString hcIPAddress;
    int hcHostPort;
    bool hcHostConnctedStatus;    
    //=============转发数据xml=============
    ApiRequestServer *apiServer;
    QThread apiThread;
    //===========================保存日志========================================
    QTimer *timer_save_log;
    //===========================通信失败计数=====================================
    QTimer *Timer_check_comFailed;
    //============================显示通信灯=====================================
#if 0
    QTimer *timer_led;
#endif /* 0 */
    //============================自动连接=====================================
    QTimer *timer_auto_connect;
};

#endif // MONITORMAINWINDOW_H
