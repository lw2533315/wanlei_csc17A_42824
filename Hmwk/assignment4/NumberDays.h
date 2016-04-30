/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NumberDays.h
 * Author: Administrator
 *
 * Created on April 28, 2016, 2:53 PM
 */

#ifndef NUMBERDAYS_H
#define NUMBERDAYS_H


class NumberDays {
public:
    NumberDays(){};
    NumberDays(int);
    double hourToDay(int n);
    int dayToHour(double n);
    int getHour()const;
    double getDay()const;
    NumberDays& operator=(NumberDays&);
    NumberDays& operator+(NumberDays&);
    NumberDays& operator-(NumberDays&);
    NumberDays& operator++();
    NumberDays const operator++(int);
    NumberDays& operator--();
    NumberDays const operator--(int);
private:
    int hours;
    double day;

};

#endif /* NUMBERDAYS_H */

