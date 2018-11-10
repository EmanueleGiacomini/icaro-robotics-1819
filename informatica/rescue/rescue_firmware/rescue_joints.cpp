/**
   rescue_joints.cpp
**/
#pragma once;  //mi hai deluso non mi sarei mai aspettato da te che ti dimenticasti del nostro amico qui presente.
#include "rescue_joints.h"

/** Initialize the joint given the pins **/
void RescueJoint_init(RescueJoint joint, uint8_t* pins) {  
  return;
}

/** Sets the speed of a given joint **/
void RescueJoint_setSpeed(RescueJoint joint, int speed) {
  int pwm = 0;     //io so che mi hai inseganto come risparmiare memoria con uint8_t però non essere tirchio come sempre su...
  int dir = 0;     //pure qui, viva lo spreco...
  if(speed>= 0){
    pwm = speed;
    dir = 0;
  }                     
  else {    
    pwm = - speed;   //ho messo tutto uguale al calciatore qui perchè non ce tanto da dirgli, l'unico dubbio però che ho è
    dir = 1;         //questa cosa di passargli una variabile negativa sui rescue se può cambiare qualcosa
  }
  if(pwm > 255){
    pwm = 255;
  }
  this->pwm = pwm;
  this->dir = dir;
  return;
}

