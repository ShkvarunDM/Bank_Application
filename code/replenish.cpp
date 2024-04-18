#include "replenish.h"
#include "ui_replenish.h"
#include <QSqlQuery>
#include <QSqlRecord>

Replenish::Replenish(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Replenish)
{
    ui->setupUi(this);
}

Replenish::~Replenish()
{
    delete ui;
}

void Replenish::set_ID(int new_id){
    id = new_id;
}


void Replenish::on_pushButton_rep_clicked()
{
    QSqlQuery query;
    QString str = QString("select * from client where id = '%0'").arg(id);
    query.exec(str);
    QSqlRecord rec  = query.record();
    query.next();
    int balance  = query.value(rec.indexOf("balance")).toInt();
    int result_balance = balance + ui->lineEdit_sum->text().toInt();


    QString str2 = QString("UPDATE client SET balance = " + QString::number(result_balance) +  " where id = " + QString::number(id));
    query.exec(str2);

    this->close();
}

