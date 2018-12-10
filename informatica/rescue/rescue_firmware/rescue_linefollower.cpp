/**
   rescue_linefollower.cpp
**/

#include "rescue_linefollower.h"


/**
 * inizializza la struttura d impostando il pin  ed azzerando tutti
 * gli altri campi.
 **/
void LineDetector_init(LineDetector* d) {
  d->misura=0;
  d->misura_minima=0;
  d->misura_massima=0;
  d->soglia=0;
  d->stato=0;
}

/**
 * imposta manualmente la soglia di d
 **/
void LineDetector_setSoglia(LineDetector* d, int soglia) {
  d->soglia=soglia;
}

/**
 * lancia la modalita automamtica di calibrazione del sensore
 * mentre attiva bisogna esporre il sensore alle tonalita del
 * campo
 **/
void LineDetector_setCalibrazione(LineDetector* d) {
  d->stato=2;
}
/**
 * termina la modalita di calibrazione e calcola la soglia
 **/
void LineDetector_stopCalibrazione(LineDetector* d) {
  /**
   * la soglia sara calcolata come la media geometrica
   * fra la misura massima e la misura minima.
   **/

  d->soglia = (int)((d->misura_massima + d->misura_minima) / 2.0);
  d->stato=0;
}

/**
 * aggiorna il valore misurato del sensore
 **/
void LineDetector_update(LineDetector* d) {
  d->misura = analogRead(d->pin);
}

/**
 * esegue la computazione dei dati misurati, calibrando o aggiornado
 * lo stato di uscita del sensore
 **/
void LineDetector_handle(LineDetector* d) {
  if(d->stato == 2) {// modalita calibrazione

    // update misura_massima
    if(d->misura > d->misura_massima)
      d->misura_massima = d->misura;

    // update misura_minima    
    if(d->misura < d->misura_minima)
      d->misura_minima=d->misura;
    
  } else {// modalita standard

    if(d->misura > d->soglia)
      d->stato=1;
    else
      d->stato=0;
  }
}

/**
 * restituisce lo stato di d
 **/
int LineDetector_getStato(LineDetector* d) {
  return d->stato;
}

/**
 * inizializza la struct l lanciando l'init dei
 * NUM_DETECTORS LineDetector(s) e azzerando 
 * offset_linea e stato
 **/
void LineSensor_init(LineSensor* l) {
  int i;
  for(i=0;i<NUM_DETECTORS;++i)
    LineDetector_init(&l->detectors[i]);
  l->offset_linea=0;
  l->stato=0;
}
/**
 * attiva la modalita di calibrazione
 **/
void LineSensor_setCalibrazione(LineSensor* l) {
  int i;
  l->stato=2;
  for(i=0;i<NUM_DETECTORS;++i)
    LineDetector_setCalibrazione(&l->detectors[i]);
}

/**
 * disattiva la modalita di calibrazione
 **/
void LineSensor_stopCalibrazione(LineSensor* l) {
  int i;
  l->stato=0;
  for(i=0;i<NUM_DETECTORS;++i)
    LineDetector_stopCalibrazione(&l->detectors[i]);
}

/**
 * aggiorna le misure dei NUM_DETECTORS LineDetector(s)
 **/
void LineSensor_update(LineSensor* l) {
  int i;
  for(i=0;i<NUM_DETECTORS;++i)
    LineDetector_update(&l->detectors[i]);
}

/**
 * elabora offset_linea e aggiorna lo stato di conseguenza
 * per fare cio, bisogna prima lancaire la funzione handle
 * per i NUM_DETECTORS LineDetector(s)
 **/
void LineSensor_handle(LineSensor* l) {
  int i;
  int visti=0;
  int somma=0;

  // elabora i dati su LineDetector
  for(i=0;i<NUM_DETECTORS;++i)
    LineDetector_handle(&l->detectors[i]);

  // controlla quali LineDetector(s) hanno rilevato la linea
  // ed aumenta somma e visti di conseguenza
  for(i=0;i<NUM_DETECTORS;++i) {
    if(LineDetector_getStato(&l->detectors[i])) {
      ++visti;
      somma+=l->detector_valore[i];
    }
  }

  if(visti > 0) {
    l->offset_linea=(int) (somma/visti);
    l->stato=1;
  } else {
    l->stato=0;
  }
}
