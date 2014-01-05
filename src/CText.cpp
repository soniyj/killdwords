/* 
 * File:   CText.cpp
 * Author: soniyj
 * 
 * Created on 27 November 2013, 08:48
 */

#include <iostream>
#include "CText.h"

using namespace std;

CText::CText() {
}

CText::CText(const CText& orig) {
}

CText::~CText() {
}

CText::CText(string fileName) {
    this->loadFont(fileName);
}

/**
 * Load font from a file and set it like a default font
 * @param fileName
 * @return true no error found or false otherwise
 */
bool CText::loadFont(string fileName) {
    if(!font.loadFromFile(fileName)) {
        cout << "Error loading font " << fileName << endl;
        return false;
    }
    this->setFont(font);
    return true;
}

/**
 * Set the speed used during the updating
 * @param s
 */
void CText::setSpeed(float s) {
    this->speed = s;
}

/**
 * Updating the Vertical position using the speed and the direction.
 * Positive Direction: will move upward than the current position
 * Negative Direction: will move downward than the current position
 * Direction must be -1 or +1 not other value, because the position
 * is updated using both the direction and the speed, in case set
 * the speed to 0.
 * Formula: (y + speed) * direction;
 * @param direction 
 */
void CText::updateVertical(const short direction) {
    sf::Vector2f pos;
    pos = this->getPosition();
    this->x = pos.x;
    this->y = pos.y;
    pos.y = this->y + (this->speed * direction);
    this->setPosition(this->x, pos.y);
}

void CText::updateBounding() {
    this->boundingBox = this->getGlobalBounds();
}

bool CText::getDestroyed() {
    return this->destroyed;
}
