/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on March 29, 2016, 6:09 PM
 */

#include <cstdlib>
#include <string>
#include<cstring>
#include<iostream>
#include <vector>
#include<ctype.h>
#include<fstream>

using namespace std;
void problem10_4();
void problem10_8();
void problem10_6();
void problem12_7();
void problem12_8();
void problem12_11();
void sumOfString(string);
void greatAndSmall(string);
void numberWords(char*);
void vowel(string);
void conso(string);
int numOfVowel(string);
int numOfConso(string);
void letters(string);
string newString();
void arrayToFile(char*, int*, int);
void fileToArray(char*, int*, int);

/*
 * 
 */
int main(int argc, char** argv) {
    while (true) {
        bool go;
        int option = 100;
        do {
            go = false;
            cout << endl ;
             cout << "Assignment3" << endl;
            cout << "choice problem,1-6,and 9 exit" << endl;
           
            cout << "-----------------------------------------" << endl;
            cout << "1.problem 10.4" << endl;
            cout << "2.problem 10.8" << endl;
            cout << "3.problem 10.6" << endl;
            cout << "4.problem 12.7" << endl;
            cout << "5.problem 12.8" << endl;
            cout << "6.problem 12.11" << endl;
            cout << "9.exit" << endl;
            string input = "";
            getline(cin, input);
            option = (int) input[0] - 48;
            //            cout << "option is " << option << endl;
            if (option > 9 || option < 1)
                go = true;
        } while (go);

        switch (option) {
            case 1: problem10_4();
                break;
            case 2: problem10_8();
                break;
            case 3:problem10_6();
                break;
            case 4:problem12_7();
                break;
            case 5:problem12_8();
                break;
            case 6:problem12_11();
                break;
                //
                //            case 7:binarySearch();
                //                break;
                //            case 8:trueOrFalseDisplay();
                //                break;
            case 9: exit(0);
            default: break;
        }
    }
    return 0;

}

void problem12_11() {

    struct Sale {
        string name;
        unsigned int quarter;
        unsigned int salse;
    };
    Sale company;

    bool go = true;
    while (go) {
        cout << "which quarter 1-4" << endl;
        string season;
        getline(cin, season);
        if (season.size() == 1 && season[0] >= 49 && season[0] <= 52) {
            go = false;
            company.quarter = season[0] - 48;
        } else {
            cout << "wrong input" << endl;
        }
    }

    go = true;
    while (go) {
        cout << "input the division name of company (East,West,South,North) " << endl;
        string division;
        getline(cin, division);
        for (int i = 0; i < division.length(); i++)
            division[i] = tolower(division[i]);
        if (division == "east" || division == "south" || division == "north" || division == "west") {
            company.name = division;
            go = false;
        } else {
            cout << "wrong input" << endl;
        }
    }
    go = true;
    string sales;
    while (go) {
        cout << "input the quantities of sales" << endl;
        getline(cin, sales);
        go = false;
        for (int i = 0; i < sales.length(); i++) {
            if (sales[i] <= 48 || sales[i] >= 57) {
                go = true;
                cout << "wrong input" << endl;
                break;
            }
        }
    }
    int num = 0;
    int cof = 1;
    for (int i = sales.size() - 1; i >= 0; i--) {
        num += (sales[i] - 48) * cof;
        cof *= 10;
    }

    fstream fs;
    fs.open("input12_11.dat", ios::out | ios::binary);
    fs.write(reinterpret_cast<char*> (&company), sizeof (company));
    fs.close();


}

void problem12_8() {
    const int SIZE = 10;
    int numbers[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int number[SIZE];
    arrayToFile("input12_8.dat", numbers, SIZE);
    fileToArray("input12_8.dat", number, SIZE);
}

void arrayToFile(char*name, int*a, int len) {
    fstream fs;
    fs.open(name, ios::out | ios::binary);
    fs.write(reinterpret_cast<char*> (a), sizeof (a) * len / 2);
    fs.close();
}

void fileToArray(char* name, int b[], int len) {
    fstream fs;
    fs.open(name, ios::in | ios::binary);
    fs.read(reinterpret_cast<char*> (b), sizeof (b) * len / 2);
    fs.close();
    for (int i = 0; i < len; i++)
        cout << b[i] << " ";
    cout << endl;
}

void problem10_6() {

    cout << "A) Count the number of vowels in the string" << endl;
    cout << "B) Count the number of Consonants in the string" << endl;
    cout << "C) Count both the " << endl;
    cout << "D) enter another string" << endl;
    cout << "E) Exit the program" << endl;
    bool goOn = true;
    cout << "input a string" << endl;
    string s;
    getline(cin, s);
    while (goOn) {
        string input;
        cout << "please enter your choice" << endl;
        getline(cin, input);

        for (int i = 0; i < input.length(); i++) {
            input[i] = toupper(input[i]);
        }
        if (input[0] >= 'A' && input[0] <= 'E') {
            switch (input[0]) {
                case 'A': vowel(s);
                    break;
                case 'B':conso(s);
                    break;
                case'C':letters(s);
                    break;
                case 'D':s = newString();
                    break;
                case 'E': goOn = false;
                    break;
            }
        }

    }
}

void problem12_7() {
    ifstream ifs;
    ifs.open("input.txt");
    string temp;
    fstream ofs;
    ofs.open("output.txt", ios::out | ios::app);
    if (ifs) {
        while (getline(ifs, temp)) {
            /*all letter converse to lower case letter*/
            for (unsigned i = 0; i < temp.size(); i++) {
                temp[i] = tolower(temp[i]);
            }
            temp[0] = toupper(temp[0]); //each line's first letter should be capital
            int index = 0;
            bool space = true; //determine is it the last period.
            while (temp.find('.', index) != -1 && space) {
                int pos = temp.find('.', index) + 1; //find the index of the upcoming space after period.
                ofs << temp.substr(index, pos - index);
                ofs << " ";
                bool go = true;
                while (go) {
                    if (pos == temp.length()) {//if the index is after the last period 
                        space = false;
                        go = false;
                    } else {
                        if (temp[pos] != toupper(temp[pos])) {//after converting, the letter changed 
                            temp[pos] = toupper(temp[pos]); //make the change
                            go = false;
                            index = pos; // the pos is the new sentence's first capital
                        } else
                            pos++; //if no changed,after period, the pos should be space, or any noletters.
                    }
                }
            }
        }
    } else
        cout << "wrong file name" << endl;
    ifs.close();
    ofs.close();
}

void vowel(string s) {
    cout << "the number of vowel is " << numOfVowel(s) << endl;
}

void conso(string s) {
    cout << "the number of consonant if " << numOfConso(s) << endl;
}

string newString() {
    cout << "input a new string" << endl;
    string temp;
    getline(cin, temp)
            ;
    return temp;
}

void letters(string s) {
    cout << "the total letters in the string is " << numOfVowel(s) + numOfConso(s) << endl;
}

int numOfVowel(string s) {
    int counter = 0;
    for (int i = 0; i < s.length(); i++) {
        s[i] = toupper(s[i]);
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            counter++;
    }
    return counter;
}

int numOfConso(string s) {
    int counter = 0;
    for (int i = 0; i < s.length(); i++) {
        s[i] = toupper(s[i]);
        if (s[i] >= 'A' && s[i] <= 'Z') {
            if (s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U')
                counter++;
        }
    }

    return counter;
}

void problem10_8() {
    cout << "enter a string of single digits,all the digits do not be separate" << endl;
    string s;
    getline(cin, s);
    sumOfString(s);
    greatAndSmall(s);
}

void sumOfString(string s) {
    cout << "s is " << s << endl;
    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        sum += (s[i] - 48);
    }
    cout << "the sum is " << sum << endl;
}

void greatAndSmall(string s) {
    int biggest = s[0] - 48, smallest = s[0] - 48;
    for (unsigned i = 0; i < s.length(); i++) {
        if (biggest < (s[i] - 48))
            biggest = s[i] - 48;
        if (smallest > (s[i] - 48))
            smallest = s[i] - 48;

    }
    cout << "the greatest number in the string is " << biggest << endl;
    cout << "the smallest number in the string is " << smallest << endl;
}

void problem10_4() {
    cout << "input a string" << endl;
    string s;
    getline(cin, s);
    int len = s.length();
    char *c = new char[len];
    strcpy(c, s.c_str());
    numberWords(c);
}

void numberWords(char* c) {
    vector<int>v;
    int len = strlen(c);
    int temp = 0; //recorder the index;
    int counter = 1;
    for (int i = 0; i < len; i++) {
        if (c[i] == ' ') {
            counter++;
            v.push_back(i - temp); //push the lenth of each words,利用index差求长度
            temp = i + 1;
            while(c[i+1]==' '){//跳过连续的空格
                i++;
                temp++;
            }
        }
    }
    v.push_back(len - temp);

    int counter1 = 0;
    for (int i = 0; i < v.size(); i++) {
        counter1 += v[i];
    }
    cout << endl;
    //    if (v.size() == 0) {//只有一个word在这个字符串的情况
    //       
    //        cout << counter << " words, and the average letters is " << len << endl;
    //    } else{
    cout << counter << " words, and the average letters is " << counter1 / (double) v.size() << endl;
    //    }
}