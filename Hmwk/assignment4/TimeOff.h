/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TimeOff.h
 * Author: Administrator
 *
 * Created on April 28, 2016, 3:42 PM
 */
#include "NumberDays.h"
#ifndef TIMEOFF_H
#define TIMEOFF_H

#include <iostream>
using namespace std;

class TimeOff {
public:
    void setName(string);
    void setId(string);
    void setMaxSickDays(NumberDays);
    void setSickTaken(NumberDays);
    void setMaxVacation(NumberDays);
    void setVacTaken(NumberDays);
    void setMaxUnpaid(NumberDays);
    void setUnpaidTaken(NumberDays);
    string getName()const;
    string getId()const;
    int getMaxSickDays()const;
    int getSickTaken()const;
    int getMaxVacation()const;
    int getVacTaken()const;
    int getMaxUnpaid()const;
    int getUnpaidTaken()const;
    void print()const;

private:
    NumberDays maxSickDays;
    NumberDays sickTaken;
    
    NumberDays maxVacation;
    NumberDays vacTaken;
    NumberDays maxUnpaid;
    NumberDays unpaidTaken;
    string name;
    string id;

};

#endif /* TIMEOFF_H */

