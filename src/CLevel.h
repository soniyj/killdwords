/* 
 * File:   CLevel.h
 * Author: soniyj
 *
 * Created on 03 December 2013, 09:29
 */

#ifndef __CLEVEL_H__
#define	__CLEVEL_H__

class CLevel {
public:
    CLevel();
    CLevel(const CLevel& orig);
    virtual ~CLevel();
    CLevel(unsigned short level);
    CLevel(unsigned short level, unsigned int points);
    CLevel(unsigned short level, unsigned int points, unsigned short len);
    CLevel(unsigned short level, unsigned int points, unsigned short len, unsigned int ptsToNext);
    void setLevel(unsigned short);
    unsigned short getLevel() const;
    void setPoints(unsigned int);
    unsigned int getPoints() const;
    void setLenWord(unsigned short);
    unsigned short getLenWord() const;
    void setPtsToNext(unsigned int);
    unsigned int getPtsToNext() const;
private:
    unsigned short level;
    unsigned int points;
    unsigned short lenWord;
    unsigned int ptsToNext;
};

#endif	/* __CLEVEL_H__ */
