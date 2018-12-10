/**
   rescue_globals.h
**/
#pragma once
#include <Arduino.h>
#include <Pixy2.h>

/** Uncomment to set debug mode on...
    this will print debug messages on the serial interface **/
//#define _DEBUG_ 1

#define NUM_MOTORS 2

#define NUM_DETECTORS 3

/** Pixy2 object **/
extern Pixy2 pixy;

