#ifndef _ROTARY_ENCODER_H
#define _ROTARY_ENCODER_H

#if 0
#include <Encoder.h>
class RotaryEncoder {
private:
  Encoder enc1, enc2;
  float lastDistance, encoderMes;
  long oldPosition, oldPosition2;
public:
  RotaryEncoder(uint8_t, uint8_t, uint8_t, uint8_t, float);
  float getDistance();
};
#endif

#endif
