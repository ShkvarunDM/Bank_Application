#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "registration.h"
#include "account.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void account_window();

private slots:
    void on_register_button_clicked();
    void on_sign_in_button_clicked();

private:
    Ui::MainWindow *ui;
    Account * ac;
    Registration * rg;

};
#endif // MAINWINDOW_H
