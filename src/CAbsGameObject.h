/* 
 * File:   CAbsGameObject.h
 * Author: soniyj
 *
 * Created on 11 December 2013, 13:03
 */

#ifndef __CABSGAMEOBJECT_H__
#define	__CABSGAMEOBJECT_H__

class CAbsGameObject {
public:
    CAbsGameObject();
    CAbsGameObject(const CAbsGameObject& orig);
    virtual ~CAbsGameObject();
    virtual bool getDestroyed() = 0;
    void setDestroyed(bool);
//private:
protected:
    bool destroyed;
};

#endif	/* __CABSGAMEOBJECT_H__*/
