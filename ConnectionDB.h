#ifndef CONNECTIONDB_H
#define CONNECTIONDB_H

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>

#include <QDebug>
#include <QFile>

#include <iostream>

/**
 * @brief The ConnectionDB class
 * This class represents a connection to a database.
 * It allows users to prepare statements.
 * It is implemented following a Singleton design pattern
 * in order to have a maximum of one connection to the
 * same database.
 */
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
