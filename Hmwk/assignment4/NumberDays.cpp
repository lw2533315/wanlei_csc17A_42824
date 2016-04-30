/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NumberDays.cpp
 * Author: Administrator
 * 
 * Created on April 28, 2016, 2:53 PM
 */

#include "NumberDays.h"


NumberDays::NumberDays(int n) {
    hours=n;
    day=hourToDay(n);
}
NumberDays& NumberDays::operator =(NumberDays &s){
    this->hours=s.hours;
    this->day=s.day;
    return *this;
}
NumberDays& NumberDays::operator +(NumberDays &a){
    this->hours+=a.hours;
    this->day+=a.day;
    return *this;
}
NumberDays& NumberDays::operator -(NumberDays &a){
    this->hours-=a.hours;
    this->day-=a.day;
    return *this;
}
NumberDays& NumberDays::operator ++(){
    this->hours++;
    this->day+=hourToDay(1);
    return *this;
}
const NumberDays NumberDays::operator ++(int){
    NumberDays a=*this;
    a.hours+=1;
    a.day+=hourToDay(1);
    return a;
}
NumberDays& NumberDays::operator --(){
    this->hours--;
    this->day-=hourToDay(1);
    return *this;
}
const NumberDays NumberDays::operator --(int){
    NumberDays a=*this;
    a.hours++;
    a.day-=hourToDay(1);
    return a;
}
double NumberDays:: hourToDay(int n){
    return (double)n/24;
}
int NumberDays::dayToHour(double d){
    return d*24;
}
int NumberDays::getHour() const{
    return hours;
}
double NumberDays::getDay()const{
    return day;
}



