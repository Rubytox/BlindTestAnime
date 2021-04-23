#include "Entry.h"

using namespace std;

Entry::Entry(const string& name,
             const string& artist,
             const string& anime,
             int number,
             const Entry::Type& type,
             const string& path) : _name(name), _artist(artist), _anime(anime), _number(number), _type(type), _path(path)
{
}

string Entry::getName() const
{
    return _name;
}

string Entry::getArtist() const
{
    return _artist;
}

string Entry::getAnime() const
{
    return _anime;
}

int Entry::getNumber() const
{
    return _number;
}

string Entry::getType() const
{
    switch (_type) {
    case OPENING:
        return "Opening";

    case ENDING:
        return "Ending";

    case OST:
        return "OST";

    default:
        return "";
    }
}

string Entry::getShortType() const
{
    switch (_type) {
    case OPENING:
        return "OP";

    case ENDING:
        return "ED";

    case OST:
        return "OST";

    default:
        return "";
    }
}


string Entry::getPath() const
{
    return _path;
}
