#include "qentry.h"


QEntry::QEntry(QString &name,
               QString &artist,
               QString &anime,
               int number,
               Entry::Type &type,
               QUrl &path) : Entry(name.toStdString(),
                                   artist.toStdString(),
                                   anime.toStdString(),
                                   number,
                                   type,
                                   path.toString().toStdString())
{
}

QEntry::QEntry(QString &name,
               QString &artist,
               QString &anime,
               int number,
               Entry::Type &type,
               QString &path) : Entry(name.toStdString(),
                                      artist.toStdString(),
                                      anime.toStdString(),
                                      number,
                                      type,
                                      path.toStdString())
{
}

QString QEntry::getName() const
{
    return QString::fromStdString(_name);
}

QString QEntry::getArtist() const
{
    return QString::fromStdString(_artist);
}

QString QEntry::getAnime() const
{
    return QString::fromStdString(_anime);
}

QString QEntry::getType() const
{
    const Entry *base = static_cast<const Entry*>(this);
    return QString::fromStdString(base->getType());
}

QString QEntry::getShortType() const
{
    const Entry *base = static_cast<const Entry*>(this);
    return QString::fromStdString(base->getShortType());
}

QUrl QEntry::getPath() const
{
    return QUrl::fromLocalFile(QString::fromStdString(_path));
}
