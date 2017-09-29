#include <SoftwareSerial.h>

// Custom Libs
#include <HBridge.h>
#include <RF.h>

HBridge hbridge(6, 7, 4, 5);
SoftwareSerial BT(9, 10);

void setup() {
}

void loop() {
#ifdef BLUTOOTH_COMMUNICATION
  if (BT.available() > 0) {
    int data = BT.read();
    switch (data) {
      case 70: hbridge.forward(); break;
      case 66: hbridge.backward(); break;
      case 76: hbridge.left(); break;
      case 82: hbridge.right(); break;
      defualt: hbridge.stop();
    }
  }
#endif
}
