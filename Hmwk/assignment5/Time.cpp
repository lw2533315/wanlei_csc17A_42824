/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Time.h"

float TimeClock::elapsed(){
  int temp;
  if(endTime-(endTime/100)*100<milHour-(milHour/100)*100){
    temp=endTime-100+60;
  }
  temp-=milHour;
  return static_cast<float>(temp)/100;
}