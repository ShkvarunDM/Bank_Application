#include "transfer2.h"
#include "ui_transfer2.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include <QMessageBox>

Transfer2::Transfer2(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Transfer2)
{
    ui->setupUi(this);
}

Transfer2::~Transfer2()
{
    delete ui;
}

void Transfer2::set_ID(int new_id){
    id = new_id;
}

void Transfer2::clear_line(){
    ui->lineEdit_phone->clear();
    ui->lineEdit_sum->clear();
}

void Transfer2::on_pushButton_tr_clicked()
{
    QSqlQuery query;

    QString str = QString("select * from client where id = " + QString::number(id));
    query.exec(str);
    QSqlRecord rec  = query.record();
    query.next();
    int my_balance  = query.value(rec.indexOf("balance")).toInt();
    int result_my_balance = my_balance - ui->lineEdit_sum->text().toInt();

    if (result_my_balance < 0){
        QMessageBox::warning(this,"Error", "insufficient funds");
    }
    else {
        QString str1 = QString("UPDATE client SET balance = " + QString::number(result_my_balance) +  " where  id = " + QString::number(id));
        query.exec(str1);

        QString str3 = QString("select * from client where phone = '%0' ").arg(ui->lineEdit_phone->text());
        query.exec(str3);
        rec  = query.record();
        query.next();
        int balance  = query.value(rec.indexOf("balance")).toInt();
        int result_balance = balance + ui->lineEdit_sum->text().toInt();

        QString str4 = QString("UPDATE client SET balance = " + QString::number(result_balance) +  " where phone = '%0' ").arg(ui->lineEdit_phone->text());
        query.exec(str4);

        clear_line();
        this->close();
    }


}

