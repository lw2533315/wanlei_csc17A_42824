/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on April 4, 2016, 11:47 PM
 */

#include <cstdlib>
#include<iostream>
#include<ctype.h>
#include<iomanip>
#include<sstream>
#include <vector>
#include <valarray>
#include<cstring>
#include <stdlib.h>
#include<set>

using namespace std;

/*
 * 
 */
struct statsResult {
    float avg;
    float median;
    int*mode;
    int nModes;
    int maxFreq;
};

struct Prime {
    unsigned int prime;
    unsigned int power;
};

struct Primes {
    Prime *prime;
    unsigned int nPrimes;
};
void Menu();
int getN();
void def(int);
void problem1();
void problem2(); //transfer money number to english string
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
string transfer(int);
string numToEn(int); //transfer number to "one","two"...
string numToEn2(int); //transfer number to "twenty","thirty"...
statsResult*avgMedMode(int *, int);
float mean(int*, int);
float median(int*, int);
int *mode(int[], int, int&, int&);
void quickSort(int [], int, int);
void displayPro3(statsResult*);
void encypts(string);
void decypts(string);
string toBinary(string);
string toOctal(string);
string toHex(string);
string toFloat(string);
string floatNumber(string);
string intNumber(string);
void problem6Display(string);
void display();
int _toHex(int);
Primes* factor(int);
void printPrm(Primes*);
bool isPrime(int n);
int factor1(int t);



template <class T>
int factor(T t);

bool cmp(const pair<int, int>&a, const pair<int, int>&b) {
    return a.second < b.second;
}


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
            default: def(inN);
        }
    } while (inN >= 1 && inN <= 7);
    return 0; //If midterm not perfect, return something other than 1
}

void Menu() {
    cout << "Menu for the Midterm" << endl;
    cout << "Type 1 for problem 1" << endl;
    cout << "Type 2 for problem 2" << endl;
    cout << "Type 3 for problem 3" << endl;
    cout << "Type 4 for problem 4" << endl;
    cout << "Type 5 for problem 5" << endl;
    cout << "Type 6 for problem 6" << endl;
    cout << "Type 7 for problem 7" << endl;
    cout << "Type anything else to exit \n" << endl;
}

int getN() {
    int inN;
    cin>>inN;
    string reminder;
    getline(cin, reminder);
    return inN;
}

void quickSort(int*a, int l, int r) {
    if (l < r) {
        int i = l, j = r, x = a[l];
        while (i < j) {
            while (i < j && a[j] >= x)
                j--;
            if (i < j)
                a[i++] = a[j];
            while (i < j && a[i] < x)
                i++;
            if (i < j)
                a[j--] = a[i];
        }
        a[i] = x;
        quickSort(a, l, j - 1);
        quickSort(a, i + 1, r);
    }
}

void problem1() {
    cout << "In problem # 1" << endl << endl;

    struct bankAccount {
        string name;
        string address;
        string accountNum;
        double balance;
        double checkOut;
        double checkIn;

        bankAccount(string n = "", string adrs = "", string accN = "",
                double b = 0, double out = 0, double in = 0) : name(n), address(adrs),
        accountNum(accN), balance(b), checkOut(out), checkIn(in) {
        }
    };
    bankAccount * p = new bankAccount();
    cout << "input the name of the account" << endl;
    string temp;
    getline(cin, temp);
    p->name = temp;
    cout << "input the address of the account" << endl;
    getline(cin, temp);
    p->name = temp;

    bool go = true;
    while (go) {
        cout << "input the account number(5 digits)" << endl;
        getline(cin, temp);
        if (temp.length() != 5) {
            cout << "the account should be 5 digits,try again" << endl;
        } else {
            go = false;
            p->accountNum = temp;
        }
    }
    go = true;
    p->checkIn = 0;
    p->checkOut = 0;
    do {
        double check = 0;
        cout << "deposit or withdrawn(d/w)" << endl;
        char c;
        cin>>c;
        if (toupper(c) == 'D') {
            cout << "input the check which you deposit" << endl;
            cin>>check;
            p->checkIn += check;
            p->balance += check;
            cout << "more check(y/n)" << endl;
            char yes;
            cin>>yes;
            if (toupper(yes) == 'N')
                go = false;
        } else if (toupper(c) == 'W') {
            cout << "input the check which you written" << endl;
            cin>>check;
            if (check > p->balance) {
                cout << "your balance is less than " << check << " and you have been charge 15 boxes overdrawn fee" << endl;
                p->balance -= 15;
                cout << "and now you balance is " << p->balance << endl;
            } else {
                p->balance -= check;
                p->checkOut += check;
            }
            cout << "more check(y/n)" << endl;
            char yes;
            cin>>yes;
            if (toupper(yes) == 'N')
                go = false;
        } else go = true;
    } while (go);


    getline(cin, temp);
    cout << "The account information" << endl
            << "Name: " << p->name << endl
            << "Address: " << p->address << endl
            << "Account Number: " << p->accountNum << endl
            << "Balance: " << p->balance << endl
            << "Total of checks written: " << p->checkOut << endl
            << "Total of checks deposits: " << p->checkIn << endl;
    delete p;
}

void problem2() {
    cout << "In problem # 2" << endl << endl;

    struct PayCheck {
        string name;
        string address;
        string company;
        double amountNum;
        string amountEng;
        string signature;
    };
    cout << "how many employee need to pay?" << endl;
    int size;
    cin>>size;
    string temp;
    getline(cin, temp);
    PayCheck* p = new PayCheck[size];
    stringstream ss;
    for (int i = 0; i < size; i++) {
        vector<int>v;
        cout << "input the Company's name" << endl;
        getline(cin, temp);
        p[i].company = temp;
        cout << "input the address" << endl;
        getline(cin, temp);
        p[i].address = temp;
        cout << "input the name" << endl;
        getline(cin, temp);
        p[i].name = temp;
        cout << "input the rate of pay" << endl;
        double rateOfPay;
        cin>>rateOfPay;
        if (rateOfPay < 0) {
            cout << "invalid input" << endl;
            continue;
        }
        cout << "input hours of work" << endl;
        double hours;
        cin>>hours;
        if (hours < 0) {
            cout << "invalid input" << endl;
            continue;
        }
        double realPay = 0;
        if (hours <= 40) {
            realPay = rateOfPay*hours;
        } else if (hours > 40 && hours <= 50) {
            realPay = rateOfPay * 40 + rateOfPay * 2 * (hours - 40);
        } else {
            realPay = rateOfPay * 40 + rateOfPay * 2 * 10 + rateOfPay * 3 * (hours - 50);
        }

        p[i].amountNum = realPay;
        double realPayInt = realPay * 100;



        //        ss.clear();
        //          ss.ignore(1024);
        //        ss.clear();
        string realPayS;
        ss.clear();
        ss << realPayInt;
        ss>>realPayS;
        ss.str("");
        string t;
        ss>>t;

        //        ss.str("");
        //         ss.ignore(1024);

        //        realPayS=realPayS-del;
        //        problem is here<<endl;

        for (int i = realPayS.length() - 1; i >= 0; i--) {
            int value = realPayS[i] - 48;
            v.push_back(value);
        }
        int value = v[1]*10 + v[0];
        if (transfer(value) != "")
            temp = " dollars and " + transfer(value);
        else
            temp = " dollars " + transfer(value);
        int index = 1;
        if ((v.size() - 2) % 3 == 1) {
            v.push_back(0);
            v.push_back(0);
        }
        if ((v.size() - 2) % 3 == 2) {
            v.push_back(0);
        }

        if (v.size() > 2) {
            int value = v[index + 3]*100 + v[index + 2]*10 + v[index + 1];
            string t = transfer(v[index + 3]*100 + v[index + 2]*10 + v[index + 1]);
            temp = t + temp;
            index += 3;
        }

        if (v.size() > 5) {
            string t = transfer(v[index + 3]*100 + v[index + 2]*10 + v[index + 1]);
            temp = t + " thousands " + temp;
            index += 3;
        }
        if (v.size() > 8) {
            string t = transfer(v[index + 3]*100 + v[index + 2]*10 + v[index + 1]);
            temp = t + " millions " + temp;
            index += 3;
        }
        p[i].amountEng = temp;
        getline(cin, temp);
    }
    for (int i = 0; i < size; i++) {
        cout << "Company: " << p[i].company << endl
                << "Address: " << p[i].address << endl
                << "Name: " << p[i].name << endl
                << "Amount: " << p[i].amountNum << endl
                << "Amount: " << p[i].amountEng << endl;

    }
    delete []p;
}

string transfer(int n) {
    string temp = "";
    string back = temp;
    int hundred = 0;
    hundred = n / 100;
    if (hundred > 0) {
        temp = numToEn(hundred);
        back = temp + " hundred " + back;
    }
    int decimal = 0;

    decimal = (n - hundred * 100) / 10;
    if (decimal > 1) {
        temp = numToEn2(decimal);
        back = back + temp;
    } else if (decimal == 0) {
    } else if (decimal == 1) {
        if (n - hundred == 10)
            return back = back + " ten ";
        if (n - hundred == 11)
            return back = back + " eleven ";
        if (n - hundred == 12)
            return back = back + " twelve ";
        if (n - hundred == 13)
            return back = back + " thirteen ";
        if (n - hundred == 14)
            return back = back + " fourteen ";
        if (n - hundred == 15)
            return back = back + " fifteen ";
        if (n - hundred == 16)
            return back = back + " sixteen ";
        if (n - hundred == 17)
            return back = back + " seventeen ";
        if (n - hundred == 18)
            return back = back + " eighteen ";
        if (n - hundred == 19)
            return back = back + " nineteen ";
    }


    int digit;
    digit = (n - hundred * 100) % 10;
    back = back + numToEn(digit);
    return back;

}

string numToEn2(int n) {
    if (n == 2)
        return "twenty ";
    if (n == 3)
        return "thirty ";
    if (n == 4)
        return "forty ";
    if (n == 5)
        return "fifty ";
    if (n == 6)
        return "sixty ";
    if (n == 7)
        return "seventy ";
    if (n == 8)
        return "eighty ";
    if (n == 9)
        return "ninty ";
}

string numToEn(int n) {
    if (n == 0)
        return "";
    if (n == 1)
        return "one ";
    if (n == 2)
        return "two ";
    if (n == 3)
        return "three ";
    if (n == 4)
        return "four ";
    if (n == 5)
        return "five ";
    if (n == 6)
        return "six ";
    if (n == 7)
        return "seven ";
    if (n == 8)
        return "eight ";
    if (n == 9)
        return "nine";
}

void problem3() {
    cout << "In problem # 3" << endl << endl;
    cout << "the array size" << endl;
    int size;
    cin>>size;
    int * p = new int[size];
    cout << "input the array (eg:1 2 3 4 ...)" << endl;
    for (int i = 0; i < size; i++) {

        cin >> p[i];
    }
    statsResult *pl = avgMedMode(p, size);
    displayPro3(pl);
    string temp;
    getline(cin, temp);
    delete [] p;
    delete pl;
    cout << endl << endl;
}

void displayPro3(statsResult *p) {
    cout << "average: " << p->avg << endl;
    cout << "median: " << p->median << endl;
    cout << "mode array: ";
    for (int i = 0; i < p->nModes; i++)
        cout << p->mode[i] << " ";
    cout << endl;
    cout << "numbers of mode: " << p->nModes << endl
            << "frequency of mode: " << p->maxFreq << endl;
}

float mean(int *a, int size) {
    float feeback = 0;
    for (int i = 0; i < size; i++)
        feeback += a[i];

    return feeback / size;
}

float median(int *a, int size) {
    quickSort(a, 0, size - 1);
    float temp = 0;
    if (size % 2 == 0) {
        temp = (*(a + (size - 1) / 2)+*(a + (size - 1) / 2 + 1)) / (float) 2;
        return temp;
    } else {
        return a[size / 2 ];
    }
}

int *mode(int *a, int size, int& n, int&f) {
    vector<pair<int, int> >v;
    quickSort(a, 0, size - 1);
    int comValue = a[0];
    int count = 1;
    bool noMode = true; //判断有无重复元素
    for (int i = 1; i < size; i++) {
        if (a[i] == comValue) {
            count++;
            noMode = false;
        } else {
            v.push_back(make_pair(comValue, count));
            count = 1;
            comValue = a[i];
        }
    }
    v.push_back(make_pair(comValue, count)); //无法比较的当前数据也要存进去
    //    for (int i = 0; i < v.size(); i++)
    //        cout << v[i].first << " ; " << v[i].second;
    cout << endl;
    sort(v.begin(), v.end(), cmp);
    int frequency = v[v.size() - 1].second;
    count = 1;
    int *temp;
    for (int i = v.size() - 2; i >= 0; i--) {
        if (frequency != v[i].second) {

            n = count;
            f = frequency;
            int index = 0;
            while (count > 0) {
                temp[index] = v[v.size() - count].first;
                count--;
                index++;
            }
            return temp;
        } else {
            count++;
        }
    }
    /*all the frequency are same*/
    temp = new int[count];
    int index = 0;
    while (count > 0) {
        temp[ index] = v[v.size() - count].first;
        count--;
        index++;
    }
    if (noMode) {//当序列中没有重复元素。
        n = size;
        f = 1;
        return a;
    }
    return temp;
}

statsResult* avgMedMode(int *a, int size) {
    statsResult *p = new statsResult();

    p->avg = mean(a, size);

    p->median = median(a, size);
    cout << endl;
    p->mode = mode(a, size, p->nModes, p->maxFreq);

    return p;
}

void problem4() {
    cout << "In problem # 4" << endl << endl;
    string reminder;
    string code;
    bool go;
    do {
        go = false;
        cout << "input the code,four digits(0-7, eg: 1234)" << endl;
        getline(cin, code);
        if (code.length() != 4)
            go = true;
        for (int i = 0; i < code.length(); i++) {
            if (code[i] < 48 || code[i] > 55)
                go = true;
        }
    } while (go);
    do {
        cout << "do you wanna encypts or decypts,please input e/d" << endl;
        char c;
        cin>>c;
        getline(cin, reminder);
        if (toupper(c) == 'E')
            encypts(code);
        else if (toupper(c) == 'D')
            decypts(code);
        else go = true;
    } while (go);
}

void encypts(string s) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = (s[i] - 48 + 5) % 8 + 48;
    }
    swap(s[0], s[1]);
    swap(s[2], s[3]);
    for (int i = 0; i < s.length(); i++) {
        cout << s[i];
    }
    cout << endl;

}

void decypts(string s) {
    swap(s[0], s[1]);
    swap(s[2], s[3]);
    for (int i = 0; i < s.length(); i++) {
        if ((s[i] - 48) >= 5)
            s[i] = s[i] - 5;
        else
            s[i] = s[i] + 8 - 5;
        cout << s[i];
    }
    cout << endl;

}

void problem5() {
    
    char c = 1;
    cout << "char variable can save " << factor(c) << "'s factorial" << endl;
    short s = 1;
    cout << "short variable can save " << factor(s) << "'s factorial" << endl;


    float f = 1;
    cout << "float variable can save " << factor(f) << "'s factorial" << endl;
    double d = 1;
    cout << "double variable can save " << factor(d) << "'s factorial" << endl;
    unsigned int ui = 1;
    cout << "unsigned int variable can save " << factor(ui) << "'s factorial" << endl;
    int i = 1;
//    cout << factor1(i) << endl;
         cout << "int variable can save " << factor1(i) << "'s factorial" << endl;
    cout << endl << endl;
}

template<class T>
int factor(T t) {

    //    cout<<"test point 1 "<<endl;
    T temp = t;
    for (T i = 2;; i++) {
        t = i*t;
        //        cout<<"t is "<<t<<" ; i is "<<i<<endl;
        if (t / temp != i) {
            return i - 1;
        }
        temp = t;
    }
}

int factor1(int t) {

    //    cout<<"test point 1 "<<endl;
    int temp = t;
    for (int i = 2;; i++) {
        t = i*t;
        //        cout<<"t is "<<t<<" ; i is "<<i<<endl;
        if (t / temp != i) {
            return i - 1;
        }
        temp = t;
    }
}

int _toHex(int n) {
    if (n < 10)
        return 48 + n;
    else if (n == 10)
        return 65;
    else if (n == 11)
        return 66;
    else if (n == 12)
        return 67;
    else if (n == 13)
        return 68;
    else if (n == 14)
        return 69;
    else
        return 70;

}

void problem6() {
    cout << "In problem # 6" << endl;
    cout << "I wrote code to realize part a." << endl;
    string a = "2.125", b = "0.1328125";


    problem6Display(a);
    cout << "convert the number; " << b << endl;
    problem6Display(b);
    cout << endl;
    display();


}

void display() {
    string c = "-2.125", d = "-0.1328125";
    cout << "convert the number: " << c << endl;
    cout << "binary:  -10.001" << endl;
    cout << "octal:  -2.1" << endl;
    cout << "Hex: -2.2" << endl;
    cout << "float_hex: BC000002 " << endl;
    cout << endl;
    cout << "convert the number: " << d << endl;
    cout << "binary:  -0.0010001" << endl;
    cout << "octal:  -0.104" << endl;
    cout << "Hex: -0.22 " << endl;
    cout << "float_hex: BC0000FE " << endl << endl;

    cout << "466666601 ->decimal" << endl;
    cout << "to float binary: " << endl;
    cout << "0100 0110 0110 0110 0110 0110 0000 0001" << endl;
    cout << "shift" << endl;
    cout << " 1.0001 1001 1001 1001 1001 1000" << endl;
    cout << "1.199998 hex" << endl;
    cout << "1.0999999904(decimal)" << endl << endl;
    cout << "46666602 ->decimal" << endl;
    cout << "to float binary:" << endl;
    cout << "0100 0110 0110 0110 0110 0110 0000 0010" << endl;
    cout << "shift" << endl;
    cout << "10.0011 0011 0011 0011 0011" << endl;
    cout << "2.33333 hex" << endl;
    cout << "2.199999809(decimal)" << endl << endl;
    cout << "B9999AFE ->decimal" << endl;
    cout << "to float binary: " << endl;
    cout << "1011 1001 1001 1001 1001 1010 1111 1110 " << endl;
    cout << "shift 1111 1110->0000 0010   -2" << endl;
    cout << "1011 1001 1001 1001 1001 1010 -1" << endl;
    cout << "1011 1001 1001 1001 1001 1001" << endl;
    cout << "0100 0110 0110 0110 0110 0110" << endl;
    cout << "shift" << endl;
    cout << "0.0010 0011 0011 0011 0011 0011" << endl;
    cout << "0.233333hex" << endl;
    cout << "-0.137499988(decimal)" << endl;

}

void problem6Display(string s) {


    string biNum = toBinary(s);
    cout << "binary: " << biNum << endl;
    string OctNum = toOctal(biNum);
    cout << "octal:  " << OctNum << endl;
    string hexNum = toHex(biNum);
    cout << "Hex: " << hexNum << endl;
    string floatNum = toFloat(biNum);
    cout << "float_hex: " << floatNum << endl;




}

string toOctal(string s) {
    string ret = "";
    int index = s.find(".");
    int lenFirst = index; //before the point
    int lenSecond = s.length() - lenFirst - 1; //the length of after the point
    string first = s.substr(0, lenFirst);
    string second = s.substr(index + 1, lenSecond);
    while (lenFirst % 3 != 0) {
        first = "0" + first;
        lenFirst++;
    }
    while (lenSecond % 3 != 0) {
        second = second + "0";
        lenSecond++;
    }
    //    cout<<"test point1 first "<<first<<" second: "<<second<<endl;
    vector<char>v;
    index = 0;
    int indexRet = 0;
    while (index < lenFirst) {
        ret = ret + " ";
        int temp = 0;
        temp = (first[index] - 48)*2 * 2;
        index++;
        temp = temp + (first[index] - 48)*2;
        index++;
        temp = temp + (first[index] - 48);
        index++;
        ret[indexRet] = temp + 48;
        indexRet++;
    }
    //    cout<<"haalf process ret: "<<ret<<endl;
    ret = ret + " ";
    ret[indexRet] = '.';
    //      cout<<"haalf process ret: "<<ret<<endl;
    index = 0;
    indexRet++;
    while (index < lenSecond) {
        ret = ret + " ";
        int temp = 0;
        temp = (second[index] - 48)*2 * 2;
        index++;
        temp = temp + (second[index] - 48)*2;
        index++;
        temp = temp + (second[index] - 48);
        index++;
        ret[indexRet] = temp + 48;
        indexRet++;
    }



    return ret;
}

string toHex(string s) {
    string ret = "";
    int index = s.find(".");
    //    cout<<"s's length is "<<s.length()<<endl;
    int lenFirst = index; //before the point
    int lenSecond = s.length() - lenFirst - 1; //the length of after the point
    string first = s.substr(0, lenFirst);
    string second = s.substr(index + 1, lenSecond);
    //    cout<<"len: "<<lenFirst<<" ; "<<lenSecond<<endl;
    //    cout<<"stirng "<<first<<" ; "<<second<<endl;
    while (lenFirst % 4 != 0) {
        first = "0" + first;
        lenFirst++;
    }
    while (lenSecond % 4 != 0) {
        second = second + "0";
        lenSecond++;
    }
    //    cout<<"test point1 first "<<first<<" second: "<<second<<endl;
    index = 0;
    int indexRet = 0;
    while (index < lenFirst) {
        ret = ret + " ";
        int temp = 0;
        temp = (first[index] - 48)*2 * 2 * 2;
        index++;
        temp = temp + (first[index] - 48)*2 * 2;
        index++;
        temp = temp + (first[index] - 48)*2;
        index++;
        temp = temp + (first[index] - 48);
        index++;
        ret[indexRet] = _toHex(temp);
        indexRet++;
    }
    //    cout<<"haalf process ret: "<<ret<<endl;
    ret = ret + " ";
    ret[indexRet] = '.';
    //      cout<<"haalf process ret: "<<ret<<endl;
    index = 0;
    indexRet++;
    while (index < lenSecond) {
        ret = ret + " ";
        int temp = 0;
        temp = (second[index] - 48)*2 * 2 * 2;
        index++;
        temp = temp + (second[index] - 48)*2 * 2;
        index++;
        temp = temp + (second[index] - 48)*2;
        index++;
        temp = temp + (second[index] - 48);
        index++;
        ret[indexRet] = _toHex(temp);
        indexRet++;
    }


    return ret;
}

string toFloat(string s) {

    string ret = "";
    char c[32] = {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
        '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'};
    int pointPos = s.find(".");
    if (pointPos == -1) {
        for (int i = 0; i < s.length(); i++) {
            c[1 + i] = s[i];
        }
        string tempS;
        stringstream ss;
        ss << s.length();
        ss>>tempS;
        ss.str("");
        ss.clear();
        string bit = toBinary(tempS);
        for (int i = 0; i < bit.length(); i++) {
            c[32 - bit.length() + i] = bit[i];
        }
        int index = 0;
        int indexRet = 0;
        while (index < 32) {
            ret = ret + " ";
            int temp = 0;
            temp = (c[index] - 48)*2 * 2 * 2;
            index++;
            temp = temp + (c[index] - 48)*2 * 2;
            index++;
            temp = temp + (c[index] - 48)*2;
            index++;
            temp = temp + (c[index] - 48);
            index++;
            ret[indexRet] = _toHex(temp);
            indexRet++;
        }
        return ret;
    }
    bool go = false;
    for (int i = 0; i < pointPos; i++) {
        if (s[i] != '0')
            go = true;
    }

    if (go) {
        string first = s.substr(0, pointPos);
        string second = s.substr(pointPos + 1, s.length() - pointPos - 1);
        first = first + second;
        //        cout << "test 4 fist.length : " << first.length() << endl;
        for (int i = 0; i < first.length(); i++) {
            c[1 + i] = first[i];
        }
        //        for (int i = 0; i < 32; i++) {
        //            cout << c[i];
        //        }
        //        cout << "test4 up" << endl;
        string tempS;
        stringstream ss;
        ss << pointPos;
        ss>>tempS;
        ss.str("");
        ss.clear();
        string bit = toBinary(tempS);

        for (int i = 0; i < bit.length(); i++) {
            c[32 - bit.length() + i] = bit[i];
        }

        int index = 0;
        int indexRet = 0;
        while (index < 32) {
            ret = ret + " ";
            int temp = 0;
            temp = (c[index] - 48)*2 * 2 * 2;
            index++;
            temp = temp + (c[index] - 48)*2 * 2;
            index++;
            temp = temp + (c[index] - 48)*2;
            index++;
            temp = temp + (c[index] - 48);
            index++;
            ret[indexRet] = _toHex(temp);
            indexRet++;
        }
        return ret;
    }
    //    go = false;

    if (s[pointPos + 1] != '0') {
        for (int i = 0; i < s.length() - 2; i++) {
            c[1 + i] = s[i + 2];
        }
        int index = 0;
        int indexRet = 0;
        while (index < 32) {
            ret = ret + " ";
            int temp = 0;
            temp = (c[index] - 48)*2 * 2 * 2;
            index++;
            temp = temp + (c[index] - 48)*2 * 2;
            index++;
            temp = temp + (c[index] - 48)*2;
            index++;
            temp = temp + (c[index] - 48);
            index++;
            ret[indexRet] = _toHex(temp);
            indexRet++;
        }
        return ret;
    } else {
        int pos = pointPos;
        int counter = 0;
        while (s[pos + 1] == '0') {
            counter++;
            pos++;
        }
        for (int i = 0; i < s.length() - counter - 2; i++) {
            c[1 + i] = s[i + counter + 2];
        }
        string tempS;
        stringstream ss;
        ss << counter;
        ss>>tempS;
        ss.str("");
        ss.clear();
        string bit = toBinary(tempS);
        for (int i = 0; i < bit.length(); i++) {
            c[32 - bit.length() + i] = bit[i];

        }

        for (int i = 24; i < 32; i++) {
            if (c[i] == '1') {
                c[i] = '0';
            } else {
                c[i] = '1';
            }
        }

        int carry = 1;
        for (int i = 31; i >= 24; i--) {
            if (c[i] == '1' && carry == 1) {
                c[i] = '0';
                carry = 1;

            } else if (c[i] == '0' && carry == 1) {
                c[i] = '1';
                carry = 0;
            }
        }
        //        for (int i = 0; i < 32; i++) {
        //            cout << c[i];
        //        }
        int index = 0;
        int indexRet = 0;
        while (index < 32) {
            ret = ret + " ";
            int temp = 0;
            temp = (c[index] - 48)*2 * 2 * 2;
            index++;
            temp = temp + (c[index] - 48)*2 * 2;
            index++;
            temp = temp + (c[index] - 48)*2;
            index++;
            temp = temp + (c[index] - 48);
            index++;
            ret[indexRet] = _toHex(temp);
            //            cout<<"ret is "<<ret<<endl;
            indexRet++;
        }
        return ret;
    }
}

string toBinary(string s) {
    if (s.find('.') != -1) {
        return floatNumber(s); //float
    } else {
        return intNumber(s); //int;
    }

}

string floatNumber(string s) {

    int index = s.find('.');
    string intPart = "0", floatPart = "0";
    intPart = intNumber(s.substr(0, index));
    floatPart = s.substr(index + 1, s.length() - index - 1);
    //    cout<<"test point 3 s is "<<floatPart<<endl;
    vector<char>v;
    int len = floatPart.length();
    stringstream ss;
    ss << floatPart;
    int num;
    int scare = pow(10, len); //判断是否有进位；
    ss>>num;
    ss.str("");
    ss.clear();
    int loop = 8;
    while (num != 0 && loop != 0) {
        //        cout<<"test point 2"<<endl;
        num = num * 2;
        //        cout<<"num is "<<num<<endl;
        if (num / scare > 0) {
            v.push_back('1');
            num -= scare;

        } else {
            v.push_back('0');
        }
        loop--;
    }
    string temp = "";

    for (int i = 0; i < v.size(); i++) {
        temp = temp + " ";
        temp[i] = v[i];
        //        cout<<temp.length()<<endl;

    }
    //    cout<<"intPart is "<<intPart<<endl;
    //    cout<<"temp is "<<temp<<endl;
    string feeback = intPart + "." + temp;
    //    cout<<feeback<<endl;
    return feeback;
}

string intNumber(string s) {
    string feeback;
    vector<int>v;
    int mode, quotient;
    stringstream ss;
    int num;
    ss << s;
    ss>>num;
    ss.str("");
    quotient = num;
    while (quotient != 0) {
        mode = quotient % 2;
        //        cout<<"mode is "<<mode<<" ";
        v.push_back(mode);

        quotient = quotient / 2;
    }
    //    cout << endl;
    int time = 0;
    num = 0;
    for (int i = 0; i < v.size(); i++) {
        num += pow(10, i) * v[i];
    }

    ss.clear();
    ss << num;
    ss>>feeback;
    return feeback;

}

void problem7() {

    cout << "type a number >100" << endl;
    int n;
    cin>>n;
    string reminder;
    getline(cin, reminder);
    Primes *p = new Primes();
    p = factor(n);
    cout << "n = ";
    printPrm(p);


}

bool isPrime(int n) {

    if (n <= 3) {
        return n > 1;
    } else if (n % 2 == 0 || n % 3 == 0) {
        return false;
    } else {
        for (unsigned short i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
}

Primes* factor(int n) {
    //        cout<<"test 1 n is "<<n<<endl;
    Primes *p = new Primes();
    set<int>s;
    int quotient = n;
    int counter = 1;
    vector<int>v;
    for (int i = 2; i <= 10000 && quotient != 1;) {
        //        cout<<"test2 quotient "<<quotient<<endl;
        if (isPrime(i) && quotient % i == 0) {
            //            cout<<"test 3 quotient is "<<quotient<<endl;
            quotient = quotient / i;
            if (s.insert(i).second) {
                //                cout<<"push in the vector counter is "<<counter<<endl;
                v.push_back(counter); //the first element is unusefull,
                //第二次能放进set时才是第一放进去的element的最大power
                counter = 1;
            } else {
                counter++;
                //                cout<<"in the else counter is "<<counter<<endl;
                //                v.push_back(counter);

            }
        } else {
            i++;
        }
    }
    v.push_back(counter);

    int size = s.size();
    Prime *pAry = new Prime[size];
    set<int>::iterator itr = s.begin();
    for (int i = 0; i < size; i++) {
        //       cout<<"test 4 power is "<<v[i+1]<<" ; "<<"producet is "<<*itr<<endl;
        pAry[i].prime = *(itr++);
        pAry[i].power = v[i + 1]; //the first element in vector is unusefull
    }

    p->prime = pAry;
    p->nPrimes = size;
    return p;

}

void printPrm(Primes* p) {
    int size = p->nPrimes;
    string print = "";
    stringstream ss;
    for (int i = 0; i < size; i++) {
        string temp1;
        string temp2;
        ss << p->prime[i].prime;
        ss>>temp1;
        ss.str("");
        ss.clear();
        ss << p->prime[i].power;
        ss>>temp2;
        ss.str("");
        ss.clear();
        print = print + temp1 + "^" + temp2 + "*";
    }
    print = print.substr(0, print.length() - 1);
    cout << print << endl;
    cout << endl;
}

void def(int inN) {
    cout << "You typed " << inN << " to exit the program" << endl;
}

