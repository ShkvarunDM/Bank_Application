#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QValidator>
#include <QRegularExpressionValidator>

namespace Ui {
class Registration;
}

class Registration : public QDialog
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = nullptr);
    ~Registration();
    void state_1();
    void state_2();
    void state_3();
    void read_info_1(QString n1,QString n2,QString n3);
    void clear_data();

public slots:
    void increase();
    void decrease();
    void state();
    void read_info();
signals:
    void clkChanged(int);
    void first_window();
private:
    Ui::Registration *ui;
    int clk;
    QSqlQuery* query;

};

#endif // REGISTRATION_H
