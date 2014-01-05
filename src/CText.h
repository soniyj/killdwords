/* 
 * File:   CText.h
 * Author: soniyj
 *
 * Created on 27 November 2013, 08:48
 */

#ifndef __CTEXT_H__
#define	__CTEXT_H__

#include <SFML/Graphics.hpp>

#include "CAbsGameObject.h"

using namespace std;

class CText : public sf::Text, public CAbsGameObject {
public:
    CText();
    CText(string);
    CText(const CText& orig);
    virtual ~CText();
    bool loadFont(string);
    void setSpeed(float);
    void updateVertical(const short);
    void updateBounding();
    bool getDestroyed();
private:
    float x, y;
    float speed;
    sf::Font font;
    sf::FloatRect boundingBox;
};

#endif	/* __CTEXT_H__ */

