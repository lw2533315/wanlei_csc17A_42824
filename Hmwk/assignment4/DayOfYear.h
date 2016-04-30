/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DayOfYear.h
 * Author: Administrator
 *
 * Created on April 28, 2016, 11:35 AM
 */

#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H
#include<iostream>
using namespace std;

class DayOfYear {
public:
    DayOfYear(int );
    DayOfYear(string,int);
    void print()const;
    int matchMon(string)const;
    int getDay()const;
    DayOfYear& operator ++();
    DayOfYear const operator++(int);
    DayOfYear& operator--();
    DayOfYear const operator--(int);
//    DayOfYear(const DayOfYear& orig);
//    virtual ~DayOfYear();
private:
    int day;
    static string month[13];
    static int dayOfMonth[13];
//    string  month[13]={"","January","February","March","April",
//    "May","June","July","August","September","October",
//    "November","December"};
//    int dayOfMonth[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

};

#endif /* DAYOFYEAR_H */



//private:
//    static string names-=[5];
//    
//    static string class::names[5] = {"6","as"}