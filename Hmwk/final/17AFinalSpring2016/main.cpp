/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on June 2, 2016, 4:34 PM
 */

#include <cstdlib>
#include <iostream>
#include<fstream>
#include <vector>
#include<iomanip>

#include "Prob1Random.h"
#include "Prob2Sorting.h"
#include "Prob3Table.h"
#include "Employee.h"
#include "SavingsAccount.h"

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
            default: def(inN);
        }
    } while (inN >= 1 && inN <= 6);
    return 0; //If midterm not perfect, return something other than 1
}

void Menu() {
    cout << "Menu for the Midterm" << endl;
    cout << "Type 1 for problem 1" << endl;
    cout << "Type 2 for problem 2" << endl;
    cout << "Type 3 for problem 3" << endl;
    cout << "Type 4 for problem 4  "<<endl
           << "a.I modify toString()function to return a string"<<endl
           << "b.I did binary serialized file save to problem4class.txt"<< endl;
    cout << "Type 5 for problem 5" << endl;
    cout << "Type 6 for problem 6" << endl;
    cout << "Type anything else to exit \n" << endl;
}

int getN() {
    int inN;
    cin>>inN;
    if (cin.fail())
        inN = -99999;
    //    else {
    //       
    //    }
    return inN;
}

void problem1() {
    cout << "In problem # 1" << endl << endl;
    int arry[] = {16, 33, 56, 78, 126};
    int size = 5;
    int loopTimes = 100000;
    Prob1Random a(size, arry);
    for (int i = 0; i < loopTimes; i++) {
        a.randSet();
    }
    int *x = a.getFreq();
    int *y = a.getAry();
    for (int i = 0; i < size; i++) {
        cout << int(y[i]) << " occured " << x[i] << " times" << endl;
    }
    cout << "The total number of random numbers is " << a.getLoopNum() << endl;
    cout << endl;
}

void problem2() {
    string remainder;
    getline(cin, remainder);
    cout << "In problem # 2 the sorting problem" << endl << endl;
    Prob2Sorting<char>rc;
    bool ascending = true;
    fstream io;
    char * ch2 = new char[10 * 17];
    char *ch2p = ch2;
    io.open("Problem2.txt", ios::in);
    int index = 0;
    try {
        while (io.get(*ch2)) {//行末尾的空格符吃进后打出来，输出结果会自动换行
            //            if (counter % 17 == 0)
            //                cout << endl;
            cout << *ch2;
            ch2p[index] = *ch2;
            index++;
            ch2++;
            //            counter++;
        }
    } catch (...) {
    }
    //    cout<<ch2p[16]<<" ; "<<ch2p[17]<<endl;
    ch2p[10 * 17 - 2] = ch2p[15];
    ch2p[10 * 17 - 1] = ch2p[16];
    cout << endl;

    io.close();
    cout << endl;
    cout << "Sorting on which column" << endl;
    int column;
    cin>>column;
    char *zc = rc.sortArray(ch2p, 10, 17, column, ascending);

    cout << endl;
    for (int i = 0; i < 10 * 17; i++)
        cout << zc[i];
    delete []zc;
    cout << endl;

}

void problem3() {
    cout << "Entering problem number 3" << endl;
    int rows = 5;
    int cols = 6;
    Prob3TableInherited<int> tab("Problem3.txt", rows, cols);
    const int *naugT = tab.getTable();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << naugT[i * cols + j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    const int *augT = tab.getAugTable();
    for (int i = 0; i <= rows; i++) {
        for (int j = 0; j <= cols; j++) {
            cout << augT[i * (cols + 1) + j] << " ";
        }
        cout << endl;
    }

}

void problem4() {
    cout << "In problem # 4" << endl << endl;
    srand(static_cast<unsigned int>(time(0)));
    SavingsAccount mine(-300);

    for (int i = 1; i <= 10; i++) {
        mine.Transaction((float) (rand() % 500)*(rand() % 3 - 1));
    }
    cout<<"test ~~~~~~~~~~~~~~~toString() function return a string"<<endl;
    cout<<mine.toString();
    cout << "Balance after 7 years given 10% interest = "
            << mine.Total((float) (0.10), 7) << endl;
    cout << "Balance after 7 years given 10% interest = "
            << mine.TotalRecursive((float) (0.10), 7)
            << " Recursive Calculation " << endl;
    cout<<"test~~~~~~~~~~~~~~`binary serialized to file "<<endl;
    fstream fs;
    fs.open("problem4Class.txt",ios::out);
    fs.write(reinterpret_cast<char*>(&mine),sizeof(mine));
    fs.close();
}

void problem5() {
    cout << "In problem # 5" << endl << endl;
    Employee Mark("Mark", "Boss", 215.50);
    Mark.setHoursWorked(-3);
    Mark.toString();
    Mark.CalculatePay(20, 25);

    Mark.toString();
    Mark.CalculatePay(40, 25);
    Mark.toString();
    Mark.CalculatePay(60, 25);
    Mark.toString();

    Employee Mary("Mary", "VP", 50.0);
    Mary.toString();
    Mary.CalculatePay(50.0, 40);
    Mary.toString();
    Mary.CalculatePay(50.0, 50);
    Mary.toString();
    Mary.CalculatePay(50.0, 60);
    Mary.toString();

}

void problem6() {
    cout << "In problem # 6" << endl << endl;
    cout<< "Convert Number"<<endl;
    cout<<"a)3.75"<<endl;
    cout<<setw(12)<<left<<"Binary: "<<"11.11"<<endl;
    cout<<setw(12)<<"Octal: "<<"3.6"<<endl;
    cout<<setw(12)<<"Hex: "<<"3.C"<<endl;
    cout<<setw(12)<<"Float_hex: "<<"78000002"<<endl;
    cout<<setw(12)<<"IEEE 754: "<<"40700000"<<endl<<endl;
    cout<<"b)0.7"<<endl;
    cout<<setw(12)<<left<<"Binary: "<<"0.101100 "<<endl;
    cout<<setw(12)<<"Octal: "<<"0.54"<<endl;
    cout<<setw(12)<<"Hex: "<<"0.B"<<endl;
    cout<<setw(12)<<"Float_hex: "<<"58000000"<<endl;
    cout<<setw(12)<<"IEEE 754: "<<"3F300000"<<endl<<endl;
    cout<<"c)89.9"<<endl;
     cout<<setw(12)<<left<<"Binary: "<<"1011001.1110011 "<<endl;
    cout<<setw(12)<<"Octal: "<<"131.714"<<endl;
    cout<<setw(12)<<"Hex: "<<"59.E6"<<endl;
    cout<<setw(12)<<"Float_hex: "<<"59E60007"<<endl;
    cout<<setw(12)<<"IEEE 754: "<<"42B3CC00"<<endl<<endl;
    
}

void def(int inN) {
    if (inN == -99999)
        cout << "You typed a string to exit the program" << endl;
    else
        cout << "You typed " << inN << " to exit the program" << endl;
}

