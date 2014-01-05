/* 
 * File:   CHallFame.cpp
 * Author: soniyj
 * 
 * Created on 4 gennaio 2014, 12.48
 */

#include "CHallFame.h"

#include <algorithm>
#include <fstream>

CHallFame::CHallFame() {
    this->fileName = "hallfame.dat";
    this->numElements = 10;
    this->mapHall[this->numElements];
}

CHallFame::CHallFame(const CHallFame& orig) {
}

CHallFame::~CHallFame() {
}

bool CHallFame::saveFile() {
    ofstream mfile;
    
    //mfile.open(this->fileName, ios::out | ios::binary);
    if(mfile.is_open()) {
        for(int i=0; i<this->mapHall.size(); i++) {
            ;
        }
    }
    else {
        cout << "Impossible to create the file: " << this->fileName << endl;
        return false;
    }
    return true;
}

bool orderHall(SHallPlayers i, SHallPlayers j) {
    return(i.score > j.score);
}

bool isGreat(SHallPlayers i, unsigned int score) {
    return(i.score < score);
}

bool isGreat1(unsigned int score, SHallPlayers i) {
    return(i.score < score);
}

/* Player score, name, level, lives */
void CHallFame::update(unsigned int score, string name, unsigned short level, unsigned short lives) {
    SHallPlayers hallPlayer;
    vector<SHallPlayers>::iterator it;
    
    hallPlayer.score = score;
    hallPlayer.name = name;
    hallPlayer.level = level;
    hallPlayer.lives = lives;
    
    sort(this->mapHall.begin(), this->mapHall.end(), orderHall);
    
    if(this->mapHall.size() == this->numElements) {
        cout << "Yes erase last one\n";
        this->mapHall.pop_back();
    }
    
    it = this->mapHall.begin();
    /* Inserting the first time */
    if(this->mapHall.size() == 0) {
        cout << "A\n";
        this->mapHall.push_back(hallPlayer);
    }
    /* Inserting on Top */
    else if(score >= it->score) {
        cout <<"B\n";
        this->mapHall.insert(it, hallPlayer);
    }
    /* Inserting in the middle */
    else /*if(score > this->mapHall.end()->score)*/ {
        cout << "C " << score << "\n";
        //it = lower_bound(this->mapHall.begin(), this->mapHall.end(), score, isGreat);
        //it = upper_bound(this->mapHall.begin(), this->mapHall.end(), score, isGreat1);
        //it = find_if(this->mapHall.begin(), this->mapHall.end(), orderHall);
        for(int i=this->mapHall.size(); i!=0; i--) {
            if(score > this->mapHall[i].score) {
                //it = this->mapHall.begin()+
                cout << "QAZ: " << this->mapHall[i].score << endl;
            }
        }
        cout << "Got it: " << it->score << " | " << (it-this->mapHall.begin()) << endl;
        this->mapHall.insert(it+1, hallPlayer);
    }
    
    for(int i=0; i < this->mapHall.size(); i++) {
        cout << "Jep: " << this->mapHall[i].score << endl;
    }
}