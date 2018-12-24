/**
 * rescue_motore.cpp
 **/

#include "rescue_motore.h"

/**
 * Inizializza la struttura m (RescueMotore) azzerando
 * velocita e direzione, e impostanto tramite la funzione
 * di PinMode, i pin di direzione (pin_dir)
 * e di velocita (pin_pwm)
 */
void RescueMotore_init(RescueMotore* m) {
  //Da completare...
  return;
}

/**
 * Imposta la velocita e direzione di m (RescueMotore)
 * secondo queste specifiche:
 * m->direzione = segno(v) [0 se positivo, 1 se negativo]
 * m->velocita = modulo(v) [0, 255]
 * se modulo(v) > 255, limitare a 255
 */
void RescueMotore_setVel(RescueMotore* m, int v) {
  //Da completare...
  return;
}

/**
 * Attiva il motore fisico tramite le funzioni di 
 * digitalWrite
 * analogWrite
 * tenendo conto dei dati interni alla struttura m (RescueMotore)
 */
void RescueMotore_handle(RescueMotore* m) {
  //Da completare...
  return;
}