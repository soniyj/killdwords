/* 
 * File:   CPlayer.h
 * Author: soniyj
 *
 * Created on 29 November 2013, 09:43
 */

#ifndef __CPLAYER_H__
#define	__CPLAYER_H__

using namespace std;

class CPlayer {
public:
    CPlayer();
    CPlayer(const CPlayer& orig);
    virtual ~CPlayer();
    CPlayer(string);
    void setPlayerName(string);
    string getPlayerName() const;
    void setNumOfLives(unsigned short);
    unsigned short getNumOfLives() const;
    void setPlayerScore(unsigned int);
    unsigned int getPlayerScore() const;
    void restorePlayer();
    void updatePlayer();
private:
    string name;
    unsigned short lives;
    unsigned int score;
    unsigned short prevLives;
    unsigned int prevScores;
};

#endif	/* __CPLAYER_H__ */
