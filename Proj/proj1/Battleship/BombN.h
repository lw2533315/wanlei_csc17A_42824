/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BombN.h
 * Author: Administrator
 *
 * Created on April 11, 2016, 11:38 AM
 */
#include "Bomb.h"
#ifndef BOMBN_H
#define BOMBN_H

class BombN : public Bomb {
protected:
    int number;
public:

    BombN() {
        number = 100;
    };

    virtual int power(Ship s) {
        return 1;
    }
    void setNumber();
    virtual int getNumber()const;
};

int BombN::getNumber()const {
    return number;
}

void BombN::setNumber() {
    number--;
}



#endif /* BOMBN_H */

