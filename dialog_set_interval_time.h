#ifndef DIALOG_SET_INTERVAL_TIME_H
#define DIALOG_SET_INTERVAL_TIME_H

#include <QDialog>

namespace Ui {
class Dialog_set_interval_time;
}

class Dialog_set_interval_time : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_set_interval_time(QWidget *parent = 0);
    ~Dialog_set_interval_time();

signals:
    void signal_auto_get_RT_time(bool flag, qint32 time);
    void signal_auto_get_ST_time(bool flag, qint32 time);
    void signal_auto_get_AL_time(bool flag, qint32 time);
    void signal_stop_get_data();

private slots:
    void on_pushButton_cancel_clicked();

    void on_pushButton_enter_clicked();

private:
    Ui::Dialog_set_interval_time *ui;
};

#endif // DIALOG_SET_INTERVAL_TIME_H
