/* 
 * File:   CLevel.cpp
 * Author: soniyj
 * 
 * Created on 03 December 2013, 09:29
 */

#include <stdint.h>

#include "CLevel.h"

CLevel::CLevel() {
    this->setLevel(1);
    this->setPoints(0);
    this->setLenWord(2);
    this->setPtsToNext(15);
}

CLevel::CLevel(const CLevel& orig) {
}

CLevel::~CLevel() {
}

CLevel::CLevel(unsigned short level) {
    this->setLevel(level);
    this->setPoints(0);
    this->setLenWord(2);
    this->setPtsToNext(15);
}

CLevel::CLevel(unsigned short level, unsigned int points) {
    this->setLevel(level);
    this->setPoints(points);
    this->setLenWord(2);
    this->setPtsToNext(15);
}

CLevel::CLevel(unsigned short level, unsigned int points, unsigned short len) {
    this->setLevel(level);
    this->setPoints(points);
    this->setLenWord(len);
    this->setPtsToNext(15);
}

CLevel::CLevel(unsigned short level, unsigned int points, unsigned short len, unsigned int ptsToNext) {
    this->setLevel(level);
    this->setPoints(points);
    this->setLenWord(len);
    this->setPtsToNext(ptsToNext);
}

void CLevel::setLevel(unsigned short level) {
    this->level = level;
}

unsigned short CLevel::getLevel() const {
    return this->level;
}

/**
 * Set up the number of point that are possible to
 * get for each word destroyed.
 * @param points
 */
void CLevel::setPoints(unsigned int points) {
    this->points = points;
}

unsigned int CLevel::getPoints() const {
    return this->points;
}

/**
 * Set up the length of the word for each level.
 * Minimum length is 2, it will be set up during the game.
 * @param len
 */
void CLevel::setLenWord(unsigned short len) {
    this->lenWord = len;
}

unsigned short CLevel::getLenWord() const {
    return this->lenWord;
}

void CLevel::setPtsToNext(unsigned int points) {
    this->ptsToNext = points;
}

unsigned int CLevel::getPtsToNext() const {
    return this->ptsToNext;
}
