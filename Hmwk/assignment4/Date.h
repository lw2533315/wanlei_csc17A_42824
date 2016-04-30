/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Date.h
 * Author: Administrator
 *
 * Created on April 27, 2016, 8:07 PM
 */

#ifndef DATE_H
#define DATE_H
#include<iostream>
using namespace std;

class Date {
public:
    Date(){
        day=1;
        month=1;
        year=1900;
    }
    void setDay();
    void setMonth();
    void setYear();
    int getDay()const;
    int getMonth()const;
    int getYear()const;
    void print()const;
    string toEnglish(int)const;
private:
    int month;
    int day;
    int year;
};

#endif /* DATE_H */

