/**
   rescue_globals.cpp
**/

#include "rescue_globals.h"
#include "rescue_pins.h"
#include "rescue_joints.h"

#ifdef __cplusplus  //compilazione condizionale
extern "C" {
#endif
  
  RescueJoint joints[NUM_MOTORS] =
    {
      {// Joint 0
        .pins =
        {
          JOINT_1_DIR_PIN,
          JOINT_1_PWM_PIN
        },
        .speed=0
      },
      {// Joint 1
        .pins =
        {
          JOINT_2_DIR_PIN,
          JOINT_2_PWM_PIN
        },
        .speed=0
      }
    };

#ifdef __cplusplus
}
#endif
