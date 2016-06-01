
/* 
 * File:   main.cpp
 * Author: Tsz, Kwan
 * Created on November 29, 2014, 5:09 PM
 * Assignment 5 chap 15-16
 */
//System libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
//User Libraries
#include "Employee.h"
#include "Time.h"
#include "Data.h"
#include "Essay.h"
//function prototypes
void menu();
int getN();
void prog1();
void prog2();
void prog3();
void prog4();
void prog5();
void prog6();
void prog7();
void prog8();
void prog9();
void prog10();
void def();
void testM(int);
void testD(int);

template <class T>
T minimum(T num1, T num2) {
    if (num1 > num2) return num2;
    else return num1;
}

template <class T>
T maximum(T num1, T num2) {
    if (num1 > num2) return num1;
    else return num2;
}

template <class T>
T absolute(T num) {
    return abs(num);
}

template <class T>
void total(T num, T &sum) {
    sum += num;
}

int main(int argc, char** argv) {
    int num;
    do {
        menu();
        num = getN();
        switch (num) {
            case 1:prog1();
                break;
            case 2:prog2();
                break;
            case 3:prog3();
                break;
            case 4:prog4();
                break;
            case 5:prog5();
                break;
            case 6:prog6();
                break;
            case 7:prog7();
                break;
            case 8:prog8();
                break;
            case 9:prog9();
                break;
            case 10:prog10();
                break;
            default:def();
                break;
        }
    } while (num < 11);
    return 0;
}

void menu() {
    cout << "Type 1 to run prog1\n";
    cout << "Type 2 to run prog2\n";
    cout << "Type 3 to run prog3\n";
    cout << "Type 4 to run prog4\n";
    cout << "Type 5 to run prog5\n";
    cout << "Type 6 to run prog6\n";
    cout << "Type 7 to run prog7\n";
    cout << "Type 8 to run prog8\n";
    cout << "Type 9 to run prog9\n";
    cout << "Type 10 to run prog10\n";
    cout << "Type other to exit\n";
}

int getN() {
    string remainder;
    bool inputValid;
    int num;
    do {
        inputValid = false;
        cin>>num;
        if(cin.fail()){
            inputValid=true;
            cin.clear();
            getline(cin,remainder);
            return 11;
        }else{
            getline(cin,remainder);
            if(remainder!="")
                return 11;
        }
    } while (inputValid);
    return num;
}
// Chap15_Prob1

void prog1() {
    string remainder;
    string name;
    string date;
    int num, shift;
    float pyrt;
    cout << "Input name\n";
    getline(cin, name);
    bool valid;
    do {
        valid = false;
        cout << "Input ID : ";
        cin>>num;
        if (cin.fail()) {
            cout << "invalid input" << endl;
            cin.clear();
            getline(cin, remainder);
            valid = true;
        }
    } while (valid);
    getline(cin, remainder);
    cout << "Input hire date with MM/DD/YY format\n";
    getline(cin, date);
    do {
        valid = false;
        cout << "Input shift (1=day, 2=night) :";
        cin>>shift;
        if (cin.fail()) {
            cout << "invalid input" << endl;
            cin.clear();
            getline(cin, remainder);
            valid = true;
        }
    } while (valid);
    do {
        valid = false;
        cout << "Input hourly pay rate : ";
        cin>>pyrt;
        if (cin.fail()) {
            cout << "invalid input" << endl;
            cin.clear();
            getline(cin, remainder);
            valid = true;
        }
    } while (valid);
    ProductionWorker a(name, num, date, shift, pyrt);
    cout << a;
}
// Chap15_Prob2

void prog2() {
    string name;
    string date;
    string remainder;
    int num;
    float annual;
    cout << "Input name\n";
    getline(cin, name);
    bool valid;
    do {
        valid = false;
        cout << "Input ID : ";
        cin>>num;
        if (cin.fail()) {
            cout << "invalid input" << endl;
            cin.clear();
            getline(cin, remainder);
            valid = true;
        }
    } while (valid);
    cout << "Input hire date with MM/DD/YY format\n";
    getline(cin, date);
    do {
        valid = false;
        cout << "Input annual salary: ";
        cin>>annual;
        if (cin.fail()) {
            cout << "invalideinput";
            cin.clear();
            getline(cin, remainder);
            valid = true;
        }
    } while (valid);
    getline(cin, remainder);
    ShiftSupervisor a(name, num, date, annual);
}
// Chap15_Prob3

void prog3() {
    string remainder;
    bool valid;
    float g, s, cl, c;

    cout << "GradedActivity and Essay\n";
    do {
        valid = false;
        cout << "input grammar score max=30\n";
        cin>>g;
        if (cin.fail()) {
            cout << "invalid input" << endl;
            cin.clear();
            getline(cin, remainder);
            valid = true;
        }
    } while (valid);
    do {
        valid = false;
        cout << "input spelling score max=20\n";
        cin>>s;
        if (cin.fail()) {
            cout << "invalid input" << endl;
            cin.clear();
            getline(cin, remainder);
            valid = true;
        }
    } while (valid);
    do {
        valid = false;
        cout << "input correct length score max=20\n";
        cin>>cl;
        if (cin.fail()) {
            cout << "invalid input" << endl;
            cin.clear();
            getline(cin, remainder);
            valid = true;
        }
    } while (valid);
    do {
        valid = false;
        cout << "input content score max=30\n";
        cin>>c;
        if (cin.fail()) {
            cout << "invalid input" << endl;
            cin.clear();
            getline(cin, remainder);
            valid = true;
        }
    } while (valid);
    Essay a(g, s, cl, c);
    cout << "score = " << a.getScore() << "\n\n";
}
//Chap15_Prob4

void prog4() {
    cout << "Military time conversion\n";
    int h, s;
    string remainder;
    bool valid;
    do {
        do {
            valid = false;
            cout << "Input hour in military format\n(h>=0&&h<=2359);" << endl;
            cin>>h;
            if (cin.fail()) {
                cout << "invalid input" << endl;
                cin.clear();
                getline(cin, remainder);
                valid = true;
            }
        } while (valid);
    } while (h < 0 || h > 2359);
    do {
        do {
            valid = false;
            cout << "Input second\n(second>=0&&s<=59)";
            cin>>s;
            if (cin.fail()) {
                valid = true;
                cin.clear();
                getline(cin, remainder);
            }
        } while (valid);
    } while (s < 0 || s > 59);
    MilTime mh(h, s);
    cout << "Hour=" << mh.getHour() << endl;
    cout << "Standard hour=" << mh.getStandHr() << "\n\n";
}
//Chap15_Prob5

void prog5() {
    cout << "TimeClock\n";
    int sh, eh;
    do {
        do {
            cout << "Input start time in XX:XX military format\n";
            cin>>sh;
        } while (sh < 0 || sh > 2359);
        do {
            cout << "Input end time in XX:XX military format\n";
            cin>>eh;
        } while (eh < 0 || eh > 2359);
    } while (sh > eh);
    TimeClock p5(eh, sh);
    cout << "The elapsed time is " << p5.elapsed() << " hours\n";
}
//Gaddis_7thEd_Chap16_Prob1

void prog6() {
    cout << "Date Exceptions\n";
    int d, m, y;
    bool valid;
    bool inputValid;
    string remainder;
    do {
        valid = false;
        do {
            inputValid = false;
            cout << "Input month :";
            cin>>m;
            if (cin.fail()) {
                cout << "invalid input" << endl;
                inputValid = true;
                cin.clear();
                getline(cin, remainder);
            }
        } while (inputValid);
        try {
            testM(m);
        } catch (string temp) {
            cout << temp;
            valid = true;
        }
    } while (valid);
    do {
        valid = false;
        do {
            inputValid = false;
            cout << "Input day :";
            cin>>d;
            if (cin.fail()) {
                cout << "invalid input" << endl;
                cin.clear();
                getline(cin, remainder);
                inputValid = true;
            }
        } while (inputValid);
        try {
            testD(d);
        } catch (string temp) {
            cout << temp;
            valid = true;
        }
    } while (valid);
    do {

        inputValid = false;
        cout << "Input year :";
        cin>>y;
        if (cin.fail()) {
            cout << "invalid input" << endl;
            inputValid = true;
            cin.clear();
            getline(cin, remainder);
        }
    } while (inputValid);
    Date p1(d, m, y);
    p1.print1();
    p1.print2();
    p1.print3();
}
//Chap14_Prob3

void prog7() {
    bool inputValid;
    string remainder;
    cout << "TimeFormatExceptions\n";
    int h, s;
    do {
        inputValid = false;
        cout << "Input hour in military format\n";
        cin>>h;
        if (cin.fail()) {
            inputValid = true;
            cout << "invalid input" << endl;
            cin.clear();
            getline(cin, remainder);
        }
    } while (inputValid);
    do {
        inputValid = false;
        cout << "Input second\n";
        cin>>s;
        if (cin.fail()) {
            cout << "invalid input" << endl;
            cin.clear();
            getline(cin, remainder);
            inputValid = true;
        }
    } while (inputValid);
    try {
        MilTime test(h, s);
        cout << "Hour=" << test.getHour() << endl;
        cout << "Standard hour=" << test.getStandHr() << "\n\n";
    } catch (string e) {
        cout << e << endl;
    } catch (string e) {
        cout << e << endl;
    }
}
//7thEd_Chap16_Prob3

void prog8() {
    cout << "min/max template\n";
    int i1, i2;
    float f1, f2;
    bool inputValid;
    string remainder;
    do {
        cout << "input two integer number with space\n";
        cin >> i1>>i2;
        inputValid = false;
        if (cin.fail()) {
            cout << "invalid input" << endl;
            cin.clear();
            getline(cin, remainder);
            inputValid = true;
        }
    } while (inputValid);
    cout << minimum(i1, i2) << " is minimum\n";
    cout << maximum(i1, i2) << " is maximum\n";
    do {
        cout << "input 2 float with space\n";
        cin >> f1>>f2;
        inputValid = false;
        if (cin.fail()) {
            inputValid = true;
            cin.clear();
            getline(cin, remainder);
            cout << "invalid input" << endl;
        }
    } while (inputValid);
    cout << minimum(f1, f2) << " is minimum\n";
    cout << maximum(f1, f2) << " is maximum\n";

}
//7thEd_Chap16_Prob4

void prog9() {
    int i;
    float f;
    cout << "absolute value template\n";
    bool inputValid;
    string remainder;
    do {
        inputValid = false;
        cout << "input a integer number \n";
        cin>>i;
        if (cin.fail()) {
            cout << "invalid input" << endl;
            inputValid = true;
            cin.clear();
            getline(cin, remainder);
        } else {
            getline(cin, remainder);
            //        cout<<"remainder is :"<<remainder<<endl;
            //        cout<<"remainder's size is "<<remainder.length()<<endl;
            if (remainder != "") {//test float
                cout << "invalid input" << endl;
                inputValid = true;
            }
        }

    } while (inputValid);
    cout << "Absolute value = " << absolute(i) << endl;
    do {
        cout << "input a float number \n";
        cin>>f;
        inputValid = false;
        if (cin.fail()) {
            cout << "invalid input" << endl;
            inputValid = true;
            cin.clear();
            getline(cin, remainder);
        }
    } while (inputValid);
    cout << "Absolute value = " << absolute(f) << endl;
}
//7thEd_Chap16_Prob5

void prog10() {
    string remainder;
    bool inputValid;
    cout << "total template\n";
    cout << "Input integer (total 5 inputs)\n";
    int num, sum = 0;
    float fnum, fsum = 0;
    for (int i = 0; i < 5; i++) {
        do {
            inputValid = false;
            cout << "The " << i + 1 << "st input\n";
            cin>>num;

            if (cin.fail()) {
                cout << "invalid input" << endl;
                cin.clear();
                getline(cin, remainder);
                inputValid = true;
            } else {
                getline(cin, remainder);
                if (remainder != "") {//test float
                    cout << "invalid input" << endl;
                    inputValid = true;
                }
            }

        } while (inputValid);
        total(num, sum);
        cout << "total = " << sum << endl;
    }
    cout << "Input float (total 5 inputs)\n";
    for (int i = 0; i < 5; i++) {
        do {
            inputValid = false;
            cout << "The " << i + 1 << "st input\n";
            cin>>fnum;
            if (cin.fail()) {
                cin.clear();
                inputValid = true;
                getline(cin, remainder);
                inputValid = true;
            }
        } while (inputValid);
        total(fnum, fsum);
        cout << "total = " << fsum << endl;
    }
}

void def() {
    cout << "Program ends\n";
}

void testM(int m) {
    if (m < 1 || m > 12) {
        string temp;
        temp = "Invalid month\n";
        throw temp;
    }
}

void testD(int d) {
    if (d < 1 || d > 31) {
        string temp;
        temp = "Invalid day\n";
        throw temp;
    }
}
