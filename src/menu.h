/* 
 * File:   menu.h
 * Author: marco.matascioli
 *
 * Created on 23 December 2013, 12:42
 */

#ifndef __MENU_H__
#define	__MENU_H__

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "CPlayer.h"
#include "CLevel.h"

unsigned int startMenuGame(sf::RenderWindow*);
unsigned int pauseMenuGame(sf::RenderWindow&);
void hallFame(sf::RenderWindow&,CPlayer&,CLevel&,bool);

#endif	/* __MENU_H__ */

