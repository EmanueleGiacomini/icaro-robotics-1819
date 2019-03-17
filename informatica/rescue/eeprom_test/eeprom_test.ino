/**
 * eeprom_test.ino
 **/

#include "rescue_eeprom.h"
#include "rescue_linea.h"

#define NUM_SENSORI_LINEA 5

SensoreLinea sensori_linea[NUM_SENSORI_LINEA] = {
  {// sensore[0]
  soglia : 200,
  misura : 0,
  misura_min : 1023,
  misura_max : 0,
  detect_flag : 0,
  calibra_flag : 0,
  pin_reading : A0
  },
  {// sensore[1]
  soglia : 300,
  misura : 0,
  misura_min : 1023,
  misura_max : 0,
  detect_flag : 0,
  calibra_flag : 0,
  pin_reading : A1
  },
  {// sensore[2]
  soglia : 600,
  misura : 0,
  misura_min : 1023,
  misura_max : 0,
  detect_flag : 0,
  calibra_flag : 0,
  pin_reading : A2
  }  
};

void SensoreLinea_print(SensoreLinea* l, char* buf) {
  sprintf(buf, "soglia: %d\t", l->soglia);
  return;
}

char buf[256];
void setup() {
  Serial.begin(9600);
  Serial.println("Serial initialized...");
  RescueEeprom_init();
  Serial.println("EEPROM initialized...");
  for(int i=0;i<NUM_SENSORI_LINEA;++i) {
    SensoreLinea_print(&sensori_linea[i], buf);
    Serial.print(buf);
  }
  Serial.println();
  Serial.print("Storing sensors in EEPROM...");
  RescueEeprom_storeSensoreLinea(sensori_linea, NUM_SENSORI_LINEA);
  Serial.println("Setting sensors to 0...");
  for(int i=0;i<NUM_SENSORI_LINEA;++i) {
    sensori_linea[i].soglia=0;
  }
  for(int i=0;i<NUM_SENSORI_LINEA;++i) {
    SensoreLinea_print(&sensori_linea[i], buf);
    Serial.print(buf);
  }
  Serial.println();
  Serial.println("Loading sensors from EEPROM...");
  RescueEeprom_loadSensoreLinea(sensori_linea, NUM_SENSORI_LINEA);
  for(int i=0;i<NUM_SENSORI_LINEA;++i) {
    SensoreLinea_print(&sensori_linea[i], buf);
    Serial.print(buf);
  }
  Serial.println();
}

void loop() {

}
