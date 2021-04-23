#include "QEntryDAO.h"

QEntry QEntryDAO::get(int id)
{
    return QEntry("Renai Circulation", "Kana Hanazawa", "Bakemonogatari", 4, Entry::Type::OPENING, "C:\\Users\\cFAG\\Videos\\renai-circulation.mp4");
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
    stmt.bindValue(":path", entry.getPath());

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
