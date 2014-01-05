/* 
 * File:   template.cpp
 * Author: soniyj
 *
 * Created on 10 December 2013, 11:38
 */

/* This module will contain all template to be include into a source file */
/* Note: this module doesn't have a header */

#include <sstream>

using namespace std;

/* This Function converts any number to a string */
template <typename T>
string numberToString(T number) {
    ostringstream ss;
    ss << number;
    return ss.str();
}
