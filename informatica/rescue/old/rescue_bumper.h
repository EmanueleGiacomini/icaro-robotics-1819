/**
   rescue_bumper.h
**/

#pragma once

#include <Arduino.h>
#include "rescue_params.h"

typedef struct {
  int pin;
  int misura;
  int stato;
} RescueBumper;

/**
 * inzializza la struttura bumper azzerando misura e stato
 **/
void RescueBumper_init(RescueBumper* b);

/**
 * esegue la lettura del pin assegnato a bumper e aggiorna misura
 **/
void RescueBumper_update(RescueBumper* b);

/**
 * calcola il nuovo stato a partire da misura
 **/
void RescueBumper_handle(RescueBumper* b);

/**
 * restituisce lo stato di uscita di bumper
 **/
int RescueBumper_getStato(RescueBumper* b);

// TODO: Implementare soluzione con interrupt
