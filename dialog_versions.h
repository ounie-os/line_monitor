#ifndef DIALOG_VERSIONS_H
#define DIALOG_VERSIONS_H

#include <QDialog>

namespace Ui {
class Dialog_Versions;
}

class Dialog_Versions : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Versions(QWidget *parent = 0);
    ~Dialog_Versions();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_Versions *ui;
};

#endif // DIALOG_VERSIONS_H
