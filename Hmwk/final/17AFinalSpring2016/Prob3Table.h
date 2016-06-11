/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prob3Table.h
 * Author: Administrator
 *
 * Created on June 9, 2016, 8:01 PM
 */

#ifndef PROB3TABLE_H
#define PROB3TABLE_H
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

template<class T>
class Prob3Table {
protected:
    int rows;
    int cols;
    T*rowSum;
    T*colSum;
    T*table;
    T grandTotal;
    void calcTable(void);
public:
    Prob3Table(char*, int, int);

    ~Prob3Table() {
        delete[] table;
        delete[]rowSum;
        delete[]colSum;
    }

    const T* getTable(void) {
        return table;
    };

    const T *getRowSum(void) {
        return rowSum;
    };

    const T *getColSum(void) {
        return colSum;
    };
};

template<class T>
Prob3Table<T>::Prob3Table(char* s, int row, int col) {
    fstream file(s, ios::in);
    table = new T[row * col];
    grandTotal=0;
    try {
        int in;
        int index = 0;
        while (file >> in) {
            table[index] = in;
            index++;
        }
    } catch (...) {
    }
    rows = row;
    cols = col;
    file.close();
    rowSum = new T[row];
    colSum = new T[col];
    T sum;
    for (int i = 0; i < row; i++) {
        sum = 0;
        for (int j = 0; j < col; j++) {

            sum += table[i * col + j];
        }
        rowSum[i] = sum;
    }
    for (int i = 0; i < col; i++) {
        sum = 0;
        int counter = i;
        while (counter < row * col) {
            sum += table[counter];
            counter += col;
        }
        colSum[i] = sum;
    }
    calcTable();
}

template<class T>
void Prob3Table<T>::calcTable() {
    for (int i = 0; i < rows; i++) {
        grandTotal += rowSum[i];
    }
}

template<class T>
class Prob3TableInherited : public Prob3Table<T> {
protected:
    T* augTable;
public:
    Prob3TableInherited(char*, int, int); //Constructor

    ~Prob3TableInherited() {
        delete [] augTable;
    }; //Destructor

    const T *getAugTable(void) {
        return augTable;
    }
};

template <class T>
Prob3TableInherited<T>::Prob3TableInherited(char* s, int r, int c)
: Prob3Table<T>(s, r, c) {
    augTable = new T[(r + 1)*(c + 1)];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            augTable[i * (c + 1) + j] = Prob3Table<T>::table[i * c + j];
        }
        augTable[i * (c + 1) + c ] = Prob3Table<T>::rowSum[i];
    }
    for (int i = 0; i < c; i++) {
        augTable[r * (c + 1) + i] = Prob3Table<T>::colSum[i];
    }
    augTable[(r + 1)*(c + 1) - 1] = Prob3Table<T>::grandTotal;
}


#endif /* PROB3TABLE_H */

