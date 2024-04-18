#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QVector>
#include <QMessageBox>
#include <QDebug>
#include <QSqlRecord>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
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

    ac = new Account();
    connect(ac,&Account::first_window,this,&MainWindow::show);

    rg = new Registration();
    connect(rg,&Registration::first_window,this,&MainWindow::show);
    connect(this,&MainWindow::account_window,ac, &Account::show);
    connect(this,&MainWindow::account_window,ac, &Account::out_info);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_register_button_clicked()
{
    rg->show();
    this->close();

}

void MainWindow::on_sign_in_button_clicked()
{
    QSqlQuery query;

    QString str = QString("select * from client where card = '%0' and password1 = '%1'").arg(ui->lineEdit->text()).arg(ui->lineEdit_2->text());
    query.exec(str);
    int record = query.size();
    QSqlRecord rec     = query.record();

    if (record == 1){
        query.next();
        int nNumber  = query.value(rec.indexOf("id")).toInt();
        ac->set_ID(nNumber);
        emit account_window();
        this->close();
    }
    else{
        QMessageBox::warning(this,"Error", "Incorrect number card or password ");
    }
}

