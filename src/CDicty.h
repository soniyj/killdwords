/* 
 * File:   CDicty.h
 * Author: soniyj
 *
 * Created on 26 November 2013, 12:10
 */

#ifndef __CDICTY_H__
#define __CDICTY_H__

#include <iostream>
#include <vector>

using namespace std;

class CDicty {
public:
    CDicty();
    CDicty(const CDicty& orig);
    virtual ~CDicty();
    void generateWord();
    void setStrWord(const char*);
    char *getStrWord() const;
    void makeVector();
    void makeVector(unsigned short);
    void makeVector(vector<string>);
    char* getWordVector(unsigned int);
    char* getNextWordVector();
    unsigned short getNumbers();
    /* Overloading operator */
    friend ostream& operator<<(ostream&,const CDicty&);
private:
    unsigned short position;
    unsigned short numbers;
    char *strWord;
    std::vector<string> words;
};

#endif /* __CDICTY_H__ */