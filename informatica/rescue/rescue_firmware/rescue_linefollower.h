/**
   rescue_linefollower.h
**/

#pragma once
#include <Arduino.h>
#include "rescue_globals.h"

typedef struct {
  int pin;// pin analogico associato al sensore
  int misura;// valore misurato dalla lettura analogica sul sensore

  int misura_minima;// valore necessario x calcolo soglia
  int misura_massima;// valore necessario x calcolo soglia
  int soglia;

  // stato puo assumere i seguenti valori:
  // 0 : misura < soglia
  // 1 : misura > soglia
  // 2 : modalita calibrazione
  int stato;
}LineDetector;

/**
 * inizializza la struttura d impostando pin e indice ed azzerando tutti
 * gli altri campi.
 **/
void LineDetector_init(LineDetector* d);

/**
 * imposta manualmente la soglia di d
 **/
void LineDetector_setSoglia(LineDetector* d, int soglia);

/**
 * lancia la modalita automamtica di calibrazione del sensore
 * mentre attiva bisogna esporre il sensore alle tonalita del
 * campo
 **/
void LineDetector_setCalibrazione(LineDetector* d);
/**
 * termina la modalita di calibrazione e calcola la soglia
 **/
void LineDetector_stopCalibrazione(LineDetector* d);

/**
 * aggiorna il valore misurato del sensore
 **/
void LineDetector_update(LineDetector* d);

/**
 * esegue la computazione dei dati misurati, calibrando o aggiornado
 * lo stato di uscita del sensore
 **/
void LineDetector_handle(LineDetector* d);

/**
 * restituisce lo stato di d
 **/
int LineDetector_getStato(LineDetector* d);


typedef struct {
  LineDetector* detectors;
  int detector_valore[NUM_DETECTORS];

  int offset_linea;
  int stato;
}LineSensor;

/**
 * inizializza la struct l lanciando l'init dei
 * NUM_DETECTORS LineDetector(s) e azzerando 
 * offset_linea e stato
 **/
void LineSensor_init(LineSensor* l);
/**
 * attiva la modalita di calibrazione
 **/
void LineSensor_setCalibrazione(LineSensor* l);

/**
 * disattiva la modalita di calibrazione
 **/
void LineSensor_stopCalibrazione(LineSensor* l);

/**
 * aggiorna le misure dei NUM_DETECTORS LineDetector(s)
 **/
void LineSensor_update(LineSensor* l);

/**
 * elabora offset_linea e aggiorna lo stato di conseguenza
 * per fare cio, bisogna prima lancaire la funzione handle
 * per i NUM_DETECTORS LineDetector(s)
 **/
void LineSensor_handle(LineSensor* l);
