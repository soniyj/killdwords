/* 
 * File:   CAudio.h
 * Author: soniyj
 *
 * Created on 4 gennaio 2014, 19.25
 */

#ifndef __CAUDIO_H__
#define	__CAUDIO_H__

#include <SFML/Audio.hpp>

using namespace std;

class CAudio : public sf::Sound {
public:
    CAudio();
    CAudio(const CAudio& orig);
    virtual ~CAudio();
    bool loadSound(string);
private:
    string fileName;
    sf::SoundBuffer buffer;
};

#endif	/* __CAUDIO_H__ */

