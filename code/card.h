#ifndef CARD_H
#define CARD_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlRecord>
#include "transfer.h"
#include "transfer2.h"
#include "replenish.h"

namespace Ui {
class card;
}

class card : public QDialog
{
    Q_OBJECT

public:
    explicit card(QWidget *parent = nullptr);
    ~card();
    void set_ID(int new_id);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::card *ui;
    Transfer* tr1;
    Transfer2* tr2;
    Replenish* rep;
    int id = 0;
    QSqlQuery query;
    QSqlRecord rec;
};

#endif // CARD_H
