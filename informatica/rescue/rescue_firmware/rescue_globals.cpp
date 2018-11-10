/**
   rescue_globals.cpp
**/

#include "rescue_globals.h"
#include "rescue_joints.h"

#ifdef __cplusplus
extern "C" {
#endif
  
  RescueJoint joints[NUM_MOTORS] =
    {
      {// Joint 0
        .pins =
        {
          10,
          11
        },
        .speed=0
      },
      {// Joint 1
        .pins =
        {
          12,
          13
        },
        .speed=0
      }
    };

#ifdef __cplusplus
}
#endif
