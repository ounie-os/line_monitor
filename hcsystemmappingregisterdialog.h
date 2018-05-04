#ifndef HCSYSTEMMAPPINGREGISTERDIALOG_H
#define HCSYSTEMMAPPINGREGISTERDIALOG_H

#include <QDialog>
#include <QList>

#include "cablemonitordevice.h"
#include "channelinfotype.h"
namespace Ui {
class hcSystemMappingRegisterDialog;
}

class hcSystemMappingRegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit hcSystemMappingRegisterDialog(QWidget *parent = 0);
    ~hcSystemMappingRegisterDialog();

    void setCableMonitorList(QList<CableMonitorDevice> list);
    void setHcSystemMapping(QHash<quint64, ChannelInfoType> *mapping);
signals:
    void insertSystemMappingSignal(quint64 hcId, ChannelInfoType channelinfo);
    void removeSystemMappingSignal(quint64 hcId);
private slots:
    void insertSystemIdMappingTableItem();
    void removeSystemIdMappintTableItem();
private:
    Ui::hcSystemMappingRegisterDialog *ui;
    QHash<quint64, ChannelInfoType> *hcMapping;


};

#endif // HCSYSTEMMAPPINGREGISTERDIALOG_H
