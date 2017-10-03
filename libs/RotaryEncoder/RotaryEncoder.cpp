#include <Arduino.h>
#include <RotaryEncoder.h>

static RotaryEncoder *ref = NULL;

int state = 3, pos = 0;
bool dir = true;

static void encoderUpdate(void) {
  if (ref) {
    ref->pos;
    delay(2);
    int A = digitalRead(PIN_INT0);
    int B = digitalRead(PIN_INT1);
    int input = A << 1 | B;
    bool step = true;

    if (input == state)
      return;

    int code = state << 2 | input;

    switch (code) {
      case 0b0111:
        step = !ref->dir;
        break;
      case 0b1011:
        step = ref->dir;
        break;
      case 0b1101:
        ref->dir = true;
        break;
      case 0b1110:
        ref->dir = false;
        break;
    }

    state = input;

    if (step && state == 3) {
      ref->dir? ++ref->pos : --ref->pos;
    }
  }
}

RotaryEncoder::RotaryEncoder(float mps) : mps(mps) {
  pinMode(PIN_INT0, INPUT_PULLUP);
  pinMode(PIN_INT1, INPUT_PULLUP);
  attachInterrupt(0, encoderUpdate, CHANGE);
  attachInterrupt(1, encoderUpdate, CHANGE);
  ref = this;
}

float RotaryEncoder::getDistance() {
  return pos * mps;
}
