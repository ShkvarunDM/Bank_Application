#include "card.h"
#include "ui_card.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>

card::card(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::card)
{
    ui->setupUi(this);



    tr1 = new Transfer();
    tr2 = new Transfer2();
    rep = new Replenish();

    connect(tr1,&Transfer::card_window,this,&card::show);
}

card::~card()
{
    delete ui;
}

void card::set_ID(int new_id){
    id = new_id;
    tr1->set_ID(new_id);
    tr2->set_ID(new_id);
    rep->set_ID(new_id);
}

void card::on_pushButton_clicked()
{
    QSqlQuery query;
    QString str = QString("select * from client where id = '%0'").arg(id);
    query.exec(str);
    QSqlRecord rec  = query.record();
    query.next();
    QString number_card  = query.value(rec.indexOf("card")).toString();
    QString balance = query.value(rec.indexOf("balance")).toString();
    ui->label_card->setText(number_card);
    ui->balance_label->setText(balance);
}


void card::on_pushButton_4_clicked()
{
    rep->show();
}


void card::on_pushButton_3_clicked()
{
    tr1->show();
}


void card::on_pushButton_2_clicked()
{
    tr2->show();
}

