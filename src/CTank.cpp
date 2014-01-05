/* 
 * File:   CTank.cpp
 * Author: soniyj
 * 
 * Created on 17 November 2013, 18:46
 */

#include <math.h>

#include "CTank.h"

using namespace std;

CTank::CTank() {
}

CTank::CTank(const CTank& orig) {
}

CTank::~CTank() {
}

CTank::CTank(string fileName) {
    this->setImgFile(fileName);
}

/**
 * Setting the file name, in case the file is not in the same directory
 * add the absolute path
 * @param fileName
 */
void CTank::setImgFile(string fileName) {
    this->imgFileName = fileName;
}

/**
 * Load a (width x height) texture rectangle that starts at (left, top)
 * @param left
 * @param top
 * @param width
 * @param height
 * @return true no error found or false otherwise
 */
bool CTank::loadTexture(int left, int top, int width, int height) {
    if(!texture.loadFromFile(this->imgFileName, sf::IntRect(left,top,width,height))) {
        cout << "Error loading image\n";
        return false;
    }
    texture.setSmooth(true);
    this->setTexture(texture);
    return true;
}

float CTank::getX() {
    sf::Vector2f pos;
    pos = this->getPosition();
    this->x = pos.x;
    return this->x;
}

float CTank::getY() {
    sf::Vector2f pos;
    pos = this->getPosition();
    this->y = pos.y;
    return this->y;
}

void CTank::updateBounding() {
    this->boundingBox = this->getGlobalBounds();
}

ostream& operator<<(ostream& os, const CTank& tk) {
    os << "Printing Tank Texture\n";
    os << "Texture Rect(h,l): " << tk.getTextureRect().height << "," << tk.getTextureRect().left << endl;
    os << "Texture Rect(t,w): " << tk.getTextureRect().top << "," << tk.getTextureRect().width << endl;
    os << "Origin(x,y): " << tk.getOrigin().x << "," << tk.getOrigin().y <<endl;
    os << "End Printing\n";
    return os;
}