/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Employee.h"
//using namespace std;
void Employee::setName(string n){
    name=n;
}
void Employee::setDept(string n){
    department=n;
}
void Employee::setPost(string n){
    position=n;
}
void Employee::setId(int n){
    idNumber=n;
}
string Employee::getDept() const{
    return department;
}
int Employee::getId() const {
    return idNumber;
}
string Employee::getName() const{
    return name;
}
string Employee::getPost() const{
    return position;
}
void Employee::display() const{
    cout<<"Name: "<<name<<endl;
    cout<<"ID: "<<idNumber<<endl;
    cout<<"Department: "<<department<<endl;
    cout<<"Position: "<<position<<endl;
    
}

Employee::Employee(){
    name="";
    idNumber=0;
    department="";
    position="";
}
Employee::Employee(string n,int id){
    name=n;
    idNumber=id;
    department="";
    position="";
}
Employee::Employee(string n,int id,string dp,string pt){
    name=n;
    idNumber=id;
    department=dp;
    position=pt;
}
