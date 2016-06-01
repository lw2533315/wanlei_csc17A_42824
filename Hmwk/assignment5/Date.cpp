/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <vector>
using namespace std;
#include"Data.h"
void Date::monthTransf(){
     switch(month){
    case 1: cout<<"January "; break;
    case 2: cout<<"February "; break;
    case 3: cout<<"March "; break;
    case 4: cout<<"April "; break;
    case 5: cout<<"May "; break;
    case 6: cout<<"June "; break;
    case 7: cout<<"July "; break;
    case 8: cout<<"August "; break;
    case 9: cout<<"September "; break;
    case 10: cout<<"October "; break;
    case 11: cout<<"November "; break;
    case 12: cout<<"December "; break;
  }
}

Date::Date(int d, int m, int yr) {
  day=d;
  month=m;
  year=yr;
}
void Date::print1(){
  cout<<month<<"/"<<day<<"/"<<year<<endl;
}
void Date::print2(){
    monthTransf();
  cout<<day<<", "<<year<<endl;
}
void Date::print3(){
  cout<<day<<" ";
  monthTransf();
  cout<<year<<endl;
}
void Date::setDate(){
  int yr[12]={31,28,31,30,31,30,31,31,30,31,30,31};
  //1-11 next month
  if(day>yr[month-1] && month<12){
    day=1;
    month++;
  }
  //12
  else if(month==12 && day>31){
    year++;
    month=1;
    day=1;
  }
  //pre month 1-12
  else if(month>1 && day==0){
    month--;
    day=yr[month-1];
  }
  //pre year
  else if(day==0 && month ==1){
    month=12;
    year--;
    day=31;
  }
}
Date Date::operator -(const Date &right){
  int yr[12]={31,28,31,30,31,30,31,31,30,31,30,31};
  Date temp;
  temp.day=0;
  if(year==right.year){
    if(month==right.month){
      if(day>right.day)
        temp.day=day-right.day;
      else cout<<"invalid input\n day=0\n";
    }
    else if(month>right.month){
      for(int i=month;i>right.month;i--){
        temp.day+=yr[i-1];
      }
      temp.day+=day;
      temp.day-=right.day;
    }
    else
      cout<<"invalid input\n day=0\n";
  }
  else if(year>right.year){
    temp.day=(year-right.year)*365;
    if(month==right.month){
        temp.day+=(day-right.day);
    }
    else if(month>right.month){
      for(int i=month;i>right.month;i--){
        temp.day+=yr[i-1];
      }
      temp.day+=day;
      temp.day-=right.day;
    }
    else{
      for(int i=0;i<month-2;i++){
        temp.day+=yr[i];
      }
      for(int i=0;i<right.month-2;i++){
        temp.day-=yr[i];
      }
    }
  }
  else cout<<"invalid input\n day=0\n";
  return temp;
}
Date Date::operator ++(){
  day++;
  setDate();
  return *this;
}
Date Date::operator --(){
  day--;
  setDate();
  return *this;
}
Date Date::operator ++(int){
  Date temp;
  setDate();
  day++;
  return temp;
}
Date Date::operator --(int){
  Date temp;
  setDate();
  day--;
  return temp;
}
ostream &operator << (ostream &strm, const Date &obj){
 
  switch(obj.month){
    case 1: strm<<"January "; break;
    case 2: strm<<"February "; break;
    case 3: strm<<"March "; break;
    case 4: strm<<"April "; break;
    case 5: strm<<"May "; break;
    case 6: strm<<"June "; break;
    case 7: strm<<"July "; break;
    case 8: strm<<"August "; break;
    case 9: strm<<"September "; break;
    case 10: strm<<"October "; break;
    case 11: strm<<"November "; break;
    case 12: strm<<"December "; break;
  }
  strm<<obj.day<<", "<<obj.year<<endl;
  return strm;
}
istream &operator >> (istream &strm, Date &obj){
  cout<<"Input day : ";
  strm>>obj.day;
  cout<<"Input month : ";
  strm>>obj.month;
  cout<<"Input year : ";
  strm>>obj.year;
  return strm;
}