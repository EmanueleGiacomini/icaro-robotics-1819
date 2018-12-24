/**
   rescue_globals.cpp
**/

#include "rescue_globals.h"
#include "rescue_pins.h"

RescueMotor motori[NUM_MOTORS] = {
  {// motore 0
  pin_dir : JOINT_0_DIR_PIN,
  pin_pwm : JOINT_0_PWM_PIN,
  velocita : 0,
  direzione : 0
  },
  {// motore 1
  pin_dir : JOINT_1_DIR_PIN,
  pin_pwm : JOINT_1_PWM_PIN,
  velocita : 0,
  direzione : 0
  }
};

RescueBumper bumpers[NUM_BUMPERS] = {
  {// bumper 0
  pin : BUMPER_0_PIN,
  misura : 0,
  stato : 0
  },
  {// bumper 1
  pin : BUMPER_1_PIN,
  misura : 0,
  stato : 0
  }
};

LineDetector line_detectors[NUM_DETECTORS] = {
  {// linedetector 0
  pin : LDETECTOR_0_PIN,
  misura : 0,
  misura_minima : 0,
  misura_massima : 0,
  soglia : 0,
  stato : 0
  },
  {// linedetector 1
  pin : LDETECTOR_1_PIN,
  misura : 0,
  misura_minima : 0,
  misura_massima : 0,
  soglia : 0,
  stato : 0
  },
  {// linedetector 2
  pin : LDETECTOR_2_PIN,
  misura : 0,
  misura_minima : 0,
  misura_massima : 0,
  soglia : 0,
  stato : 0
  }
};

LineSensor line_sensor = {
 detectors : line_detectors,
 detector_valore : {-2, 0, 2},
 offset_linea : 0,
 stato : 0
};







