/**
 * pid.h
 **/

#pragma once

#include <Arduino.h>

typedef struct {
  float kp;
  float ki;
  float kd;

  int16_t max_output;
  int16_t max_i;
  int16_t slope;

  int16_t ramp_reference;

  int16_t* input;
  int16_t set_point;
  int16_t output;
  int16_t error;
  int16_t error_integral;
  int16_t previous_error;
}PIDController;

void PIDController_init(PIDController* c, int16_t* input);

void PIDController_handle(PIDController*c);
