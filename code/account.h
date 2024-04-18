#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QDialog>
#include <QPushButton>
#include "card.h"
#include "data.h"


namespace Ui {
class Account;
}

class Account : public QDialog
{
    Q_OBJECT
public:
    explicit Account(QWidget *parent = nullptr);
    ~Account();
    void set_ID(int new_id);
public slots:
    void out_info();
signals:
    void first_window();
private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_1_clicked();

private:
    Ui::Account *ui;
    int id = 0;
    card* Card;
    Data* data;
    Transfer* tr1;
    Transfer2* tr2;
};

#endif // ACCOUNT_H
