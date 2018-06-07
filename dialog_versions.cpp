#include "dialog_versions.h"
#include "ui_dialog_versions.h"
#define Version  "1.0"
#define Datatime "2018-06-07"
#include <QDateTime>

Dialog_Versions::Dialog_Versions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Versions)
{
    ui->setupUi(this);
    this->ui->label_Verision->setText(Version);
    this->ui->label_data_change->setText(Datatime);
}

Dialog_Versions::~Dialog_Versions()
{
    delete ui;
}

void Dialog_Versions::on_pushButton_clicked()
{
    this->close();
}
