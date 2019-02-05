/**
 * rescue_senscolore.h
 *
 **/

#pragma once
#include <Arduino.h>

/**
 * Tavola frequenza output 
 * in relazione ad s0 ed s1:
 * ----------------------
 * s0 s1 | Freq
 * 0  0  | Unita spenta
 * 0  1  | 2 % freq
 * 1  0  | 20 % freq
 * 1  1  | 100 % freq
 * ----------------------
 *
 * Tavola Fotodiodo output
 * in relazione ad s2 ed s3:
 * ----------------------
 * s0 s1 | Tipo Fotodiodo
 * 0  0  | Rosso
 * 0  1  | Blu
 * 1  0  | Nessun Filtro (tutto lo spettro)
 * 1  1  | Verde
 * ----------------------
 **/

typedef struct {
  // Pin di controllo
  uint8_t pin_s0;
  uint8_t pin_s1;
  uint8_t pin_s2;
  uint8_t pin_s3;
  // pin di input (OUT) dal sensore
  uint8_t pin_misura;

  // Stati correnti
  uint8_t s0;
  uint8_t s1;
  uint8_t s2;
  uint8_t s3;
  int misura;
  
} RescueSensColore;

/**
 * Inizializza la struttra s (RescueSensColore) azzerando
 * gli stati (s0---s3, misura) ed impostando tramite la funzione
 * di PinMode, i pin di stato (pin_s0---pin_s3)
 * e di misura (pin_misura)
 **/
void RescueSensColore_init(RescueSensColore* s);

/**
 * Interroga il sensore, trasmettendo prima i valori degli stati
 * (s0---s3) tramite la funzione di DigitalWrite
 * poi assegna a misura il valore restituito dalla funzione
 * pulseIn(s->pin_misura, LOW)
 **/
void RescueSensColore_handle(RescueSensColore* s);

/**
 * Imposta lo stato s0 di s (RescueSensColore) secondo questa tabella:
 * s0 = 1 se v != 0
 * s0 = 0 se v == 0
 **/
void RescueSensColore_setS0(RescueSensColore* s, uint8_t v);

/**
 * Imposta lo stato s1 di s (RescueSensColore) secondo questa tabella:
 * s1 = 1 se v != 0
 * s1 = 0 se v == 0
 **/
void RescueSensColore_setS1(RescueSensColore* s, uint8_t v);

/**
 * Imposta lo stato s2 di s (RescueSensColore) secondo questa tabella:
 * s2 = 1 se v != 0
 * s2 = 0 se v == 0
 **/
void RescueSensColore_setS2(RescueSensColore* s, uint8_t v);

/**
 * Imposta lo stato s3 di s (RescueSensColore) secondo questa tabella:
 * s3 = 1 se v != 0
 * s3 = 0 se v == 0
 **/
void RescueSensColore_setS3(RescueSensColore* s, uint8_t v);
