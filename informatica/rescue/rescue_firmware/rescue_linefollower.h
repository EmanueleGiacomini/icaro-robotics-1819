/**
   rescue_linefollower.h
**/

#pragma once
#include <Arduino.h>
#include "rescue_globals.h"
//#include <Pixy2.h>

/** Initialize the LineFollower **/
void LineFollower_init();

/** Update the LineFollower by updating Pixy data **/
void LineFollower_update();

/** Extracts the line vector angle from Pixy data **/
int LineFollower_getVectorAngle();
