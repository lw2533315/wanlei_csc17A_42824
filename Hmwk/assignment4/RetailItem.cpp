/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RetailItem.cpp
 * Author: Administrator
 * 
 * Created on April 28, 2016, 10:24 AM
 */

#include "RetailItem.h"

RetailItem::RetailItem(string n,string d,int num,double p){
    name=n;
    description=d;
    unitsOnHand=num;
    price=p;
}
void RetailItem::setDescription(string s){
    description= s;
}
void RetailItem::setName(string s){
    name=s;
}
void RetailItem::setPrice(double d){
    price=d;
}
void RetailItem::setUnitsOnHand(int n){
    unitsOnHand=n;
}
string RetailItem::getDescription() const{
    return description;
}
string RetailItem::getName()const{
    return name;
}
int RetailItem::getUnitsOnHand() const{
    return unitsOnHand;
}
double RetailItem::getPrice() const{
    return price;
}
void RetailItem::display() const{
    cout<<"Name: "<<name<<endl;
    cout<<"Description: "<<description<<endl;
    cout<<"UnitsOnHand: "<<unitsOnHand<<endl;
    cout<<"Price: "<<price<<endl;
}
//RetailItem::RetailItem(const RetailItem& orig) {
//}

//RetailItem::~RetailItem() {
//}

