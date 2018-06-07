#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QThread>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <QHash>
#include <QDateTime>
#include <QTimer>
#include <QMetaType>
#include "dataconf.h"
#include "cablemonitordevice.h"
#include "electriccablemetadata.h"
#include "channelinfotype.h"
#include "cabledatawidget.h"
#include <QApplication>
#include "export_execel.h"


#define DBPATH "./CMDB.db"
#define DEVICEID_TABLE QString("deviceid_table")
#define MAINCABLE_TABLE QString("maincable_table")
#define GROUNDCABLE_A_TABLE QString("groundcable_a_table")
#define GROUNDCABLE_B_TABLE QString("groundcable_b_table")
#define GROUNDCABLE_C_TABLE QString("groundcable_c_table")
#define GROUNDCABLE_N_TABLE QString("groundcable_n_table")
#define CONNECTOR_A_TABLE QString("connector_a_table")
#define CONNECTOR_B_TABLE QString("connector_b_table")
#define CONNECTOR_C_TABLE QString("connector_c_table")

#define MAINCABLE_ALARM_TABLE QString("maincable_alarm_table")
#define GROUNDCABLE_A_ALARM_TABLE QString("groundcable_a_alarm_table")
#define GROUNDCABLE_B_ALARM_TABLE QString("groundcable_b_alarm_table")
#define GROUNDCABLE_C_ALARM_TABLE QString("groundcable_c_alarm_table")
#define GROUNDCABLE_N_ALARM_TABLE QString("groundcable_n_alarm_table")

#define CONNECTOR_A_ALARM_TABLE QString("connector_a_alarm_table")
#define CONNECTOR_B_ALARM_TABLE QString("connector_b_alarm_table")
#define CONNECTOR_C_ALARM_TABLE QString("connector_c_alarm_table")

#define MAINCABLE_RATE_ALARM_TABLE QString("maincable_rate_alarm_table")
#define GROUNDCABLE_RATE_A_ALARM_TABLE QString("groundcable_a_rate_alarm_table")
#define GROUNDCABLE_RATE_B_ALARM_TABLE QString("groundcable_b_rate_alarm_table")
#define GROUNDCABLE_RATE_C_ALARM_TABLE QString("groundcable_c_rate_alarm_table")
#define GROUNDCABLE_RATE_N_ALARM_TABLE QString("groundcable_n_rate_alarm_table")


//#define GROUNDCABLE_TEMP_A_TABLE QString("groundcable_temp_a_table")
//#define GROUNDCABLE_TEMP_B_TABLE QString("groundcable_temp_b_table")
//#define GROUNDCABLE_TEMP_C_TABLE QString("groundcable_temp_c_table")
//#define GROUNDCABLE_TEMP_N_TABLE QString("groundcable_temp_n_table")

#define SYSTEM_MAPPING_TABLE QString("system_mapping_table")
#define RECORD_MAXLIMIT 50000

class DataBaseManager : public QThread
{
    Q_OBJECT
public:
    explicit DataBaseManager(QObject *parent = 0);
    ~DataBaseManager();

    void initTables();
    QHash<QByteArray , CableMonitorDevice> readCableMonitorTable();
    QHash<quint64, ChannelInfoType> readSystemMappingList();

    QList<electricCableMetaData> queryHistoryData(deviceIdType devid, QDateTime beginTime, QDateTime endTime, enum dataType type);
    QList<CableCurrent> queryHistoryData(deviceIdType devid, QDateTime beginTime, QDateTime endTime, enum current_type type);
    void save_alarm_data_to_file(QList<CableCurrent> datalist, QString type, CableMonitorDevice devid);
signals:
    void signal_alarm_save_done();
public slots:
    void insertDevice(CableMonitorDevice device);
    void removeDevice(deviceIdType devid);
    void updateDevice(CableMonitorDevice device);

    void dataSave(CableMonitorDevice devid, electricCableMetaData data);
    void dataSave(CableMonitorDevice devid, CableCurrent data);
    void dataTableSelfCheck();
    void deleteForm(QString form);

    void insertSystemMapping(quint64 hcId, ChannelInfoType channelinfo);
    void updateSystemMapping(quint64 hcId, ChannelInfoType channelinfo);
    void removeSystemMapping(quint64 hcId);
    void slot_close();
    void dataTableDeleteAll(void);
    void collect_alarm_data(CableMonitorDevice devid);
    void DBDel_alarm(void);
private:
    QSqlDatabase db;
    QTimer *dbSelfCheckTimer;
    void createDataTable(QString tablename);
    void createIdTable(QString tablename);
    void createSystemMappingTable(QString tablename);

    void dataTableSelfDelete(QString table);
    void dataTableDelete(QString table);
    void _collect_alarm_data(CableMonitorDevice devid, enum current_type type);
    Export_Execel *export_execel;

};

#endif // DATABASEMANAGER_H
