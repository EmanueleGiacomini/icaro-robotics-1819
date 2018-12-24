/**
   rescue_colorsensor.h
**/


// from datasheet: output_freq_min = GREEN_MIN(8kHz) => 125uS => TIMEOUT_US = 150
#pragma once
#include <Arduino.h>

#define TIMEOUT_US 150
#define FREQ_SCALE_2 2
#define FREQ_SCALE_20 1
#define FREQ_SCALE_100 3

#define PHOTO_RED 0
#define PHOTO_BLUE 2
#define PHOTO_CLEAR 1
#define PHOTO_GREEN 3

typedef enum {
  Red=0,
  Green=1,
  Blue=2,
  White=3,
  Black=4,
  NotClear=-1
}Color;

typedef struct {
  uint8_t pin_s0;
  uint8_t pin_s1;
  uint8_t pin_s2;
  uint8_t pin_s3;
  uint8_t pin_misura;


  uint8_t s0;
  uint8_t s1;
  uint8_t s2;
  uint8_t s3;
  uint16_t misura;
  uint8_t r_chn;
  uint8_t g_chn;
  uint8_t b_chn;

  Color colore_stimato;
}ColorSensor;

/** inizializza il sensore impostando i pin s0-..-s3 e azzerando misura **/
void ColorSensor_init(ColorSensor* c);

void ColorSensor_update(ColorSensor* c);

void ColorSensor_startUp(ColorSensor* c, uint8_t freq_scale);

void ColorSensor_shutDown(ColorSensor* c);

Color ColorSensor_compute(ColorSensor* c);


