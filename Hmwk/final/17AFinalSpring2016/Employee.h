/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Employee.h
 * Author: Administrator
 *
 * Created on June 10, 2016, 12:35 AM
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <cstring>
#include <iostream>
using namespace std;

class Employee {
public:
    Employee(char[], char[], float); //Constructor
    float CalculatePay(float, int); //Procedure
    float getGrossPay(float, int);
    float getGrossPay(); //Procedure
    float getNetPay(); //Procedure
    float getNetPay(float, int);
    void toString(); //Procedure

    int setHoursWorked(int a) {
        if (a > 0 && a < 84)
            HoursWorked = a;
        else
            cout << "Unacceptable HoursWorked " << endl;
    }; //Procedure

    float setHourlyRate(float f) {
        if (f > 0 && f < 200)HourlyRate = f;
        else
            cout << "Unacceptable HourlyRate " << endl;
    }; //Procedure
private:
    double Tax(); //Utility Procedure
    char MyName[20]; //Property
    char JobTitle[20]; //Property
    float HourlyRate; //Property
    int HoursWorked; //Property
    float GrossPay; //Property
    float NetPay; //Property
};

float Employee::CalculatePay(float rate, int time) {
    return getNetPay(rate, time);
    cout << "cal~~~~~~~" << endl;
}

float Employee::getNetPay(float rate, int time) {
    NetPay = getGrossPay(rate, time) - Tax();
    return NetPay;
}

float Employee::getGrossPay(float rate, int time) {
//    cout << "be~~~~~~~~~~" << endl;
//    cout << "rate is " << rate << " : " << "time is " << time << endl;
    setHourlyRate(rate);
    setHoursWorked(time);
//    cout << "after~~~~~~~~~" << endl;

    return getGrossPay();
}

float Employee::getNetPay() {
    return getGrossPay() - Tax();
}

float Employee::getGrossPay() {
    if (HoursWorked <= 40) {
        GrossPay = HourlyRate*HoursWorked;
        return GrossPay;
    } else if (HoursWorked > 40 && HoursWorked <= 50) {
        GrossPay = 40 * HourlyRate;
        GrossPay += HourlyRate * 1.5 * (HoursWorked - 40);
        return GrossPay;
    } else {
        GrossPay = 40 * HourlyRate;
        GrossPay += 10 * 1.5 * HourlyRate;
        GrossPay += HourlyRate * 2 * (HoursWorked - 50);
        return GrossPay;
    }
}

void Employee::toString() {
    cout << "Name: " << MyName << endl;
    cout << "JobTitle: " << JobTitle << endl;
    cout << "HourslyRate: " << HourlyRate << endl;
    cout << "HoursWored: " << HoursWorked << endl;
    cout << "GrossPay: " << GrossPay << endl;
    cout << "NetPay: " << NetPay << endl;
}

double Employee::Tax() {
    if (GrossPay <= 500)
        return GrossPay * 0.1;
    else if (GrossPay > 500 && GrossPay <= 1000) {
        double tax = 500 * 0.1;
        tax += (GrossPay - 500)*.2;
        return tax;
    } else {
        double tax = 500 * 0.1;
        tax += 500 * 0.2;
        tax += (GrossPay - 1000)*0.3;
        return tax;
    }
}

Employee::Employee(char c[], char t[], float r) {
    int cLen = strlen(c);
    for (int i = 0; i < cLen; i++) {
        MyName[i] = c[i];
    }
    int tLen = strlen(t);
    for (int i = 0; i < tLen; i++) {
        JobTitle[i] = t[i];
    }
    HourlyRate = 0;
    setHourlyRate(r);
    HoursWorked = 0;
    GrossPay = 0;
    NetPay = 0;
}


#endif /* EMPLOYEE_H */

