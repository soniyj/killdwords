/* 
 * File:   CDicty.cpp
 * Author: soniyj
 *
 * Created on 26 November 2013, 12:12
 */

/* This class will contain the words to be showed */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iosfwd>

#include "CDicty.h"

using namespace std;

CDicty::CDicty() {
}

CDicty::CDicty(const CDicty& orig) {
}

/* Memory released */
CDicty::~CDicty() {
    if(this->strWord != NULL)
        delete [] strWord;
}

/**
 * This method will generate a random word
 */
void CDicty::generateWord() {
    ;
}

void CDicty::setStrWord(const char *tmp) {
    unsigned int len = strlen(tmp)+1;
    this->strWord = new char[len];
    memcpy(this->strWord, tmp, len);
}

char *CDicty::getStrWord() const {
    return(this->strWord);
}

unsigned short CDicty::getNumbers() {
    return this->numbers;
}

/*** Vector Initialisation ***/
/* This part will be substitute by SQL Lite */

/** 
 * Making a test dictionary
 * Each word is stored into a position related to the level
 */
void CDicty::makeVector() {
    /*this->words.insert(words.begin(),(char*)"SI");
    this->words.insert(words.begin()+1,(char*)"NO");
    this->words.insert(words.begin()+2,(char*)"TRE");
    this->words.insert(words.begin()+3,(char*)"PER");
    this->words.insert(words.begin()+4,(char*)"NAVE");
    this->words.insert(words.begin()+5,(char*)"CASA");
    this->words.insert(words.begin()+6,(char*)"ASINO");
    this->words.insert(words.begin()+7,(char*)"ZAINO");*/
    this->position = 0;
    //this->numbers = this->words.size();
}

/* for testing will make a vector for the level */
void CDicty::makeVector(unsigned short i) {
    /*words.clear();
    switch(i){
        case 0:
            this->words.insert(words.begin(),(char*)"SI");
            this->words.insert(words.begin()+1,(char*)"NO");
            break;
        case 1:
            this->words.insert(words.begin(),(char*)"TRE");
            this->words.insert(words.begin()+1,(char*)"PER");
            break;
        case 2:
            this->words.insert(words.begin(),(char*)"NAVE");
            this->words.insert(words.begin()+1,(char*)"CASA");
            break;
        case 3:
            this->words.insert(words.begin(),(char*)"ASINO");
            this->words.insert(words.begin()+1,(char*)"ZAINO");
    }*/
    this->position = 0;
    //this->numbers = this->words.size();
}

/* Making dictionary from a ready map */
/*void makeVectorFromMap(map) {
    ;
}*/

/* Making vector from another one past by map */
void CDicty::makeVector(vector<string> vect) {
    this->words = vect;
    this->position = 0;
    this->numbers = this->words.size();
}

/**
 * Return the word into the given position into the vector
 * @param position
 * @return word
 */
char* CDicty::getWordVector(unsigned int position) {
    //return this->words[position];
    return (char*)this->words[position].c_str();
}

/**
 * Return the next word into the vector.
 * It returns the word if exists or "" otherwise.
 * Updating the position after extraction.
 * @return 
 */
char* CDicty::getNextWordVector() {
    char *tmp;
    /*if(this->position < this->numbers) {
        tmp = this->words[position];
        this->position += 1;
        return tmp;
    }
    else {
        return (char*)"";
    }*/
    return (char*)"";
}

ostream& operator<<(ostream& os, const CDicty& cd) {
    os << "Start Printing\n";
    for (int i=0; i < cd.words.size(); i++) {
        os << "Word n. [" << i << "] = " << cd.words[i] << endl;
    }
    os << "End Printing\n";
    return os;
}

/*** End Vector ***/