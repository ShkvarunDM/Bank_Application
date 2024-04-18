#ifndef REPLENISH_H
#define REPLENISH_H

#include <QDialog>

namespace Ui {
class Replenish;
}

class Replenish : public QDialog
{
    Q_OBJECT

public:
    explicit Replenish(QWidget *parent = nullptr);
    ~Replenish();
    void set_ID(int new_id);

private slots:
    void on_pushButton_rep_clicked();

private:
    Ui::Replenish *ui;
    int id = 0;
};

#endif // REPLENISH_H
