#ifndef TRANSFER_H
#define TRANSFER_H

#include <QDialog>

namespace Ui {
class Transfer;
}

class Transfer : public QDialog
{
    Q_OBJECT

public:
    explicit Transfer(QWidget *parent = nullptr);
    ~Transfer();
    void set_ID(int new_id);
    void clear_line();
signals:
    void card_window();
private slots:
    void on_pushButton_tr_clicked();

private:
    Ui::Transfer *ui;
    int id = 0;
};

#endif // TRANSFER_H
