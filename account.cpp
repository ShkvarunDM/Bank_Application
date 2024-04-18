#include "account.h"
#include "ui_account.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QGroupBox>
#include <QCoreApplication>

Account::Account(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Account)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setConnectOptions();
    db.setHostName("localhost");
    db.setDatabaseName("bank_bd");
    db.setPort(5432);
    db.setUserName("postgres");
    db.setPassword("060809");
    bool connected = db.open();

    Card = new card();

    connect(ui->pushButton_2,SIGNAL(clicked()),Card,SLOT(show()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(close()));

    data = new Data();
    connect(ui->pushButton_1,SIGNAL(clicked()),data,SLOT(show()));

    tr1 = new Transfer();
    tr2 = new Transfer2();

}

Account::~Account()
{
    delete ui;
}

void Account::set_ID(int new_id){
    id = new_id;
    Card->set_ID(new_id);
    data->set_ID(new_id);
    tr1->set_ID(new_id);
    tr2->set_ID(new_id);
}

void Account::out_info(){

    QSqlQuery query;
    QString str = QString("select * from client where id = '%0'").arg(id);
    query.exec(str);
    QSqlRecord rec  = query.record();
    query.next();
    QString name  = query.value(rec.indexOf("firstname")).toString();
    ui->lineEdit_name->setText("Hello, " + name + "!");
}


void Account::on_pushButton_3_clicked()
{

    ui->label->setText("TRANSFER");
    QPushButton* button_card =  new QPushButton("by card number", this);
    button_card->setStyleSheet("background: #ee0979;border-radius: 12px; border:1px solid black;");
    button_card->setGeometry(510,325,180,30);
    button_card->show();
    connect(button_card,SIGNAL(clicked()),tr1,SLOT(show()));


    QPushButton* button_phone =  new QPushButton("by phone number", this);
    button_phone->setStyleSheet("background: #ee0979;border-radius: 12px; border:1px solid black;");
    button_phone->setGeometry(510, 405,180,30);
    button_phone->show();
    connect(button_phone,SIGNAL(clicked()),tr2,SLOT(show()));

    connect(ui->pushButton_1,SIGNAL(clicked()),button_card,SLOT(close()));
    connect(ui->pushButton_1,SIGNAL(clicked()),button_phone,SLOT(close()));
}


void Account::on_pushButton_1_clicked()
{

}

