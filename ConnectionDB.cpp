#include "ConnectionDB.h"


ConnectionDB::ConnectionDB()
{
    const QString DRIVER("QSQLITE");

    if (QSqlDatabase::isDriverAvailable(DRIVER)) {
        _connection = QSqlDatabase::addDatabase(DRIVER);

        bool createTable = !QFile::exists("entries.db");

        _connection.setDatabaseName("entries.db");
        if (!_connection.open())
            qWarning() << "ERROR:" << _connection.lastError();

        if (createTable) {
            QSqlQuery query("CREATE TABLE entries (id INTEGER PRIMARY KEY,"
                                                  "name TEXT,"
                                                  "artist TEXT,"
                                                  "anime TEXT,"
                                                  "number INTEGER,"
                                                  "type TEXT,"
                                                  "path TEXT)");
            if (!query.isActive())
                qWarning() << "ERROR:" << query.lastError().text();
        }


        /*
        QSqlQuery query("CREATE TABLE people (id INTEGER PRIMARY KEY, name TEXT)");
        if (!query.isActive())
            qWarning() << "ERROR:" << query.lastError().text();

        if (!query.exec("INSERT INTO people(name) VALUES('Eddie')"))
            qWarning() << "ERROR:" << query.lastError().text();

        query.prepare("SELECT name FROM people WHERE id = ?");
        query.addBindValue(1);
        if (!query.exec())
            qWarning() << "ERROR:" << query.lastError().text();

        if (query.first())
            std::cout << query.value(0).toString().toStdString() << std::endl;
        else
            std::cout << "Person not found" << std::endl;
            */
    }
}

ConnectionDB ConnectionDB::_instance;
ConnectionDB& ConnectionDB::getInstance() noexcept
{
    return _instance;
}

QSqlQuery ConnectionDB::prepareStatement(QString sql)
{
    QSqlQuery stmt;
    stmt.prepare(sql);
    return stmt;
}
