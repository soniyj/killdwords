/* 
 * File:   level.h
 * Author: marco.matascioli
 *
 * Created on 18 December 2013, 11:44
 */

#ifndef __LEVEL_H__
#define	__LEVEL_H__

#include "CTank.h"
#include "CText.h"
#include "CPlayer.h"

CTank* loadTank(const int,const int);
CText* loadText(const int,const int);
CText* loadPlayerText(CPlayer*);
CText* loadPlayerScore(CPlayer*);

#endif	/* __LEVEL_H__ */

