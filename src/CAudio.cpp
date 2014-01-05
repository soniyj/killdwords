/* 
 * File:   CAudio.cpp
 * Author: soniyj
 * 
 * Created on 4 gennaio 2014, 19.25
 */

#include <iostream>

#include "CAudio.h"

using namespace std;

CAudio::CAudio() {
}

CAudio::CAudio(const CAudio& orig) {
}

CAudio::~CAudio() {
}

bool CAudio::loadSound(string filename) {
    if(!this->buffer.loadFromFile(filename)) {
        cout << "Error loading sound: " << filename << endl;
        return false;
    }
    this->setBuffer(buffer);
    return true;
}
