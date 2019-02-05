/**
 * rescue_firmware.ino
 * @author Emanuele Giacomini
 **/

#include "rescue_motore.h"
#include "rescue_drive.h"
#include "rescue_linea.h"
#include "rescue_linea_internal.h"

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

SensoreLinea sensori_linea[NUMERO_SENSORI_LINEA] = {
  {// sensore[0]
  soglia : 0,
  misura : 0,
  misura_min : 1023,
  misura_max : 0,
  detect_flag : 0,
  calibra_flag : 0,
  pin_reading : A0
  },
  {// sensore[1]
  soglia : 0,
  misura : 0,
  misura_min : 1023,
  misura_max : 0,
  detect_flag : 0,
  calibra_flag : 0,
  pin_reading : A1
  },
  {// sensore[2]
  soglia : 0,
  misura : 0,
  misura_min : 1023,
  misura_max : 0,
  detect_flag : 0,
  calibra_flag : 0,
  pin_reading : A2
  }  
};

RescueLinea linea = {
 output : 0,
 line_flag : 0,
 calib_flag : 0,
 s_offset : {-2, 0, 2},
 sensori : 0
};


void setup() {
  Serial.begin(9600);
  Serial.println("Seriale inizializzata...");

  // Inizializzazione motori...
  RescueMotore_init(&motore_dx);
  RescueMotore_init(&motore_sx);

  // Inizializzazione drive
  RescueDrive_init(&drive, &motore_dx, &motore_sx);

  for(int i=0;i<NUMERO_SENSORI_LINEA; ++i)
    SensoreLinea_init(&sensori_linea[i]);

  RescueLinea_init(&linea, sensori_linea);
}

void loop() {
  
}
