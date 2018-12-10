/**
   rescue_joints.cpp
**/
#include "rescue_joints.h"


/** 
 * inizializza la struttura m impostando pin_dir, pin_pwm e azzerando
 * velocita e direzione  
 **/
void RescueMotor_init(RescueMotor* m, int pin_dir, int pin_pwm) {
  m->pin_dir=pin_dir;
  m->pin_pwm=pin_pwm;
  m->velocita=0;
  m->direzione=0;
}

/**
 * imposta la velocita di m in base v.
 * v puo essere sia negativo che positivo mentre 
 * m->velocita deve essere necessariamente positivo
 * il segno di v determina m->direzione (0 se positivo, 1 se negativo
 **/
void RescueMotor_setVelocita(RescueMotor* m, int v) {
  if(v>0) {
    m->velocita=v;
    m->direzione=0;
  } else {
    m->velocita=-v;
    m->direzione=1;
  }
}

/**
 * comunica al controllore i comandi per accendere il motore
 **/
void RescueMotor_handle(RescueMotor* m) {
  digitalWrite(m->pin_dir, m->direzione);
  analogWrite(m->pin_pwm, m->velocita);
}
