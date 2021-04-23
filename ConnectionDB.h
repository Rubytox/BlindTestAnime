#ifndef CONNECTIONDB_H
#define CONNECTIONDB_H

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>

#include <QDebug>
#include <QFile>

#include <iostream>

class ConnectionDB
{
private:
    ConnectionDB();

    static ConnectionDB _instance;

    QSqlDatabase _connection;

public:
    static ConnectionDB& getInstance() noexcept;

    QSqlQuery prepareStatement(QString sql);
};

#endif // CONNECTIONDB_H
