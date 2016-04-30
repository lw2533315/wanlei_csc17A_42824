/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Date.cpp
 * Author: Administrator
 * 
 * Created on April 27, 2016, 8:07 PM
 */

#include "Date.h"
//#include<iostream>
//using namespace std;

void Date::setMonth() {
    bool go;
    int m;
    do {
        go = false;
        cout << "type the month" << endl;
        cin>>m;
        string reminder;
        if (cin.fail()) {
            cin.clear();
            getline(cin, reminder);
            cout << "invalid input" << endl;
            go = true;
        }
        if (m > 12 || m < 1) {
            cout << "invalid input" << endl;
            go = true;
        }
    } while (go);
   this->month=m;
}

void Date::setDay() {
    int d;
    bool go;
    do {
        go = false;
        cout << "type the day" << endl;
        cin>>d;
        string reminder;
        if (cin.fail()) {
            cin.clear();
            getline(cin, reminder);
            cout << "invalid input" << endl;
            go = true;
        }
        if (d > 31 || d < 1) {
            cout << "invalid input" << endl;
            go = true;
        }
    } while (go);
    this->day=d;
}

void Date::setYear() {
    bool go;
    int m;
    do {
        go = false;
        cout << "type the year" << endl;
        
        cin>>m;
        string reminder;
        if (cin.fail()) {
            cin.clear();
            getline(cin, reminder);
            cout << "invalid input" << endl;
            go = true;
        }
    } while (go);
    this->year=m;
}

int Date::getDay() const{
    return day;
}
int Date::getMonth() const{
    return month;
}
int Date::getYear() const{
    return year;
}

string Date::toEnglish(int m)const {
    if (m == 1)
        return "January";
    if (m == 2)
        return "February";
    if (m == 3)
        return "March";
    if (m == 4)
        return "April";
    if (m == 5)
        return "May";
    if (m == 6)
        return "June";
    if (m == 7)
        return "July";
    if (m == 8)
        return "August";
    if (m == 9)
        return "September";
    if (m == 10)
        return "October";
    if (m == 11)
        return"November";
    if (m == 12)
        return "December";
}

void Date::print() const {
    cout << month << "/" << day << "/" << year << endl;
    cout << toEnglish(month);
    cout<< " " << day << "," << year << endl;
    cout << day << " " << toEnglish(month) ;
    cout<< " " << year << endl;
}



