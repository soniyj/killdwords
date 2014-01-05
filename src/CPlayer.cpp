/* 
 * File:   CPlayer.cpp
 * Author: soniyj
 * 
 * Created on 29 November 2013, 09:43
 */

#include <string>

#include "CPlayer.h"

CPlayer::CPlayer() {
    this->name = "";
    this->score = this->lives = 0;
    this->prevLives = this->prevScores = 0;
}

CPlayer::CPlayer(const CPlayer& orig) {
}

CPlayer::~CPlayer() {
    this->name.clear();
    this->score = this->lives = 0;
    this->prevLives = this->prevScores = 0;
}

CPlayer::CPlayer(string name) {
    this->setPlayerName(name);
    this->score = this->lives = 0;
    this->prevLives = this->prevScores = 0;
}

void CPlayer::setPlayerName(string name) {
    this->name = name;
}

string CPlayer::getPlayerName() const {
    return this->name;
}

void CPlayer::setNumOfLives(unsigned short lives) {
    this->lives = lives;
}

unsigned short CPlayer::getNumOfLives() const {
    return this->lives;
}

void CPlayer::setPlayerScore(unsigned int score) {
    this->score = score;
}

unsigned int CPlayer::getPlayerScore() const {
    return this->score;
}

/* These methods updating player to save the info during the levels */
void CPlayer::updatePlayer() {
    this->prevLives = this->lives;
    this->prevScores = this->score;
}

void CPlayer::restorePlayer() {
    this->lives = this->prevLives;
    this->score = this->prevScores;
}
