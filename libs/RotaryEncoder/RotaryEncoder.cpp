#if 0
#include <RotaryEncoder.h>

#include "Encoder.h"

// Yes, all the code is in the header file, to provide the user
// configure options with #define (before they include it), and
// to facilitate some crafty optimizations!

Encoder_internal_state_t * Encoder::interruptArgs[];

RotaryEncoder::RotaryEncoder(uint8_t e1p1, uint8_t e1p2, uint8_t e2p1, uint8_t e2p2, float mes) {
    enc1 = Encoder(e1p1, e1p2);
    enc2 = Encoder(e2p1, e2p2);
    lastDistance = 0;
    oldPosition  = -999;
    oldPosition2 = -999;
    encoderMes = mes;
}

float RotaryEncoder::getDistance() {
  long newPosition = enc1.read();
  long newPosition2 = enc2.read();
  oldPosition = newPosition;
  oldPosition2 = newPosition2;
  long realPos = (newPosition + newPosition2) / 2;
  return realPos * encoderMes;
}
#endif
