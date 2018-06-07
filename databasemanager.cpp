#include "databasemanager.h"
#include <QSqlRecord>
#include <QDebug>
#include "qt_windows.h"
DataBaseManager::DataBaseManager(QObject *parent) :
    QThread(parent)
{
    this->db = QSqlDatabase::addDatabase("QSQLITE");
    this->db.setDatabaseName(DBPATH);


    if(this->db.open())
    {
        qDebug() << "数据库连接成功";
    }
    else
    {
        qDebug() << "数据库连接失败";
    }
    this->initTables();
    this->dbSelfCheckTimer = new QTimer();
    connect(this->dbSelfCheckTimer, SIGNAL(timeout()), this, SLOT(dataTableSelfCheck()));
    connect(this,SIGNAL(destroyed(QObject*)),this->dbSelfCheckTimer,SLOT(deleteLater()));
    this->dbSelfCheckTimer->start(3600 * 1000); //检测数据库中表的行数不超过5000行
    this->dataTableSelfCheck();

    this->export_execel = new Export_Execel();
    QThread * thread_export = new QThread();
    connect(export_execel,SIGNAL(destroyed(QObject*)),thread_export,SLOT(quit()));
    connect(thread_export,SIGNAL(finished()),thread_export,SLOT(deleteLater()));
    export_execel->moveToThread(thread_export);
    thread_export->start();
}

DataBaseManager::~DataBaseManager()
{
}

void DataBaseManager::initTables()
{
    if(this->db.isOpen() == false)
        return;

    bool deviceidtbexist = false;
    bool maincabletbexist = false;
    bool groundcableatbexit = false;
    bool groundcablebtbexit = false;
    bool groundcablectbexit = false;
    bool groundcablentbexit = false;
    bool systemmappingtbexit = false;
    bool connectoratbexit = false;
    bool connectorbtbexit = false;
    bool connectorctbexit = false;

    bool main_cable_alarm_exit = false;
    bool a_cable_alarm_exit = false;
    bool b_cable_alarm_exit = false;
    bool c_cable_alarm_exit = false;
    bool n_cable_alarm_exit = false;

    bool connectora_alarm_exit = false;
    bool connectorb_alarm_exit = false;
    bool connectorc_alarm_exit = false;

    bool main_cable_rate_alarm_exit = false;
    bool a_cable_rate_alarm_exit = false;
    bool b_cable_rate_alarm_exit = false;
    bool c_cable_rate_alarm_exit = false;
    bool n_cable_rate_alarm_exit = false;

    if(this->db.isOpen() == false)
        return;
    QSqlQuery query(this->db);
    query.exec("select name from sqlite_master");
    while(query.next())
    {
        if(query.value(0).toString() == MAINCABLE_TABLE)
        {
            qDebug() << "主缆数据存储表已建立";
            maincabletbexist = true;
        }
        else if(query.value(0).toString() == GROUNDCABLE_A_TABLE)
        {
            qDebug() << "A相接地电缆数据存储表已建立";
            groundcableatbexit = true;
        }
        else if(query.value(0).toString() == GROUNDCABLE_B_TABLE)
        {
            qDebug() << "B相接地电缆数据存储表已建立";
            groundcablebtbexit = true;
        }
        else if(query.value(0).toString() == GROUNDCABLE_C_TABLE)
        {
            qDebug() << "C相接地电缆数据存储表已建立";
            groundcablectbexit = true;
        }
        else if(query.value(0).toString() == GROUNDCABLE_N_TABLE)
        {
            qDebug() << "N相接地电缆数据存储表已建立";
            groundcablentbexit = true;
        }
        else if(query.value(0).toString() == CONNECTOR_A_TABLE)
        {
            qDebug() << "A接头温度表已建立";
            connectoratbexit = true;
        }
        else if(query.value(0).toString() == CONNECTOR_B_TABLE)
        {
            qDebug() << "B接头温度表已建立";
            connectorbtbexit = true;
        }
        else if(query.value(0).toString() == CONNECTOR_C_TABLE)
        {
            qDebug() << "C接头温度表已建立";
            connectorctbexit = true;
        }
        else if(query.value(0).toString() == DEVICEID_TABLE)
        {
            qDebug() << "设备列表已建立";
            deviceidtbexist = true;
        }
        else if(query.value(0).toString() == SYSTEM_MAPPING_TABLE)
        {
            qDebug() << "协议映射表已建立";
            systemmappingtbexit = true;
        }
        else if(query.value(0).toString() == MAINCABLE_ALARM_TABLE)
        {
            qDebug() << "主缆电流报警数据表已建立";
            main_cable_alarm_exit = true;
        }
        else if(query.value(0).toString() == GROUNDCABLE_A_ALARM_TABLE)
        {
            qDebug() << "A相电流报警数据表已建立";
            a_cable_alarm_exit = true;
        }
        else if(query.value(0).toString() == GROUNDCABLE_B_ALARM_TABLE)
        {
            qDebug() << "B相电流报警数据表已建立";
            b_cable_alarm_exit = true;
        }
        else if(query.value(0).toString() == GROUNDCABLE_C_ALARM_TABLE)
        {
            qDebug() << "C相电流报警数据表已建立";
            c_cable_alarm_exit = true;
        }
        else if(query.value(0).toString() == GROUNDCABLE_N_ALARM_TABLE)
        {
            qDebug() << "N相电流报警数据表已建立";
            n_cable_alarm_exit = true;
        }
        else if(query.value(0).toString() == CONNECTOR_A_ALARM_TABLE)
        {
            qDebug() << "A接头报警温度表已建立";
            connectora_alarm_exit = true;
        }
        else if(query.value(0).toString() == CONNECTOR_B_ALARM_TABLE)
        {
            qDebug() << "B接头报警温度表已建立";
            connectorb_alarm_exit = true;
        }
        else if(query.value(0).toString() == CONNECTOR_C_ALARM_TABLE)
        {
            qDebug() << "C接头报警温度表已建立";
            connectorc_alarm_exit = true;
        }
        else if(query.value(0).toString() == MAINCABLE_RATE_ALARM_TABLE)
        {
            qDebug() << "主缆电流变化率报警数据表已建立";
            main_cable_rate_alarm_exit = true;
        }
        else if(query.value(0).toString() == GROUNDCABLE_RATE_A_ALARM_TABLE)
        {
            qDebug() << "A相电流变化率报警数据表已建立";
            a_cable_rate_alarm_exit = true;
        }
        else if(query.value(0).toString() == GROUNDCABLE_RATE_B_ALARM_TABLE)
        {
            qDebug() << "B相电流变化率报警数据表已建立";
            b_cable_rate_alarm_exit = true;
        }
        else if(query.value(0).toString() == GROUNDCABLE_RATE_C_ALARM_TABLE)
        {
            qDebug() << "C相电流变化率报警数据表已建立";
            c_cable_rate_alarm_exit = true;
        }
        else if(query.value(0).toString() == GROUNDCABLE_RATE_N_ALARM_TABLE)
        {
            qDebug() << "N相电流变化率报警数据表已建立";
            n_cable_rate_alarm_exit = true;
        }
    }

    if(maincabletbexist == false)
    {
        qDebug() << "创建主缆数据存储表";
        createDataTable(MAINCABLE_TABLE);
    }

    if(groundcableatbexit == false)
    {
        qDebug() << "创建A相接地电缆数据存储表";
        createDataTable(GROUNDCABLE_A_TABLE);
    }

    if(groundcablebtbexit == false)
    {
        qDebug() << "创建B相接地电缆数据存储表";
        createDataTable(GROUNDCABLE_B_TABLE);
    }

    if(groundcablectbexit == false)
    {
        qDebug() << "创建C相接地电缆数据存储表";
        createDataTable(GROUNDCABLE_C_TABLE);
    }

    if(groundcablentbexit == false)
    {
        qDebug() << "创建N相接地电缆数据存储表";
        createDataTable(GROUNDCABLE_N_TABLE);
    }
    if(connectoratbexit == false)
    {
        qDebug() << "创建A接头温度表";
        createDataTable(CONNECTOR_A_TABLE);
    }
    if(connectorbtbexit == false)
    {
        qDebug() << "创建B接头温度表";
        createDataTable(CONNECTOR_B_TABLE);
    }
    if(connectorctbexit == false)
    {
        qDebug() << "创建C接头温度表";
        createDataTable(CONNECTOR_C_TABLE);
    }
    if(deviceidtbexist == false)
    {
        qDebug() << "创建设备列表";
        createIdTable(DEVICEID_TABLE);
    }

    if(systemmappingtbexit == false)
    {
        qDebug() << "创建协议映射表";
        createSystemMappingTable(SYSTEM_MAPPING_TABLE);
    }

    if(main_cable_alarm_exit == false)
    {
        qDebug() << "创建主缆电流报警数据表";
        createDataTable(MAINCABLE_ALARM_TABLE);
    }
    if(a_cable_alarm_exit == false)
    {
        qDebug() << "创建A相电流报警数据表";
        createDataTable(GROUNDCABLE_A_ALARM_TABLE);
    }
    if(b_cable_alarm_exit == false)
    {
        qDebug() << "创建B相电流报警数据表";
        createDataTable(GROUNDCABLE_B_ALARM_TABLE);
    }
    if(c_cable_alarm_exit == false)
    {
        qDebug() << "创建C相电流报警数据表";
        createDataTable(GROUNDCABLE_C_ALARM_TABLE);
    }
    if(n_cable_alarm_exit == false)
    {
        qDebug() << "创建N相电流报警数据表";
        createDataTable(GROUNDCABLE_N_ALARM_TABLE);
    }
    if(connectora_alarm_exit == false)
    {
        qDebug() << "创建A接头报警温度数据表";
        createDataTable(CONNECTOR_A_ALARM_TABLE);
    }
    if(connectorb_alarm_exit == false)
    {
        qDebug() << "创建B接头报警温度数据表";
        createDataTable(CONNECTOR_B_ALARM_TABLE);
    }
    if(connectorc_alarm_exit == false)
    {
        qDebug() << "创建C接头报警温度数据表";
        createDataTable(CONNECTOR_C_ALARM_TABLE);
    }
    if(main_cable_rate_alarm_exit == false)
    {
        qDebug() << "创建主缆电流变化率报警数据表";
        createDataTable(MAINCABLE_RATE_ALARM_TABLE);
    }
    if(a_cable_rate_alarm_exit == false)
    {
        qDebug() << "创建A相电流变化率报警数据表";
        createDataTable(GROUNDCABLE_RATE_A_ALARM_TABLE);
    }
    if(b_cable_rate_alarm_exit == false)
    {
        qDebug() << "创建B相电流变化率报警数据表";
        createDataTable(GROUNDCABLE_RATE_B_ALARM_TABLE);
    }
    if(c_cable_rate_alarm_exit == false)
    {
        qDebug() << "创建C相电流变化率报警数据表";
        createDataTable(GROUNDCABLE_RATE_C_ALARM_TABLE);
    }
    if(n_cable_rate_alarm_exit == false)
    {
        qDebug() << "创建N相电流变化率报警数据表";
        createDataTable(GROUNDCABLE_RATE_N_ALARM_TABLE);
    }
}

QHash<QByteArray, CableMonitorDevice> DataBaseManager::readCableMonitorTable()
{
    QHash<QByteArray, CableMonitorDevice> table;

    if(this->db.isOpen() == false)
        return table;

    QSqlQuery query(this->db);
    QString sqlCmd = "select * from " + DEVICEID_TABLE;
    if(query.exec(sqlCmd))
    {
        while(query.next())
        {
            QSqlRecord record = query.record();
            deviceIdType devid = deviceIdType::fromString(record.value("deviceid").toString());
            CableMonitorDevice device;

            device.setDeviceDeviceId(devid);
            device.setDeviceName(record.value("devicename").toString());
            device.setUserName(record.value("username").toString());

            table.insert(devid.toByteArray(), device);
        }
    }
    else
    {
        qCritical() << query.lastError().text();
    }
//    qDebug() << "DataBaseManager: "<< QThread::currentThreadId();
    return table;
}

QHash<quint64, ChannelInfoType> DataBaseManager::readSystemMappingList()
{
    QHash<quint64, ChannelInfoType> mappingList;

    if(this->db.isOpen() == false)
        return mappingList;

    QSqlQuery query(this->db);

    QString sqlCmd = "select * from " + SYSTEM_MAPPING_TABLE;

    if(query.exec(sqlCmd))
    {
        while(query.next())
        {
            QSqlRecord record = query.record();
            bool okflag;

            quint64 hcId;
            ChannelInfoType channelInfo;
            hcId = record.value("hcId").toULongLong();
            channelInfo.deviceId = deviceIdType::fromString(record.value("deviceid").toString(), &okflag);
            channelInfo.phase = record.value("phase").toInt();
            if(okflag)
            {
                mappingList.insert(hcId, channelInfo);
            }
        }
    }

    return mappingList;
}

QList<electricCableMetaData> DataBaseManager::queryHistoryData(deviceIdType devid, QDateTime beginTime, QDateTime endTime, dataType type)
{
    QString beginTimeStr = "datetime('" + beginTime.toString("yyyy-MM-dd hh:mm:ss") + "')";
    QString endTimeStr = "datetime('" + endTime.toString("yyyy-MM-dd hh:mm:ss") + "')";
    QString tablename;

    switch (type) {
    case MainCable_RT:
    case MainCable_AVG:
    case MainCable_MAX:
    case MainCable_MIN:
    case MainCable_Alarm:
        tablename = MAINCABLE_TABLE;
        break;
    case GroundCablePhaseA_RT:
    case GroundCablePhaseA_AVG:
    case GroundCablePhaseA_MAX:
    case GroundCablePhaseA_MIN:
    case GroundCablePhaseA_Alarm:

    case GroundCablePhaseA_Temp_RT:
    case GroundCablePhaseA_Temp_AVG:
    case GroundCablePhaseA_Temp_MAX:
    case GroundCablePhaseA_Temp_MIN:
    case GroundCablePhaseA_Temp_Alarm:
        tablename = GROUNDCABLE_A_TABLE;
        break;
    case GroundCablePhaseB_RT:
    case GroundCablePhaseB_AVG:
    case GroundCablePhaseB_MAX:
    case GroundCablePhaseB_MIN:
    case GroundCablePhaseB_Alarm:

    case GroundCablePhaseB_Temp_RT:
    case GroundCablePhaseB_Temp_AVG:
    case GroundCablePhaseB_Temp_MAX:
    case GroundCablePhaseB_Temp_MIN:
    case GroundCablePhaseB_Temp_Alarm:
        tablename = GROUNDCABLE_B_TABLE;
        break;
    case GroundCablePhaseC_RT:
    case GroundCablePhaseC_AVG:
    case GroundCablePhaseC_MAX:
    case GroundCablePhaseC_MIN:
    case GroundCablePhaseC_Alarm:

    case GroundCablePhaseC_Temp_RT:
    case GroundCablePhaseC_Temp_AVG:
    case GroundCablePhaseC_Temp_MAX:
    case GroundCablePhaseC_Temp_MIN:
    case GroundCablePhaseC_Temp_Alarm:
        tablename = GROUNDCABLE_C_TABLE;
        break;
    case GroundCablePhaseN_RT:
    case GroundCablePhaseN_AVG:
    case GroundCablePhaseN_MAX:
    case GroundCablePhaseN_MIN:
    case GroundCablePhaseN_Alarm:

    case GroundCablePhaseN_Temp_RT:
    case GroundCablePhaseN_Temp_AVG:
    case GroundCablePhaseN_Temp_MAX:
    case GroundCablePhaseN_Temp_MIN:
    case GroundCablePhaseN_Temp_Alarm:
        tablename = GROUNDCABLE_N_TABLE;
        break;
    default:
        break;
    }

    QString sqlCmd = "select  * from " + tablename + " where datetime >= " + beginTimeStr
                + " and datetime <= " + endTimeStr +
                " and deviceid = " + "'" + devid.toString() + "'"  +
                " and datatype = " +  QString::number(type)  + " order by id";
    QList<electricCableMetaData> list;
    if(this->db.isOpen() == false)
        return list;

    QSqlQuery query(this->db);
    if(query.exec(sqlCmd))
    {
        while(query.next())
        {
            QSqlRecord record = query.record();
            electricCableMetaData data;

            data.time = QDateTime::fromString(record.value("datetime").toString(),"yyyy-MM-dd hh:mm:ss");
            data.value = record.value("value").toFloat();
            data.datatype = (enum dataType)(record.value("datatype").toInt());

            list.append(data);
        }
    }
    else
    {
        qCritical() << query.lastError().text();

    }
//    qDebug() << "DataBaseManager: "<< QThread::currentThreadId();
    return list;
}

QList<CableCurrent> DataBaseManager::queryHistoryData(deviceIdType devid, QDateTime beginTime, QDateTime endTime, current_type type)
{
    QString beginTimeStr = "datetime('" + beginTime.toString("yyyy-MM-dd hh:mm:ss") + "')";
    QString endTimeStr = "datetime('" + endTime.toString("yyyy-MM-dd hh:mm:ss") + "')";
    QString tablename;

    switch (type)
    {
        case GroundCablePhaseA:
        {
            tablename = GROUNDCABLE_A_TABLE;
            break;
        }
        case GroundCablePhaseB:
        {
            tablename = GROUNDCABLE_B_TABLE;
            break;
        }
        case GroundCablePhaseC:
        {
            tablename = GROUNDCABLE_C_TABLE;
            break;
        }
        case GroundCablePhaseN:
        {
            tablename = GROUNDCABLE_N_TABLE;
            break;
        }
        case GroundCablePhaseMain:
        {
            tablename = MAINCABLE_TABLE;
            break;
        }
        case ConnectorATemp:
        {
            tablename = CONNECTOR_A_TABLE;
            break;
        }
        case ConnectorBTemp:
        {
            tablename = CONNECTOR_B_TABLE;
            break;
        }
        case ConnectorCTemp:
        {
            tablename = CONNECTOR_C_TABLE;
            break;
        }
        default:
            break;
    }

    QString sqlCmd = "select  * from " + tablename + " where datetime >= " + beginTimeStr
                + " and datetime <= " + endTimeStr +
                " and deviceid = " + "'" + devid.toString() + "'"  +
                " and datatype = " +  QString::number(type)  + " order by id";
    QList<CableCurrent> list;
    if(this->db.isOpen() == false)
        return list;

    QSqlQuery query(this->db);
    if(query.exec(sqlCmd))
    {
        while(query.next())
        {
            QSqlRecord record = query.record();
            CableCurrent data;

            data.time = QDateTime::fromString(record.value("datetime").toString(),"yyyy-MM-dd hh:mm:ss");
            data.ground_current = record.value("value").toFloat();
            data.type = (enum current_type)(record.value("datatype").toInt());

            list.append(data);
        }
    }
    else
    {
        qCritical() << query.lastError().text();

    }
//    qDebug() << "DataBaseManager: "<< QThread::currentThreadId();
    return list;
}

void DataBaseManager::insertDevice(CableMonitorDevice device)
{
    if(this->db.isOpen() == false)
        return;

    QSqlQuery query(this->db);
    query.prepare("insert into " + DEVICEID_TABLE +"(deviceid, devicename)" + " values(?, ?)");
    query.addBindValue(device.getDeviceId().toString());
    query.addBindValue(device.getDeviceName());
    if(query.exec() == false)
    {
        qCritical() << query.executedQuery();
        qCritical() << query.lastError().text();
    }
//     qDebug() << "DataBaseManager: "<< QThread::currentThreadId();
}

void DataBaseManager::removeDevice(deviceIdType devid)
{
    if(this->db.isOpen() == false)
        return;

    QSqlQuery query(this->db);
    query.prepare("delete from " + DEVICEID_TABLE + " where deviceid = " + "'" + devid.toString() + "'");
    if(query.exec() == false)
    {
        qCritical() << query.lastError().text();
    }
}

void DataBaseManager::updateDevice(CableMonitorDevice device)
{
    if(this->db.isOpen() == false)
        return;

    QSqlQuery query(this->db);
    query.prepare("update " + DEVICEID_TABLE +" set devicename = ? where deviceid = ?");
    query.addBindValue(device.getDeviceName());
    query.addBindValue(device.getDeviceId().toString());

    if(query.exec() == false)
    {
        qCritical() << query.executedQuery();
        qCritical() << query.lastError().text();
    }
}

void DataBaseManager::dataSave(CableMonitorDevice devid, electricCableMetaData data)
{

    if(this->db.isOpen() == false)
        return;

    QString tablename = "";
    switch (data.datatype) {
    case MainCable_RT:
    case MainCable_AVG:
    case MainCable_MAX:
    case MainCable_MIN:
    case MainCable_Alarm:
        tablename = MAINCABLE_TABLE;
        break;
    case GroundCablePhaseA_RT:
    case GroundCablePhaseA_AVG:
    case GroundCablePhaseA_MAX:
    case GroundCablePhaseA_MIN:
    case GroundCablePhaseA_Alarm:

    case GroundCablePhaseA_Temp_RT:
    case GroundCablePhaseA_Temp_AVG:
    case GroundCablePhaseA_Temp_MAX:
    case GroundCablePhaseA_Temp_MIN:
    case GroundCablePhaseA_Temp_Alarm:
        tablename = GROUNDCABLE_A_TABLE;
        break;
    case GroundCablePhaseB_RT:
    case GroundCablePhaseB_AVG:
    case GroundCablePhaseB_MAX:
    case GroundCablePhaseB_MIN:
    case GroundCablePhaseB_Alarm:

    case GroundCablePhaseB_Temp_RT:
    case GroundCablePhaseB_Temp_AVG:
    case GroundCablePhaseB_Temp_MAX:
    case GroundCablePhaseB_Temp_MIN:
    case GroundCablePhaseB_Temp_Alarm:
        tablename = GROUNDCABLE_B_TABLE;
        break;
    case GroundCablePhaseC_RT:
    case GroundCablePhaseC_AVG:
    case GroundCablePhaseC_MAX:
    case GroundCablePhaseC_MIN:
    case GroundCablePhaseC_Alarm:

    case GroundCablePhaseC_Temp_RT:
    case GroundCablePhaseC_Temp_AVG:
    case GroundCablePhaseC_Temp_MAX:
    case GroundCablePhaseC_Temp_MIN:
    case GroundCablePhaseC_Temp_Alarm:
        tablename = GROUNDCABLE_C_TABLE;
        break;
    case GroundCablePhaseN_RT:
    case GroundCablePhaseN_AVG:
    case GroundCablePhaseN_MAX:
    case GroundCablePhaseN_MIN:
    case GroundCablePhaseN_Alarm:

    case GroundCablePhaseN_Temp_RT:
    case GroundCablePhaseN_Temp_AVG:
    case GroundCablePhaseN_Temp_MAX:
    case GroundCablePhaseN_Temp_MIN:
    case GroundCablePhaseN_Temp_Alarm:
        tablename = GROUNDCABLE_N_TABLE;
        break;
//    case GroundCablePhaseA_Temp_RT:
//    case GroundCablePhaseA_Temp_AVG:
//    case GroundCablePhaseA_Temp_MAX:
//    case GroundCablePhaseA_Temp_MIN:
//    case GroundCablePhaseA_Temp_Alarm:
//        tablename = GROUNDCABLE_TEMP_A_TABLE;
//        break;
//    case GroundCablePhaseB_Temp_RT:
//    case GroundCablePhaseB_Temp_AVG:
//    case GroundCablePhaseB_Temp_MAX:
//    case GroundCablePhaseB_Temp_MIN:
//    case GroundCablePhaseB_Temp_Alarm:
//        tablename = GROUNDCABLE_TEMP_B_TABLE;
//        break;
//    case GroundCablePhaseC_Temp_RT:
//    case GroundCablePhaseC_Temp_AVG:
//    case GroundCablePhaseC_Temp_MAX:
//    case GroundCablePhaseC_Temp_MIN:
//    case GroundCablePhaseC_Temp_Alarm:
//        tablename = GROUNDCABLE_TEMP_C_TABLE;
//        break;
//    case GroundCablePhaseN_Temp_RT:
//    case GroundCablePhaseN_Temp_AVG:
//    case GroundCablePhaseN_Temp_MAX:
//    case GroundCablePhaseN_Temp_MIN:
//    case GroundCablePhaseN_Temp_Alarm:
//        tablename = GROUNDCABLE_TEMP_N_TABLE;
//        break;
    default:
        break;
    }

    if(tablename.isEmpty())
        return;

    QSqlQuery query(this->db);
    query.prepare("insert into " + tablename +
                  " values(NULL, :deviceid, :datatype, :datetime, :value)");
    query.bindValue(":deviceid", devid.getDeviceId().toString());
    query.bindValue(":datatype", data.datatype);
    query.bindValue(":datetime", data.time.toString("yyyy-MM-dd hh:mm:ss"));
    query.bindValue(":value", data.value);

    if(query.exec() == false)
    {
        qCritical() << query.lastError().text();
    }
//    qDebug() << QString("dataSave id:") << QThread::currentThreadId();
}

void DataBaseManager::dataSave(CableMonitorDevice devid, CableCurrent data)
{
    if(this->db.isOpen() == false)
        return;

    QString tablename = "";

    switch (data.type)
    {
        case GroundCablePhaseA:
        {
            tablename = GROUNDCABLE_A_TABLE;
            break;
        }
        case GroundCablePhaseB:
        {
            tablename = GROUNDCABLE_B_TABLE;
            break;
        }
        case GroundCablePhaseC:
        {
            tablename = GROUNDCABLE_C_TABLE;
            break;
        }
        case GroundCablePhaseN:
        {
            tablename = GROUNDCABLE_N_TABLE;
            break;
        }
        case GroundCablePhaseMain:
        {
            tablename = MAINCABLE_TABLE;
            break;
        }
        case ConnectorATemp:
        {
            tablename = CONNECTOR_A_TABLE;
            break;
        }
        case ConnectorBTemp:
        {
            tablename = CONNECTOR_B_TABLE;
            break;
        }
        case ConnectorCTemp:
        {
            tablename = CONNECTOR_C_TABLE;
            break;
        }
        case GroundCable_A_Alarm:
        {
            tablename = GROUNDCABLE_A_ALARM_TABLE;
            break;
        }
        case GroundCable_B_Alarm:
        {
            tablename = GROUNDCABLE_B_ALARM_TABLE;
            break;
        }
        case GroundCable_C_Alarm:
        {
            tablename = GROUNDCABLE_C_ALARM_TABLE;
            break;
        }
        case GroundCable_N_Alarm:
        {
            tablename = GROUNDCABLE_N_ALARM_TABLE;
            break;
        }
        case GroundCable_Main_Alarm:
        {
            tablename = MAINCABLE_ALARM_TABLE;
            break;
        }
        case GroundCablePhaseA_Rate_Alarm:
        {
            tablename = GROUNDCABLE_RATE_A_ALARM_TABLE;
            break;
        }
        case GroundCablePhaseB_Rate_Alarm:
        {
            tablename = GROUNDCABLE_RATE_B_ALARM_TABLE;
            break;
        }
        case GroundCablePhaseC_Rate_Alarm:
        {
            tablename = GROUNDCABLE_RATE_C_ALARM_TABLE;
            break;
        }
        case GroundCablePhaseN_Rate_Alarm:
        {
            tablename = GROUNDCABLE_RATE_N_ALARM_TABLE;
            break;
        }
        case GroundCablePhaseMain_Rate_Alarm:
        {
            tablename = MAINCABLE_RATE_ALARM_TABLE;
            break;
        }
        case ConnectorATemp_Alarm:
        {
            tablename = CONNECTOR_A_ALARM_TABLE;
            break;
        }
        case ConnectorBTemp_Alarm:
        {
            tablename = CONNECTOR_B_ALARM_TABLE;
            break;
        }
        case ConnectorCTemp_Alarm:
        {
            tablename = CONNECTOR_C_ALARM_TABLE;
            break;
        }
        default:
            break;
    }

    if (tablename.isEmpty())
        return;

    QSqlQuery query(this->db);
    query.prepare("insert into " + tablename +
                  " values(NULL, :deviceid, :datatype, :datetime, :value)");
    query.bindValue(":deviceid", devid.getDeviceId().toString());
    query.bindValue(":datatype", data.type);
    query.bindValue(":datetime", data.time.toString("yyyy-MM-dd hh:mm:ss"));
    query.bindValue(":value", data.ground_current);

    if(query.exec() == false)
    {
        qCritical() << query.lastError().text();
    }
}

void DataBaseManager::dataTableSelfCheck()
{
    this->dataTableSelfDelete(MAINCABLE_TABLE);
    this->dataTableSelfDelete(GROUNDCABLE_A_TABLE);
    this->dataTableSelfDelete(GROUNDCABLE_B_TABLE);
    this->dataTableSelfDelete(GROUNDCABLE_C_TABLE);
    this->dataTableSelfDelete(GROUNDCABLE_N_TABLE);
    this->dataTableSelfDelete(CONNECTOR_A_TABLE);
    this->dataTableSelfDelete(CONNECTOR_B_TABLE);
    this->dataTableSelfDelete(CONNECTOR_C_TABLE);
}

void DataBaseManager::deleteForm(QString form)
{
//    QSqlQuery query(this->db);
//    QString checkSqlCmd = "select count(*) from " + table;
//    if(query.exec(checkSqlCmd) == false)
//    {
//        qDebug() << query.lastError();
//        return;
//    }
//    query.last();
//    int tableRecordsNum = query.value(0).toInt();
////    qDebug()<<table<<":"<<tableRecordsNum;
//    if(tableRecordsNum <= RECORD_MAXLIMIT)
//        return;
//    int recordNeedDelNum = tableRecordsNum - RECORD_MAXLIMIT;
//    QString deleteSqlCmd = "delete from " + table + " where id in (" + "select id from "
//            + table + " order by id limit " + QString::number(recordNeedDelNum) + ")";
//    if(query.exec(deleteSqlCmd) == false)
//    {
//        qDebug() << query.lastError();
//    }
}

void DataBaseManager::insertSystemMapping(quint64 hcId, ChannelInfoType channelinfo)
{
    if(this->db.isOpen() == false)
        return;

    QSqlQuery query(this->db);
    query.prepare("insert into " + SYSTEM_MAPPING_TABLE + " values(NULL, ?, ?, ?)");
    query.addBindValue(QString::number(hcId));
    query.addBindValue(channelinfo.deviceId.toString());
    query.addBindValue(channelinfo.phase);

    if(query.exec() == false)
    {
        qCritical() << query.lastError().text();
    }
}

void DataBaseManager::updateSystemMapping(quint64 hcId, ChannelInfoType channelinfo)
{
    if(this->db.isOpen() == false)
        return;

    QSqlQuery query(this->db);
    query.prepare("update " + SYSTEM_MAPPING_TABLE + " set hcId = ? where deviceid = ? and phase = ?");
    query.addBindValue(QString::number(hcId));
    query.addBindValue(channelinfo.deviceId.toString());
    query.addBindValue(channelinfo.phase);

    if(query.exec() == false)
    {
        qDebug() << query.lastError().text();
    }
}

void DataBaseManager::removeSystemMapping(quint64 hcId)
{
    if(this->db.isOpen() == false)
        return;

    QSqlQuery query(this->db);
    query.prepare("delete from " + SYSTEM_MAPPING_TABLE + " where hcId = ?");
    query.addBindValue(QString::number(hcId));

    if(query.exec() == false)
    {
        qDebug() << query.lastError().text();
    }
}

void DataBaseManager::slot_close()
{
    if(this->db.isOpen())
    {
        this->db.close();
    }
//    delete this->dbSelfCheckTimer;
}

void DataBaseManager::createDataTable(QString tablename)
{
    QSqlQuery query(this->db);
    QString sqlCmd = "create table " + tablename +
            "(id INTEGER primary key autoincrement, deviceid TEXT, datatype INTEGER, datetime TEXT, value REAL)";
    if(query.exec(sqlCmd))
    {
        qDebug() << tablename << " 创建成功";
    }
    else
    {
        qCritical() << tablename << " 创建失败";
        qCritical() << query.lastError().text();
    }
}

void DataBaseManager::createIdTable(QString tablename)
{
    QSqlQuery query(this->db);
    QString sqlCmd = "create table " + tablename + "(id INTEGER primary key autoincrement, deviceid TEXT unique, devicename TEXT)";

    if(query.exec(sqlCmd))
    {
        qDebug() << tablename << " 创建成功";
    }
    else
    {
        qCritical() << tablename << " 创建失败";
        qCritical() << query.lastError().text();

    }
}

void DataBaseManager::createSystemMappingTable(QString tablename)
{
    QSqlQuery query(this->db);
    QString sqlCmd = "create table " + tablename + "(id INTEGER primary key autoincrement, hcId TEXT, deviceid TEXT , phase INTEGER)";

    if(query.exec(sqlCmd))
    {
        qDebug() << tablename << " 创建成功";
    }
    else
    {
        qCritical() << tablename << " 创建失败";
        qCritical() << query.lastError().text();

    }
}

void DataBaseManager::dataTableSelfDelete(QString table)
{
    QSqlQuery query(this->db);
    QString checkSqlCmd = "select count(*) from " + table;
    if(query.exec(checkSqlCmd) == false)
    {
        qDebug() << query.lastError();
        return;
    }
    query.last();
    int tableRecordsNum = query.value(0).toInt();
//    qDebug()<<table<<":"<<tableRecordsNum;
    if(tableRecordsNum <= RECORD_MAXLIMIT)
        return;
    int recordNeedDelNum = tableRecordsNum - RECORD_MAXLIMIT;
    QString deleteSqlCmd = "delete from " + table + " where id in (" + "select id from "
            + table + " order by id limit " + QString::number(recordNeedDelNum) + ")";
    if(query.exec(deleteSqlCmd) == false)
    {
        qDebug() << query.lastError();
    }
}

void DataBaseManager::dataTableDeleteAll(void)
{
    this->dataTableDelete(MAINCABLE_TABLE);
    this->dataTableDelete(GROUNDCABLE_A_TABLE);
    this->dataTableDelete(GROUNDCABLE_B_TABLE);
    this->dataTableDelete(GROUNDCABLE_C_TABLE);
    this->dataTableDelete(GROUNDCABLE_N_TABLE);
    this->dataTableDelete(CONNECTOR_A_TABLE);
    this->dataTableDelete(CONNECTOR_B_TABLE);
    this->dataTableDelete(CONNECTOR_C_TABLE);
}

void DataBaseManager::dataTableDelete(QString table)
{
    QSqlQuery query(this->db);
    QString checkSqlCmd = "select count(*) from " + table;
    if(query.exec(checkSqlCmd) == false)
    {
        qDebug() << query.lastError();
        return;
    }
    query.last();
    int tableRecordsNum = query.value(0).toInt();
    QString deleteSqlCmd = "delete from " + table + " where id in (" + "select id from "
            + table + " order by id limit " + QString::number(tableRecordsNum) + ")";
    if(query.exec(deleteSqlCmd) == false)
    {
        qDebug() << query.lastError();
    }
}

void DataBaseManager::DBDel_alarm(void)
{
    this->dataTableDelete(MAINCABLE_ALARM_TABLE);
    this->dataTableDelete(GROUNDCABLE_A_ALARM_TABLE);
    this->dataTableDelete(GROUNDCABLE_B_ALARM_TABLE);
    this->dataTableDelete(GROUNDCABLE_C_ALARM_TABLE);
    this->dataTableDelete(GROUNDCABLE_N_ALARM_TABLE);
    this->dataTableDelete(MAINCABLE_RATE_ALARM_TABLE);
    this->dataTableDelete(GROUNDCABLE_RATE_A_ALARM_TABLE);
    this->dataTableDelete(GROUNDCABLE_RATE_B_ALARM_TABLE);
    this->dataTableDelete(GROUNDCABLE_RATE_C_ALARM_TABLE);
    this->dataTableDelete(GROUNDCABLE_RATE_N_ALARM_TABLE);
    this->dataTableDelete(CONNECTOR_A_ALARM_TABLE);
    this->dataTableDelete(CONNECTOR_B_ALARM_TABLE);
    this->dataTableDelete(CONNECTOR_C_ALARM_TABLE);
    qDebug() << "删除完毕";
}

void DataBaseManager::save_alarm_data_to_file(QList<CableCurrent> datalist, QString type, CableMonitorDevice devid)
{
    QDir tmp;
    QString filePath = QString("/data/设备%1").arg(devid.getDeviceId().toString());
    filePath = QCoreApplication::applicationDirPath() + filePath;
    if(tmp.exists(filePath))
    {
    }else
    {
        if(!tmp.mkdir(filePath))
        {
            //QMessageBox::warning(tr("错误信息"),tr("创建目录%1失败").arg(filePath),tr("确认"));
            return;
        }
    }
    QString str_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss");
    filePath = filePath + QString("/报警数据%1").arg(str_time) + QString(" ")+ type + QString(".xlsx");
    filePath = filePath.replace("/", "\\");//路径需要’\’反斜杠
    HRESULT r = OleInitialize(0);
    if (r != S_OK && r != S_FALSE)
    {
        qWarning("Qt: Could not initialize OLE (error %x)", (unsigned int)r);
    }
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
    cell->setProperty("Value", "报警值");
    cell = first_sheet->querySubObject("Cells(int,int)", 1, 2);
    cell->setProperty("Value", "报警时间");

    for (int i=0; i < datalist.length(); i++)
    {
        cell = first_sheet->querySubObject("Cells(int,int)", 2+i, 1);
        cell->setProperty("Value", QString::number(datalist.at(i).ground_current));
        cell->setProperty("ColumnWidth", 15);  //设置单元格列宽
        cell = first_sheet->querySubObject("Cells(int,int)", 2+i, 2);
        cell->setProperty("Value", datalist.at(i).time.toString("yyyy-MM-dd hh:mm:ss"));
        cell->setProperty("ColumnWidth", 25);  //设置单元格列宽
    }

    work_book->dynamicCall("SaveAs(const QString &)", QDir::toNativeSeparators(filePath)); //转换路径不可少，否则会崩溃
    work_book->dynamicCall("Close(Boolean)", false);  //关闭文件
    excel.dynamicCall("Quit(void)");  //退出
    OleUninitialize();
}

void DataBaseManager::_collect_alarm_data(CableMonitorDevice devid, enum current_type type)
{
    QList<CableCurrent> list;
    if(this->db.isOpen() == false)
        return ;

    QString tablename;
    QString type_name;

    switch (type)
    {
        case GroundCable_A_Alarm:
        {
            tablename = GROUNDCABLE_A_ALARM_TABLE;
            type_name = "A相电流报警值";
            break;
        }
        case GroundCable_B_Alarm:
        {
            tablename = GROUNDCABLE_B_ALARM_TABLE;
            type_name = "B相电流报警值";
            break;
        }
        case GroundCable_C_Alarm:
        {
            tablename = GROUNDCABLE_C_ALARM_TABLE;
            type_name = "C相电流报警值";
            break;
        }
        case GroundCable_N_Alarm:
        {
            tablename = GROUNDCABLE_N_ALARM_TABLE;
            type_name = "N相电流报警值";
            break;
        }
        case GroundCable_Main_Alarm:
        {
            tablename = MAINCABLE_ALARM_TABLE;
            type_name = "主缆电流报警值";
            break;
        }
        case GroundCablePhaseA_Rate_Alarm:
        {
            tablename = GROUNDCABLE_RATE_A_ALARM_TABLE;
            type_name = "A相电流变化率报警值";
            break;
        }
        case GroundCablePhaseB_Rate_Alarm:
        {
            tablename = GROUNDCABLE_RATE_B_ALARM_TABLE;
            type_name = "B相电流变化率报警值";
            break;
        }
        case GroundCablePhaseC_Rate_Alarm:
        {
            tablename = GROUNDCABLE_RATE_C_ALARM_TABLE;
            type_name = "C相电流变化率报警值";
            break;
        }
        case GroundCablePhaseN_Rate_Alarm:
        {
            tablename = GROUNDCABLE_RATE_N_ALARM_TABLE;
            type_name = "N相电流变化率报警值";
            break;
        }
        case GroundCablePhaseMain_Rate_Alarm:
        {
            tablename = MAINCABLE_RATE_ALARM_TABLE;
            type_name = "主缆电流变化率报警值";
            break;
        }
        case ConnectorATemp_Alarm:
        {
            tablename = CONNECTOR_A_ALARM_TABLE;
            type_name = "A相温度报警值";
            break;
        }
        case ConnectorBTemp_Alarm:
        {
            tablename = CONNECTOR_B_ALARM_TABLE;
            type_name = "B相温度报警值";
            break;
        }
        case ConnectorCTemp_Alarm:
        {
            tablename = CONNECTOR_C_ALARM_TABLE;
            type_name = "C相温度报警值";
            break;
        }
        default:
            break;
    }

    QDateTime frameTime;
    frameTime = QDateTime::currentDateTime();
    QString beginTimeStr = "datetime('1970-01-01 00:00:00')";
    QString endTimeStr = "datetime('" + frameTime.toString("yyyy-MM-dd hh:mm:ss") + "')";
    
    QString sqlCmd = "select  * from " + tablename + " where datetime >= " + beginTimeStr
                + " and datetime <= " + endTimeStr +
                " and deviceid = " + "'" + devid.getDeviceId().toString() + "'"  +
                " and datatype = " +  QString::number(type)  + " order by id";

    QSqlQuery query(this->db);
    if(query.exec(sqlCmd))
    {
        while(query.next())
        {
            QSqlRecord record = query.record();
            CableCurrent data;

            data.time = QDateTime::fromString(record.value("datetime").toString(),"yyyy-MM-dd hh:mm:ss");
            data.ground_current = record.value("value").toFloat();
            data.type = (enum current_type)(record.value("datatype").toInt());
            list.append(data);
        }
    }
    else
    {
        qCritical() << query.lastError().text();

    }

    save_alarm_data_to_file(list, type_name, devid);
    //emit signal_send_alarm_data(list);
}

void DataBaseManager::collect_alarm_data(CableMonitorDevice devid)
{
    _collect_alarm_data(devid, GroundCable_A_Alarm);
    qDebug() << "A相电流报警值保存成功";
    _collect_alarm_data(devid, GroundCable_B_Alarm);
    qDebug() << "B相电流报警值保存成功";
    _collect_alarm_data(devid, GroundCable_C_Alarm);
    qDebug() << "C相电流报警值保存成功";
    _collect_alarm_data(devid, GroundCable_N_Alarm);
    qDebug() << "N相电流报警值保存成功";
    _collect_alarm_data(devid, GroundCable_Main_Alarm);
    qDebug() << "主缆电流报警值保存成功";
    _collect_alarm_data(devid, GroundCablePhaseA_Rate_Alarm);
    qDebug() << "A相电流变化率报警值保存成功";
    _collect_alarm_data(devid, GroundCablePhaseB_Rate_Alarm);
    qDebug() << "B相电流变化率报警值保存成功";
    _collect_alarm_data(devid, GroundCablePhaseC_Rate_Alarm);
    qDebug() << "C相电流变化率报警值保存成功";
    _collect_alarm_data(devid, GroundCablePhaseN_Rate_Alarm);
    qDebug() << "N相电流变化率报警值保存成功";
    _collect_alarm_data(devid, GroundCablePhaseMain_Rate_Alarm);
    qDebug() << "主缆电流变化率报警值保存成功";
    _collect_alarm_data(devid, ConnectorATemp_Alarm);
    qDebug() << "A相温度报警值保存成功";
    _collect_alarm_data(devid, ConnectorBTemp_Alarm);
    qDebug() << "B相温度报警值保存成功";
    _collect_alarm_data(devid, ConnectorCTemp_Alarm);
    qDebug() << "C相温度报警值保存成功";
    QDebug(QtCriticalMsg) << "全部报警数据保存完毕";
    emit signal_alarm_save_done();
}

