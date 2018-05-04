#ifndef HCSYSTEMNETCONFIGDIALOG_H
#define HCSYSTEMNETCONFIGDIALOG_H

#include <QDialog>

namespace Ui {
class hcSystemNetConfigDialog;
}

class hcSystemNetConfigDialog : public QDialog
{
    Q_OBJECT

public:
    explicit hcSystemNetConfigDialog(QWidget *parent = 0);
    ~hcSystemNetConfigDialog();

    void setIPAddressAndPort(QString ip, int port);
    QString getIPAdress();
    int getPort();
private slots:
    void okButtonClicked();
private:
    Ui::hcSystemNetConfigDialog *ui;
    QString ipAddress;
    int port;
};

#endif // HCSYSTEMNETCONFIGDIALOG_H
