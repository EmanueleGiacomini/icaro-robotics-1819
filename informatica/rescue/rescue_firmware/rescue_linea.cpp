/**
 * rescue_linea.cpp
 **/

#include "rescue_linea.h"


/**
 * inizializza l (RescueLinea) azzerando i valori
 * di output, line_flag e calib_flag. Poi imposta
 * l->sensori pari a s.
 **/
void RescueLinea_init(RescueLinea* l, SensoreLinea* s) {
  return;
}

/**
 * Esegue la lettura di tuti i sensori e contemporaneamente,
 * calcola l'output del modulo. I passi che svolge la funzione
 * sono i seguenti:
 * 0) Azzera line_flag e output
 * 1) Lancia la funzione SensoreLinea_handle per ogni
 *    sensore presente in l->sensori
 *    (NOTA: Per ricavare il puntatore ad uno dei sensori
 *    basta scrivere &l->sensori[x] dove x è l'indice a cui
 *    si vuole accedere)
 * 2) se calib_flag == 0 allora bisogna calcolare
 *    l'output ( altrimenti possiamo terminare
 *    subito)
 * 3) per ogni sensore viene lanciata la funzione
 *    SensoreLinea_getStatus. Se restituisce un valore
 *    diverso da 0 (il sensore ha visto la linea) allora
 *    bisogna 
 *    - incrementare line_flag
 *    - sommare a line_offset il valore di s_offset[x] dove x
 *      è l'indice del sensore che ha visto la linea
 * 4) Dopo aver controllato i sensori, se line_flag è maggiore
 *    di 0, allora l->output = line_offset/l->line_flag
 **/
void RescueLinea_handle(RescueLinea* l) {
  int16_t line_offset=0; // variabile temporanea
  // Da completare...
  return;
}

/**
 * imposta l->calib_flag ad 1
 * e lancia la funzione SensoreLinea_startCalib
 * per ogni sensore in l->sensori
 **/
void RescueLinea_startCalib(RescueLinea* l) {
  // Da completare...
  return;
}

/**
 * azzera l->calib_flag
 * e lancia la funzione SensoreLinea_stopCalib
 * per ogni sensore in l->sensori
 **/
void RescueLinea_stopCalib(RescueLinea* l) {
  // Da completare...
  return;
}

/**
 * restituisce il valore di l->line_flag
 **/
uint8_t RescueLinea_rilevaLinea(RescueLinea* l) {
  // Da completare...
  return 0;
}

/**
 * restituisce l->output
 **/
int16_t RescueLinea_getStatus(RescueLinea* l) {
  // Da completare...
  return 0;
}
