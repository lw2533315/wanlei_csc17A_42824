/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Employee.h
 * Author: Administrator
 *
 * Created on April 27, 2016, 11:58 PM
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<iostream>
using namespace std;
class Employee{
private:
    string name;
    int idNumber;
    string department;
    string position;
public:
    Employee(string name,int id,string dp,string pt);
    Employee(string name,int id);
    Employee();
    void setName(string n);
    void setId(int id);
    void setDept(string d);
    void setPost(string p);
    string getName()const;
    int getId() const;
    string getDept()const;
    string getPost()const;
    void display()const;
};



#endif /* EMPLOYEE_H */

