/**
   rescue_joints.h
**/
#pragma once
#include <Arduino.h>
#include "rescue_globals.h"

typedef struct {
  int pin_dir;// pin direzione
  int pin_pwm;// pin pwm

  int velocita;// velocita del motore
  int direzione;// direzione del motore
}RescueMotor;

/** 
 * inizializza la struttura m impostando pin_dir, pin_pwm e azzerando
 * velocita e direzione  
 **/
void RescueMotor_init(RescueMotor* m, int pin_dir, int pin_pwm);

/**
 * imposta la velocita di m in base v.
 * v puo essere sia negativo che positivo mentre 
 * m->velocita deve essere necessariamente positivo
 * il segno di v determina m->direzione (0 se positivo, 1 se negativo
 **/
void RescueMotor_setVelocita(RescueMotor* m, int v);

/**
 * comunica al controllore i comandi per accendere il motore
 **/
void RescueMotor_handle(RescueMotor* m);

