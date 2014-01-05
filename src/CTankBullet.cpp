/* 
 * File:   CTankBullet.cpp
 * Author: soniyj
 * 
 * Created on 17 November 2013, 19:15
 */

#include "CTankBullet.h"

CTankBullet::CTankBullet() {
}

CTankBullet::CTankBullet(const CTankBullet& orig) {
}

CTankBullet::~CTankBullet() {
}

CTankBullet::CTankBullet(const float x, const float y) {
    this->x = x;
    this->x = y;
    this->setPosition(x, y);
}

/**
 * Set the speed used during the updating
 * @param s
 */
void CTankBullet::setSpeed(float s) {
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
void CTankBullet::updateVertical(const short direction) {
    sf::Vector2f pos;
    pos = this->getPosition();
    this->x = pos.x;
    this->y = pos.y;
    pos.y = this->y + (this->speed * direction);
    this->setPosition(this->x, pos.y);
}

void CTankBullet::updatePosition(const float x, const float y) {
    this->x = x;
    this->y = y;
    this->setPosition(x, y);
}

void CTankBullet::updateBounding() {
    this->boundingBox = this->getGlobalBounds();
}
