/* 
 * File:   level.cpp
 * Author: soniyj
 *
 * Created on 18 December 2013, 08:52
 */

/* This module will substitute levelAdmin */

#include <iostream>
#include <vector>

#include "main.h"

#include "CTank.h"
#include "CLevel.h"
#include "CText.h"
#include "CPlayer.h"

#include "template.cpp"

using namespace std;

/* Loading level*/
bool loadLevel(vector<CTank>& vect) {
    CTank *tank;
    tank = &vect[0];
    if(tank == NULL) {
        cout << "Tank 0 is null\n";
        tank = new CTank(TANK_PATH);
    }
}

/* Will contain both the player and the tank setup */
CTank* loadTank(const int x, const int TANK_Y_POS) {
    CTank *tank;
    tank = new CTank(TANK_PATH);
    tank->loadTexture(0,0,88,113);
    tank->setScale(0.5f,0.5f); /* half of the original */
    tank->setPosition(x,TANK_Y_POS);
    return tank;
}

CText* loadText(const int x, const int TXT_Y_POS) {
    CText *text;
    text = new CText();
    text->loadFont(FONT_PATH);
    text->setCharacterSize(24);
    text->setColor(sf::Color::Red);
    text->setPosition(x,TXT_Y_POS);
    text->setSpeed(0.1);
    return text;
}

CText* loadPlayerText(CPlayer *player) {
    CText *playerText = NULL;
    playerText = new CText();
    playerText->loadFont(FONT_PATH);
    player->setNumOfLives(3);
    playerText->setString(player->getPlayerName()+": "+numberToString(player->getNumOfLives()));
    playerText->setCharacterSize(24);
    playerText->setColor(sf::Color::Green);
    playerText->setPosition(15,5);
    return playerText;
}

CText* loadPlayerScore(CPlayer *player) {
    CText *playerScore = NULL;
    playerScore = new CText();
    playerScore->loadFont(FONT_PATH);
    playerScore->setString("Score: "+numberToString(player->getPlayerScore()));
    playerScore->setCharacterSize(24);
    playerScore->setColor(sf::Color::Yellow);
    playerScore->setPosition(620,5);
    return playerScore;
}