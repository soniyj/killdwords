/* 
 * File:   newmain.cpp
 * Author: soniyj
 *
 * Created on 17 November 2013, 19:12
 */

#include <iostream>
#include <cstdlib>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "main.h"
#include "utility.h"
#include "template.cpp"
#include "levelAdmin.h"
#include "player.h"
#include "level.h"
#include "menu.h"

#include "CDicty.h"
#include "CTank.h"
#include "CText.h"
#include "CTankBullet.h"
#include "CPlayer.h"
#include "CLevel.h"
#include "CHallFame.h"
#include "CAudio.h"

/* Window Size */
#define WIDHT 800
#define HEIGHT 600

/* Static Position */
#define TANK_X_POS 180
#define TANK_Y_POS 530
#define TXT_Y_POS 20

using namespace std;

/* This Function will create the Player */
bool startGame(sf::RenderWindow& window, CPlayer& player) {
    CText *txtName;
    CText *playerName;
    sf::String userInput;
    
    txtName = new CText();
    txtName->loadFont(FONT_PATH);
    txtName->setCharacterSize(24);
    txtName->setColor(sf::Color::Red);
    txtName->setPosition(200,200);
    txtName->setString("Enter your name and press enter: ");
    
    playerName = new CText();
    playerName->loadFont(FONT_PATH);
    playerName->setCharacterSize(24);
    playerName->setColor(sf::Color::Green);
    playerName->setPosition(220,250);
    
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
            /* Keyboard Event */
            /* 65 <= key <= 90 */
            if(event.type == sf::Event::KeyPressed) {
                char c = event.key.code + 65;
                if(event.text.unicode <= 25) {
                    userInput += event.text.unicode + 65;
                    //cout << "[DBG] {player name}: " << userInput.toAnsiString() << " | " << userInput.getSize() << endl;
                }
            }
        } /* End while(event) */
            
        /* Purging buffer in case of typing errors */
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
            userInput.clear();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
            player.setPlayerName(userInput);
            player.setNumOfLives(3);
            player.setPlayerScore(0);
            return true;
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            return false;
        }
        
        playerName->setString(userInput);

        window.clear();
        window.draw(*txtName);
        window.draw(*playerName);
        window.display();
    }
}

/* This function will be used like a game loop */
bool gameLoop(sf::RenderWindow& window, CPlayer *player, CLevel *level) {
    CDicty *dicty;
    CText *playerText = NULL;
    CText *playerScore = NULL;
    CText *levelText = NULL;
    CTank *tank1 = NULL;
    CTank *tank2 = NULL;
    CTank *tank3 = NULL;
    CText *text1 = NULL;
    CText *text2 = NULL;
    CText *text3 = NULL;
    CTankBullet *bullet1 = NULL;
    CTankBullet *bullet2 = NULL;
    CTankBullet *bullet3 = NULL;
    CAudio *bulletSound = NULL;
    CAudio *destroySound = NULL;
    CAudio *tankSound = NULL;
    sf::String userInput;
    bool destroyed = true; /* is for word and not for tank */
    bool levelUp = false;
    bool isGame = true;
    unsigned short j = 0, levelEnd = 0, i = 0;
    map<unsigned int,vector<string> > mmap;
    unsigned int choice = 0;
    
    /* Loading Data file */
    if(readTextFile(mmap,DBX_PATH) == false)
        return(1);

    /* Testing Level */
    levelText = new CText();
    createLevel(*level,*levelText);
    levelEnd = level->getLevel();
    i = levelEnd;
    /* End Testing Level */
    
    /* Testing Dictionary */
    dicty = new CDicty();
    //dicty->makeVector(levelEnd-1);
    dicty->makeVector(mmap[levelEnd-1]);
    //cout << *dicty << endl; //Testing new reading
    /* End Testing Dictionary */
    
    /* Create Player */
    playerText = loadPlayerText(player);
    playerScore = loadPlayerScore(player);
    /* End Create Player */
    
    /* Loading Tank */
    tank1 = loadTank(TANK_X_POS,TANK_Y_POS);
    tank2 = loadTank(TANK_X_POS+200,TANK_Y_POS);
    tank3 = loadTank(TANK_X_POS+400,TANK_Y_POS);
    /* End Tank */
    
    /* Loading Text */
    text1 = loadText(tank1->getX(),TXT_Y_POS);
    text2 = loadText(tank2->getX(),TXT_Y_POS);
    text3 = loadText(tank3->getX(),TXT_Y_POS);
    /* End Text*/
    
    /* Loading Audio */
    bulletSound = new CAudio();
    destroySound = new CAudio();
    tankSound = new CAudio();
    bulletSound->loadSound(SND_BULLET_PATH);
    destroySound->loadSound(SND_TEXT_PATH);
    tankSound->loadSound(SND_TANK_PATH);
    /* End Audio */
    
    /* Game Loop */
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
            /* Keyboard Event */
            /* 65 <= key <= 90 */
            if(event.type == sf::Event::KeyPressed) {
                char c = event.key.code + 65;
                if(event.text.unicode <= 25) {
                    userInput += event.text.unicode + 65;
                    //cout << "^1: " << userInput.toAnsiString() << " | " << userInput.getSize() << endl;
                }
            }
        } /* End while(event) */
        
        /* Loading Menu Pause */
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            choice = pauseMenuGame(window);
            if(choice == 1) {
                player->restorePlayer();
                return false;
            }
            if(choice == 4) break;
        }
        
        /* Purging buffer in case of typing errors */
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
            userInput.clear();
        }
        
        /* Re-Start the game when the player lost */
        if((isGame==false) & sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            isGame=true;
            //cout << "dePressed\n";
        }
        
        window.clear();
        
        /* Game ends player won */
        if((player->getPlayerScore() > level->getPtsToNext()) && (i >= mmap.size())) {
            if(text1->getDestroyed()==true && text2->getDestroyed()==true && text3->getDestroyed()==true) {
                text1->setString("YOU WON");
                text1->setPosition(WIDHT/3, HEIGHT/3);
                text1->setDestroyed(true);
                window.draw(*text1);
            }
            levelUp = true;
        }
        
        /* Next level when points are passed and there are words */
        if((player->getPlayerScore() > level->getPtsToNext()) && (i < mmap.size())) {
            //cout << "Go to the next level #(+1): " << level->getLevel() << " | " << i << endl;
            levelUp = true;
            if(text1->getDestroyed()==true && text2->getDestroyed()==true && text3->getDestroyed()==true) {
                nextLevel(*level, *levelText);
                levelUp = false;
                levelEnd = level->getLevel()-1;
                dicty->makeVector(mmap[levelEnd]);
                i+=1;
                player->updatePlayer();
                /* Create the objects in case are destroyed */
                if(tank1 == NULL)
                    tank1 = loadTank(TANK_X_POS,TANK_Y_POS);
                if(tank2 == NULL)
                    tank2 = loadTank(TANK_X_POS+200,TANK_Y_POS);
                if(tank3 == NULL)
                    tank3 = loadTank(TANK_X_POS+400,TANK_Y_POS);
            }
        }

        if(levelText != NULL) {
            window.draw(*levelText);
            playerScore->setString("Score: "+numberToString(player->getPlayerScore()));
            window.draw(*playerScore);
        }
        
        if(playerText != NULL) {
            playerText->setString(player->getPlayerName()+": "+numberToString(player->getNumOfLives()));
            window.draw(*playerText);
        }
        
        if(player->getNumOfLives() == 0) {
            text1->setString("GAME OVER");
            text1->setPosition(WIDHT/3, HEIGHT/3);
            text1->setDestroyed(true);
            window.draw(*text1);
            if(tank1 != NULL) {
                delete tank1; tank1 = NULL;
            }
            if(tank2 != NULL) {
                delete tank2; tank2 = NULL;
            }
            if(tank3 != NULL) {
                delete tank3; tank3 = NULL;
            }
            isGame=false;
        }
        
        /* Get the next word from the dictionary */
        //if(destroyed == true) {
        if(levelUp == false) {
            if(text1->getDestroyed() == true && tank1 != NULL) {
                j = generateRandomIndex(j,dicty->getNumbers());
                //cout << "Text 1 index: " << j << endl;
                text1->setString(dicty->getWordVector(0));
                text1->setPosition(tank1->getX(),TXT_Y_POS);
                text1->setDestroyed(false);
                destroyed = false;
            }
            if(text2->getDestroyed() == true && tank2 != NULL) {
                j = generateRandomIndex(j,dicty->getNumbers());
                //cout << "Text 2 index: " << j << endl;
                text2->setString(dicty->getWordVector(1));
                text2->setPosition(tank2->getX(),TXT_Y_POS);
                text2->setDestroyed(false);
                destroyed = false;
            }
            if(text3->getDestroyed() == true && tank3 != NULL) {
                j = generateRandomIndex(j,dicty->getNumbers());
                //cout << "Text 3 index: " << j << endl;
                text3->setString(dicty->getWordVector(2));
                text3->setPosition(tank3->getX(),TXT_Y_POS);
                text3->setDestroyed(false);
                destroyed = false;
            }
        }
        
        //if(destroyed == false) {
            if(userInput.toAnsiString() == text1->getString().toAnsiString()) {
                userInput.clear();
                bullet1 = new CTankBullet(tank1->getX()+15,tank1->getY()-10);
                bullet1->setRadius(10.0f);
                bullet1->setFillColor(sf::Color::Red);
                bullet1->setSpeed(0.1);
                bulletSound->play();
            }
            if(userInput.toAnsiString() == text2->getString().toAnsiString()) {
                userInput.clear();
                bullet2 = new CTankBullet(tank2->getX()+15,tank2->getY()-10);
                bullet2->setRadius(10.0f);
                bullet2->setFillColor(sf::Color::Red);
                bullet2->setSpeed(0.1);
                bulletSound->play();
            }
            if(userInput.toAnsiString() == text3->getString().toAnsiString()) {
                userInput.clear();
                bullet3 = new CTankBullet(tank3->getX()+15,tank3->getY()-10);
                bullet3->setRadius(10.0f);
                bullet3->setFillColor(sf::Color::Red);
                bullet3->setSpeed(0.1);
                bulletSound->play();
            }
            
            /* Draw the Text only if isn't destroyed */
            if(text1->getDestroyed() == false) {
                text1->updateVertical(10);
                window.draw(*text1);
                /* Purging the user input */
                if(userInput.getSize() > text1->getString().getSize()) {
                    userInput.clear();
                }
            }
            if(text2->getDestroyed() == false) {
                text2->updateVertical(10);
                window.draw(*text2);
                /* Purging the user input */
                if(userInput.getSize() > text2->getString().getSize()) {
                    userInput.clear();
                }
            }
            if(text3->getDestroyed() == false) {
                text3->updateVertical(10);
                window.draw(*text3);
                /* Purging the user input */
                if(userInput.getSize() > text3->getString().getSize()) {
                    userInput.clear();
                }
            }
        //}
        
        /* Draw needs a pointer to the object */
        if(tank1 != NULL) {
            bool draw = true;
            if(text1->getDestroyed() == false) {
                /* Collision between Text and Word */
                if(text1->getGlobalBounds().intersects(tank1->getGlobalBounds())) {
                    //cout << "Tank1 Destroyed\n";
                    destroyed = true;
                    text1->setDestroyed(true);
                    draw = false;
                    player->setNumOfLives(player->getNumOfLives()-1);
                    /* Tank Destroyed */
                    delete tank1; tank1 = NULL;
                    tankSound->play();
                }
            }
            if(draw && tank1 != NULL)
                window.draw(*tank1);
        }
        
        if(tank2 != NULL) {
            bool draw = true;
            if(text2->getDestroyed() == false) {
                /* Collision between Tank and Word */
                if(text2->getGlobalBounds().intersects(tank2->getGlobalBounds())) {
                    //cout << "Tank2 Destroyed\n";
                    destroyed = true;
                    text2->setDestroyed(true);
                    draw = false;
                    player->setNumOfLives(player->getNumOfLives()-1);
                    /* Tank Destroyed */
                    delete tank2; tank2 = NULL;
                    tankSound->play();
                }
            }
            if(draw == true)
                window.draw(*tank2);
        }
        
         if(tank3 != NULL) {
            bool draw = true;
            if(text3->getDestroyed() == false) {
                /* Collision between Tank and Word */
                if(text3->getGlobalBounds().intersects(tank3->getGlobalBounds())) {
                    //cout << "Tank3 Destroyed\n";
                    destroyed = true;
                    text3->setDestroyed(true);
                    draw = false;
                    player->setNumOfLives(player->getNumOfLives()-1);
                    /* Tank Destroyed */
                    delete tank3; tank3 = NULL;
                    tankSound->play();
                }
            }
            if(draw == true)
                window.draw(*tank3);
        }
        
        if(bullet1 != NULL) {
            /* Collision between Bullet and Text */
            if(bullet1->getGlobalBounds().intersects(text1->getGlobalBounds())) {
                //cout << "Text Destroyed: " << text1->getString().toAnsiString() << "\n";
                destroyed = true;
                text1->setDestroyed(true);
                delete bullet1; bullet1 = NULL;
                player->setPlayerScore(player->getPlayerScore() + level->getPoints());
                destroySound->play();
            }
            else {
                bullet1->updateVertical(-20);
                window.draw(*bullet1);
            }
        }
        
        if(bullet2 != NULL) {
            /* Collision between Bullet and Text */
            if(bullet2->getGlobalBounds().intersects(text2->getGlobalBounds())) {
                //cout << "Text Destroyed: " << text2->getString().toAnsiString() << "\n";
                destroyed = true;
                text2->setDestroyed(true);
                delete bullet2; bullet2 = NULL;
                player->setPlayerScore(player->getPlayerScore() + level->getPoints());
                destroySound->play();
            }
            else {
                bullet2->updateVertical(-20);
                window.draw(*bullet2);
            }
        }
        
        if(bullet3 != NULL) {
            /* Collision between Bullet and Text */
            if(bullet3->getGlobalBounds().intersects(text3->getGlobalBounds())) {
                //cout << "Text Destroyed: " << text3->getString().toAnsiString() << "\n";
                destroyed = true;
                text3->setDestroyed(true);
                delete bullet3; bullet3 = NULL;
                player->setPlayerScore(player->getPlayerScore() + level->getPoints());
                destroySound->play();
            }
            else {
                bullet3->updateVertical(-20);
                window.draw(*bullet3);
            }
        }
        
        window.display();
    } /* End main while */
    /* End Game Loop */
    
    /* Needs to add the end of game */
    
    return true;
}

/*
 * This will be a new main instead the main.c that it used for testing
 */
int main(int argc, char** argv) {
    CPlayer player;
    CLevel *level;
    CHallFame hallOfFame/* = new CHallFame()*/;
    unsigned int choice = 0;
    
    sf::RenderWindow window(sf::VideoMode(WIDHT, HEIGHT), "Kill The Word(s) - Alpha Version", sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(60); //60 FPS {if enabled changing the speed}
    window.setMouseCursorVisible(false); // mouse pointer not visible
        
    while(window.isOpen()) {
        choice = startMenuGame(&window);
        switch(choice) {
            case 1:
                choice = startGame(window, player);
                level = new CLevel(1,5);
                if(choice == true) {
                    do {
                        choice = gameLoop(window, &player, level);
                    } while(choice == false);
                }
                delete level;
                choice = 0;
                break;
            case 2:
                cout << "Load Game: is Not Supported yet\n";
                /* To be loaded: Player name, score, lives, level */
                break;
            case 3:
                cout << "Hall Of Fame: is Not Supported yet\n";
                /* Possible only after added the storing */
                /*hallOfFame.update(j,"marco",choice+1,choice+2);
                hallFame(window,player,*level,false);*/
                choice = 0;
                break;
            /*case 4:
                choice = 0;
                cout << "Exit\n";
                break;*/
        }
        if(choice == 4) break;
    }
    window.close();
    return 0;
} /* End main */
