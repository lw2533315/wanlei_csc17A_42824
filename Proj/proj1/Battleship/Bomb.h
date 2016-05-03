/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bomb.h
 * Author: Administrator
 *
 * Created on April 11, 2016, 11:35 AM
 */
#include "Ship.h"
#ifndef BOMB_H
#define BOMB_H

class Bomb {
public:
    virtual int power(Ship s) = 0;
    virtual int getNumber() const = 0;

};

#endif /* BOMB_H */

