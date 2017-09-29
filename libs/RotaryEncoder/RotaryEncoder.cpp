#include <RotaryEncoder.h>

//#include "Encoder.h"

RotaryEncoder::RotaryEncoder() {
    //enc1 = Encoder(e1p1, e1p2);
    //enc2 = Encoder(e2p1, e2p2);
    lastDistance = 0;
    oldPosition  = -999;
    oldPosition2 = -999;
    //encoderMes = mes;
}

float RotaryEncoder::getDistance() {
  long newPosition = 0; //enc1.read();
  long newPosition2 = 0; //enc2.read();
  oldPosition = newPosition;
  oldPosition2 = newPosition2;
  long realPos = (newPosition + newPosition2) / 2;
  return realPos * encoderMes;
}
