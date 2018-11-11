/**
   rescue_joints.cpp
**/
#include "rescue_joints.h"

/** Initialize the joint given the pins **/
void RescueJoint_init(RescueJoint joint, uint8_t* pins, int speed) {  //alloraaaaa, ho provato a inserire "speed" per fare delle
  //pinMode(joint->pins[0], INPUT);              //prove, comunque è qui l'errore che ti dicevo, praticamente dice che "->" non è un
  //pinMode(speed->pins[1], OUTPUT);     //puntatore della struttura RescueJoint
  return;
}

/** Sets the speed of a given joint **/
void RescueJoint_setSpeed(RescueJoint joint, int speed) {
  int pwm = 0;     //io so che mi hai insegnato come risparmiare memoria con uint8_t però non essere tirchio come sempre su...
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
  return;
}

