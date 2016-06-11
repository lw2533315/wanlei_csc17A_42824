/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prob1Random.h
 * Author: Administrator
 *
 * Created on June 2, 2016, 5:22 PM
 */

#ifndef PROB1RANDOM_H
#define PROB1RANDOM_H
#include <iostream>

class Prob1Random {
private:
    int * ary;
    int * freq;
    int size;
    int loopNum;
public:
    Prob1Random(int, int*);
    ~Prob1Random();
    int * getAry()const;
    int * getFreq()const;
    int getLoopNum()const;
    void initialAry();
    void randSet();

};

Prob1Random::Prob1Random(int n, int* ary) {
    srand(static_cast<unsigned int> (time(0)));
    this->ary = ary;
    size = n;
    loopNum = 0;
    initialAry();
}

Prob1Random::~Prob1Random() {
    delete []freq;
}

void Prob1Random::initialAry() {
    freq = new int [5];
    for (int i = 0; i < 5; i++) {
        freq[i] = 0;
    }
}

int Prob1Random::getLoopNum() const {
    return loopNum;
}

int *Prob1Random::getAry()const {
    return ary;
}

int * Prob1Random::getFreq()const {
    return freq;
}

void Prob1Random::randSet() {
    loopNum++;
    int index = rand() % 5;
    switch (index) {
        case 0: freq[index] += 1;
            break;
        case 1: freq[index] += 1;
            break;
        case 2: freq[index] += 1;
            break;
        case 3: freq[index] += 1;
            break;
        case 4: freq[index] += 1;
            break;
    }

}




#endif /* PROB1RANDOM_H */

