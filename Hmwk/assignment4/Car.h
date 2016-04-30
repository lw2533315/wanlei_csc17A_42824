/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Car.h
 * Author: Administrator
 *
 * Created on April 28, 2016, 8:19 AM
 */

#ifndef CAR_H
#define CAR_H
#include<iostream>
using namespace std;

class Car {
public:
    Car(int ,string);
//    Car(const Car& orig);
//    virtual ~Car();
    string getMake() const;
    int getYear() const;
    int getSpeed() const;
    void setSpeed(int);
    void brake();
private:
    int year;
    string make;
    int speed;
};

#endif /* CAR_H */

