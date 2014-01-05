/* 
 * File:   menu.cpp
 * Author: soniyj
 * 
 * Created on 23 December 2013, 12:42
 */

/* Contains function to manage the menu system */

/* Window Size */
#define WIDHT 800
#define HEIGHT 600

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "main.h"

#include "CText.h"
#include "CPlayer.h"
#include "CLevel.h"
#include "CHallFame.h"

/* Menu will be displayed when the game starts */
unsigned int startMenuGame(sf::RenderWindow* window) {
    CText text0;
    CText text1;
    CText text2;
    CText text3;
    CText text4;
    CText text5;
    
    text0.loadFont(FONT_PATH);
    text0.setString("Kill The Word(s)");
    text0.setColor(sf::Color::Red);
    text0.setCharacterSize(24);
    
    text1.loadFont(FONT_PATH);
    text1.setString("1 - Start Game");
    text1.setColor(sf::Color::Red);
    text1.setCharacterSize(24);
    
    text2.loadFont(FONT_PATH);
    text2.setString("2 - Load Game");
    text2.setColor(sf::Color::Red);
    text2.setCharacterSize(24);
    
    text3.loadFont(FONT_PATH);
    text3.setString("3 - Hall Of Fame");
    text3.setColor(sf::Color::Red);
    text3.setCharacterSize(24);
    
    text4.loadFont(FONT_PATH);
    text4.setString("4 - Quit Game");
    text4.setColor(sf::Color::Red);
    text4.setCharacterSize(24);
    
    text5.loadFont(FONT_PATH);
    text5.setString("Version: 0.1.0 Alpha - Copyright (C) 2013 - Marco \"soniyj\" Matascioli");
    text5.setColor(sf::Color::Red);
    text5.setCharacterSize(10);
        
    text0.setPosition(WIDHT/3,50);
    text1.setPosition(WIDHT/3,180);
    text2.setPosition(WIDHT/3,220);
    text3.setPosition(WIDHT/3,260);
    text4.setPosition(WIDHT/3,300);
    text5.setPosition(5,570);
    
    sf::Event event;
    while(window->isOpen()) {
        // Event processing.
        while(window->pollEvent(event)) {
            // If window is about to be closed, leave program.
            if(event.type == sf::Event::Closed) {
		window->close();
            }
	}
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
            return 1;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
            return 2;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
            return 3;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
            return 4;
        
	window->clear();
        window->draw(text0);
        window->draw(text1);
        window->draw(text2);
        window->draw(text3);
        window->draw(text4);
        window->draw(text5);
	window->display();
    }
}

/* Menu will be displayed when the game is not running */
unsigned int pauseMenuGame(sf::RenderWindow& window) {
    CText text0;
    CText text1;
    CText text2;
    CText text3;
    CText text4;
    CText text5;
    
    text0.loadFont(FONT_PATH);
    text0.setString("(Press 0 to Continue)");
    text0.setColor(sf::Color::Yellow);
    text0.setCharacterSize(24);
    
    text1.loadFont(FONT_PATH);
    text1.setString("1 - ReStart Game");
    text1.setColor(sf::Color::Red);
    text1.setCharacterSize(24);
    
    text2.loadFont(FONT_PATH);
    text2.setString("2 - Save Game");
    text2.setColor(sf::Color::Red);
    text2.setCharacterSize(24);
    
    text3.loadFont(FONT_PATH);
    text3.setString("3 - Load Game");
    text3.setColor(sf::Color::Red);
    text3.setCharacterSize(24);
    
    text4.loadFont(FONT_PATH);
    text4.setString("4 - Quit Game");
    text4.setColor(sf::Color::Red);
    text4.setCharacterSize(24);
    
    text5.loadFont(FONT_PATH);
    text5.setString("Version: 0.1.0 Alpha - Copyright (C) 2013 - Marco \"soniyj\" Matascioli");
    text5.setColor(sf::Color::Red);
    text5.setCharacterSize(10);
    
    text0.setPosition(WIDHT/3,100);
    text1.setPosition(WIDHT/3,180);
    text2.setPosition(WIDHT/3,220);
    text3.setPosition(WIDHT/3,260);
    text4.setPosition(WIDHT/3,300);
    text5.setPosition(5,570);
        
    sf::Event event;
    while(window.isOpen()) {
	// Event processing.
	while(window.pollEvent(event)) {
            // If window is about to be closed, leave program.
            if(event.type == sf::Event::Closed) {
                window.close();
            }
	}
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
            return 0;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
            return 1;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
            return 2;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
            return 3;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
            return 4;
        
	// Rendering.
	window.clear(sf::Color::Transparent); //Without needs to be transparency into the first screen
        window.draw(text0);
        window.draw(text1);
        window.draw(text2);
        window.draw(text3);
        window.draw(text4);
        window.draw(text5);
        window.display();
    }
}

/* Player Score, Player Name, Level, Player Lives */
void hallFame(sf::RenderWindow& window, CPlayer& player, CLevel &level, bool file) {
    CHallFame hallFame;
    //vector<CText&> hallText;
    CText hallTextHead;
    CText* hallText;
    
    hallTextHead.loadFont(FONT_PATH);
    hallTextHead.setCharacterSize(24);
    hallTextHead.setColor(sf::Color::Yellow);
    
    hallText = new CText();
    hallText->loadFont(FONT_PATH);
    hallText->setCharacterSize(24);
    hallText->setColor(sf::Color::Red);
    
    if(file == true) {
        /* Reading from file */
        ;
    }
    else {;
        //hallText.push_back();
    }
    int i=0;
    /* Drawing */
    /*if(window.isOpen())
        window.clear();*/
    while(window.isOpen()) {
        window.clear();
        hallTextHead.setString("Name   Points Lives Level");
        hallText->setString   ("qwerty   9999     3    10");
        hallTextHead.setPosition(200,125);
        hallText->setPosition(200,150+i);
        window.draw(hallTextHead);
        window.draw(*hallText);
        window.display();
        //i+=25;
    }
}
