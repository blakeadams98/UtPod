/*
 * Blake Adams
 * UtPod Lab 5
 * 11/1/18
 */

/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

*/
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{

    cout << "Constructor Tests" << endl;

    UtPod t;
    UtPod t2(105);
    UtPod t3(516);
    UtPod t4(-50);

    cout << "Test 1: UtPod t          Memory = " << t.getTotalMemory() <<  "\tDefault Constructor" << endl;
    cout << "Test 2: UtPod t2(105)    Memory = " << t2.getTotalMemory() << "\tOverriden Constructor" << endl;
    cout << "Test 3: UtPod t3(516)    Memory = " << t3.getTotalMemory() << "\tMemory over limit" << endl;
    cout << "Test 4: UtPod t4(-50)    Memory = " << t4.getTotalMemory() << "\tMemory under zero" << endl;

    cout << endl << "addSong Tests" << endl;

    Song s1("Travis Scott", "goosebumps", 70);
    int result = t.addSong(s1);
    cout << "Test 1: add s1(Travis Scott, goosebumps, 70)\t   Result = " << result << "\tNormal Add" << endl;

    Song s2("Travis Scott", "YOSEMITE", 40);
    result = t.addSong(s2);
    cout << "Test 2: add s2(Travis Scott, YOSEMITE, 40)\t   Result = " << result << "\tNormal Add" << endl;

    Song s3("Travis Scott", "goosebumps", 70);
    result = t.addSong(s3);
    cout << "Test 3: add s3(Travis Scott, goosebumps, 70)\t   Result = " << result << "\tDuplicate Add" << endl;

    Song s4("ASAP Rocky", "Buck Shots", 25);
    result = t.addSong(s4);
    cout << "Test 4: add s4(ASAP Rocky, Buck Shots, 25)\t   Result = " << result << "\tNormal Add" << endl;

    Song s5("21 Savage", "Ric Flair Drip", 47);
    result = t.addSong(s5);
    cout << "Test 5: add s5(21 Savage, Ric Flair Drip, 47)\t   Result = " << result << "\tNormal Add" << endl;

    Song s6("Future", "Mask Off", -5);
    result = t.addSong(s6);
    cout << "Test 6: add s6(Future, Mask Off, -5)\t\t   Result = " << result << "\tInvalid Song" << endl;

    Song s7("Maxo Kream", "Roaches", 300);
    result = t.addSong(s7);
    cout << "Test 7: add s7(Maxo Kream, Roaches, 300)\t   Result = " << result << "\tNo Memory Avaiable" <<endl;



    cout << endl << "Show Song List Test: Normal Case";
    t.showSongList();



    cout << "Remaining Memory: Normal Case Test 1:" << endl;
    cout << "Remaining Memory " << t.getRemainingMemory() << endl;



    cout << endl << "removeSong Tests" << endl;

    Song s8("Kendrick Lamar", "ELEMENT", 56);
    result = t.removeSong(s8);
    cout << "Test 1: remove s8(Kendrick Lamar, ELEMENT, 56)\t   Result = " << result << "\tSong not in UtPod" << endl;

    result = t.removeSong(s5);
    cout << "Test 2: remove s5(21 Savage, Ric Flair Drip, 47)   Result = " << result << "\tNormal Remove" << endl;

    result = t.removeSong(s1);
    cout << "Test 3: remove s1(Travis Scott, goosebumps, 70)\t   Result = " << result << "\tDuplicate Remove" << endl;

    result = t.removeSong(s3);
    cout << "Test 4: remove s3(Travis Scott, goosebumps, 70)\t   Result = " << result << "\tNormal Remove" << endl;

    result = t.removeSong(s4);
    cout << "Test 5: remove s4(ASAP Rocky, Buck Shots, 25)\t   Result = " << result << "\tNormal Remove" << endl;

    result = t.removeSong(s2);
    cout << "Test 6: remove s2(Travis Scott, YOSEMITE, 40)\t   Result = " << result << "\tNormal Remove" << endl;

    result = t.removeSong(s2);
    cout << "Test 7: remove s2(Travis Scott, YOSEMITE, 40)\t   Result = " << result << "\tUtPod is Empty" << endl;


    cout << endl <<  "Show Song List Test: Empty UtPod Case";
    t.showSongList();


    cout << "Remaining Memory: Empty UtPod Case:" << endl;
    cout << "Remaining Memory " << t.getRemainingMemory() << endl;



    t.addSong(s1);
    t.addSong(s2);
    t.addSong(s3);
    t.addSong(s4);
    t.addSong(s5);

    Song s9("Mac Miller", "Self Care", 26);
    Song s10("Rae Sremmurd", "Powerglide", 42);
    Song s12("Rae Sremmurd", "Powerglide", 60);
    Song s11("ScHoolboy Q", "THat Part", 55);

    t.addSong(s9);
    t.addSong(s10);
    t.addSong(s11);
    t.addSong(s12);

    t.showSongList();



    cout << endl << "Shuffle/Sort Test Cases" << endl << endl;

    t.shuffle();
    cout << "Shuffle Test 1:";
    t.showSongList();

    t.sortSongList();
    cout << "Sort Test 1:";
    t.showSongList();

    t.shuffle();
    cout << "Shuffle Test 2:";
    t.showSongList();

    t.sortSongList();
    cout << "Sort Test 2:";
    t.showSongList();


    cout << "Total Memory " << t.getTotalMemory() << endl << endl;
    cout << "Remaining Memory: Normal Case Test 2:" << endl;
    cout << "Remaining Memory " << t.getRemainingMemory() << endl;

    cout << "Clear Memory: Normal Case Test 1:" << endl;
    t.clearMemory();
    t.showSongList();


    cout << "Clear Memory: Empty UtPod" << endl;
    t.clearMemory();
    t.showSongList();
}