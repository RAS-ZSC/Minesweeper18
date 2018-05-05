#include <Arduino.h>
#include <RotaryEncoder.h>

static RotaryEncoder *ref = NULL;
static RotaryEncoder *ref2 = NULL;

static void encoderUpdate1(void) {
  if (ref) {
    ref->pos;
    delay(2);
    int A = digitalRead(PIN_INT0);
    int B = digitalRead(PIN_INT1);
    int input = A << 1 | B;
    bool step = true;


    if (input == ref->state)
=======
    if (input == state)

      return;

    int code = ref->state << 2 | input;

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

    ref->state = input;

    if (step && ref->state == 3) {
      ref->dir? ++ref->pos : --ref->pos;
    }
  }
}

static void encoderUpdate2(void) {
  if (ref2) {
    ref2->pos;
    delay(2);
    int A = digitalRead(PIN_INT0);
    int B = digitalRead(PIN_INT1);
    int input = A << 1 | B;
    bool step = true;

    if (input == ref2->state)
=======
    if (input == state)

      return;

    int code = ref2->state << 2 | input;

    switch (code) {
      case 0b0111:
        step = !ref2->dir;
        break;
      case 0b1011:
        step = ref2->dir;
        break;
      case 0b1101:
        ref2->dir = true;
        break;
      case 0b1110:
        ref2->dir = false;
        break;
    }

    ref2->state = input;

    if (step && ref2->state == 3) {
      ref2->dir? ++ref2->pos : --ref2->pos;
    }
  }
}

RotaryEncoder::RotaryEncoder(int id, float mps) : mps(mps) {
  if (id == 0) {
    pinMode(PIN_INT0, INPUT_PULLUP);
    pinMode(PIN_INT1, INPUT_PULLUP);

    attachInterrupt(0, encoderUpdate1, CHANGE);      // interrupt 0 ,1  (2,3)
    attachInterrupt(1, encoderUpdate2, CHANGE);
=======
    attachInterrupt(0, encoderUpdate, CHANGE);
    attachInterrupt(1, encoderUpdate, CHANGE);

    ref = this;
  } else {
    pinMode(PIN_INT2, INPUT_PULLUP);
    pinMode(PIN_INT3, INPUT_PULLUP);

    attachInterrupt(2, encoderUpdate1, CHANGE);      //interrupt 2 ,3  (18,19) or (20,21)
    attachInterrupt(3, encoderUpdate2, CHANGE);
=======
    attachInterrupt(2, encoderUpdate, CHANGE);
    attachInterrupt(3, encoderUpdate, CHANGE);

    ref2 = this;
  }
}

float RotaryEncoder::getDistance() {
  return pos * mps;
}
