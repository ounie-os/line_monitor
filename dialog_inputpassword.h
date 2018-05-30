#ifndef DIALOG_INPUTPASSWORD_H
#define DIALOG_INPUTPASSWORD_H
#define PASSWORD "ZhenTai"
#include <QDialog>

namespace Ui {
class Dialog_InputPassWord;
}

class Dialog_InputPassWord : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_InputPassWord(QWidget *parent = 0);
    ~Dialog_InputPassWord();

private slots:
    void on_pushButton_inputPassWord_clicked();

private:
    Ui::Dialog_InputPassWord *ui;
};

#endif // DIALOG_INPUTPASSWORD_H
