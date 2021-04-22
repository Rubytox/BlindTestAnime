#ifndef ENTRY_H
#define ENTRY_H

#include <string>

class Entry
{
public:
    enum Type {
        NONE = 0,
        OPENING,
        ENDING,
        OST,
        NB
    };

    Entry(const std::string& name, const std::string& artist, const std::string& anime, int number, const Type& type, const std::string& path);

    std::string getName() const;
    std::string getArtist() const;
    std::string getAnime() const;
    int getNumber() const;

    std::string getType() const;
    std::string getShortType() const;
    std::string getPath() const;


protected:
    std::string _name;
    std::string _artist;
    std::string _anime;
    int _number;

    Type _type;
    std::string _path;
};

#endif // ENTRY_H
