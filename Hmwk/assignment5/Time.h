#ifndef PROB4_H
#define	PROB4_H
#include <iostream>
using namespace std;
class Time{
protected:
  int hour;
  int min;
  int sec;
public:
  Time(){
    hour=0;min=0;sec=0;
  }
  Time(int h, int m, int s){
    hour=h;min=m;sec=s;
  }
  Time(int h, int s){
    if(h>1259){h-=1200;}
    min=h-(h/100)*100;
    hour=h/100;
    sec=s;
  }
  int getHour() const{
    return hour;
  }
  int getMin() const{
    return min;
  }
  int getSec() const{
    return sec;
  }
  int setTime(int h){
    if(h>1259){hour=(h-1200)/100;}
  }
};
class MilTime:public Time{
protected:
  int milHour;
  int milsec;
  void testHour(int h){
//    if(h<0 || h>2359){throw BadHour();
    if(h<0 || h>2359){string s="BadHour";
            throw s;}
  }
  void testSec(int s){
    if(s<0 || s>59){
        string s="BadSeconds";
        throw s;}
  }
public:
  MilTime(int h, int s):Time(h, s){
    cout<<"miltime\n";
    milHour=0;
    milsec=0;
    testHour(h);
    testSec(s);
  }
  int getHour(){
    return milHour;
  }
  int getStandHr(){
    return hour*100+min;
  }
  void setTime(int h){
    milHour=h;
    setTime(h);
  }
};
class TimeClock:public MilTime{
private:
  int endTime;
public:
  TimeClock(int EndTime, int StartTime):MilTime(StartTime, 0){
    endTime=EndTime;
  }
  float elapsed();
};
#endif	/* PROB4_H */