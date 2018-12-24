/**
 * rescue_firmware.ino
 * @author Emanuele Giacomini
 **/

#include "rescue_motore.h"
#include "rescue_drive.h"

RescueMotore motore_dx = {
  pin_dir : 11,
  pin_pwm : 4,
  velocita : 0,
  direzione : 0
};

RescueMotore motore_sx = {
  pin_dir : 12,
  pin_pwm : 5,
  velocita : 0,
  direzione : 0
};

RescueDrive drive;

void setup() {
  Serial.begin(9600);
  Serial.println("Seriale inizializzata...");

  // Inizializzazione motori...
  RescueMotore_init(&motore_dx);
  RescueMotore_init(&motore_sx);

  // Inizializzazione drive
  RescueDrive_init(&drive, &motore_dx, &motore_sx);
}

void loop() {
  
}