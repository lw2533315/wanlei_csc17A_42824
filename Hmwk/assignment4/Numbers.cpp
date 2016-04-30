/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Numbers.cpp
 * Author: Administrator
 * 
 * Created on April 28, 2016, 10:40 AM
 */

#include "Numbers.h"

Numbers::Numbers(unsigned int n) {
    number = n;
}

void Numbers::display()const {
    int result, left;
    result = number / 1000;
    if (result > 0) {
        cout<<lessThan20[result]<<" thousand ";
    }
    
    left=number%1000;
    result=left/100;
    if(result>0){
        cout<<lessThan20[result]<<" hundred ";
    }
    result=left%100;
    if(result>=20){
        left=result%10;
        result=result/10;
        if(left==0)
        cout<<greatThan20[result]<<endl;
        else{
            cout<<greatThan20[result]<<"-"<<left<<endl;
        }
    }else{
        if(result==0)
            cout<<""<<endl;
        else
        cout<<lessThan20[result]<<endl;
    }
        
}

//Numbers::Numbers(const Numbers& orig) {
//}
//
//Numbers::~Numbers() {
//}

