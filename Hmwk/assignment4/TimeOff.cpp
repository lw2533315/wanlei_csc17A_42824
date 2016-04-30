/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TimeOff.cpp
 * Author: Administrator
 * 
 * Created on April 28, 2016, 3:42 PM
 */

#include "TimeOff.h"

void TimeOff::print() const{
    cout<<"Name: "<<name<<endl;
    cout<<"Id: "<<id<<endl;
    cout<<"MaxSickDay: "<<getMaxSickDays()<<endl;
    cout<<"SickDayTaken: "<<getSickTaken()<<endl;
    cout<<"MaxVacation: "<<getMaxVacation()<<endl;
    cout<<"VacationTaken: "<<getVacTaken()<<endl;
    cout<<"MaxUnpaidVacation: "<<getMaxUnpaid()<<endl;
    cout<<"UnpaidVacationTaken: "<<getUnpaidTaken()<<endl;
}
void TimeOff::setId(string s){
    id=s;
}
void TimeOff::setName(string s){
    name=s;
}
void TimeOff::setMaxSickDays(NumberDays a){
    maxSickDays=a;
}
void TimeOff::setMaxUnpaid(NumberDays a){
    maxUnpaid=a;
}
void TimeOff::setMaxVacation(NumberDays a){
    maxVacation=a;
}
void TimeOff::setSickTaken(NumberDays a){
    sickTaken=a;
}
void TimeOff::setUnpaidTaken(NumberDays a){
    unpaidTaken=a;
}
void TimeOff::setVacTaken(NumberDays a){
    vacTaken=a;
}
string TimeOff::getId() const{
    return id;
}
string TimeOff::getName() const{
    return name;
}
int TimeOff::getMaxSickDays() const{
    return maxSickDays.getDay();
}
int TimeOff::getMaxUnpaid() const{
    return maxUnpaid.getDay();
}
int TimeOff::getMaxVacation() const{
    return maxVacation.getDay();
}
int TimeOff::getSickTaken() const{
    return sickTaken.getDay();
}
int TimeOff::getUnpaidTaken()  const{
    return unpaidTaken.getDay();
}
int TimeOff::getVacTaken() const{
    return vacTaken.getDay();
}







