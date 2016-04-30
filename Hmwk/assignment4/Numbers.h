/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Numbers.h
 * Author: Administrator
 *
 * Created on April 28, 2016, 10:39 AM
 */

#ifndef NUMBERS_H
#define NUMBERS_H
#include<iostream>
using namespace std;

class Numbers {
public:
    Numbers(unsigned int );
    void display()const;
    
//    Numbers(const Numbers& orig);
//    virtual ~Numbers();
private:
    int number;
    string lessThan20[20]={"zero","one","two","three","four","five","six",
    "seven","eight","nine","ten","eleven","twelve","thirteen","fourteen",
    "fifteen","sixteen","seventeen","eighteen","nineteen"};
    string greatThan20[10]={"","","twenty","thirty","fourty",
    "fifty","sixty","seventy","eighty","ninety"};
};

#endif /* NUMBERS_H */

