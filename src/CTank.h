/* 
 * File:   CTank.h
 * Author: soniyj
 *
 * Created on 17 November 2013, 18:46
 */

#ifndef __CTANK_H__
#define	__CTANK_H__

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class CTank : public sf::Sprite {
public:
    CTank();
    CTank(const CTank& orig);
    virtual ~CTank();
    CTank(string);
    void setImgFile(string);
    bool loadTexture(int,int,int,int);
    void updateBounding();
    sf::Texture getDrawTexture() const;
    float getX();
    float getY();
    /* Overloading operator */
    friend ostream& operator<<(ostream&,const CTank&);
private:
    float x, y;
    sf::Texture texture;
    string imgFileName;
    sf::FloatRect boundingBox;
  };

#endif	/* __CTANK_H__ */
