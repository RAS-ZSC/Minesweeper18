#ifndef _ROTARY_ENCODER_H
#define _ROTARY_ENCODER_H

#define PIN_INT0  2
#define PIN_INT1  3
class RotaryEncoder {
private:
  int state = 3;
  float mps;

public:
  long pos = 0;
  bool dir = true;
  RotaryEncoder(float);
  float getDistance();
};

#endif
