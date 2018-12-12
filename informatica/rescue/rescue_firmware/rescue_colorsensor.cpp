/**
   rescue_colorsensor.cpp
**/

#include "rescue_colorsensor.h"
#include <Arduino.h>

/** inizializza il sensore impostando i pin s0-..-s3 e azzerando misura **/
void ColorSensor_init(ColorSensor* c) {
  pinMode(c->pin_s0, OUTPUT);
  pinMode(c->pin_s1, OUTPUT);
  pinMode(c->pin_s2, OUTPUT);
  pinMode(c->pin_s3, OUTPUT);
  pinMode(c->pin_misura, INPUT);

  c->s0=0;
  c->s1=0;
  c->s2=0;
  c->s3=0;

  c->r_chn=0;
  c->g_chn=0;
  c->b_chn=0;

  c->colore_stimato=NotClear;
}

void ColorSensor_update(ColorSensor* c) {
  digitalWrite(c->pin_s0, c->s0);
  digitalWrite(c->pin_s1, c->s1);
  digitalWrite(c->pin_s2, c->s2);
  digitalWrite(c->pin_s3, c->s3);

  // inseriamo il timeout x evitare di intoppare il programma
  c->misura = pulseIn(c->pin_misura, LOW, TIMEOUT_US);
}

void ColorSensor_startUp(ColorSensor* c, uint8_t freq_scale) {
  switch(freq_scale) {
  case FREQ_SCALE_2:
    c->s0=0;
    c->s1=1;
    break;
  case FREQ_SCALE_20:
    c->s0=1;
    c->s1=0;
    break;
  case FREQ_SCALE_100:
    c->s0=1;
    c->s1=1;
    break;
  }
}

void ColorSensor_shutDown(ColorSensor* c) {
  c->s0=0;
  c->s1=1;
}

Colore ColorSensor_compute(ColorSensor* c) {
  uint16_t colore_misurato=0;
  // calcolo rosso
  c->s2=0;
  c->s3=0;
  ColorSensor_update(c);
  c->r_chn=c->misura;
  // calcolo verde
  c->s2=1;
  c->s3=1;
  ColorSensor_update(c);
  c->g_chn=c->misura;
  // calcolo blu
  c->s2=0;
  c->s3=1;
  ColorSensor_update(c);
  c->b_chn=c->misura;
}

