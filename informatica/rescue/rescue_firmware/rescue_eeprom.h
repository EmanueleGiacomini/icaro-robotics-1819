/**
 * rescue_eeprom.h
 **/
#pragma once
#include "eeprom.h"
#include "rescue_linea.h"

void RescueEeprom_init(void);
void RescueEeprom_storeSensoreLinea(SensoreLinea*, uint16_t);
void RescueEeprom_loadSensoreLinea(SensoreLinea*, uint16_t);

