/**
   rescue_joints.h
**/
#pragma once
#include <Arduino.h>
#include "rescue_globals.h"

typedef struct {
  // Pointer to pin array
  /**
     0 -> direction pin
     1 -> speed pin
   **/
  uint8_t pins[NUM_MOTORS];
  // speed of the joint, (-255,255)
  int speed;
} RescueJoint;

/** Initialize the joint given the pins **/
void RescueJoint_init(uint8_t* pins);

/** Sets the speed of a given joint **/
void RescueJoint_setSpeed(int speed);

