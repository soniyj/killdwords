/* 
 * File:   CAbsGameObject.cpp
 * Author: soniyj
 * 
 * Created on 11 December 2013, 13:03
 */

#include "CAbsGameObject.h"

CAbsGameObject::CAbsGameObject() {
    this->setDestroyed(true);
}

CAbsGameObject::CAbsGameObject(const CAbsGameObject& orig) {
}

CAbsGameObject::~CAbsGameObject() {
}

void CAbsGameObject::setDestroyed(bool d) {
    this->destroyed = d;
}
