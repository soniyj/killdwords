/* 
 * File:   levelAdmin.cpp
 * Author: soniyj
 *
 * Created on 09 December 2013, 17:45
 */

/* This module will contain all the functionality not linked directly with the game */

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

/**
 * Get a random index, where max_index is the maximum allowed.
 * @param max_index max index allowed
 * @return index found
 */
unsigned int generateRandomIndex(unsigned int max_index) {
    time_t sec;
    time(&sec);
    srand((unsigned int)sec);
    return(rand() % max_index);
}

/**
 * Get a random index that is different respect prev.
 * max_index is the maximum index allowed.
 * @param prev previous index got
 * @param max_index maximum index allowed
 * @return index found
 */
unsigned int generateRandomIndex(unsigned int prev, unsigned int max_index) {
    unsigned int tmp = 0;
    time_t sec;
    time(&sec);
    srand((unsigned int)sec);
    do {
        tmp = (rand() % max_index);
    }while(tmp==prev);
    return tmp;
}

/**
 * Reading a text file and store each row into a map.
 * Text layout where each word must be on one line, two words on the same line
 * could create an error or an inconsistent state of the object.
 * Each word will be stored into a vector and the vector will be stored into
 * a map where the index is based on the length of the string.
 * Map Template: map<unsigned int, vector>
 * Vector Template: vector<string>
 * @param mmap map where store the file read from the file
 * @param filename name of the file to read
 * @return true if the map is read, false otherwise
 */
bool readTextFile(map<unsigned int,vector<string> >& mmap, const char* filename) {
    unsigned int index=0,prev=2;
    vector<string> vect;
    string line;
    ifstream mfile(filename);
    
    if(mfile.is_open()) {
        while(getline(mfile,line)) {
            if(prev < line.size()) {
                mmap[index] = vect;
                index = (line.size()-2);
                prev = line.size();
                vect.clear();
            }
            vect.push_back(line);
            line.clear();
        } /* End While */
        mmap[index] = vect;
        mfile.close();
      }
      else {
          cout << "File not exists: " << filename << endl;
          return false;
      }
    return true;
}/* End Function */