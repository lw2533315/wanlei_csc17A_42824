/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SavingsAccunt.h
 * Author: Administrator
 *
 * Created on June 9, 2016, 10:57 PM
 */

#ifndef SAVINGSACCUNT_H
#define SAVINGSACCUNT_H
#include <sstream>
#include<iostream>
using namespace std;

class SavingsAccount {
private:
    float Withdraw(float a); //Utility Procedure

    float Deposit(float a) {
        Balance += a;
        FreqDeposit++;
    }; //Utility Procedure
    float Balance; //Property
    int FreqWithDraw; //Property
    int FreqDeposit; //Property
public:
    SavingsAccount(float); //Constructor
    void Transaction(float); //Procedure
    float Total(float = 0, int = 0); //Savings Procedure
    float TotalRecursive(float = 0, int = 0, float =0);
    string toString(); //Output Properties

};

float SavingsAccount::TotalRecursive(float savint, int time, float BalanceT) {
    float BalanceTemp = BalanceT;
    if (BalanceTemp==0)
        BalanceTemp=Balance;
    if (time == 0)
        return BalanceTemp;
    else {
        BalanceTemp *= (1 + savint);
        time--;
        TotalRecursive(savint, time,BalanceTemp);

    }

}

float SavingsAccount::Total(float savint, int time) {
    float BalanceTemp = Balance;
    for (int i = 0; i < time; i++) {
        BalanceTemp *= (1 + savint);
    }
    return BalanceTemp;
}

string  SavingsAccount::toString() {
    stringstream ss;
    string b,w,d;
    ss<<Balance;
    ss>>b;
    ss.str("");
    ss.clear();
   ss<< FreqWithDraw;
    ss>>w;
    ss.str("");
    ss.clear();
    ss<<FreqDeposit;
    ss>>d;
    ss.str("");
    ss.clear();
    return  "your account's balance: "+b+'\n'+
            "FreqWithDraw: : "+w+'\n'+
            "Freqdeposit: "+d+'\n';
//    cout << "your account's balance: " << Balance << endl
//            << "FreqWithDraw: " << FreqWithDraw << endl
//            << "Freqdeposit: " << FreqDeposit << endl;
}

float SavingsAccount::Withdraw(float a) {
    if (a > Balance) {
        cout << "withdraw not allowed" << endl;
    } else {
        Balance -= a;
        FreqWithDraw++;
    }
}

void SavingsAccount::Transaction(float a) {
    if (a > 0) {
        Deposit(a);
        //        cout<<"balance now is: "<<endl;
    } else {
        Withdraw(a);
    }
}

SavingsAccount::SavingsAccount(float a) {
    Balance = 0;
    if (a > 0)
        Balance = a;
    FreqWithDraw = 0;
    FreqDeposit = 0;

}
#endif /* SAVINGSACCUNT_H */

