/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BombS.h
 * Author: Administrator
 *
 * Created on April 11, 2016, 1:18 PM
 */
//#include "BombN.h"
#include "Bomb.h"
#ifndef BOMBS_H
#define BOMBS_H

class BombS : public Bomb {
    //    private;
    //    int damage;
    int number;

public:

    BombS() {
        number = 1;
    };

    virtual int power(Ship s) {
        return s.getSize();
    }
    void setNumber();
    virtual int getNumber()const;
};

int BombS::getNumber()const {
    return number;
}

void BombS::setNumber() {
    number--;
}



//int BombS::bombLeft() {
//    return number;
//}
//
//void BombS::setNumber() {
//    if (number >= 1)
//        number--;
//    else
//        cout << "no bomb " << endl;
//}




#endif /* BOMBS_H */

