/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prob2Sorting.h
 * Author: Administrator
 *
 * Created on June 2, 2016, 8:33 PM
 */

#ifndef PROB2SORTING_H
#define PROB2SORTING_H
#include<iostream>
using namespace std;

template<class T>
class Prob2Sorting {
private:
    T * sort;
public:

    Prob2Sorting() {
        sort = NULL;
    };

    ~Prob2Sorting() {
        delete []sort;
    };
    T * sortArray(const T*, int, bool); //Sorts a single column array
    T * sortArray(const T*, int, int, int, bool); //Sorts a 2 dimensional array represented as a 1 dim array

};

template <class T>
T *Prob2Sorting<T>::sortArray(const T* ary, int col, bool up) {
    T *a = new T[col];
    for (int i = 0; i < col; i++) {
        a[i] = ary[i];
    }
    for (int i = 0; i < col; i++) {
        for (int j = i + 1; j < col; j++) {
            if (up && a[i] > a[j]) {
                swap(a[i], a[j]);
            }
            if (!up && a[i] < a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
    return a;
}

template <class T>
T* Prob2Sorting<T>::sortArray(const T * ary, int row, int col, int column, bool up) {
    int size = row*col;
    T *a = new T[size];
    for (int i = 0; i < size; i++) {
        a[i] = ary[i];
        cout << a[i];
    }
    for (int i = column - 1; i < size; i += col) {//找到要比较的那column的char
        //        for (int j = i + col; j < size; j += col) {
        for (int j = column - 1; j < size - col; j += col) {
            if (up && a[j] > a[j+col]) {
//                int r = i / col;
                //                cout<<"row number is "<<r<<endl;
                //                cout<<"i is "<<i<<"a[i]"<<a[i]<<endl;
                //                cout<<"j is "<<j<<"a[j]"<<a[j]<<endl;
                for (int k = 0; k < col; k++) {//整行对调，
                    //                    char temp=a[r * col + k];
                    //                    a[r * col + k]=a[(r + 1) * col + k];
                    //                    a[(r + 1) * col + k]=temp;
//                    int first = r*col, second = (r + 1) * col;
//                    cout << "firsst is " << first << " ; " << "seconde is " << second << endl;
                    swap(a[j-column+1 + k], a[j+col-column+1 + k]);
                }
                //                for (int k = 0; k < col; k++) {
                //                    swap(a[i - k], a[j - k]);
                //                }
            }
            if (!up && a[i] < a[j]) {
                int r = i / col;
                for (int k = 0; k < col; k++) {
                    swap(a[r * col + k], a[(r + 1) * col + k]);
                }
            }
        }
    }
    return a;
}




#endif /* PROB2SORTING_H */

