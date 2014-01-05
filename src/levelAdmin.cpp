/* 
 * File:   levelAdmin.cpp
 * Author: soniyj
 *
 * Created on 09 December 2013, 17:37
 */

/* This module will contain everything is related with the level management */

#include "CText.h"
#include "CLevel.h"

#include "main.h"
#include "template.cpp"

void createLevel(CLevel& level, CText& levelText) {
    levelText.loadFont(FONT_PATH);
    levelText.setString("Level: "+numberToString(level.getLevel()));
    levelText.setCharacterSize(24);
    levelText.setColor(sf::Color::Magenta);
    levelText.setPosition(300,0);
}

/* This function will update the level and the text related to it */
void nextLevel(CLevel& level, CText& text) {
    level.setLevel(level.getLevel()+1);
    level.setLenWord(level.getLenWord()+1);
    level.setPoints(level.getPoints()+level.getPoints());
    level.setPtsToNext(level.getPtsToNext()+level.getPtsToNext());
    text.setString("Level: "+numberToString(level.getLevel()));
}