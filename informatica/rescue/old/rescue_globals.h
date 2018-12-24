/**
   rescue_globals.h
**/
#pragma once
#include <Arduino.h>
#include "rescue_params.h"
#include "rescue_joints.h"
#include "rescue_bumper.h"
#include "rescue_linefollower.h"
#include "rescue_colorsensor.h"

/** Pixy2 object **/
//extern Pixy2 pixy;

/** motori **/
extern RescueMotor motori[NUM_MOTORS];

/** bumper **/
extern RescueBumper bumpers[NUM_BUMPERS];

/** line sensors **/
extern LineDetector line_detectors[NUM_DETECTORS];
extern LineSensor line_sensor;

/** color sensors **/
extern ColorSensor color_sensors[NUM_COLOR_SENSORS];
