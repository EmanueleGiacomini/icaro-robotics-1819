/**
 * rescue_eeprom.cpp
 **/
#include "rescue_eeprom.h"

#define SENSORE_LINEA_OFFSET 16

void RescueEeprom_init(void) {
  EEPROM_init();
  return;
}

void RescueEeprom_storeSensoreLinea(SensoreLinea* s, uint16_t n) {
  EEPROM_write(SENSORE_LINEA_OFFSET, (void*)s, sizeof(SensoreLinea)*n);
  return;
}

void RescueEeprom_loadSensoreLinea(SensoreLinea* s, uint16_t n) {
  EEPROM_read((void*)s, SENSORE_LINEA_OFFSET, sizeof(SensoreLinea)*n);
  return;
}
