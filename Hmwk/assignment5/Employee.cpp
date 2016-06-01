/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Employee.h"
#include <iostream>
using namespace std;

Employee::Employee(string name, int num, string date) {
    this->name = name;
    this->num = num;
    this->date = date;
}

ProductionWorker::ProductionWorker
(string name, int num, string date,
        int shift, float pyrt)
: Employee(name, num, date) {
    this->shift = shift;
    this->pyrt = pyrt;
}

ostream &operator<<(ostream &strm, const ProductionWorker &obj) {
    strm << "Name: " << obj.name << endl;
    strm << "ID: " << obj.num << endl;
    strm << "Hire date: " << obj.date << endl;
    strm << "Shift: " << obj.shift << endl;
    strm << "Hourly pay rate: $" << obj.pyrt << endl;
}

ShiftSupervisor::ShiftSupervisor(string name, int num, string date,
        float annual)
: Employee(name, num, date) {
    this->annual = annual;
    bonus = annual * 0.2;
}

ostream &operator<<(ostream &strm, const ShiftSupervisor &object) {
    strm << "Name: " << object.name << endl;
    strm << "ID: " << object.num << endl;
    strm << "Hire date: " << object.date << endl;
    strm << "Annual salary : " << object.annual << endl;
    strm << "Production bonus : " << object.bonus << endl;
    strm << "If you reach the goal, you will have " << object.bonus << " bonus\n";
}