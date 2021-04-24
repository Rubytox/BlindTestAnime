#include "Entry.h"

using namespace std;

/**
 * @brief Entry::Entry
 * An Entry basically consists in a video and metadata.
 *
 * @param name 		The name of the song.
 * @param artist 	The artist of the song.
 * @param anime 	The anime the song is from.
 * @param number 	The number of the song: which opening or ending for instance.
 * @param type		The type of the song: opening, ending or OST.
 * @param path		The path to the video, or at least audio.
 */
Entry::Entry(const string& name,
             const string& artist,
             const string& anime,
             int number,
             const Entry::Type& type,
             const string& path) : _name(name), _artist(artist), _anime(anime), _number(number), _type(type), _path(path)
{
}

/**
 * @brief Entry::getName
 * @return The name of the song.
 */
string Entry::getName() const
{
    return _name;
}

/**
 * @brief Entry::getArtist
 * @return The artist of the song.
 */
string Entry::getArtist() const
{
    return _artist;
}

/**
 * @brief Entry::getAnime
 * @return The anime the song is from.
 */
string Entry::getAnime() const
{
    return _anime;
}

/**
 * @brief Entry::getNumber
 * @return 	The number of the song in the set of songs of the same type
 * 			from the same anime.
 */
int Entry::getNumber() const
{
    return _number;
}

/**
 * @brief Entry::getType
 * Converts the Entry::Type enumeration to string.
 *
 * @return The type of the song: opening, ending or OST.
 */
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

/**
 * @brief Entry::getShortType
 * Alternative to Entry::getType.
 *
 * @return The type of the song: opening, ending or OST.
 */
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

/**
 * @brief Entry::getPath
 * @return The path to the video.
 */
string Entry::getPath() const
{
    return _path;
}
