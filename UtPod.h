/*
 * Blake Adams
 * UtPod Lab 5
 * 11/1/18
 */

#ifndef UTPOD_H
#define UTPOD_H
#include "Song.h"

//UtPod class declaration
class UtPod
{
private:
    static const int MAX_MEMORY = 512;
    static const int SUCCESS = 0;
    static const int NO_MEMORY = -1;
    static const int NOT_FOUND = -2;

    struct SongNode
    {
        Song s;
        SongNode *next;
    };

    SongNode *songs;  //the head pointer

    int memSize;

    /*
    * Name: int countSongs
    * Description: Returns the number of songs in the UtPod
    * Input: N/A
    * Output: the number of songs in the UtPod
    */
    int countSongs()
    {
        int count = 0;
        if (songs!=NULL)
        {
            SongNode *p = songs;
            while (p!=NULL)
            {
                count++;
                p = p->next;
            }
        }
        return count;
    }


    /*
    * Name: swap
    * Description: Switches the songs of two songNodes
    * Input: SongNode* first, SongNode* second
    * Output: N/A
    */
    void swap(SongNode* first, SongNode* second)
    {
        Song temp = first->s;
        first->s = second->s;
        second->s = temp;
    }

public:

    /*
     * Default Constructor
     * Memory is set to max (512 MB)
     */
    UtPod();

    /*
     * Constructor with size parameter
     * Creates a UtPod object with a defined size
     * Input: int size - size of the UtPod to be created
     * Output: N/A
     */
    UtPod(int size);

    /*
     * Name: int addSong
     * Description: Adds a valid song to the UtPod if there is memory available
     * Precondition: s is a valid song
     * Input: Song const &s - song to be added
     * Output: 0 if song was added, -1 if invalid or not enough memory
     */
    int addSong(Song const &s);

    /*
    * Name: int removeSong
    * Description: Attempts to remove the first instance of a song from the UtPod
    * Input: Song const &s - song to be removed
    * Output: 0 if song was removed, -2 if nothing is removed
    */
    int removeSong(Song const &s);


    /*
     * Name: shuffle
     * Description: Shuffles the songs into a random order if there are 2 or more songs
     * Input: N/A
     * Output: N/A
     */
    void shuffle();

    /*
     * Name: showSongList
     * Description: Prints the current list of songs in the UtPod in order from first to last
     * Input: N/A
     * Output: N/A
     */
    void showSongList();

    /*
     * Name: sortSongList
     * Description: Sorts the list of songs in ascending order by Artist, Title and Sizes if there are 2 or more songs
     * Input: N/A
     * Output: N/A
     */
    void sortSongList();

    /*
     * Name: clearMemory
     * Description: Clears all the songs from the UtPod
     * Input: N/A
     * Output: N/A
     */
    void clearMemory();

    /*
     * Name: getTotalMemory
     * Description: Returns the total amount of memory in the UtPod
     * Input: N/A
     * Output: The size of the UtPod
     */
    int getTotalMemory() {
        return memSize;
    }

    /*
     * Name: getRemainingMemory
     * Description: Returns the remaining amount of memory in th UtPod
     * Input: N/A
     * Output: The remaining size of the UtPod
     */
    int getRemainingMemory();

    /*
     * Destructor
     * Memory is deallocated
     */
    ~UtPod();

};



#endif