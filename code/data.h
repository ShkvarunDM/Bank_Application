#ifndef DATA_H
#define DATA_H

#include <QDialog>

namespace Ui {
class Data;
}

class Data : public QDialog
{
    Q_OBJECT

public:
    explicit Data(QWidget *parent = nullptr);
    ~Data();
    void set_ID(int new_id);

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::Data *ui;
    int id = 0;
};

#endif // DATA_H
