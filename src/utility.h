/* 
 * File:   utility.h
 * Author: soniyj
 *
 * Created on 09 December 2013, 17:52
 */

#ifndef __UTILITY_H__
#define	__UTILITY_H__

#include <map>
#include <vector>

using namespace std;

unsigned int generateRandomIndex(unsigned int);
unsigned int generateRandomIndex(unsigned int,unsigned int);
bool readTextFile(map<unsigned int,vector<string> >&, const char*);

#endif	/* __UTILITY_H__ */
