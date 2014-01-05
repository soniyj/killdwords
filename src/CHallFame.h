/* 
 * File:   CHallFame.h
 * Author: soniyj
 *
 * Created on 4 gennaio 2014, 12.48
 */

#ifndef __CHALLFAME_H__
#define	__CHALLFAME_H__

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct SHallPlayers {
    unsigned int score;
    string name;
    unsigned short level;
    unsigned short lives;
};

class CHallFame {
public:
    CHallFame();
    CHallFame(const CHallFame& orig);
    virtual ~CHallFame();
    void setFileName(string);
    string getFileName() const;
    void setNumElements(unsigned short);
    void getNumElements() const;
    void update();
    void update(unsigned int,string,unsigned short,unsigned short);
    bool loadFile();
    bool saveFile();
private:
    string fileName;
    unsigned short numElements;
    //map<unsigned int,SHallPlayers&> mapHall;
    vector<SHallPlayers> mapHall;
};

#endif	/* __CHALLFAME_H __*/
