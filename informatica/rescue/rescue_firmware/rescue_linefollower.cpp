/**
   rescue_linefollower.cpp
**/

#include "rescue_linefollower.h"

/** Initialize the LineFollower **/
void LineFollower_init() {
#ifdef _DEBUG_
  Serial.println(F("Initializing Pixy2"));
#endif
  
  pixy.init();
  
#ifdef _DEBUG_
  Serial.println(pixy.changeProg("line"));
#else
  pixy.changeProg("line");
#endif
  return;
}

/** Update the LineFollower by updating Pixy data **/
void LineFollower_update() {
  pixy.line.getMainFeatures();
  return;
}

/** Extracts the line vector angle from Pixy data **/
int LineFollower_getVectorAngle() {
  return 0;
}
