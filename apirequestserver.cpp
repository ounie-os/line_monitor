#include "apirequestserver.h"
#include "databasemanager.h"

#include <QSqlRecord>
#include <QDomDocument>
#include <QSettings>
#define DBTEMPPATH "./tempData.db"

//添加温度
#define TEST_ADD_TEMP

ApiRequestServer::ApiRequestServer(QObject *parent) :
    QThread(parent)
{
    this->netServer = new QTcpServer();
    this->db = QSqlDatabase::addDatabase("QSQLITE","qt_sql");
    this->db.setDatabaseName(DBTEMPPATH);

    if(this->db.open())
    {
        qDebug() << "临时数据库连接成功";
    }
    else
    {
        qDebug() << "临时数据库连接失败";
    }

    QSettings settingFile("./config.ini", QSettings::IniFormat, 0);
    settingFile.beginGroup("API_SERVER_PORT");
    QStringList keys = settingFile.allKeys();

    if(keys.contains("Port")) {
        this->serverPort = settingFile.value("Port").toInt();
    } else {
        this->serverPort = 8421;
        settingFile.setValue("Port","8421");
    }
    settingFile.endGroup();
    connect(this->netServer, SIGNAL(newConnection()), this, SLOT(newConnectionSetup()));

    this->netServer->listen(QHostAddress::Any, this->serverPort);
}

ApiRequestServer::~ApiRequestServer()
{
    delete this->netServer;
    this->db.close();
}

void ApiRequestServer::insertTempDataTable(QString id)
{
    QString tablename = "tempdata_table_" + id;
    createTempDataTable(tablename);
}

void ApiRequestServer::newConnectionSetup()
{
    QTcpSocket *socket = this->netServer->nextPendingConnection();

    qDebug() << socket->peerAddress().toString() << " 连接到API服务器";
    ApiRequestSocket *api_socket = new ApiRequestSocket(socket);

    connect(api_socket, SIGNAL(disconnected()), this, SLOT(connectionDestroy()));
    connect(api_socket, SIGNAL(requestDataSignal(deviceIdType)), this, SLOT(requestTempData(deviceIdType)));
}

void ApiRequestServer::connectionDestroy()
{
    ApiRequestSocket *api_socket = (ApiRequestSocket*)this->sender();
    delete api_socket;
}

void ApiRequestServer::requestTempData(deviceIdType devid)
{
    if(this->db.isOpen() == false)
    {
        return;
    }
    QDomDocument xmlDoc;
    QDomElement root;
    QDomProcessingInstruction instruction;
    instruction = xmlDoc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"utf-8\"");
    xmlDoc.appendChild(instruction);
    root = xmlDoc.createElement("result");
    root.setAttribute("type", "realtimedata");
    root.setAttribute("id", devid.toString());
    xmlDoc.appendChild(root);

    QString tablename = "tempdata_table_" + devid.toString();
    QSqlQuery query(this->db);
    query.prepare("select * from " + tablename + " where datatype = ? or datatype = ? or datatype = ? or datatype = ? or datatype = ?" +
                  " or datatype = ? or datatype = ? or datatype = ? or datatype = ? or datatype = ? " +
                  " or datatype = ? or datatype = ? or datatype = ? or datatype = ?" +
                  " or datatype = ? or datatype = ? or datatype = ? or datatype = ?"
                  );
    query.addBindValue(MainCable_RT);
    query.addBindValue(GroundCablePhaseA_RT);
    query.addBindValue(GroundCablePhaseB_RT);
    query.addBindValue(GroundCablePhaseC_RT);
    query.addBindValue(GroundCablePhaseN_RT);
    query.addBindValue(MainCable_Alarm);
    query.addBindValue(GroundCablePhaseA_Alarm);
    query.addBindValue(GroundCablePhaseB_Alarm);
    query.addBindValue(GroundCablePhaseC_Alarm);
    query.addBindValue(GroundCablePhaseN_Alarm);
#ifdef TEST_ADD_TEMP
    query.addBindValue(GroundCablePhaseA_Temp_RT);
    query.addBindValue(GroundCablePhaseB_Temp_RT);
    query.addBindValue(GroundCablePhaseC_Temp_RT);
    query.addBindValue(GroundCablePhaseN_Temp_RT);

    query.addBindValue(GroundCablePhaseA_Temp_Alarm);
    query.addBindValue(GroundCablePhaseB_Temp_Alarm);
    query.addBindValue(GroundCablePhaseC_Temp_Alarm);
    query.addBindValue(GroundCablePhaseN_Temp_Alarm);
#endif

    if(query.exec())
    {
        while(query.next())
        {
            QSqlRecord record = query.record();
            if(record.value("value").isNull())
                continue;

            qDebug() << record.value("datetime").toDateTime().toString("yyyy-MM-dd hh:mm:ss") << " " << record.value("value").toFloat();
            QString nodeName;
            switch (record.value("datatype").toInt()) {
            case MainCable_RT:
                nodeName = "MainCable_RT_Data";
                break;
            case GroundCablePhaseA_RT:
                nodeName = "GroundCablePhaseA_RT_Data";
                break;
            case GroundCablePhaseB_RT:
                nodeName = "GroundCablePhaseB_RT_Data";
                break;
            case GroundCablePhaseC_RT:
                nodeName = "GroundCablePhaseC_RT_Data";
                break;
            case GroundCablePhaseN_RT:
                nodeName = "GroundCablePhaseN_RT_Data";
                break;

            case MainCable_Alarm:
                nodeName = "MainCable_Alarm_Data";
                break;
            case GroundCablePhaseA_Alarm:
                nodeName = "GroundCablePhaseA_Alarm_Data";
                break;
            case GroundCablePhaseB_Alarm:
                nodeName = "GroundCablePhaseB_Alarm_Data";
                break;
            case GroundCablePhaseC_Alarm:
                nodeName = "GroundCablePhaseC_Alarm_Data";
                break;
            case GroundCablePhaseN_Alarm:
                nodeName = "GroundCablePhaseN_Alarm_Data";
                break;
#ifdef TEST_ADD_TEMP
            case GroundCablePhaseA_Temp_RT:
                nodeName = "GroundCablePhaseA_Temp_Data";
                break;
            case GroundCablePhaseB_Temp_RT:
                nodeName = "GroundCablePhaseB_Temp_Data";
                break;
            case GroundCablePhaseC_Temp_RT:
                nodeName = "GroundCablePhaseC_Temp_Data";
                break;
            case GroundCablePhaseN_Temp_RT:
                nodeName = "GroundCablePhaseN_Temp_Data";
                break;

            case GroundCablePhaseA_Temp_Alarm:
                nodeName = "GroundCablePhaseA_Temp_Alarm_Data";
                break;
            case GroundCablePhaseB_Temp_Alarm:
                nodeName = "GroundCablePhaseB_Temp_Alarm_Data";
                break;
            case GroundCablePhaseC_Temp_Alarm:
                nodeName = "GroundCablePhaseC_Temp_Alarm_Data";
                break;
            case GroundCablePhaseN_Temp_Alarm:
                nodeName = "GroundCablePhaseN_Temp_Alarm_Data";
                break;
#endif
            default:
                break;
            }
            QDomElement newElem = xmlDoc.createElement(nodeName);
            newElem.toElement().setAttribute("timestamp", record.value("datetime").toDateTime().toString("yyyy-MM-dd hh:mm:ss"));
            newElem.toElement().setAttribute("value", record.value("value").toDouble());
            root.appendChild(newElem);
        }
    }
    else
    {
        qCritical() << query.lastError().text();
    }

    QString str;
    QTextStream stream(&str, QIODevice::ReadWrite);
    xmlDoc.save(stream, 4);

    ApiRequestSocket *socket = (ApiRequestSocket*)(QObject::sender());

    socket->writeToNet(str);

}

void ApiRequestServer::dataUpdate(deviceIdType devid, electricCableMetaData data)
{
    if(this->db.isOpen() == false)
    {
        return;
    }

//    QString tablename = "tempdata_table_" + devid.toString();
//    QSqlQuery query(this->db);
//    query.prepare("update " + tablename + "set deviceid = ?,set datetime = ? ,set value = ? where datatype = ?");
//    query.addBindValue(devid.toString());
//    query.addBindValue(data.time.toString());
//    query.addBindValue(data.value);
//    query.addBindValue(data.datatype);

    QString tablename = "tempdata_table_" + devid.toString();
    QSqlQuery query(this->db);
    query.prepare("update " + tablename + " set deviceid = ?, datetime = ? ,value = ? ,updatetime = ? where datatype = ?");
    query.addBindValue(devid.toString());
    query.addBindValue(data.time.toString("yyyy-MM-dd hh:mm:ss"));
    query.addBindValue(data.value);
    query.addBindValue(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    query.addBindValue(data.datatype);

    if(query.exec() == false)
    {
        qCritical() << query.lastError().text();
    }
}

void ApiRequestServer::createTempDataTable(QString tablename)
{
    QSqlQuery query(this->db);
    query.prepare("select count(*) from sqlite_master where name = ?");//<收索数据库中表格名称
    query.addBindValue(tablename);
    if(query.exec())
    {
        query.next();
        if(1 == query.value(0).toInt())  //<表存在
        {
            return;
        }
    }else
    {
        qDebug() << query.lastError().text();
        return;
    }

    //==================创建新的表
    QString sqlCmd = "create table " + tablename +
            "(id INTEGER primary key autoincrement, deviceid TEXT, datatype INTEGER, datetime TEXT, value REAL, updatetime TEXT)";
    if(query.exec(sqlCmd))
    {
        qDebug() << "临时数据表" << tablename << " 创建成功";
    }
    else
    {
        qCritical() << tablename << " 创建失败";
        qCritical() << query.lastError().text();
    }

    for(int i = 1; i <= GroundCablePhaseN_Ratio_Warning; i++)
    {
//        query.prepare("insert into " + tablename +
//                      " values(NULL,NULL, :datatype, NULL, NULL)");
        query.prepare("insert into " + tablename +
                      " values(NULL,NULL,?, NULL, NULL,NULL)");
        query.addBindValue(i);
        if(query.exec() == false)
        {
            qDebug() << query.lastError().text();
        }
    }
}
