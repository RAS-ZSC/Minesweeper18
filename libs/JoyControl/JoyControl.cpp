#include <JoyControl.h>

JoyControl::JoyControl(HBridge& hbridge) : hbridge(hbridge) {

}

void JoyControl::handle(byte code) {
  switch (state) {
    case 0:
      if (code == 'S')
        ++state;
      break;
    case 1:
      d1.bytes[1] = code;
      ++state;
      break;
    case 2:
      d1.bytes[0] = code;
      ++state;
      break;
    case 3:
      d2.bytes[1] = code;
      ++state;
      break;
    case 4:
      d2.bytes[0] = code;
      state = 0;
      x = d1.value;
      y = d2.value;
      hbridge.move(x, y);
      break;
  }
}
