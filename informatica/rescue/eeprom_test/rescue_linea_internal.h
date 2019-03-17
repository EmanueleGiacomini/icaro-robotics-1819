/**
 * rescue_linea_internal.h
 **/

#pragma once
#include <Arduino.h>

typedef struct {
  uint16_t soglia;// soglia riconoscimento linea
  uint16_t misura;// misura attuale del sensore
  uint16_t misura_min;// x Calibrazione: Lettura di valore minimo
  uint16_t misura_max;// x Calibrazione: Lettura di valore massimo
  uint8_t detect_flag;// flag di rilevazione linea ( 1 : linea rilevata )
  uint8_t calibra_flag;// x Calibrazione: flag di calibrazione

  uint8_t pin_reading;// Pin relativo al sensore
}SensoreLinea;

/**
 * inizializza s (SensoreLinea) azzerando i valori di
 * soglia, misura, misura_max, detect_flag e 
 * calibra_flag
 * imposta misura_min a 1023
 * Imposta come pin di OUTPUT il "pin_reading"
 **/
void SensoreLinea_init(SensoreLinea* s);

/**
 * Esegue la lettura del sensore, se la flag di calibrazione
 * (calibra_flag) e' attiva, allora aggiorna anche
 * misura_min e misura_max secondo queste condizioni:
 * misura < misura_min ? => misura_min = misura
 * misura > misura_max ? => misura_max = misura
 *
 * In oltre se la lettura e' maggiore della soglia
 * allora imposta ad 1 lo status (detect_flag)
 **/
void SensoreLinea_handle(SensoreLinea* s);

/**
 * restituisce il valore di detect_flag
 **/
uint16_t SensoreLinea_getStato(SensoreLinea* s);

/**
 * imposta la variabile calibra_flag di s (SensoreLinea)
 * pari a 1
 **/
void SensoreLinea_startCalib(SensoreLinea* s);

/**
 * imposta la variabile calibra_flag di s (SensoreLinea)
 * pari a 0 
 * Poi imposta soglia secondo la formula:
 * soglia = (misura_max + misura_min) / 2
 * Poi azzera misura_max e pone misura_min = 1023
 **/
void SensoreLinea_stopCalib(SensoreLinea* s);
