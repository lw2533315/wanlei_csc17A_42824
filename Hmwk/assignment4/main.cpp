/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on April 27, 2016, 7:52 PM
 */
#include "Date.h"
#include "Employee.h"
#include "Car.h"
#include "PersonalInformation.h"
#include "RetailItem.h"
#include "Numbers.h"
#include "DayOfYear.h"
#include "NumberDays.h"
#include "TimeOff.h"
#include <cstdlib>
#include <vector>

using namespace std;

/*
 * 
 */
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();
void problem9();
void problem10();

//Begin Execution Here!!!

int main(int argv, char *argc[]) {
    int inN;
    do {
        Menu();
        inN = getN();
        switch (inN) {
            case 1: problem1();
                break;
            case 2: problem2();
                break;
            case 3: problem3();
                break;
            case 4: problem4();
                break;
            case 5: problem5();
                break;
            case 6: problem6();
                break;
            case 7: problem7();
                break;
            case 8: problem8();
                break;
            case 9: problem9();
                break;
            case 10: problem10();
                break;
            default: def(inN);
        }
    } while (inN >= 1 && inN <= 10);
    return 0; //If midterm not perfect, return something other than 1
}

void Menu() {
    cout << "Menu for the assignment 4" << endl;
    cout << "Type 1 for 13.1" << endl;
    cout << "Type 2 for 13.2" << endl;
    cout << "Type 3 for 13.3" << endl;
    cout << "Type 4 for 13.4" << endl;
    cout << "Type 5 for 13.5" << endl;
    cout << "Type 6 for 14.1" << endl;
    cout << "Type 7 for 14.2 " << endl;
    cout << "Type 8 for 14.3 " << endl;
    cout << "Type 9 for 14.4 " << endl;
    cout << "Type 10 for 14.5" << endl;

    cout << "Type anything else to exit \n" << endl;
}

int getN() {
    int inN;
    cin>>inN;
    string remainder;
    getline(cin, remainder);
    return inN;
}

void problem1() {
    Date date;
    date.setDay();
    date.setMonth();
    date.setYear();
    date.print();
}

void problem2() {
    Employee employee1;
    employee1.setName("Susan Meyers");
    employee1.setId(47899);
    employee1.setDept("Accounting");
    employee1.setPost("vice President");
    Employee employee2("Mark Jones", 39119, "IT", "Programmer");
    Employee employee3("Joy Rogers", 81774, "Manufacturing", "Engineer");
    employee1.display();
    employee2.display();
    employee3.display();

}

void problem3() {
    Car car(1995, "Saab");
    car.setSpeed(90);
    for (int i = 0; i < 5; i++) {
        cout << "the car is " << car.getYear() << " year " << car.getMake() << " now the speed is " << car.getSpeed() << endl;
        car.brake();
    }
}

void problem4() {

    PersonalInformation *pInfor = new PersonalInformation[3];
    PersonalInformation pi1;
    PersonalInformation pi2;
    PersonalInformation pi3;
    pInfor[0] = pi1;
    pInfor[1] = pi2;
    pInfor[2] = pi3;


    for (int i = 0; i < 3; i++) {

        int age, phone;
        bool go;
        cout << "type the name" << endl;
        string remainder;
        getline(cin, remainder);
        pInfor[i].setName(remainder);
        cout << "type the address" << endl;
        getline(cin, remainder);
        pInfor[i].setAddress(remainder);
        do {
            go = false;
            cout << "type the age" << endl;
            cin>>age;
            if (cin.fail()) {
                cin.clear();
                getline(cin, remainder);
                cout << "invalid input" << endl;
                go = true;
            }
            if (age > 200 || age < 0) {
                cout << "invalid input" << endl;
                go = true;
            }
        } while (go);
        pInfor[i].setAge(age);
        do {
            go = false;
            cout << "type the phone number" << endl;
            cin>>phone;
            if (cin.fail()) {
                cin.clear();
                getline(cin, remainder);
                cout << "invalid input" << endl;
                go = true;
            }
        } while (go);
        pInfor[i].setPhoneNumber(phone);
        getline(cin, remainder);
    }
    for (int i = 0; i < 3; i++) {
        pInfor[i].display();
    }
    delete []pInfor;
}

void problem5() {
    RetailItem retailItem1("Item#1", "Jacket", 12, 59.95);
    RetailItem retailItem2("Item#2", "Designer Jeans", 40, 34.95);
    RetailItem retailItem3("Item#3", "Shirt", 20, 24.95);
    retailItem1.display();
    retailItem2.display();
    retailItem3.display();

}

void problem6() {
    bool go;
    int num;
    string remainder;
    do {
        go = false;
        cout << "type a number 0-9999" << endl;
        cin>>num;
        if (cin.fail()) {
            cin.clear();
            getline(cin, remainder);
            cout << "valid input" << endl;
            go = true;
        }
        if (num > 9999 || num < 0) {
            cout << "out of range" << endl;
            go = true;
        }
    } while (go);
    getline(cin, remainder);
    Numbers number(num);
    number.display();
}

void problem7() {
    bool go;
    int num;
    string remainder;
    do {
        go = false;
        cout << "Type the day" << endl;
        cin>>num;
        if (cin.fail()) {
            cin.clear();
            getline(cin, remainder);
            go = true;
            cout << "valid input" << endl;
        }
        if (num < 1 || num > 365) {
            cout << "out of range" << endl;
            go = true;
        }
    } while (go);
    DayOfYear dOfYear(num);
    dOfYear.print();

}

void problem8() {
    bool go;
    int num;
    string remainder;
    do {
        go = false;
        cout << "type day" << endl;
        cin>>num;
        if (cin.fail()) {
            cin.clear();
            getline(cin, remainder);
            go = true;
            cout << "valid input" << endl;
        }
        if (num > 31 || num < 1) {
            cout << "out of range" << endl;
            go = true;
        }
    } while (go);
    getline(cin, remainder);
    cout << "type which month the day is in" << endl;
    cin>>remainder;
    DayOfYear dOfYear(remainder, num);
    cout << dOfYear.getDay() << endl;
    cout << "test the operator ++,--" << endl;
    cout<<"set the first object is January 2"<<endl;
    DayOfYear dOfYear1("january", 2);
    cout << "january 2+1 is; ";
    dOfYear1++;
    cout << "the day is " << dOfYear1.getDay() << endl;
    cout<<"set the second object is January 1"<<endl;
    DayOfYear dOfYear2("january", 1);
    cout << "January 1-1 ";
    dOfYear2--;
    cout << "the day is " << dOfYear2.getDay() << endl;
    cout<<"set the third object is December 31"<<endl;
    DayOfYear dOfYear3("december", 31);
    cout << "December 31 +1 ";
    ++dOfYear3;
    cout << "the day is " << dOfYear3.getDay() << endl;
    cout<<"set the fourth object is December 26"<<endl;
    DayOfYear dOfYear4("December", 26);
    cout << "December 26-1; ";
    --dOfYear4;
    cout << "the day is " << dOfYear4.getDay() << endl;

}

void problem9() {
    cout << "if work1:15 hours" << endl;
    NumberDays nd(15);
    cout << "15 hours= " << nd.getDay() << " day" << endl;
    cout << "if work2: 22 hours" << endl;
    NumberDays nd1(22);
    nd.operator+(nd1);
    cout << "work1+work2, now work1: hours is " << nd.getHour() << " the day is " << nd.getDay() << endl;
    NumberDays nd2(5);
    cout << "if work3: 5 hours" << endl;

    nd.operator-(nd2);
    cout << "work1-work3, now work1; the hours is " << nd.getHour() << " the day is " << nd.getDay() << endl;
    nd.operator++();
    cout << "work1++; the hours is " << nd.getHour() <<
            "the day is " << nd.getDay();
    nd.operator--();
    cout << "work1--: the hours is " << nd.getHour() <<
            "the day is " << nd.getDay() << endl;
}

void problem10() {
    TimeOff tOff;
    string remainder;
    cout << "type the name " << endl;
    getline(cin, remainder);
    tOff.setName(remainder);
    cout << "type the id" << endl;
    getline(cin, remainder);
    tOff.setId(remainder);
    bool go;
    double num;
    do {
        go = false;
        cout << "how many days the maxsickdays is " << endl;
        cin>>num;
        if (cin.fail()) {
            cin.clear();
            getline(cin, remainder);
            cout << "valid input" << endl;
            go = true;
        }
    } while (go);
      NumberDays t(num*24);
    tOff.setMaxSickDays(t);
    do {
        go = false;
        cout << "how many days do you have take for sick-left " << endl;
        cin>>num;
        if (cin.fail()) {
            cin.clear();
            getline(cin, remainder);
            cout << "valid input" << endl;
            go = true;
        }
        if (num > tOff.getMaxSickDays()) {
            cout << "invalid input" << endl;
            go = true;
        }
    } while (go);
      NumberDays t1(num*24);
    tOff.setSickTaken(t1);
    do {
        go = false;
        cout << "how many days the maxVacation is " << endl;
        cin>>num;
        if (cin.fail()) {
            cin.clear();
            getline(cin, remainder);
            cout << "valid input" << endl;
            go = true;
        }
        if (num > 240 / 24) {
            cout << "valid input" << endl;
            go=true;
        }
    } while (go);
      NumberDays t2(num*24);
    tOff.setMaxVacation(t2);
    do {
        go = false;
        cout << "how many days do you have taken for vacation " << endl;
        cin>>num;
        if (cin.fail()) {
            cin.clear();
            getline(cin, remainder);
            cout << "valid input" << endl;
            go = true;
        }
        if (num > tOff.getMaxVacation()) {
            cout << "valid input" << endl;
            go=true;
        }
    } while (go);
      NumberDays t3(num*24);
    tOff.setVacTaken(t3);
    do {
        go = false;
        cout << "how many days the max unpaid vaction is " << endl;
        cin>>num;
        if (cin.fail()) {
            cin.clear();
            getline(cin, remainder);
            cout << "valid input" << endl;
            go = true;
        }
    } while (go);
    NumberDays t4(num*24);
    tOff.setMaxUnpaid(t4);
    do {
        go = false;
        cout << "how many days the unpaid vacation do you have taken " << endl;
        cin>>num;
        if (cin.fail()) {
            cin.clear();
            getline(cin, remainder);
            cout << "valid input" << endl;
            go = true;
        }if(num>tOff.getMaxUnpaid()){
            cout<<"invalid input"<<endl;
            go=true;
        }
    } while (go);
     NumberDays t5(num*24);
    tOff.setUnpaidTaken(t5);
    tOff.print();


}

void def(int inN) {
    cout << "You typed " << inN << " to exit the program" << endl;
}


