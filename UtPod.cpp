/*
 * Blake Adams
 * UtPod Lab 5
 * 11/1/18
 */


#include <iostream>
#include <ctime>
#include "UtPod.h"

using namespace std;


    UtPod::UtPod()
    {
        songs = NULL;
        memSize = MAX_MEMORY;
    }

    UtPod::UtPod(int size)
    {
        songs = NULL;
        if (size<=0 || size>MAX_MEMORY)
            memSize = MAX_MEMORY;
        else
            memSize = size;
    }


    int UtPod::addSong(Song const &s)
    {
        //cout << "Trying to add: Artist-" << s.getArtist() << " Title-" << s.getTitle() << " Size-" << s.getSize() << endl;
        if (s.getSize()>0 && s.getSize()<=getRemainingMemory())
        {
            SongNode *temp = new SongNode;
            temp->s.setArtist(s.getArtist());
            temp->s.setTitle(s.getTitle());
            temp->s.setSize(s.getSize());
            //temp->s=s;
            temp->next = songs;
            songs = temp;
            //cout << s.getTitle() << " successfully added" << endl;
            return SUCCESS;
        }
        else
        {
            //cout << "Not enough memory" << endl;
            return NO_MEMORY;
        }
    }

    int UtPod::removeSong(Song const &s)
    {
        if (songs!=NULL)
        {
            SongNode *p = songs;
            if (p->s == s)
            {
                songs = p->next;
                delete p;
                return SUCCESS;
            }
            else
            {
                SongNode *tail = p;
                p = p->next;
                while (p!=NULL)
                {
                    if (p->s == s)
                    {
                        tail->next = p->next;
                        delete p;
                        return SUCCESS;
                    }
                    else
                    {
                        tail = p;
                        p = p->next;
                    }
                }
                return NOT_FOUND;
            }
        }
        else
        {
            return NOT_FOUND;
        }
    }

    void UtPod::shuffle()
    {
        int numSongs = countSongs();
        if (numSongs>1)
        {
            unsigned int currentTime = (unsigned)time(0);
            srand(currentTime);
            for (int i = 0; i<numSongs; i++)
            {
                long indexOne = (rand()%numSongs);
                long indexTwo = (rand()%numSongs);
                SongNode *p1 = songs;
                SongNode *p2 = songs;
                for (int j = 0; j<indexOne; j++)
                {
                    p1 = p1->next;
                }
                for (int k = 0; k<indexTwo; k++)
                {
                    p2 = p2->next;
                }
                Song temp = p1->s;
                p1->s = p2->s;
                p2->s = temp;
            }
        }
    }

    void UtPod::showSongList()
    {
        cout << endl << "Songs: " << endl;
        if (songs!=NULL)
        {
            SongNode *p = songs;
            while (p!=NULL)
            {
                cout << "- Title: " << p->s.getTitle() << "\tArtist: " << p->s.getArtist() << "\tSize: " << p->s.getSize() << "MB" << endl;
                p = p->next;
            }
        }
        cout << "Total Number of Songs: " << countSongs() << endl << endl;
    }

    void UtPod::sortSongList()
    {
        int numSongs = countSongs();
        if (numSongs>1)
        {
            SongNode *selectionIndex = songs;
            for (int i = 0; i<numSongs-1; i++)
            {
                SongNode *smallest = selectionIndex;
                SongNode *p = smallest;
                for (int j = i+1; j<numSongs; j++)
                {
                    p = p->next;
                    if (p->s<smallest->s)
                    {
                        smallest = p;
                    }
                }
                swap(selectionIndex,smallest);
                selectionIndex = selectionIndex->next;
            }
        }
    }

    void UtPod::clearMemory()
    {
        SongNode *p = songs;
        while (p!=NULL)
        {
            songs = p->next;
            delete p;
            p = songs;
        }
    }


    int UtPod::getRemainingMemory()
    {
        int countMem = 0;
        if (songs!=NULL)
        {
            SongNode *p = songs;
            while (p!=NULL)
            {
                countMem += p->s.getSize();
                p = p->next;
            }
        }
        return getTotalMemory()-countMem;
    }

    UtPod::~UtPod()
    {
        SongNode *p = songs;
        while (p!=NULL)
        {
            songs = p->next;
            delete p;
            p = songs;
        }
    }