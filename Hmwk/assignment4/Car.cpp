/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Car.cpp
 * Author: Administrator
 * 
 * Created on April 28, 2016, 8:20 AM
 */

#include "Car.h"

Car::Car(int year, string make) {
    this->year = year;
    this->make = make;
    this->speed = 0;
}

//Car::Car(const Car& orig) {
//}
//
//Car::~Car() {
//}

string Car::getMake() const {
    return make;
}

int Car::getSpeed() const {
    return speed;
}

int Car::getYear() const {
    return year;
}

void Car::brake() {
    if (speed > 0 && speed <= 5)
        speed = 0;
    else if (speed > 5)
        speed -= 5;
    else
        cout << "ths car has stop" << endl;
}

void Car::setSpeed(int s){
    speed =s;
}