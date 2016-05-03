/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ship.h
 * Author: Administrator
 *
 * Created on April 10, 2016, 7:39 PM
 */

#ifndef SHIP_H
#define SHIP_H

class Ship {
private:
    int size;
    char direct;
    int x;
    int y;
public:

    void setDirection(char);
    void setCoPosition(int, int);
    void setSize(int);
    int getSize()const;
    int getX()const;
    int getY()const;
    char getDirect()const;


};

void Ship::setCoPosition(int a, int b) {
    x = a;
    y = b;
}

void Ship::setDirection(char d) {
    direct = d;
}

void Ship::setSize(int n) {
    size = n;
}

int Ship::getX()const {
    return x;
}

int Ship::getY()const {
    return y;
}

char Ship::getDirect() const {
    return direct;
}

int Ship::getSize()const {
    return size;
}


#endif /* SHIP_H */

