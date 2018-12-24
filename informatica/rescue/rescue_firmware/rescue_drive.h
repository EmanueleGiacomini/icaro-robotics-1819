/**
 * rescue_drive.h
 */
#pragma once
#include <Arduino.h>
#include "rescue_motore.h"

typedef struct {
  RescueMotore* motore_dx;
  RescueMotore* motore_sx;

  double vel_x_desiderata;
  double vel_y_desiderata;
}RescueDrive;

/**
 * Inizializza la struttura d (RescueDrive) azzerando
 * tutte le velocita desiderate,ed impostando le variabili
 * d->motore_dx = mdx
 * d->motore_sx = msx
 */
void RescueDrive_init(RescueDrive* d, RescueMotore* mdx, RescueMotore* msx);

/**
 * Imposta le velocita desiderate di d (RescueDrive) secondo i parametri (x,y)
 * forniti.
 * d->vel_x... = x
 * d->vel_y... = y
 * 
 * Successivamente calcola per i due motori, le velocita secondo la formula:
 * velocita(mot_dx) : y - x
 * velocita(mot_sx) : - y - x
 */
void RescueDrive_setVel(RescueDrive* d, double x, double y);

/**
 * Lancia per ogni motore (RescueMotore) interno all'array d->motori
 * la funzione RescueMotore_handle cosi da far muovere la piattaforma
 */
void RescueDrive_handle(RescueDrive* d);

/**
 * Reimposta a 0 i valori di velocita desiderate della struttura d (RescueDrive)
 */
void RescueDrive_reset(RescueDrive* d);