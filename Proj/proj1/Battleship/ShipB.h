/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ShipB.h
 * Author: Administrator
 *
 * Created on April 11, 2016, 12:27 PM
 */
#include"Ship.h"
#include"BombS.h"
#ifndef SHIPB_H
#define SHIPB_H

#include <vector>
#include<iostream>
using namespace std;

class BattleShip : public Ship {
private:
    friend class Bomb; //friend class
    bool sink;
    int damagePart;
    vector<pair< int, int> >shipLoca; //store the x and y 's value
public:
    void clearShipLoca(); //clear the wrong points,which do not appear on the board
    void setWholeShip(); //draw the ship on the board
    void setSink(bool);
    bool isSink() const;
    void setDamage(int);
    int getDamage()const;
    vector<pair< int, int > >getShipLoca()const;
};

void BattleShip::clearShipLoca() {
    shipLoca.clear();
}

vector<pair< int, int > > BattleShip::getShipLoca()const {
    return shipLoca;
}

void BattleShip::setWholeShip() {
    int size = getSize();
    int x = getX();
    int y = getY();
    char d = getDirect();
    if (d == 'n') {
        for (int i = 0; i < size; i++) {
            shipLoca.push_back(make_pair(x + i, y));
        }
    }
    if (d == 's') {
        for (int i = 0; i < size; i++) {
            shipLoca.push_back(make_pair(x - i, y));
        }
    }
    if (d == 'w') {
        for (int i = 0; i < size; i++) {
            shipLoca.push_back(make_pair(x, y + i));
        }
    }
    if (d == 'e') {
        for (int i = 0; i < size; i++) {
            shipLoca.push_back(make_pair(x, y - i));
        }
    }

}

void BattleShip::setDamage(int n) {
    damagePart = n;
}

void BattleShip::setSink(bool y) {
    sink = y;
}

bool BattleShip::isSink() const {
    return sink;
}

int BattleShip::getDamage() const {
    return damagePart;
}


#endif /* SHIPB_H */

