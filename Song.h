/*
 * Blake Adams
 * UtPod Lab 5
 * 11/1/18
 */

#ifndef SONG_H
#define SONG_H

#include <string>

using namespace std;

class Song {

private:
    string artist;
    string title;
    int size;


public:

    /*
     * Default Constructor
     * Artist and Title are set to ""
     * Size is set to 0
     */
    Song();

    /*
     * Constructor with parameters
     * Creates a song with a defined artist, title, and size
     */
    Song(string artistName,string songTitle, int songSize);

    /*
     * Name: getArtist
     * Description: Returns the name of the artist
     * Input: N/A
     * Output: the name of the artist
     */
    string getArtist() const;

    /*
     * Name: setArtist
     * Description: Changes the name of the artist
     * Input: string newArtist - the artist to change to
     * Output: N/A
     */
    void setArtist(string newArtist);

    /*
     * Name: getTitle
     * Description: Returns the title of the song
     * Input: N/A
     * Output: the title of the song
     */
    string getTitle() const;

    /*
     * Name: setTitle
     * Description: Changes the title of the song
     * Input: string newTitle - the title to change to
     * Output: N/A
     */
    void setTitle(string newTitle);

    /*
     * Name: getSize
     * Description: Returns the size of the song
     * Input: N/A
     * Output: the size of the song
     */
    int getSize() const;

    /*
     * Name: setSize
     * Description: Changes the size of the artist
     * Input: string newSize - the size to change to
     * Output: N/A
     */
    void setSize(int newSize);


    bool operator >(Song const &rhs);
    bool operator ==(Song const &rhs);
    bool operator <(Song const &rhs);

    ~Song();
};


#endif //SONG_H
