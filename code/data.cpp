#include "data.h"
#include "ui_data.h"
#include <QDebug>
#include <QSqlQuery>
#include<QSqlRecord>

Data::Data(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Data)
{
    ui->setupUi(this);
}

Data::~Data()
{
    delete ui;
}

void Data::set_ID(int new_id){
    id = new_id;
}

void Data::on_pushButton_3_clicked()
{
    QSqlQuery query;
    QString str = QString("select * from client where id = '%0'").arg(id);
    query.exec(str);
    QSqlRecord rec  = query.record();
    query.next();
    ui->label_fname->setText(query.value(rec.indexOf("firstname")).toString());
    ui->label_lname->setText(query.value(rec.indexOf("lastname")).toString());
    ui->label_datebirth->setText(query.value(rec.indexOf("datebirth")).toString());
    ui->label_email->setText(query.value(rec.indexOf("email")).toString());
    ui->label_phone->setText(query.value(rec.indexOf("phone")).toString());
}

