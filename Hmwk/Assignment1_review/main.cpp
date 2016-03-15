/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on March 1, 2016, 9:03 PM
 */

#include <cstdlib>
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<cctype>
using namespace std;
void celsiusToFahrenheit();
void currency();
void dayInMonth();
void dayCal(int, int);
void population();
void temperatureTable();
double celsius(double);
void rainOrShine();
void binarySearch();
void muchDayRain(int, int, int);
void sort(string [], int size);
void search(string, string [], int begin, int end);
void trueOrFalseDisplay();
void display(bool, bool);

/*
 * 
 */
int main(int argc, char** argv) {
    while (true) {
        bool go;
        int option = 100;
        do {
            go = false;
            cout << "choice problem,1-8,and 9 exit" << endl;
            string input = "";
            cin>>input;
            option = (int) input[0] - 48;
            //            cout << "option is " << option << endl;
            if (option > 9 || option < 1)
                go = true;
        } while (go);

        switch (option) {
            case 1: celsiusToFahrenheit();
                break;
            case 2: currency();
                break;
            case 3: dayInMonth();
                break;
            case 4: population();
                break;
            case 5: temperatureTable();
                break;
            case 6: rainOrShine();
                break;

            case 7:binarySearch();
                break;
            case 8:trueOrFalseDisplay();
                break;
            case 9: exit(0);
            default: break;
        }
    }

    return 0;
}

void trueOrFalseDisplay() {
    cout << setw(12) << "X : T , Y : F" << endl;
    display(true, false);
    cout << endl;
    cout << setw(12) << "X : T , Y : T" << endl;
    display(true, true);
    cout << endl;
    cout << setw(12) << "X : F , Y :T" << endl;
    display(false, true);
    cout << endl;
    cout << setw(12) << "X : F , Y : F" << endl;
    display(false, false);
}

void display(bool x, bool y) {
    cout << left << setw(12) << "!X :" << ((!x) ? "T" : "F") << endl;
    cout << setw(12) << "!Y :" << ((!y) ? "T" : "F") << endl;
    cout << setw(12) << "X&&Y :" << ((x && y) ? "T" : "F") << endl;
    cout << setw(12) << "X||Y :" << ((x || y) ? "T" : "F") << endl;
    cout << setw(12) << "X^Y : " << ((x^y) ? "T" : "F") << endl;
    cout << setw(12) << "X^Y^Y :" << ((x^y^y) ? "T" : "F") << endl;
    cout << setw(12) << "X^Y^X :" << ((x^y^x) ? "T" : "F") << endl;
    cout << setw(12) << "!(X||Y) :" << ((!(x || y)) ? "T" : "F") << endl;
    cout << setw(12) << "!X&&!Y :" << ((!x&&!y) ? "T" : "F") << endl;
    cout << setw(12) << "!(X&&Y) :" << (!(x && y) ? "T" : "F") << endl;
    cout << setw(12) << "!X||!Y :" << (!x || !y ? "T" : "F") << endl;
}

void binarySearch() {
    const int NUM_NAMES = 20;
    string names[NUM_NAMES] = {
        "Collins,bill", "Smith,Bart", "Allen,Jim",
                "griffin,Jim", "Stamey,Marty", "Rose,Geri",
                "Taylor,Terri", "Johnson,Jill", "Allison,Jeff",
                "Looney,Joe", "Wolfe,Bill", "James,Jean",
                "Weaver,Jim", "Pore,Bob", "Rutherford,Grey",
                "Javens,Renee", "Harrison,Rose", "Setzer,Cathy"
        "Pike,Gordon", "Hollan,Beth"
    };
    sort(names, NUM_NAMES);
    cout << "enter the full name" << endl;
    string inputName;
    cin>>inputName;
    inputName[0] = toupper(inputName[0]);
    search(inputName, names, 0, NUM_NAMES-1 );
}

void search(string s, string name[], int begin, int end) {
    if (end != begin) {
        int mid = (end + begin) / 2;
//               << name[mid] << endl;
        if (s.compare(name[mid]) == 0) {
            cout << "the name is on  the list" << endl;
        } else if (s.compare(name[mid]) > 0) {
            search(s, name, ++mid, end);
        } else {
            search(s, name, begin,--mid);
        }
    } else{
        if(name[end]==s)
            cout<<"the name is on the list"<<endl;
        else
        cout << "the name is not on the list" << endl;
    }
}

void sort(string a[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            a[i][0] = toupper(a[i][0]);
            a[j][0] = toupper(a[j][0]);
            if (a[i].compare(a[j]) > 0)
                swap(a[i], a[j]);
        }
    }
}

void rainOrShine() {

    ifstream ifs;
    ifs.open("RainOrShine.txt");
    char weather[3][30] = {};
    int row = 0, col = 0;
    string tempS;

    while (getline(ifs, tempS)) {
        //        cout << tempS << endl;
        int len = tempS.length();
        col = 0;
        for (int i = 0; i < len; i++) {
            if (tempS[i] == 'r' || tempS[i] == 'c' || tempS[i] == 's')
                weather[row][col++] = tempS[i];
            if (col == 31)
                break;
        }
        row++;
//        cout << "col now is " << col << endl;
    }
    //    cout << "test1" << endl;
    int juneR = 0, juneS = 0, juneC = 0,
            julyR = 0, julyS = 0, julyC = 0,
            augustR = 0, augustC = 0, augustS = 0,
            rain = 0, cloudy = 0, shine = 0;

    for (int j = 0; j < 30; j++) {
//        cout << weather[0][j] << " ";
        if (weather[0][j] == 'r') {
            juneR++;
            rain++;
        }
        if (weather[0][j] == 'c') {
            juneC++;
            cloudy++;
        }
        if (weather[0][j] == 's') {
            juneS++;
            shine++;
        }
    }
    cout << endl;
    for (int j = 0; j < 30; j++) {
//        cout << weather[1][j] << " ";
        if (weather[1][j] == 'r') {
            julyR++;
            rain++;
        }
        if (weather[1][j] == 'c') {
            julyC++;
            cloudy++;
        }
        if (weather[1][j] == 's') {
            julyS++;
            shine++;
        }
    }
    cout << endl;
    for (int j = 0; j < 30; j++) {
//        cout << weather[2][j] << " ";
        if (weather[2][j] == 'r') {
            augustR++;
            rain++;
        }
        if (weather[2][j] == 'c') {
            augustC++;
            cloudy++;
        }
        if (weather[2][j] == 's') {
            augustS++;
            shine++;
        }
    }
    cout << endl;

    cout << "in june there are " << juneS << " days shine" << endl;
    cout << "                  " << juneC << " days cloudy" << endl;
    cout << "                  " << juneR << " days rain" << endl;
    cout << "in july there are " << julyS << " days shine" << endl;
    cout << "                  " << julyC << " days cloudy" << endl;
    cout << "                  " << julyR << " days rain" << endl;
    cout << "in august there are " << augustS << " days shine" << endl;
    cout << "                    " << augustC << " days cloudy" << endl;
    cout << "                    " << augustR << " days rain" << endl;
    cout << "in the three monthes totlly there are " << rain << " days raining;" << endl;
    cout << "                                      " << cloudy << " days cloudy" << endl;
    cout << "                                      " << shine << " days shining" << endl;
    muchDayRain(juneR, julyR, augustR);
}

void muchDayRain(int juneR, int julyR, int augustR) {
    if (juneR > julyR) {
        if (juneR > augustR)
            cout << "june has largest number of raining days" << endl;
        else if (juneR == augustR) {
            cout << "june and august both have largest number of raining days" << endl;
        } else
            cout << "august has largest number of raining days" << endl;
    } else if (juneR == julyR) {
        if (juneR > augustR)
            cout << "june and july both have largest number of raining days" << endl;
        else if (juneR == augustR)
            cout << "three months have the same number of raining days" << endl;
        else
            cout << "august has largest number of raining days" << endl;
    } else {
        if (julyR > augustR)
            cout << "july has largest number of raining days" << endl;
        else if (julyR == augustR)
            cout << "july and august both have  largest number of raining days" << endl;
        else
            cout << "august has largest number of raining days" << endl;
    }
}

void celsiusToFahrenheit() {

    cout << "please enter the temperature(c)" << endl;
    int temperature;
    cin>>temperature;
    cout << "the temperature (F) is " << 9.0 / 5 * temperature + 32 << endl;
}

void currency() {
    const float YEN_PER_DOLLAR = 98.93;
    const float EUROS_PER_DOLLAR = 0.74;
    cout << "how much dollar do you wanna to exchange?" << endl;
    float money;

    if (cin >> money) {
        cout << "if exchange Yen, you could get " << fixed << setprecision(2) << money * YEN_PER_DOLLAR << endl;
        cout << "if exchange EUROS,you could get" << fixed << setprecision(2) << money * EUROS_PER_DOLLAR << endl;
    } else {

        cin.clear();
        cin.ignore(1024, '\n');
    }


}

void dayInMonth() {
    cout << "which month input the month (1-12)" << endl;
    int month, year;
    bool go;
    if (cin >> month) {

        if (month <= 12 && month >= 1) {
            do {
                go = false;
                cout << "which year? please input the number" << endl;
                if (cin >> year) {
                    dayCal(month, year);
                } else {
                    go = true;
                    cout << "wrong input" << endl;
                    cin.clear();
                    cin.ignore(1024, '\n');
                }
            } while (go);
        } else {
            cout << "no month is 13, month should be 1-12" << endl;
            return;
        }
    } else {

        cout << "wrong input" << endl;
        cin.clear();
        cin.ignore(1026, '\n');
    }
}

void dayCal(int month, int year) {
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        cout << "31 days" << endl;
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        cout << "30 days" << endl;
    else {
        if (year % 400 == 0)
            cout << "29 days" << endl;
        else if (year % 100 != 0 && year % 4 == 0)
            cout << "29 days" << endl;

        else
            cout << "28 days" << endl;
    }
}

void population() {
    int num = 0;
    double up = 0;
    int day = 0;
    bool go;
    do {
        go = false;
        cout << "please input the original number of the population (greater than 1)\n "
                "   the increasing percentage %(positive)\n and how many day multiply(greater than 1)" << endl;
        if (cin >> num >> up >> day) {
            if (num < 2) {
                cout << "size of the population cannot less than 2" << endl;
                go = true;
            }
            if (day < 1) {
                cout << "increasing day cannot less than 1" << endl;
                go = true;
            }
            if (up < 0) {
                cout << "increasing percentage cannot be negative" << endl;
                go = true;
            }
        } else {
            cout << "wrong input" << endl;
            cin.clear();
            cin.ignore(1025, '\n');
            go = true;
        }
    } while (go);
    for (int i = 1; i <= day; i++) {

        int n = num * (1 + up * 0.01);
        cout << "the " << i << " day, the population is " << n << endl;
        num = num * (1 + up * 0.01);
        cout << "num is " << num << endl;
    }
}

void temperatureTable() {
    cout << setw(10) << "F" << setw(16) << "C" << endl;
    for (int i = 0; i <= 20; i++) {

        cout << setw(10) << i << setw(20) << celsius(i) << endl;
    }
}

double celsius(double t) {
    return 5 / 9.0 * (t - 32);
}