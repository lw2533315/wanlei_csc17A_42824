/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PersonalInformation.cpp
 * Author: Administrator
 * 
 * Created on April 28, 2016, 9:05 AM
 */

#include "PersonalInformation.h"

string PersonalInformation::getAddress() const{
    return address;
}
int PersonalInformation::getAge() const{
    return age;
}
string PersonalInformation::getName() const{
    return name;
}
int PersonalInformation::getPhoneNumber() const{
    return phoneNumber;
}
void PersonalInformation::setAddress(string s){
    address=s;
}
void PersonalInformation::setAge(int n){
    age=n;
}
void PersonalInformation::setName(string s){
    name=s;
}
void PersonalInformation::setPhoneNumber(int n){
    phoneNumber=n;
}
void PersonalInformation::display(){
    cout<<"Name: "<<getName()<<endl;
    cout<<"Age: "<<getAge()<<endl;
    cout<<"Address: "<<getAddress()<<endl;
    cout<<"Phone: "<<getPhoneNumber()<<endl;
}


