#include "dialog_inputpassword.h"
#include "ui_dialog_inputpassword.h"

Dialog_InputPassWord::Dialog_InputPassWord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_InputPassWord)
{
    ui->setupUi(this);
}

Dialog_InputPassWord::~Dialog_InputPassWord()
{
    delete ui;
}

void Dialog_InputPassWord::on_pushButton_inputPassWord_clicked()
{
    if(this->ui->lineEdit_inputPassWord->text() == PASSWORD)
    {
        this->accept();
    }else
    {
        this->close();
    }
}
