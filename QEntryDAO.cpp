#include "QEntryDAO.h"

Entry::Type toType(QString string)
{
    if (string == "Opening")
        return Entry::Type::OPENING;
    if (string == "Ending")
        return Entry::Type::ENDING;
    if (string == "OST")
        return Entry::Type::OST;
    return Entry::Type::NONE;
}

QEntry QEntryDAO::get(int id)
{
    QString query = "SELECT * FROM entries WHERE id = ?";
    QSqlQuery stmt = ConnectionDB::getInstance().prepareStatement(query);
    stmt.addBindValue(id);

    stmt.exec();

    if (stmt.first()) {
        QString name = stmt.value("name").toString();
        QString artist = stmt.value("artist").toString();
        QString anime = stmt.value("anime").toString();
        int number = stmt.value("number").toInt();
        Entry::Type type = toType(stmt.value("type").toString());
        QUrl path = QUrl::fromLocalFile(stmt.value("path").toString());

        return QEntry(name, artist, anime, number, type, path);
    }
    exit(EXIT_FAILURE);
}

QVector<QEntry> QEntryDAO::getAll()
{
    QString query = "SELECT * FROM entries";
    QSqlQuery stmt = ConnectionDB::getInstance().prepareStatement(query);

    stmt.exec();

    QVector<QEntry> result;

    while (stmt.next()) {
        QString name = stmt.value("name").toString();
        QString artist = stmt.value("artist").toString();
        QString anime = stmt.value("anime").toString();
        int number = stmt.value("number").toInt();
        Entry::Type type = toType(stmt.value("type").toString());
        QUrl path = QUrl::fromLocalFile(stmt.value("path").toString());

        result.append(QEntry(name, artist, anime, number, type, path));
    }
    return result;
}

QSqlTableModel* QEntryDAO::getModel()
{
    QSqlTableModel *model = new QSqlTableModel(NULL, ConnectionDB::getInstance().getConnection());

    model->setTable("entries");
    model->select();
	model->setHeaderData(0, Qt::Horizontal, "ID");
	model->setHeaderData(1, Qt::Horizontal, "Name");
	model->setHeaderData(2, Qt::Horizontal, "Artist");
	model->setHeaderData(3, Qt::Horizontal, "Anime");
	model->setHeaderData(4, Qt::Horizontal, "Number");
	model->setHeaderData(5, Qt::Horizontal, "Type");
	model->setHeaderData(6, Qt::Horizontal, "Path");

    return model;
}

void QEntryDAO::save(QEntry entry)
{
    QString query = "INSERT INTO entries (name, artist, anime, number, type, path)"
                                 "VALUES (:name, :artist, :anime, :number, :type, :path)";
    QSqlQuery stmt = ConnectionDB::getInstance().prepareStatement(query);
    stmt.bindValue(":name", entry.getName());
    stmt.bindValue(":artist", entry.getArtist());
    stmt.bindValue(":anime", entry.getAnime());
    stmt.bindValue(":number", entry.getNumber());
    stmt.bindValue(":type", entry.getType());
    stmt.bindValue(":path", entry.getPath().toString(QUrl::RemoveScheme).mid(3));

    stmt.exec();
}

void QEntryDAO::update(QEntry entry)
{

}

QEntryDAO QEntryDAO::_instance;
QEntryDAO& QEntryDAO::getInstance() noexcept
{
    return _instance;
}
