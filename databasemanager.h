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

#define DBPATH "./ECM.db"
#define DEVICEID_TABLE QString("deviceid_table")
#define MAINCABLE_TABLE QString("maincable_table")
#define GROUNDCABLE_A_TABLE QString("groundcable_a_table")
#define GROUNDCABLE_B_TABLE QString("groundcable_b_table")
#define GROUNDCABLE_C_TABLE QString("groundcable_c_table")
#define GROUNDCABLE_N_TABLE QString("groundcable_n_table")

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

signals:

public slots:
    void insertDevice(CableMonitorDevice device);
    void removeDevice(deviceIdType devid);
    void updateDevice(CableMonitorDevice device);

    void dataSave(CableMonitorDevice devid, electricCableMetaData data);
    void dataTableSelfCheck();
    void deleteForm(QString form);

    void insertSystemMapping(quint64 hcId, ChannelInfoType channelinfo);
    void updateSystemMapping(quint64 hcId, ChannelInfoType channelinfo);
    void removeSystemMapping(quint64 hcId);
    void slot_close();
private:
    QSqlDatabase db;
    QTimer *dbSelfCheckTimer;
    void createDataTable(QString tablename);
    void createIdTable(QString tablename);
    void createSystemMappingTable(QString tablename);

    void dataTableSelfDelete(QString table);

};

#endif // DATABASEMANAGER_H
