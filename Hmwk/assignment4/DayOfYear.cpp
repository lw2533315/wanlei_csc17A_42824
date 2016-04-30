/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DayOfYear.cpp
 * Author: Administrator
 * 
 * Created on April 28, 2016, 11:35 AM
 */

#include <vector>

#include "DayOfYear.h"
string DayOfYear::month[13]={"","January","February","March","April",
    "May","June","July","August","September","October",
    "November","December"};
int DayOfYear::dayOfMonth[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};


DayOfYear::DayOfYear(int n) {
    day = n;
}
DayOfYear& DayOfYear:: operator++(){
    if(day==365){
        day=1;
    }else
        day++;
    return *this;
}
const DayOfYear DayOfYear::operator ++(int){
    DayOfYear doy=*this;
     if(day==365){
        day=1;
    }else
       ++ day;
    return doy;
}
DayOfYear& DayOfYear::operator --(){
    if(day==1)
        day=365;
    else
        day++;
    return *this;
}
 const DayOfYear DayOfYear::operator --(int){
     DayOfYear doy=*this;
       if(day==1)
        day=365;
    else
        day++;
     return doy;
     
 } 

void DayOfYear::print() const {
    int num = day;
    int left = 0;
    int mon = 1;
    if (num <= 31) {
        cout << "Day " << day << " would be " << month[mon] << " " << num << endl;
    } else {
        mon++;
        num = num - 31;
        if (num <= 28) {
            cout << "Day " << day << " would be " << month[mon] << " " << num << endl;
        } else {
            mon++; //3
            num -= 28;
            if (num <= 31) {
                cout << "Day " << day << " would be " << month[mon] << " " << num << endl;
            } else {
                mon++; //4
                num -= 31;
                if (num <= 30) {
                    cout << "Day " << day << " would be " << month[mon] << " " << num << endl;
                } else {
                    mon++; //5
                    num -= 30;
                    if (num <= 31)
                        cout << "Day " << day << " would be " << month[mon] << " " << num << endl;
                    else {
                        mon++; //6
                        num -= 31;
                        if (num <= 30)
                            cout << "Day " << day << " would be " << month[mon] << " " << num << endl;
                        else {
                            mon++; //7;
                            num -= 30;
                            if (num <= 31)
                                cout << "Day " << day << " would be " << month[mon] << " " << num << endl;
                            else {
                                mon++; //8
                                num -= 31;
                                if (num <= 31)
                                    cout << "Day " << day << " would be " << month[mon] << " " << num << endl;
                                else {
                                    mon++; //9
                                    num -= 31;
                                    if (num <= 30)
                                        cout << "Day " << day << " would be " << month[mon] << " " << num << endl;
                                    else {
                                        mon++; //10
                                        num -= 30;
                                        if (num <= 31)
                                            cout << "Day " << day << " would be " << month[mon] << " " << num << endl;
                                        else {
                                            mon++; //11
                                            num -= 31;
                                            if (num <= 30)
                                                cout << "Day " << day << " would be " << month[mon] << " " << num << endl;
                                            else {
                                                mon++; //12
                                                num -= 30;
                                                cout << "Day " << day << " would be " << month[mon] << " " << num << endl;

                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

    }
}
int DayOfYear::getDay() const{
    return day;
}
DayOfYear::DayOfYear(string mon, int day){
    if(day>dayOfMonth[matchMon(mon)])
        cout<<"out of range"<<endl;
    else{
//        int num=0;
        for(int i=0;i<matchMon(mon);i++)
            day+=dayOfMonth[i];
        this->day=day;
        
    }
}
int DayOfYear::matchMon(string mon) const{
    mon[0]=toupper(mon[0]);
    for(int i=0;i<13;i++){
        if(mon==month[i])
            return i;
    }
}

//DayOfYear::DayOfYear(const DayOfYear& orig) {
//}
//
//DayOfYear::~DayOfYear() {
//}

