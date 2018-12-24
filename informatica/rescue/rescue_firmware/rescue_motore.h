/**
 * rescue_motore.h
 */
#pragma once
#include <Arduino.h>

typedef struct {
  // pin relativo alla direzione del motore
  uint8_t pin_dir;
  // pin relativo alla velocita (PWM) del motore
  uint8_t pin_pwm;

  // variabile interna necessaria per sapere la velocita del motore
  uint8_t velocita; 
  // variabile interna necessaria per sapere il verso di rotazione
  // del motore
  uint8_t direzione;  
} RescueMotore;

/**
 * Inizializza la struttura m (RescueMotore) azzerando
 * velocita e direzione, e impostanto tramite la funzione
 * di PinMode, i pin di direzione (pin_dir)
 * e di velocita (pin_pwm)
 */
void RescueMotore_init(RescueMotore* m);

/**
 * Imposta la velocita e direzione di m (RescueMotore)
 * secondo queste specifiche:
 * m->direzione = segno(v) [0 se positivo, 1 se negativo]
 * m->velocita = modulo(v) [0, 255]
 * se modulo(v) > 255, limitare a 255
 */
void RescueMotore_setVel(RescueMotore* m, int v);

/**
 * Attiva il motore fisico tramite le funzioni di 
 * digitalWrite
 * analogWrite
 * tenendo conto dei dati interni alla struttura m (RescueMotore)
 */
void RescueMotore_handle(RescueMotore* m);

