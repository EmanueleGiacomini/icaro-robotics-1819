/**
   rescue_bumper.cpp
**/

#include "rescue_bumper.h"

/**
 * inzializza la struttura bumper azzerando misura e stato
 **/
void RescueBumper_init(RescueBumper* b) {
  pinMode(b->pin, INPUT);
  b->misura=0;
  b->stato=0;
}

/**
 * esegue la lettura del pin assegnato a bumper e aggiorna misura
 **/
void RescueBumper_update(RescueBumper* b) {
  b->misura=digitalRead(b->pin);
}

/**
 * calcola il nuovo stato a partire da misura
 **/
void RescueBumper_handle(RescueBumper* b) {
  b->stato=b->misura;
}

/**
 * restituisce lo stato di uscita di bumper
 **/
int RescueBumper_getStato(RescueBumper* b) {
  return b->stato;
}
