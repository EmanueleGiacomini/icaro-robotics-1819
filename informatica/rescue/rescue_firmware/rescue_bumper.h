/**
   rescue_bumper.h
**/

typedef struct {
  uint8_t pin;
  uint8_t state;
} RescueBumper;

void RescueBumper_init(RescueBumper* bumper);

int RescueBumper_getState(RescueBumper* bumper);

// TODO: Implementare soluzione con interrupt
