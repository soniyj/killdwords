/* 
 * File:   CTankBullet.h
 * Author: soniyj
 *
 * Created on 17 November 2013, 19:15
 */

#ifndef CTANKBULLET_H
#define	CTANKBULLET_H

#include <SFML/Graphics.hpp>

#include "CTank.h"

class CTankBullet : public sf::CircleShape {
public:
    CTankBullet();
    CTankBullet(const CTankBullet& orig);
    virtual ~CTankBullet();
    CTankBullet(const float, const float);
    void setSpeed(float);
    void updateVertical(const short);
    void updateHorizontal();
    void updatePosition(const float, const float);
    void updateBounding();
private:
    float x, y;
    float speed;
    sf::FloatRect boundingBox;
};

#endif	/* CTANKBULLET_H */
