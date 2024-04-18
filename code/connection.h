#ifndef CONNECTION_H
#define CONNECTION_H
/*#include <QSqlDatabase>
#include <QDebug>

bool create_connection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setConnectOptions();
    db.setHostName("localhost");
    db.setDatabaseName("bank_bd");
    db.setPort(5432);
    db.setUserName("postgres");
    db.setPassword("060809");

    if(!db.open())
    {
        qDebug()<<"не удалось подключиться к базе данных";
        return true;
    }
    else
    {
        qDebug()<<"успешное подключение";
        return false;
    }
}
*/

#endif // CONNECTION_H
