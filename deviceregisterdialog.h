#ifndef DEVICEREGISTERDIALOG_H
#define DEVICEREGISTERDIALOG_H

#include <QDialog>
#include <QTableWidgetItem>

#include "cablemonitordevice.h"
namespace Ui {
class deviceRegisterDialog;
}

class deviceRegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit deviceRegisterDialog(QWidget *parent = 0);
    ~deviceRegisterDialog();

    void setUserList(QStringList userlist);
    void setDeviceTable(QHash<QByteArray, CableMonitorDevice> *table);
signals:
    void insertDeviceSignal(CableMonitorDevice device);
    void removeDeviceSignal(deviceIdType devid);
    void updateDeviceSignal(CableMonitorDevice device);
private slots:
    void insertDevice();
    void removeDevice();

    void deviceNameItemEditting(QTableWidgetItem *item);
    void deviceNameItemEditted(QTableWidgetItem *item);
    void on_createPushButton_clicked();

    void on_createPushButton_clicked(bool checked);

    void on_createPushButton_pressed();

    void on_createPushButton_windowIconChanged(const QIcon &icon);

private:
    Ui::deviceRegisterDialog *ui;
    QHash<QByteArray, CableMonitorDevice> *deviceTable;
    QString textBeforeEditting;
    QTableWidgetItem *edittingItem;

    void insertdeviceTableShowTableWidget(CableMonitorDevice device);
};

#endif // DEVICEREGISTERDIALOG_H
