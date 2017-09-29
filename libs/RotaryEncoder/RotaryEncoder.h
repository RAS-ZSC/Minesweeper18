#ifndef _ROTARY_ENCODER_H
#define _ROTARY_ENCODER_H

class RotaryEncoder {
private:
  //Encoder enc1, enc2;
  float lastDistance, encoderMes;
  long oldPosition, oldPosition2;

public:
  RotaryEncoder();
  float getDistance();
};

#endif
