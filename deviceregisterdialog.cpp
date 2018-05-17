#include "deviceregisterdialog.h"
#include "ui_deviceregisterdialog.h"

#include <QMessageBox>

Q_DECLARE_METATYPE(CableMonitorDevice)
deviceRegisterDialog::deviceRegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deviceRegisterDialog)
{
    ui->setupUi(this);
    this->ui->label_3->setHidden(true);
    this->ui->userSelectComboBox->setHidden(true);

    this->ui->deviceTableShowTableWidget->setColumnCount(2);
    this->ui->deviceTableShowTableWidget->setHorizontalHeaderLabels(QStringList() << tr("ID") << tr("设备名称"));
    this->ui->deviceTableShowTableWidget->horizontalHeader()->setStretchLastSection(true);
    this->ui->deviceTableShowTableWidget->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);
    this->ui->deviceTableShowTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    connect(this->ui->createPushButton, SIGNAL(clicked()), this, SLOT(insertDevice()));
    connect(this->ui->removePushButton, SIGNAL(clicked()), this, SLOT(removeDevice()));

    connect(this->ui->deviceTableShowTableWidget, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), this, SLOT(deviceNameItemEditting(QTableWidgetItem*)));
    connect(this->ui->deviceTableShowTableWidget, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(deviceNameItemEditted(QTableWidgetItem*)));
}

deviceRegisterDialog::~deviceRegisterDialog()
{
    delete ui;
}

void deviceRegisterDialog::setUserList(QStringList userlist)
{
    this->ui->userSelectComboBox->addItems(userlist);
}


void deviceRegisterDialog::setDeviceTable(QHash<QByteArray, CableMonitorDevice> *table)
{
    this->deviceTable = table;

    QList<CableMonitorDevice> devicelist = this->deviceTable->values();
    for(int i = 0 ; i < devicelist.length(); i++)
    {
        this->insertdeviceTableShowTableWidget(devicelist.value(i));
    }

}

void deviceRegisterDialog::insertDevice()
{
    QString idStr = this->ui->deviceIdLineEdit->text();

    if(idStr.isEmpty())
    {
        QMessageBox::warning(this,tr("Error") ,tr("Please Input Device ID"));
        return;
    }

    deviceIdType devid = deviceIdType::fromString(idStr);

    QString devname = this->ui->deviceNameLineEdit->text();
    if(devname.isEmpty())
    {
        QMessageBox::warning(this, tr("Error"), tr("Please Input Device Name"));
        return;
    }

    //QString username = this->ui->userSelectComboBox->currentText();

    CableMonitorDevice device;
    device.setDeviceDeviceId(devid);
    device.setDeviceName(devname);
    //device.setUserName(username);

    if(this->deviceTable->contains(devid.toByteArray()))
    {
        QMessageBox::warning(this, tr("Error"), tr("Thid Device Has Contained"));
        return;
    }

    this->deviceTable->insert(devid.toByteArray(), device);
    this->insertdeviceTableShowTableWidget(device);
    emit this->insertDeviceSignal(device);
    this->ui->deviceTableShowTableWidget->sortItems(0, Qt::AscendingOrder);
}

void deviceRegisterDialog::removeDevice()
{
    QTableWidgetItem *item = this->ui->deviceTableShowTableWidget->currentItem();

    int curRow = this->ui->deviceTableShowTableWidget->row(item);

    if(curRow == -1)
        return;

    CableMonitorDevice device = this->ui->deviceTableShowTableWidget->item(curRow, 0)->data(Qt::UserRole).value<CableMonitorDevice>();

    this->ui->deviceTableShowTableWidget->removeRow(curRow);
    this->deviceTable->remove(device.getDeviceId().toByteArray());

    emit this->removeDeviceSignal(device.getDeviceId());
}

void deviceRegisterDialog::deviceNameItemEditting(QTableWidgetItem *item)
{
    this->textBeforeEditting = item->text();
    this->edittingItem = item;
}

void deviceRegisterDialog::deviceNameItemEditted(QTableWidgetItem *item)
{
    if(this->edittingItem != item)
        return;

    QString newDeviceName = item->text();
    if(newDeviceName.isEmpty())
    {
        item->setText(this->textBeforeEditting);
        return;
    }

    int row = this->ui->deviceTableShowTableWidget->row(item);
    CableMonitorDevice device = this->ui->deviceTableShowTableWidget->item(row, 0)->data(Qt::UserRole).value<CableMonitorDevice>();
    device.setDeviceName(newDeviceName);
    this->deviceTable->insert(device.getDeviceId().toByteArray(), device);

    emit this->updateDeviceSignal(device);
}

void deviceRegisterDialog::insertdeviceTableShowTableWidget(CableMonitorDevice device)
{
    int curRow = this->ui->deviceTableShowTableWidget->rowCount();

    this->ui->deviceTableShowTableWidget->setRowCount(curRow + 1);

    QTableWidgetItem *idItem = new QTableWidgetItem(device.getDeviceId().toString());
    idItem->setFlags(idItem->flags() & (~Qt::ItemIsEditable));
    QVariant bindData;
//    bindData.setValue(device.getDeviceId().toString());
    bindData.setValue(device);
    idItem->setData(Qt::UserRole, bindData);

    this->ui->deviceTableShowTableWidget->setItem(curRow, 0, idItem);
    this->ui->deviceTableShowTableWidget->setItem(curRow, 1, new QTableWidgetItem(device.getDeviceName()));
    this->ui->deviceTableShowTableWidget->sortItems(0, Qt::AscendingOrder);
    /*
    QTableWidgetItem *userItem = new QTableWidgetItem(device.getUserName());
    userItem->setFlags(userItem->flags() & (~Qt::ItemIsEditable));
    this->ui->deviceTableShowTableWidget->setItem(curRow, 2, userItem);
    */
}


void deviceRegisterDialog::on_createPushButton_clicked()
{

}

void deviceRegisterDialog::on_createPushButton_clicked(bool checked)
{

}

void deviceRegisterDialog::on_createPushButton_pressed()
{

}

void deviceRegisterDialog::on_createPushButton_windowIconChanged(const QIcon &icon)
{

}
