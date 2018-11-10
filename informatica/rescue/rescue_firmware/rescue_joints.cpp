/**
   rescue_joints.cpp
**/
#pragma once;  //mi hai deluso non mi sarei mai aspettato da te che ti dimenticasti del nostro amico qui presente.
#include "rescue_joints.h"

/** Initialize the joint given the pins **/
void RescueJoint_init(RescueJoint joint, uint8_t* pins1, uint8_t pins2) {  //ti spiego perchè sicuramente di chiederai
  uint8_t* JOINT_1_DIR_PIN = &pins1[0];                                    //perchè ho creato due variabile che contengono i pin
  uint8_t* JOINT_1_PWM_PIN = &pins1[1];      //il motivo è solo perchè secondo me è più comodo gestirsi i pin di ogni singolo motore
  uint8_t* JOINT_2_DIR_PIN = &pins2[0];     //separatamente così è più pulito e non si fa confusione anche quando usano 
  uint8_t* JOINT_2_PWM_PIN = &pins2[1];

  pinMode(JOINT_1_DIR_PIN, OUTPUT);
  pinMode(JOINT_1_PWM_PIN, OUTPUT);    //li imposto come output perchè ti voglio copiare almeno una cosa di tutto quello che
  pinMode(JOINT_2_DIR_PIN, OUTPUT);    //ho scritto sarà giusta...
  pinMode(JOINT_2_PWM_PIN, OUTPUT);

  this->JOINT_1_DIR_PIN = JOINT_1_DIR_PIN;
  this->JOINT_1_PWM_PIN = JOINT_1_PWM_PIN;   //anche su questo ti copio perchè sei bello. Non ti fare strani pensieri a me
  this->JOINT_2_DIR_PIN = JOINT_2_DIR_PIN;   //piace la figa
  this->JOINT_2_PWM_PIN = JOINT_2_PWM_PIN;
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

