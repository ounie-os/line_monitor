#include "hcsystemmappingregisterdialog.h"
#include "ui_hcsystemmappingregisterdialog.h"
#include <QMessageBox>
#include <QDebug>

Q_DECLARE_METATYPE(deviceIdType)
hcSystemMappingRegisterDialog::hcSystemMappingRegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hcSystemMappingRegisterDialog)
{
    ui->setupUi(this);

    qRegisterMetaType<ChannelInfoType>("ChannelInfoType");

    this->ui->systemMappingShowTableWidget->setColumnCount(3);
    this->ui->systemMappingShowTableWidget->setHorizontalHeaderLabels(QStringList() << tr("Device Id") << tr("Phase") << tr("HC System Id"));
    this->ui->systemMappingShowTableWidget->horizontalHeader()->setStretchLastSection(true);
    this->ui->systemMappingShowTableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);

    this->ui->systemMappingShowTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(this->ui->systemMappingSetPushButton, SIGNAL(clicked()), this, SLOT(insertSystemIdMappingTableItem()));
    connect(this->ui->systemMappingDeletePushButton, SIGNAL(clicked()), this, SLOT(removeSystemIdMappintTableItem()));
}

hcSystemMappingRegisterDialog::~hcSystemMappingRegisterDialog()
{
    delete ui;
}

void hcSystemMappingRegisterDialog::setCableMonitorList(QList<CableMonitorDevice> list)
{
    for(int i = 0 ; i < list.length(); i++)
    {
        QVariant bindData;
        bindData.setValue(list.value(i).getDeviceId());
        this->ui->devicceIdComboBox->addItem(list.value(i).getDeviceId().toString(), bindData);
    }



}

void hcSystemMappingRegisterDialog::setHcSystemMapping(QHash<quint64, ChannelInfoType> *mapping)
{
    this->hcMapping = mapping;

    QList<quint64> hcIdList = this->hcMapping->keys();

    this->ui->systemMappingShowTableWidget->setRowCount(hcIdList.length());
    for(int i = 0 ; i < hcIdList.length(); i++)
    {
        quint64 hcId = hcIdList.value(i);
        ChannelInfoType channelInfo = this->hcMapping->value(hcId);

        this->ui->systemMappingShowTableWidget->setItem(i, 0, new QTableWidgetItem(channelInfo.deviceId.toString()));
        this->ui->systemMappingShowTableWidget->setItem(i, 1, new QTableWidgetItem(channelInfo.toPhaseString()));
        this->ui->systemMappingShowTableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(hcId)));
    }
}

void hcSystemMappingRegisterDialog::removeSystemIdMappintTableItem()
{
    QTableWidgetItem *item = this->ui->systemMappingShowTableWidget->currentItem();
    if(item == NULL)
    {
        QMessageBox::warning(this, tr("Error"), tr("Choose a item First"));
        return;
    }
    int row = this->ui->systemMappingShowTableWidget->row(item);
    quint64 hcid = this->ui->systemMappingShowTableWidget->item(row, 2)->text().toULongLong();

    this->ui->systemMappingShowTableWidget->removeRow(row);
    this->hcMapping->remove(hcid);

    emit this->removeSystemMappingSignal(hcid);

}

void hcSystemMappingRegisterDialog::insertSystemIdMappingTableItem()
{
    ChannelInfoType channelInfo;

    channelInfo.deviceId = this->ui->devicceIdComboBox->itemData(this->ui->devicceIdComboBox->currentIndex(), Qt::UserRole).value<deviceIdType>();
    channelInfo.phase = this->ui->phaseComboBox->currentIndex();

    quint64 hcid = this->ui->hcIdLineEdit->text().toULongLong();

    if(this->hcMapping->contains(hcid))
    {
        QMessageBox::warning(this, tr("Error"), tr("The System Id has Used"));
        return;
    }

    if(this->hcMapping->values().contains(channelInfo))
    {
        QMessageBox::warning(this, tr("Error"), tr("The channel Has been mapped"));
        return;
    }

    this->hcMapping->insert(hcid, channelInfo);

    int curRow = this->ui->systemMappingShowTableWidget->rowCount();
    this->ui->systemMappingShowTableWidget->setRowCount(curRow + 1);
    this->ui->systemMappingShowTableWidget->setItem(curRow, 0, new QTableWidgetItem(channelInfo.deviceId.toString()));
    this->ui->systemMappingShowTableWidget->setItem(curRow, 1, new QTableWidgetItem(channelInfo.toPhaseString()));
    this->ui->systemMappingShowTableWidget->setItem(curRow, 2, new QTableWidgetItem(QString::number(hcid)));

//   qDebug() << "insertSystemMappingSignal";
    emit this->insertSystemMappingSignal(hcid, channelInfo);
}
