/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PersonalInformation.h
 * Author: Administrator
 *
 * Created on April 28, 2016, 9:05 AM
 */

#ifndef PERSONALINFORMATION_H
#define PERSONALINFORMATION_H
#include<iostream>
using namespace std;
class PersonalInformation {
public:
//    PersonalInformation();
    void setName(string );
    void setAddress(string);
    void setAge(int);
    void setPhoneNumber(int );
    string getName()const;
    string getAddress()const;
    int getAge()const;
    int getPhoneNumber()const;
    void display();
private:
    string name;
    string address;
    int age;
    int phoneNumber;

};

#endif /* PERSONALINFORMATION_H */

