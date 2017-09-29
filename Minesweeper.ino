//#include <SoftwareSerial.h>

// Custom Libs
#include <HBridge.h>
#include <RF.h>
#include <MetalDetector.h>
#include <Ultrasonic.h>
#include <Compass.h>

//HBridge hbridge(6, 7, 4, 5);
//SoftwareSerial BT(9, 10);
MetalDetector rdetector(10), ldetector(11);
Ultrasonic usonic(7, 8, 5, 6);
RF radio(49, 48);
Compass compass;

void setup() {
  Serial.begin(9600);
  radio.begin();
  compass.begin();
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
  /* TODO: Calibrate Coordinates */
}
