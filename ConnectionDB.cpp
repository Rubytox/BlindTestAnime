#include "ConnectionDB.h"

/**
 * @brief ConnectionDB::ConnectionDB
 * Connects to the SQLite database and creates the entries table
 * if not existing.
 */
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
    }
}

/**
 * @brief ConnectionDB::_instance
 * This is the unique instance of the connection: it implements
 * a Singleton design pattern.
 */
ConnectionDB ConnectionDB::_instance;
/**
 * @brief ConnectionDB::getInstance
 *
 * @return The unique instance of the database connection.
 */
ConnectionDB& ConnectionDB::getInstance() noexcept
{
    return _instance;
}

/**
 * @brief ConnectionDB::prepareStatement
 * Wrapper for easy creation of prepared statements.
 * It simply prepares the given request for immediate use
 * in the current connection.
 *
 * @param sql 	The query to prepare.
 *
 * @return	An object representign the prepared statement.
 */
QSqlQuery ConnectionDB::prepareStatement(QString sql)
{
    QSqlQuery stmt;
    stmt.prepare(sql);
    return stmt;
}
