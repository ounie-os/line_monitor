
#include "monitormainwindow.h"
#include "ui_monitormainwindow.h"

/*!
  *Q_DECLARE_METATYPE
  *将自定义类型在QVariant中使用
  *如果要使自定义类型或其他非QMetaType内置类型在QVariant中使用，必须使用该宏。
  *该类型必须有公有的 构造、析构、复制构造 函数
  */
Q_DECLARE_METATYPE(CableMonitorDevice)
Q_DECLARE_METATYPE(deviceIdType)
Q_DECLARE_METATYPE(ChannelInfoType)
Q_DECLARE_METATYPE(TcpClientType)
/*!
 * \brief MonitorMainWindow::MonitorMainWindow
 * \param parent
 * 作者 ：刘峰
 * 时间：2017-07-30
 * 未完成工作：
 * 1.检查设备是否会向终端发送心跳包（可以绑定客户端一地址，不需要轮询查看）没有心跳包
 * 2.绑定标志 (默认为485)；
 * 3.网络端和485端列表需要区分
 * 4.收到数据设备列表对应的item变色（检查是否在正常通信）
 * 5.数据显示界面修改
 * 6.曲线图
 * 7.数据库
 * 8.远端服务器转发
 */
/*!
 * \brief MonitorMainWindow::MonitorMainWindow
 * \param parent
 * 作者 ：刘峰
 * 时间：2017-08-17
 * 未完成工作：
 * 3.网络端和485端列表需要区分
 * 4.收到数据设备列表对应的item变色（检查是否在正常通信）
 * 5.数据显示界面修改
 * 6.曲线图
 * 7.数据库
 * 8.远端服务器转发
 */

/*!
 * \brief MonitorMainWindow::MonitorMainWindow
 * \param parent
 * 作者 ：刘峰
 * 时间：2017-08-25
 * 未完成工作：
 * 通过XML 转发数据
 * 多个网络设备接受数据是否需要队列缓存
 * 温度存储
 * 温度转发
 */
uint32_t CNT_COM = 0;
MonitorMainWindow::MonitorMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MonitorMainWindow)
{
    ui->setupUi(this);
//    QSettings *settingFile = new QSettings("./threshold.ini", QSettings::IniFormat, 0);
//    settingFile->clear();
//    delete settingFile;
    colorList.append(Qt::darkBlue);
    colorList.append(Qt::darkRed);
    colorList.append(Qt::darkGreen);
    colorList.append(Qt::darkCyan);
    colorList.append(Qt::darkMagenta);
    colorList.append(Qt::darkYellow);
    this->currentColorIndex = 0;
//    this->ui->textBrowser->document()->setMaximumBlockCount(1000);
    CNT_COM = 0;
    QDir tmp;
    if(tmp.exists(QCoreApplication::applicationDirPath()+"/data"))
    {

    }else
    {
        if(!tmp.mkdir(QCoreApplication::applicationDirPath()+"/data"))
        {
            QMessageBox::warning(this,tr("错误信息"),tr("创建目录data失败"),tr("确认"));
            return;
        }
    }
    if(tmp.exists(QCoreApplication::applicationDirPath()+"/autogetdata"))
    {

    }else
    {
        if(!tmp.mkdir(QCoreApplication::applicationDirPath()+"/autogetdata"))
        {
            QMessageBox::warning(this,tr("错误信息"),tr("创建目录autogetdata失败"),tr("确认"));
            return;
        }
    }
    if(tmp.exists(QCoreApplication::applicationDirPath()+"/device_config"))
    {

    }else
    {
        if(!tmp.mkdir(QCoreApplication::applicationDirPath()+"/device_config"))
        {
            QMessageBox::warning(this,tr("错误信息"),tr("创建目录device_config失败"),tr("确认"));
            return;
        }
    }
    this->ui->treeWidget_deviceList->setColumnWidth(0,220);
    this->ui->treeWidget_deviceList->setColumnWidth(1,10);
}

MonitorMainWindow::~MonitorMainWindow()
{
    save_log();
    emit signal_disconnect_to_remote_server();
//    emit signal_close_DB();
    delete ui;
    this->comDevice->exit();
    this->comDeviceThread->exit();
    this->comDeviceThread->deleteLater();

    this->serverDevice->deleteLater();

    this->cableMonitorsTable->clear();
    delete this->cableMonitorsTable;
    this->list_unboundID->clear();
    delete this->list_unboundID;
    this->list_unboundIDTmp->clear();
    delete this->list_unboundIDTmp;
    this->cableMonitorItemTable->clear();
    delete this->cableMonitorItemTable;
    this->cableMonitorWidgetTable->clear();
    delete this->cableMonitorWidgetTable;
    this->cableMonitorTcpClientTable->clear();
    delete this->cableMonitorTcpClientTable;

    this->hcIdMappingTable->clear();
    delete this->hcIdMappingTable;

    delete this->apiServer;
    this->socket_save_to_server->deleteLater();
    this->DBManager->deleteLater();
    delete this->timer_save_log;
    delete this->Timer_check_comFailed;
    delete timer_led;
}
/*!
 * \brief MonitorMainWindow::init
 */
void MonitorMainWindow::init()
{
    //============添加列表==============
    this->cableMonitorsTable = new QHash<QByteArray, CableMonitorDevice>();
    this->list_unboundID = new QList<deviceIdType>();
    this->list_unboundIDTmp = new QList<deviceIdType>();
    this->list_unboundIDTmp->clear();
    this->cableMonitorItemTable = new QHash<QByteArray, QTreeWidgetItem*>();
    this->cableMonitorWidgetTable = new QHash<QTreeWidgetItem*, CableDataWidget*>();
    this->cableMonitorTcpClientTable = new QHash<QString,QTreeWidgetItem*>();
    //============网络通信线程==============
    list_clientfd.clear();
    hash_client.clear();
    this->serverDevice          = new tcpServerDevice();
    QThread *thread_server      = new QThread();
    connect(this->serverDevice,SIGNAL(destroyed(QObject*)),thread_server,SLOT(quit()));
    connect(thread_server,SIGNAL(finished()),thread_server,SLOT(deleteLater()));

    connect(this->serverDevice,SIGNAL(signal_client_newconnect_to_ui(int,QString,quint16)),SLOT(newClientConnet_solt(int,QString,quint16)));
    connect(this->serverDevice,SIGNAL(signal_client_disconnect_to_ui(int)),this,SLOT(slot_list_clientfd_remove(int)));
    connect(this->serverDevice,SIGNAL(signal_send_data_to_ui(int,QByteArray)),this,SLOT(receiveDatFromDevice_slot(int,QByteArray)));

    connect(this,SIGNAL(signal_open_server()),this->serverDevice,SLOT(slot_open_server()));
    connect(this,SIGNAL(signal_close_server()),this->serverDevice,SLOT(slot_close_server()));
    connect(this,SIGNAL(sendDataToDevice_signal(int,QByteArray)),this->serverDevice,SLOT(slot_send_data_to_client(int,QByteArray)));

    this->serverDevice->moveToThread(thread_server);
    thread_server->start();

    //============485通信线程==============
    this->comDevice             = new comThread();
    this->comDeviceThread       = new QThread();
    this->comDevice->moveToThread(comDeviceThread);
    connect(this,SIGNAL(sendDataToDevice_signal(QByteArray)),
            this->comDevice,SLOT(sendDataToDevice_slot(QByteArray)),Qt::QueuedConnection);
//    connect(this,SIGNAL(sendDataToDevice_signal(QByteArray)),
//            this->comDevice,SLOT(sendDataToDevice_slot(QByteArray)));
    connect(this->comDevice,SIGNAL(receiveDataFromDevice(QByteArray)),
            this,SLOT(receiveDataFromDevice_slot(QByteArray)));
    connect(this->comDevice,SIGNAL(destroyed(QObject*)),
            comDeviceThread,SLOT(quit()));

    comDeviceThread->start();
    //============转发数据xml==============
//    this->apiServer = new ApiRequestServer();
    //============数据库线程==============
    this->DBManager = new DataBaseManager();
    QThread *workThread = new QThread();
    *cableMonitorsTable = this->DBManager->readCableMonitorTable();///<读取设备列表

    this->apiServer = new ApiRequestServer();
    QList<CableMonitorDevice> deviceList = this->cableMonitorsTable->values();
    for(int i = 0 ; i < deviceList.length(); i++)
    {
        this->insertCableDevice(deviceList.value(i));
    }
    connect(this->DBManager,SIGNAL(destroyed(QObject*)),workThread,SLOT(quit()));
    connect(this->DBManager,SIGNAL(finished()),workThread,SLOT(deleteLater()));
    connect(this,SIGNAL(signal_close_DB()),this->DBManager,SLOT(slot_close()));
    this->DBManager->moveToThread(workThread);
    workThread->start();
    //=============远端服务器=============
    socket_save_to_server = new SaveToServer();
    QThread *thread_socket = new QThread();
    connect(socket_save_to_server,SIGNAL(destroyed(QObject*)),thread_socket,SLOT(quit()));
    connect(thread_socket,SIGNAL(finished()),thread_socket,SLOT(deleteLater()));

    connect(this,SIGNAL(signal_connect_to_remote_server()),socket_save_to_server,SLOT(slot_open()));
    connect(this,SIGNAL(signal_disconnect_to_remote_server()),socket_save_to_server,SLOT(slot_close()));
    connect(this,SIGNAL(signal_send_data_to_remote_server(QByteArray)),socket_save_to_server,SLOT(slot_send_data_to_server(QByteArray)));
    connect(this,SIGNAL(signal_set_ip_to_remote_server(QString)),socket_save_to_server,SLOT(set_ip(QString)));
    connect(this,SIGNAL(signal_set_port_to_remote_server(quint16)),socket_save_to_server,SLOT(set_port(quint16)));
    connect(this->socket_save_to_server, SIGNAL(connected()), this, SLOT(hcSocketConnectedToServer()));
    connect(this->socket_save_to_server, SIGNAL(disconnected()), this, SLOT(hcSocketDisconnectedFromServer()));
    connect(this->socket_save_to_server,SIGNAL(readyRead()),this->socket_save_to_server,SLOT(slot_recv_data_from_server()));
    connect(this->socket_save_to_server, SIGNAL(signal_data_from_server_to_ui(QByteArray)), this, SLOT(recv_data_from_server(QByteArray)));
    
    socket_save_to_server->moveToThread(thread_socket);
    thread_socket->start();
    this->hcIdMappingTable = new QHash<quint64, ChannelInfoType>();
    this->hcHostConnctedStatus = false;
    *hcIdMappingTable = this->DBManager->readSystemMappingList();
    QSettings settingFile("./config.ini",  QSettings::IniFormat, 0);
    settingFile.beginGroup("HcSystemNetConfig");
    QStringList keys = settingFile.allKeys();
    if(keys.contains("IPAddress"))
    {
        this->hcIPAddress = settingFile.value("IPAddress").toString();
        emit signal_set_ip_to_remote_server(settingFile.value("IPAddress").toString());
    }
    else
    {
        this->hcIPAddress = "120.24.14.110";
        emit signal_set_ip_to_remote_server("120.24.14.110");
    }

    if(keys.contains("Port"))
    {
        this->hcHostPort = settingFile.value("Port").toInt();
    }
    else
    {
        this->hcHostPort = 2010;
        emit signal_set_port_to_remote_server(3005);
    }
    settingFile.endGroup();

    //=============转发数据xml============
//    this->apiServer = new ApiRequestServer();
//    this->apiServer->moveToThread(&apiThread);
//    apiThread.start();
//    connect(this->apiServer,SIGNAL(destroyed(QObject*)),&apiThread,SLOT(quit()));
    //=============点击设备列表============
    connect(this->ui->treeWidget_deviceList,
            SIGNAL(itemClicked(QTreeWidgetItem*,int)),
            this, SLOT(deviceListTreeWidgetItemClicked(QTreeWidgetItem*,int)));
    this->ui->action_show_info->setChecked(true);

    //============保存日志==============
    this->timer_save_log = new QTimer();
    this->timer_save_log->setInterval(30*60*1000);
    connect(this->timer_save_log,SIGNAL(timeout()),this,SLOT(auto_save_log()));
    this->timer_save_log->start();


    this->Timer_check_comFailed = new QTimer(this);
    this->Timer_check_comFailed->setInterval(100);
    this->Timer_check_comFailed->start();
    connect(this->Timer_check_comFailed,SIGNAL(timeout()),this,SLOT(cnt_comFailed_slot()));
    this->timer_led = new QTimer();
    this->timer_led->setInterval(1000);
    connect(this->timer_led,SIGNAL(timeout()),this,SLOT(slot_close_led()));
    this->timer_led->start();
    //============自动连接==============
    this->network_Flag = false;
    this->timer_auto_connect = new QTimer();
    connect(this->timer_auto_connect,  SIGNAL(timeout()), this, SLOT(slot_auto_connect()));
    this->timer_auto_connect->start(5000);
}
/*!
 * \brief MonitorMainWindow::printDebug
 * \param type
 * \param text
 * 输除调试信息
 */
void MonitorMainWindow::printDebug(int type, QString text)
{
    switch (type) {
    case QtDebugMsg:
        this->ui->textBrowser->setTextColor(Qt::black);
        break;
    case QtWarningMsg:
        this->ui->textBrowser->setTextColor(Qt::yellow);
        break;
    case QtCriticalMsg:
        this->ui->textBrowser->setTextColor(Qt::red);
        break;
    case QtFatalMsg:
        this->ui->textBrowser->setTextColor(Qt::darkRed);
        break;
    default:
        break;
    }
    this->ui->textBrowser->append(QDateTime::currentDateTime().toString(
                                      "yyyy-MM-dd hh:mm:ss") + "：" +text);
    QTextCursor cursor = this->ui->textBrowser->textCursor();
    cursor.movePosition(QTextCursor::End);
    this->ui->textBrowser->setTextCursor(cursor);
//    qDebug()<< this->ui->textBrowser->document()->blockCount();
}
/*!
 * \brief MonitorMainWindow::on_action_connect_485_triggered
 * 485通讯方式
 */
void MonitorMainWindow::on_action_connect_485_triggered()
{
    if(this->comDevice->isComConnected())
    {
        this->comDevice->comDisconnect();
        this->ui->action_connect_485->setText(tr("485通讯连接"));
        qWarning()<<"485通讯断开";
        this->comDevice->quit();
        this->com_485_Flag = false;
        this->ui->action_connect_network->setEnabled(true);
    }else
    {
        comSettingDialog *dialog = new comSettingDialog(this);
        dialog->setWindowFlags(Qt::Dialog);
        dialog->setWindowModality(Qt::ApplicationModal);
        dialog->setupComSetting(this->comDevice->getComSetting());
        dialog->show();
        if(dialog->exec() == QDialog::Accepted)
        {
            this->comDevice->setComSetting(dialog->getComSetting());
//            QSettings *comSettingFile = new QSettings("./config.ini", QSettings::IniFormat, 0);
//            comSettingFile->beginGroup("ComSetting");
//            comSettingFile->setValue("ComPort", this->comDevice->getComSetting()->getComPort());
//            comSettingFile->setValue("PortNum", this->comDevice->getComSetting()->getPortNum());
//            comSettingFile->setValue("Baud", this->comDevice->getComSetting()->getBaud());
//            comSettingFile->setValue("DataBit", this->comDevice->getComSetting()->getDataBit());
//            comSettingFile->setValue("StopBit", this->comDevice->getComSetting()->getStopBit());
//            comSettingFile->setValue("Parity", this->comDevice->getComSetting()->getParity());
//            comSettingFile->endGroup();
//            delete comSettingFile;
            if(this->comDevice->comConnect() !=true)
            {
               QMessageBox::warning(this,tr("端口打开失败"),tr("请检查端口"),tr("确定"));
            }else
            {
                this->ui->action_connect_485->setText(tr("485通讯断开"));
                this->comDevice->start();
                //                this->comDevice->timeBreak->start();
                qDebug()<<"485通讯连接成功";  
            }
            this->com_485_Flag = true;
            this->ui->action_connect_network->setEnabled(false);
        }else
        {
            this->ui->action_connect_485->setText(tr("485通讯连接"));
            this->ui->action_connect_network->setEnabled(true);
        }
        dialog->close();
        delete dialog;
    }
}
/*!
 * \brief MonitorMainWindow::on_action_connect_network_triggered
 * 网络通讯方式
 */
void MonitorMainWindow::on_action_connect_network_triggered()
{
    if(this->serverDevice->isListening())
    {
        emit signal_close_server();
        this->ui->action_connect_network->setText(tr("网络通信连接"));
        qWarning()<<"网络通信断开";
        this->network_Flag = false;
        this->ui->action_connect_485->setEnabled(true);
    }else
    {
        emit signal_open_server();
        this->ui->action_connect_network->setText(tr("网络通信断开"));
        qDebug()<<"网络通信连接成功";
        this->network_Flag = true;
        this->ui->action_connect_485->setEnabled(false);
    }
}
/*!
 * \brief MonitorMainWindow::insertCableDevice
 * \param device
 * 添加设备
 */
void MonitorMainWindow::insertCableDevice(CableMonitorDevice device)
{

    QTreeWidgetItem *deviceItem = new QTreeWidgetItem();
    QVariant bindData;
    bindData.setValue(device);
    deviceItem->setData(0, Qt::UserRole, bindData);
    deviceItem->setText(0, device.getDeviceId().toString());

    this->cableMonitorItemTable->insert(device.getDeviceId().toByteArray(), deviceItem);

    QTreeWidgetItem *deviceNameItem = new QTreeWidgetItem();
    deviceNameItem->setText(0,  device.getDeviceName());
    deviceItem->addChild(deviceNameItem);
    this->ui->treeWidget_deviceList->insertTopLevelItem(0, deviceItem);

    this->ui->treeWidget_deviceList->sortItems(0, Qt::AscendingOrder);  ///<按列表序号排序

    this->ui->queryDevicceIdComboBox->addItem(device.getDeviceId().toString(), bindData); ///<历史查询界面中

    qDebug() << "添加设备 设备ID：" << device.getDeviceId().toString() << "设备名称：" << device.getDeviceName();
    this->apiServer->insertTempDataTable(device.getDeviceId().toString());
    CableDataWidget *widget = new CableDataWidget(this);
    widget->setDeviceID(device);
    widget->setLabelID();
    widget->init_para();

    this->cableMonitorWidgetTable->insert(deviceItem, widget);
    this->list_unboundID->append(device.getDeviceId());

    this->ui->stackedWidget_device->addWidget(widget);

    this->ui->stackedWidget_device->setCurrentWidget(widget);

    connect(widget,SIGNAL(sendDataToDevice(int,QByteArray)),
            this,SLOT(sendDataToDevice_slot(int,QByteArray)));
    connect(widget,SIGNAL(sendDataToDevice(QByteArray)),this,
            SLOT(sendDataToDevice_slot(QByteArray)));
    connect(this,SIGNAL(receiveDataToDevice_signal(QByteArray)),
            widget,SLOT(receiveDataFromDevice(QByteArray)));
    connect(widget,SIGNAL(DBsave(CableMonitorDevice,electricCableMetaData)),
            this->DBManager,SLOT(dataSave(CableMonitorDevice,electricCableMetaData)));
    connect(widget,SIGNAL(DBsave(CableMonitorDevice,CableCurrent)),
            this->DBManager,SLOT(dataSave(CableMonitorDevice,CableCurrent)));    
//    connect(widget,SIGNAL(DBsave(deviceIdType,electricCableMetaData)),
//            this->DBManager,SLOT(dataSave(deviceIdType,electricCableMetaData)),Qt::DirectConnection);

//    connect(widget,SIGNAL(sendDataToServer(deviceIdType,electricCableMetaData)),
//            this,SLOT(sendDataToServer_slot(deviceIdType,electricCableMetaData)));

    connect(widget,SIGNAL(sendDataToXml(deviceIdType,electricCableMetaData)),
            this->apiServer,SLOT(dataUpdate(deviceIdType,electricCableMetaData)));
    connect(this, SIGNAL(signal_auto_get_RT_time(bool,qint32)),
            widget, SLOT(slot_auto_get_RT_time(bool,qint32)));
   /* connect(this, SIGNAL(signal_auto_get_ST_time(bool,qint32)),
            widget, SLOT(slot_auto_get_ST_time(bool,qint32)));*/
    connect(this, SIGNAL(signal_auto_get_AL_time(bool,qint32)),
            widget, SLOT(slot_auto_get_AL_time(bool,qint32)));
    connect(this, SIGNAL(signal_stop_get_data()),
            widget, SLOT(slot_stop_get_data()));

    connect(widget,SIGNAL(sendDataToServer(QByteArray)),this,SLOT(send_rt_data_to_server(QByteArray)));
    connect(this, SIGNAL(signal_recv_data_to_ui(QByteArray)), widget, SLOT(receiveDataFromDevice(QByteArray)));
}
/*!
 * \brief MonitorMainWindow::removeCableDevice
 * \param deviceid
 * 删除设备
 */
void MonitorMainWindow::removeCableDevice(deviceIdType deviceid)
{
    if(this->cableMonitorItemTable->contains(deviceid.toByteArray()))
    {
        QTreeWidgetItem *deviceItem = this->cableMonitorItemTable->value(deviceid.toByteArray());
        if(this->cableMonitorWidgetTable->contains(deviceItem))
        {
            CableDataWidget *widget = this->cableMonitorWidgetTable->value(deviceItem);
            if(widget == NULL)
                return;

            this->ui->stackedWidget->removeWidget(widget);
            this->cableMonitorWidgetTable->remove(deviceItem);
            delete widget;
            qDebug() << "删除设备 设备ID：" << deviceid.toString();
        }
        this->cableMonitorItemTable->remove(deviceid.toByteArray());
        this->ui->treeWidget_deviceList->takeTopLevelItem(this->ui->treeWidget_deviceList->indexOfTopLevelItem(deviceItem));
        this->ui->queryDevicceIdComboBox->removeItem(this->ui->queryDevicceIdComboBox->findText(deviceid.toString()));
    }
}
/*!
 * \brief MonitorMainWindow::updateCableDevice
 * \param device
 * 更新设备
 */
void MonitorMainWindow::updateCableDevice(CableMonitorDevice device)
{
    if(this->cableMonitorItemTable->contains(device.getDeviceId().toByteArray()))
    {
       QTreeWidgetItem *deviceItem = this->cableMonitorItemTable->value(device.getDeviceId().toByteArray());
       if(deviceItem->childCount() >= 1)
       {
           deviceItem->child(0)->setText(0, device.getDeviceName());
       }
       this->cableMonitorWidgetTable->value(deviceItem)->setDeviceID(device);
    }
}
/*!
 * \brief MonitorMainWindow::sendDataToDevice_slot
 * \param clientID
 * \param data
 * 向已注册设备发送数据
 */
void MonitorMainWindow::sendDataToDevice_slot(int clientID,QByteArray data)
{
    if(this->network_Flag)
    {
        emit sendDataToDevice_signal(clientID,data);
    }
}

void MonitorMainWindow::sendDataToDevice_slot(QByteArray data)
{
    if(this->com_485_Flag)
    {
        emit sendDataToDevice_signal(data);
    }
}
/*!
 * \brief MonitorMainWindow::deviceListTreeWidgetItemClicked
 * \param item
 * \param col
 * 点击设备列表
 */
void MonitorMainWindow::deviceListTreeWidgetItemClicked(QTreeWidgetItem *item, int col)
{
    if(col != 0)
    {
        return;
    }
    if(true == this->cableMonitorWidgetTable->contains(item))
    {
        this->ui->stackedWidget_device->setCurrentWidget(this->cableMonitorWidgetTable->value(item));
    }
}
/*!
 * \brief MonitorMainWindow::on_action_register_device_triggered
 * 显示注册设备对话框
 */
void MonitorMainWindow::on_action_register_device_triggered()
{
    deviceRegisterDialog *dialog = new deviceRegisterDialog(this);
    dialog->setDeviceTable(this->cableMonitorsTable);

    connect(dialog, SIGNAL(insertDeviceSignal(CableMonitorDevice)),
            this->DBManager, SLOT(insertDevice(CableMonitorDevice)));
    connect(dialog,SIGNAL(removeDeviceSignal(deviceIdType)),
            this->DBManager,SLOT(removeDevice(deviceIdType)),Qt::DirectConnection);
    connect(dialog, SIGNAL(updateDeviceSignal(CableMonitorDevice)),
            this->DBManager, SLOT(updateDevice(CableMonitorDevice)));

    connect(dialog, SIGNAL(insertDeviceSignal(CableMonitorDevice)),
            this, SLOT(insertCableDevice(CableMonitorDevice)));
    connect(dialog, SIGNAL(removeDeviceSignal(deviceIdType)),
            this, SLOT(removeCableDevice(deviceIdType)));
    connect(dialog, SIGNAL(updateDeviceSignal(CableMonitorDevice)),
            this, SLOT(updateCableDevice(CableMonitorDevice)));
    dialog->show();
    dialog->exec();

    dialog->close();
    delete dialog;
}
/*!
 * \brief MonitorMainWindow::newClientConnet_solt
 * \param clientID
 * 网络通讯有新的连接
 */
void MonitorMainWindow::newClientConnet_solt(int clientID,QString ip,quint16 port)
{
    //==========================设备断开重新链接===========================
    TcpClientType client;
    client.clientfd = clientID;
    client.ip       = ip;
    client.port     = port;
    if(!hash_client.contains(clientID))
    {
        hash_client.insert(clientID,client);
    }
    slot_list_clientfd_insert(clientID);
    if(this->cableMonitorTcpClientTable->contains(ip))
    {
        this->cableMonitorTcpClientTable->value(ip)->child(1)->setText(0,ip+":"+QString::number(port));
        this->cableMonitorWidgetTable->value(this->cableMonitorTcpClientTable->value(ip))->setTcpClientID(clientID);
        this->cableMonitorTcpClientTable->value(ip)->setBackgroundColor(1,Qt::green);
    }else
    {
        //==========================设备未绑定扫描设备===========================
        qDebug()<<"扫描设备:";
        if(this->list_unboundIDTmp->count() != 0)
        {
            for(int i=0;i<list_unboundIDTmp->count();i++)
            {
                this->list_unboundID->removeOne(this->list_unboundIDTmp->value(i));
            }
            this->list_unboundIDTmp->clear();
        }
        for(int i=0;i<list_unboundID->length();i++)
        {
            emit sendDataToDevice_signal(clientID,
                comProtocol::assembleRtDataRequestFrame(list_unboundID->value(i)));
//            myHelper::Delay_MSec(200);
        }
    }
}
/*!
 * \brief MonitorMainWindow::receiveDataFromDevice_slot
 * \param data
 * 接收485设备返回的数据
 */
void MonitorMainWindow::receiveDataFromDevice_slot(QByteArray data)
{
    if(data.length()>18)
    {
        QByteArray dataTmp = data.mid(8,4);
        CableMonitorDevice deviceId;
        if(cableMonitorsTable->contains(dataTmp))
        {
            deviceId = cableMonitorsTable->value(dataTmp);
        }
        if(this->list_unboundIDTmp->count() != 0)
        {
            for(int i=0;i<list_unboundIDTmp->count();i++)
            {
                this->list_unboundID->removeOne(this->list_unboundIDTmp->value(i));
            }
            this->list_unboundIDTmp->clear();
        }
        if(list_unboundID->contains(deviceId.getDeviceId()))
        {
            list_unboundIDTmp->append(deviceId.getDeviceId());
            QTreeWidgetItem *deviceItem = this->cableMonitorItemTable->value(deviceId.getDeviceId().toByteArray());
            this->cableMonitorWidgetTable->value(deviceItem)->setBlindFlag(flag_485);
        }
#if 0
        if((uchar)data.at(4) == 0x81)
        {
            emit signal_send_data_to_remote_server(data);
        }
#endif /* 0 */
        emit receiveDataToDevice_signal(data);

    }
//    qDebug() << "MonitorMainWindow: "<< QThread::currentThreadId();
}
/*!
 * \brief MonitorMainWindow::receiveDatFromDevice_slot
 * \param clientID
 * \param data
 * 接收网络设备返回的数据
 */
void MonitorMainWindow::receiveDatFromDevice_slot(int clientID, QByteArray data)
{
    //this->cableMonitorTcpClientTable->insert();
//    uchar *dataTmp = (uchar *)data.data();
    if(data.length()>18)
    {
        QByteArray dataTmp = data.mid(5,12);
        CableMonitorDevice deviceId;
        if(cableMonitorsTable->contains(dataTmp))
        {
            deviceId = cableMonitorsTable->value(dataTmp);
        }
        if(this->list_unboundIDTmp->count() != 0)
        {
            for(int i=0;i<list_unboundIDTmp->count();i++)
            {
                this->list_unboundID->removeOne(this->list_unboundIDTmp->value(i));
            }
            this->list_unboundIDTmp->clear();
        }
        if(list_unboundID->contains(deviceId.getDeviceId()))
        {
            list_unboundIDTmp->append(deviceId.getDeviceId());
            //===========绑定客户端============
            QTreeWidgetItem *deviceItem = this->cableMonitorItemTable->value(deviceId.getDeviceId().toByteArray());
            QTreeWidgetItem *ipBindItem = new QTreeWidgetItem();
            ipBindItem->setData(0, Qt::UserRole, true);
            ipBindItem->setText(0, hash_client.value(clientID).ip     //<客户端地址
                                + ":" +QString::number(hash_client.value(clientID).port));    //<客户端端口号
            deviceItem->addChild(ipBindItem);
            this->cableMonitorWidgetTable->value(deviceItem)->setBlindFlag(flag_network);
            this->cableMonitorWidgetTable->value(deviceItem)->setTcpClientID(clientID);
            this->cableMonitorWidgetTable->value(deviceItem)->setClientIP(hash_client.value(clientID).ip);
            this->cableMonitorTcpClientTable->insert(hash_client.value(clientID).ip,deviceItem);
            if(hash_client.contains(clientID))
            {
                QString ip = hash_client.value(clientID).ip;
                if(cableMonitorTcpClientTable->contains(ip))
                {
                    cableMonitorTcpClientTable->value(ip)->setBackgroundColor(1,Qt::green);
                }
            }
        }
    }
    if((uchar)data.at(4) == 0x81)
    {
        emit signal_send_data_to_remote_server(data);
    }
    emit receiveDataToDevice_signal(data);
    if(hash_client.contains(clientID))
    {
        QString ip = hash_client.value(clientID).ip;
        if(cableMonitorTcpClientTable->contains(ip))
        {
            cableMonitorTcpClientTable->value(ip)->setBackgroundColor(0,Qt::green);
//            cableMonitorTcpClientTable->value(ip)->setBackgroundColor(1,Qt::green);
        }
    }
}
/*!
 * \brief MonitorMainWindow::on_action_show_info_triggered
 * 调试信息显示
 */
void MonitorMainWindow::on_action_show_info_triggered()
{
    if(this->ui->action_show_info->isChecked())
    {
        this->ui->textBrowser->show();
    }else
    {
        this->ui->textBrowser->hide();
    }
}
/*!
 * \brief MonitorMainWindow::on_action_data_triggered
 * 显示实时数据显示界面
 */
void MonitorMainWindow::on_action_data_triggered()
{
    if(this->ui->stackedWidget->currentIndex() != 0)
    {
        this->ui->stackedWidget->setCurrentIndex(0);
    }
}
/*!
 * \brief MonitorMainWindow::on_action_history_triggered
 * 显示历史数据显示界面
 */
void MonitorMainWindow::on_action_history_triggered()
{
    if(this->ui->stackedWidget->currentIndex() != 1)
    {
        this->ui->stackedWidget->setCurrentIndex(1);
        this->ui->endDateTimeEdit->setDateTime(QDateTime::currentDateTime());
    }
}
/*!
 * \brief MonitorMainWindow::on_action_clearLog_triggered
 * 清除调试信息
 */
void MonitorMainWindow::on_action_clearLog_triggered()
{
    this->save_log();
    this->ui->textBrowser->clear();
}

void MonitorMainWindow::on_queryPushButton_clicked()
{
    QDateTime beginTime = this->ui->beginDateTimeEdit->dateTime();
    QDateTime endTime = this->ui->endDateTimeEdit->dateTime();

    deviceIdType deviceid;

    int index = this->ui->queryDevicceIdComboBox->currentIndex();
    deviceid = this->ui->queryDevicceIdComboBox->itemData(index, Qt::UserRole).value<CableMonitorDevice>().getDeviceId();
    enum current_type datatype;

    switch (this->ui->queryDataTypeComboBox->currentIndex()) {
    case 0:
        datatype = GroundCablePhaseMain;
        break;
    case 1:
        datatype = GroundCablePhaseA;
        break;
    case 2:
        datatype = GroundCablePhaseB;
        break;
    case 3:
        datatype = GroundCablePhaseC;
        break;
    case 4:
        datatype = GroundCablePhaseN;
        break;
    case 5:
        datatype = ConnectorATemp;
        break;
    case 6:
        datatype = ConnectorBTemp;
        break;
    case 7:
        datatype = ConnectorCTemp;
        break;


    default:
        break;
    }

    QList<CableCurrent> datalist;

    datalist = this->DBManager->queryHistoryData(deviceid, beginTime, endTime, datatype);
    qDebug() << "获取数据条目：" << datalist.length();
    qDebug()<< this->ui->queryDevicceIdComboBox->currentText()+ " " + this->ui->queryDataTypeComboBox->currentText();

    this->ui->widget_historyPlot->addDataCurve(datalist, this->ui->queryDevicceIdComboBox->currentText() + " " + this->ui->queryDataTypeComboBox->currentText(),
                                        this->colorList.value(currentColorIndex++));
}

void MonitorMainWindow::on_clearCurvesPushButton_clicked()
{
    this->ui->widget_historyPlot->clearAllCurves();
}

void MonitorMainWindow::on_clearDBPushButton_clicked()
{
 //   this->DBManager
}

void MonitorMainWindow::on_action_set_map_triggered()
{
    hcSystemMappingRegisterDialog *dialog = new hcSystemMappingRegisterDialog(this);
    QList<CableMonitorDevice> list = this->cableMonitorsTable->values();
    dialog->setCableMonitorList(list);
    dialog->setHcSystemMapping(this->hcIdMappingTable);
    connect(dialog, SIGNAL(insertSystemMappingSignal(quint64,ChannelInfoType)), this->DBManager, SLOT(insertSystemMapping(quint64,ChannelInfoType)));
    connect(dialog, SIGNAL(removeSystemMappingSignal(quint64)), this->DBManager, SLOT(removeSystemMapping(quint64)));

    dialog->show();
    dialog->exec();

    dialog->close();
    delete dialog;
}

void MonitorMainWindow::on_action_connet_server_triggered()
{
    if(this->hcHostConnctedStatus)
    {
        emit signal_disconnect_to_remote_server();
    }else
    {
        hcSystemNetConfigDialog *dialog = new hcSystemNetConfigDialog(this);
        QString ip = this->socket_save_to_server->get_ip();
        quint16 port = this->socket_save_to_server->get_port();
        dialog->setIPAddressAndPort(ip,port);
        dialog->show();
        if(QDialog::Accepted == dialog->exec())
        {
            qDebug() << "设置系统远端服务器连接IP为：" << dialog->getIPAdress();
            qDebug() << "设置系统远端服务器端口为：" << dialog->getPort();

            this->hcIPAddress = dialog->getIPAdress();
            this->hcHostPort = dialog->getPort();
            emit signal_set_ip_to_remote_server(this->hcIPAddress);
            emit signal_set_port_to_remote_server(this->hcHostPort);
            QSettings settingFile("./config.ini",  QSettings::IniFormat, 0);
            settingFile.beginGroup("HcSystemNetConfig");
            settingFile.setValue("IPAddress", this->hcIPAddress);
            settingFile.setValue("Port", this->hcHostPort);
            settingFile.endGroup();
            if(this->hcHostConnctedStatus)
            {
                emit signal_disconnect_to_remote_server();
            }
            emit signal_connect_to_remote_server();
            
        }
        dialog->close();
        delete dialog;
    }
}

void MonitorMainWindow::hcSendDataToServer()
{
//    if(hcDataList.isEmpty())
//        return;
//    QByteArray sendArray = HcNetMetaData::assembleFrame(hcDataList);

//    if(this->hcNetSocket->isOpen())
//    {
//        this->hcNetSocket->write(sendArray);
//        qDebug()<<"向服务器"+ this->hcIPAddress+":"
//                                  +QString::number(this->hcHostPort)
//                                  +"发送数据："+myHelper::ByteArrayToHexStr(sendArray);
//    }
//    this->hcDataList.clear();
}

void MonitorMainWindow::hcSocketConnectedToServer()
{
    this->hcHostConnctedStatus = true;
    qDebug() << "连接到远端服务器";
    this->ui->action_connet_server->setText("远端服务器断开");
}

void MonitorMainWindow::hcSocketDisconnectedFromServer()
{
    this->hcHostConnctedStatus = false;
    qDebug() << "从远端服务器断开";
    this->ui->action_connet_server->setText("远端服务器连接");
}
/*!
 * \brief MonitorMainWindow::sendDataToServer_slot
 * \param ID
 * \param data
 * 数据格式
 *
AA 55  数据头
33 00  有效数据长度
00 00  数据类型
03 00  帧长度
28 23 00 00 编号
00 00 00 00 设备ID
00 00 00 00 数据值
01          是否正常

29 23 00 00
00 00 00 00
00 00 00 00
01
2A 23 00 00
00 00 00 00
00 00 00 00
01
8F 0D  校验值
A5 5A  数据尾
 */
void MonitorMainWindow::sendDataToServer_slot(deviceIdType ID, electricCableMetaData data)
{
    HcNetMetaData hcData;
    bool okflag;

    hcData = this->electricCableMetaData2HcNetMetaData(ID, data, &okflag);
    if(okflag)
    {
//        if(hcDataList.contains(hcData))
//        {
//            return;
//        }else
//        {
            hcDataList.append(hcData);
//        }
    }
}
/*!
 * \brief MonitorMainWindow::electricCableMetaData2HcNetMetaData
 * \param devid
 * \param data
 * \param flag
 * \return
 * 当前阶段只能想服务器发送电流实时值
 */
HcNetMetaData MonitorMainWindow::electricCableMetaData2HcNetMetaData(deviceIdType devid, electricCableMetaData data, bool *flag)
{
    HcNetMetaData hcData;
    ChannelInfoType channelInfo;
    switch (data.datatype) {
        case MainCable_RT:
            hcData.isNormal = true;
            channelInfo.phase = 1;
            break;
        case MainCable_Alarm:
            hcData.isNormal = false;
            channelInfo.phase = 1;
            break;
        case GroundCablePhaseA_RT:
        case GroundCablePhaseA_Temp_RT:
            hcData.isNormal = true;
            channelInfo.phase = 2;
            break;
        case GroundCablePhaseA_Alarm:
            hcData.isNormal = false;
            channelInfo.phase = 2;
            break;
        case GroundCablePhaseB_RT:
        case GroundCablePhaseB_Temp_RT:
            hcData.isNormal = true;
            channelInfo.phase = 3;
            break;
        case GroundCablePhaseB_Alarm:
            hcData.isNormal = false;
            channelInfo.phase = 3;
            break;
        case GroundCablePhaseC_RT:
        case GroundCablePhaseC_Temp_RT:
            hcData.isNormal = true;
            channelInfo.phase = 4;
            break;
        case GroundCablePhaseC_Alarm:
            hcData.isNormal = false;
            channelInfo.phase = 4;
            break;
        case GroundCablePhaseN_RT:
        case GroundCablePhaseN_Temp_RT:
            hcData.isNormal = true;
            channelInfo.phase = 5;
            break;
        case GroundCablePhaseN_Alarm:
            hcData.isNormal = false;
            channelInfo.phase = 5;
            break;
        default:
            break;
        }

    channelInfo.deviceId = devid;

    QList<quint64> keys = this->hcIdMappingTable->keys(channelInfo);
    if(keys.isEmpty())
    {
        *flag = false;
        return hcData;
    }
    else
    {
        *flag = true;
        hcData.id = keys.value(0);
        hcData.CV = data.value;

        return hcData;
    }
}

void MonitorMainWindow::cnt_comFailed_slot()
{
    this->ui->action_cnt_com_failed->setText("通信失败计数"+QString::number(CNT_COM)+"次");
}

void MonitorMainWindow::on_action_clearCnt_triggered()
{
    CNT_COM =0;
    this->ui->action_cnt_com_failed->setText("通信失败计数0次");
}

void MonitorMainWindow::save_log()
{
    QDir tmp;
    if(!tmp.exists(QCoreApplication::applicationDirPath()+"/log"))
    {
        if(!tmp.mkdir(QCoreApplication::applicationDirPath()+"/log"))
        {
            QMessageBox::warning(this,tr("警告"),tr("创建目录log失败"),tr("确认"));
            return;
        }
    }
    QString file_path =QCoreApplication::applicationDirPath() + QString("/log/%1.txt").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss"));
//    QString file_path = QString("log/log.txt");
    QFile file(file_path);
    if(!file.open(QIODevice::WriteOnly | QFile::Text))
    {
        qDebug()<<"open"<<file_path<<"失败";
        return;
    }else
    {
        QTextStream out(&file);
        out<<this->ui->textBrowser->toPlainText()<<endl;
        file.flush();
        file.close();
        this->ui->textBrowser->clear();
    }
}

void MonitorMainWindow::auto_save_log()
{
    if(this->ui->textBrowser->document()->blockCount() >= 10000)
    {
        save_log();
    }
}

void MonitorMainWindow::slot_list_clientfd_insert(int clientfd)
{
    if(list_clientfd.contains(clientfd))
    {
        return;
    }else
    {
        list_clientfd.append(clientfd);
    }
}

void MonitorMainWindow::slot_list_clientfd_remove(int clientfd)
{
    if(list_clientfd.contains(clientfd))
    {
        if(hash_client.contains(clientfd))
        {
            QString ip = hash_client.value(clientfd).ip;
            if(cableMonitorTcpClientTable->contains(ip))
            {
                cableMonitorTcpClientTable->value(ip)->setBackgroundColor(1,Qt::white);
            }
        }
        list_clientfd.removeOne(clientfd);
        hash_client.remove(clientfd);
    }else
    {
        return;
    }
}

void MonitorMainWindow::slot_close_led()
{
    for(int i=0;i<this->ui->treeWidget_deviceList->topLevelItemCount();i++)
    {
        if(this->ui->treeWidget_deviceList->topLevelItem(i)->backgroundColor(0) != Qt::white)
        {
            this->ui->treeWidget_deviceList->topLevelItem(i)->setBackgroundColor(0,Qt::white) ;
        }
    }
}

void MonitorMainWindow::on_action_CableMonitor_triggered()
{
    Dialog_Versions dialog;
    dialog.show();
    dialog.exec();
    dialog.close();
}

/*!
 * 函数名称：MonitorMainWindow::slot_auto_connect
 * 功能描述：在网络异常断开时能重新连接
 * 参数说明：无
 * 返回类型：void
 * 作    者： 刘峰
 * 软件版本：Ver 0.1.3:1202
 * 日    期：2017-12-02
 */
void MonitorMainWindow::slot_auto_connect()
{
    if((this->network_Flag == true) && (this->hash_client.count() == 0))
    {
        emit signal_close_server();
        emit signal_open_server();
    }
}

void MonitorMainWindow::on_action_auto_get_data_triggered()
{
    if(this->ui->action_auto_get_data->text() == "自动获取数据")
    {
        Dialog_set_interval_time *dialog = new Dialog_set_interval_time();
        connect(dialog, SIGNAL(signal_auto_get_RT_time(bool,qint32)),
                this, SIGNAL(signal_auto_get_RT_time(bool,qint32)));
        connect(dialog, SIGNAL(signal_auto_get_ST_time(bool,qint32)),
                this, SIGNAL(signal_auto_get_ST_time(bool,qint32)));
        connect(dialog, SIGNAL(signal_auto_get_AL_time(bool,qint32)),
                this, SIGNAL(signal_auto_get_AL_time(bool,qint32)));
        connect(dialog, SIGNAL(signal_stop_get_data()),
                this, SIGNAL(signal_stop_get_data()));
        dialog->show();
        if(dialog->exec() == QDialog::Accepted)
        {
            this->ui->action_auto_get_data->setText("停止获取数据");
        }
        dialog->close();
        delete dialog;

    } else {
        emit this->signal_stop_get_data();
        this->ui->action_auto_get_data->setText("自动获取数据");
    }
}

void MonitorMainWindow::send_rt_data_to_server(QByteArray data)
{
    emit signal_send_data_to_remote_server(data);
}

void MonitorMainWindow::recv_data_from_server(QByteArray data)
{
    emit signal_recv_data_to_ui(data);
}

void MonitorMainWindow::on_scrollAreaWidgetContents_destroyed()
{

}

void MonitorMainWindow::on_page_2_destroyed()
{

}

void MonitorMainWindow::on_page_3_destroyed()
{

}
