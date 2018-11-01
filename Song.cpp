/*
 * Blake Adams
 * UtPod Lab 5
 * 11/1/18
 */

#include "Song.h"

using namespace std;

    Song::Song()
    {
        artist = "";
        title = "";
        size = 0;
    }

    Song::Song(string artistName,string songTitle, int songSize)
    {
        artist = artistName;
        title = songTitle;
        size = songSize;
    }

    string Song::getArtist() const
    {
        return artist;
    }

    void Song::setArtist(string newArtist)
    {
        artist = newArtist;
    }

    string Song::getTitle() const
    {
        return title;
    }

    void Song::setTitle(string newTitle)
    {
        title = newTitle;
    }

    int Song::getSize() const
    {
        return size;
    }

    void Song::setSize(int newSize)
    {
        size = newSize;
    }

    bool Song::operator >(Song const &rhs)
    {
        if (artist>rhs.artist)
        {
            return true;
        }
        else if  (artist==rhs.artist)
        {
            if (title>rhs.title)
            {
                return true;
            }
            else if  (artist==rhs.artist)
            {
                return (size>rhs.size);
            }
            else
                return false;
        }
        else
            return false;



    }

    bool Song::operator ==(Song const &rhs)
    {
        return (artist==rhs.artist && title==rhs.title && size==rhs.size);
    }

    bool Song::operator <(Song const &rhs)
    {
        return (artist<rhs.artist || (artist==rhs.artist && (title<rhs.title || (title==rhs.title &&  size<rhs.size))));
    }

    Song::~Song()
    {

    }

