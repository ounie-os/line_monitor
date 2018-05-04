#include "dialog_set_interval_time.h"
#include "ui_dialog_set_interval_time.h"

Dialog_set_interval_time::Dialog_set_interval_time(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_set_interval_time)
{
    ui->setupUi(this);
}

Dialog_set_interval_time::~Dialog_set_interval_time()
{
    delete ui;
}
void Dialog_set_interval_time::on_pushButton_cancel_clicked()
{
    emit this->signal_stop_get_data();
    this->close();
}

void Dialog_set_interval_time::on_pushButton_enter_clicked()
{
    bool flag_RT = this->ui->checkBox_RT->isChecked();
    bool flag_ST = this->ui->checkBox_ST->isChecked();
    bool flag_AL = this->ui->checkBox_AL->isChecked();
    emit signal_auto_get_RT_time(flag_RT, this->ui->spinBox_RT->value());
    emit signal_auto_get_ST_time(flag_ST, this->ui->spinBox_ST->value());
    emit signal_auto_get_AL_time(flag_AL, this->ui->spinBox_AL->value());
    this->accept();
}
