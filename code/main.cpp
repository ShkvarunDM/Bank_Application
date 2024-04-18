#include "mainwindow.h"
#include "registration.h"
#include "account.h"
#include <QApplication>
#include "transfer.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
