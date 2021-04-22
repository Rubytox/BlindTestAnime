#ifndef QENTRY_H
#define QENTRY_H

#include "entry.h"

#include <QString>
#include <QUrl>

class QEntry : public Entry
{
public:
    using Entry::Entry;

    QEntry(QString& name, QString& artist, QString& anime, int number, Type& type, QUrl& path);
    QEntry(QString& name, QString& artist, QString& anime, int number, Type& type, QString& path);

    QString getName() const;
    QString getArtist() const;
    QString getAnime() const;

    QString getType() const;
    QString getShortType() const;
    QUrl getPath() const;
};

#endif // QENTRY_H
