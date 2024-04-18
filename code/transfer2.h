#ifndef TRANSFER2_H
#define TRANSFER2_H

#include <QDialog>

namespace Ui {
class Transfer2;
}

class Transfer2 : public QDialog
{
    Q_OBJECT

public:
    explicit Transfer2(QWidget *parent = nullptr);
    ~Transfer2();
    void set_ID(int new_id);
    void clear_line();

private slots:
    void on_pushButton_tr_clicked();

private:
    Ui::Transfer2 *ui;
    int id =0;
};

#endif // TRANSFER2_H
