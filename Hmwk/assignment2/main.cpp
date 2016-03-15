/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on March 14, 2016, 2:35 PM
 */

#include <cstdlib>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void meanMedianMode();
int* fillArray(int, int);
void printArray(int*, int);
float mean(int[], int);
float median(int[], int);
int *mode(int[], int, int&);
void quickSort(int [], int, int);
void programming_10();
int* arrayReverse(int [], int);
void programming_11();
int* arrayExpander(int [], int);
void programming_12();
int * addSizeOne(int [], int);
void programming_1();
void programming_13();

bool cmp(const pair<int, int>&a, const pair<int, int>&b) {
    return a.second < b.second;
}

/*
 * 
 */
int main(int argc, char** argv) {
    while (true) {
        bool go;
        int option = 100;
        do {
            go = false;
            cout << "choice problem,1-6,and 9 exit" << endl;
            string input = "";
            cin>>input;
            option = (int) input[0] - 48;
            //            cout << "option is " << option << endl;
            if (option > 9 || option < 1)
                go = true;
        } while (go);

        switch (option) {
            case 1: meanMedianMode();
                break;
            case 2: programming_11();
                break;
            case 3: programming_10();
                break;
            case 4: programming_12();
                break;
            case 5: programming_1();
                break;
            case 6: programming_13();
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

void programming_13() {
    int studentNum;
    bool go = true;
    while (go) {
        cout << "how many student do the survey?" << endl;
        if (cin >> studentNum && studentNum >= 0) {
            go = false;
        } else {
            cin.clear();
            cin.ignore(1024, '\n');
        }
    }
    cout << "size is " << studentNum << endl;
    int *seeMovie = new int[studentNum];
    while (!go) {
        go = true;
        cout << "please enter the number of movie of each student saw in the month one by one" << endl;
        for (int i = 0; i < studentNum; i++) {
            if (cin >> seeMovie[i]) {

            } else {
                go = false;

                cin.clear();
                cin.ignore(1024, '\n');
                break;

            }
            if (seeMovie[i] < 0)
                go = false; //不能用break，buff里有东西
        }
    }

    int len = 0;
    cout << "mean: " << mean(seeMovie, studentNum) << endl << "median: " << median(seeMovie, studentNum)
            << endl << "mode array: ";
    int *mArray = mode(seeMovie, studentNum, len);
    for (int i = 0; i < len; i++)
        cout << mArray[i] << " ";
    cout << endl;

}

void programming_1() {
    int size, range;
    cout << "input the array size, and the element range" << endl;
    cin >> size>>range;
    int*a = fillArray(size, range);
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}

void programming_12() {
    int *a = new int[5];
    //    int a[]={1,2,3,4,5};
    for (int i = 0; i < 5; i++) {
        a[i] = i + 1;
    }

    for (int i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    int *b = addSizeOne(a, 5);

}

int *addSizeOne(int a[], int size) {

    static int count1 = 0;
    //    cout<<"count1 is "<<count1<<endl;
    int len = size + 1;
    int *temp = new int[len];
    temp[0] = count1;
    for (int i = 0; i < size; i++) {
        temp[i + 1] = a[i];
    }\
    cout << "the " << count1 << " times: " << endl;
    for (int i = 0; i < len; i++) {
        cout << temp[i] << " ";
    }
    cout << endl;
    delete []a;
    if (count1 == 4) {
        return temp;
    } else {
        count1++;
        addSizeOne(temp, len);
    }
}

void programming_10() {
    int a[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
        cout << a[i] << " ";
    cout << endl;
    int *b = arrayReverse(a, 5);
    for (int i = 0; i < 5; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
}

int *arrayReverse(int a[], int size) {
    int *temp = new int[size];
    for (int i = 0; i < size; i++) {
        temp[i] = a[size - i - 1];
    }
    return temp;
}

void programming_11() {
    int a[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
        cout << a[i] << " ";
    cout << endl;
    int *b = arrayExpander(a, 5);
    for (int i = 0; i < 10; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
}

int *arrayExpander(int a[], int size) {
    int *temp = new int[2 * size];
    for (int i = 0; i < size; i++) {
        temp[i] = a[i];
    }
    for (int i = size; i < 2 * size; i++) {
        temp[i] = 0;
    }
    return temp;
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

float mean(int*a, int size) {
    float temp = 0;
    for (int i = 0; i < size; i++)
        temp += *(a + i);
    return temp / (float) size;
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

void meanMedianMode() {
    int size, range;
    cin >> size>>range;
    int * pArray = fillArray(size, range);
    printArray(pArray, size);
    int len;
    int *mArray = mode(pArray, size, len);
    cout << "mean: " << mean(pArray, size) << endl << "median: " << median(pArray, size)
            << endl << "mode array: ";

    for (int i = 0; i < len; i++)
        cout << mArray[i] << " ";
    cout << endl;

}

int *mode(int *a, int size, int&len) {
    vector<pair<int, int> >v;
    quickSort(a, 0, size - 1);
    int comValue = a[0];
    int count = 1;
    for (int i = 1; i < size; i++) {
        if (a[i] == comValue) {
            count++;
        } else {
            v.push_back(make_pair(comValue, count));
            count = 1;
            comValue = a[i];
        }
    }
    v.push_back(make_pair(comValue, count)); //无法比较的当前数据也要存进去
    sort(v.begin(), v.end(), cmp);
    int frequency = v[v.size() - 1].second;
    count = 1;
    int *temp;
    for (int i = v.size() - 2; i >= 0; i--) {
        if (frequency != v[i].second) {
            len = count + 2;
            temp = new int[len];
            temp[0] = count;
            temp[1] = frequency;
            int index = 0;
            while (count > 0) {
                temp[2 + index] = v[v.size() - count].first;
                count--;
                index++;
            }
            return temp;
        } else {
            count++;
        }
    }
    /*all the frequency are same*/
    len = count + 2;
    temp = new int[len];
    temp[0] = count;
    temp[1] = frequency;
    int index = 0;
    while (count > 0) {
        temp[2 + index] = v[v.size() - count].first;
        count--;
        index++;
    }
    return temp;
    cout << "in mod function the len is " << len << endl;
}

void printArray(int*a, int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int *fillArray(int size, int range) {
    srand(static_cast<unsigned int> (time(0)));
    int *p = new int[size];
    for (int i = 0; i < size; i++) {
        *(p + i) = rand() % range + 1;
    }
    return p;
}

