/**
 * pid.cpp
 **/

#include "pid.h"

int16_t clamp(int16_t v, int16_t m) {
  if(v>m)
    return m;
  if(v<-m)
    return -m;
  return v;
}

void PIDController_init(PIDController* c, int16_t* input) {
  c->input=input;
  c->error=0;
  c->error_integral=0;
  c->previous_error=0;
}

void PIDController_handle(PIDController*c) {
  c->error=clamp(c->set_point-*(c->input), c->slope);
  // ramp magic stuff :)
  c->ramp_reference=c->input+c->error;

  // integral term
  c->error_integral+=c->error;
  c->error_integral=clamp(c->error_integral, c->max_i);
  // derivative term
  int16_t d_error=(c->error-c->previous_error);

  c->output=c->ramp_reference+(c->kp*c->error
                               +c->ki*c->error_integral
                               +c->kd*d_error);
  
  c->output=clamp(c->output, c->max_output);
  c->previous_error=c->error;
}

int16_t PIDController_getOutput(PIDController* c) {
  return c->output;
}
