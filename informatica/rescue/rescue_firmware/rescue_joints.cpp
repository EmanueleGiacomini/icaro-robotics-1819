/**
   rescue_joints.cpp
**/
#include "rescue_joints.h"

/** Initialize the joint given the pins **/
void RescueJoint_init(RescueJoint* joint, uint8_t* pins) { 
  pinMode(joint->pins[0], INPUT);              
  return;
}

/** Sets the speed of a given joint **/
void RescueJoint_setSpeed(RescueJoint joint, int speed) {
  int pwm = 0;     //lo so che mi hai insegnato come risparmiare memoria con uint8_t però non essere tirchio come sempre su...
  int dir = 0;     //pure qui, viva lo spreco...
  if(speed>= 0){
    pwm = speed;
    dir = 0; 
  }                     
  else {    
    pwm = - speed;   
    dir = 1;         
  }
  if(pwm > 255){
    pwm = 255;
  }
  return;
}

