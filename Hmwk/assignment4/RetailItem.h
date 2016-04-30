/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RetailItem.h
 * Author: Administrator
 *
 * Created on April 28, 2016, 10:24 AM
 */

#ifndef RETAILITEM_H
#define RETAILITEM_H
#include<iostream>
using namespace std;

class RetailItem {
public:
    RetailItem(string ,string,int ,double);
    string getDescription()const;
    string getName()const;
    int getUnitsOnHand() const;
    double getPrice()const;
    void display()const;
    void setDescription(string);
    void setName(string);
    void setUnitsOnHand(int);
    void setPrice(double);
//    RetailItem(const RetailItem& orig);
//    virtual ~RetailItem();
private:
    string name;
    string description;
    int unitsOnHand;
    double price;

};

#endif /* RETAILITEM_H */

