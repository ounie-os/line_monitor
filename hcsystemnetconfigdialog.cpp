#include "hcsystemnetconfigdialog.h"
#include "ui_hcsystemnetconfigdialog.h"

#include <QMessageBox>

hcSystemNetConfigDialog::hcSystemNetConfigDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hcSystemNetConfigDialog)
{
    ui->setupUi(this);

    connect(this->ui->okPushButton, SIGNAL(clicked()), this, SLOT(okButtonClicked()));
    connect(this->ui->cancelPushButton, SIGNAL(clicked()), this, SLOT(reject()));
}

hcSystemNetConfigDialog::~hcSystemNetConfigDialog()
{
    delete ui;
}

void hcSystemNetConfigDialog::setIPAddressAndPort(QString ip, int port)
{
    this->ui->ipAdressLineEdit->setText(ip);

    this->ui->portLineEdit->setText(QString::number(port));
}

QString hcSystemNetConfigDialog::getIPAdress()
{
    return this->ipAddress;
}

int hcSystemNetConfigDialog::getPort()
{
    return this->port;
}

void hcSystemNetConfigDialog::okButtonClicked()
{
    QRegExp ipRx("((?:(?:25[0-5]|2[0-4]\\d|((1\\d{2})|([1-9]?\\d)))\\.){3}(?:25[0-5]|2[0-4]\\d|((1\\d{2})|([1-9]?\\d))))");
    if(ipRx.exactMatch(this->ui->ipAdressLineEdit->text()) == false)
    {
        QMessageBox::warning(this, tr("Error"), tr("Invalid IP Format"));
        return;
    }

    QRegExp portRx("^[1-9][0-9]{0,3}|[1-5][0-9]{4}|6[0-4][0-9]{3}|65[0-4][0-9]{2}|655[0-2][0-9]{1}|6553[0-5]$");
    if(portRx.exactMatch(this->ui->portLineEdit->text()) == false)
    {
        QMessageBox::warning(this, tr("Error"), tr("Port should between 0 ~ 65535"));
        return;
    }

    this->ipAddress = this->ui->ipAdressLineEdit->text();
    this->port = this->ui->portLineEdit->text().toInt();

    this->accept();
    return;
}
