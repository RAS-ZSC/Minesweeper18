#include <SoftwareSerial.h>

// Custom Libs
#include <HBridge.h>
//#include <MetalDetector.h>
//#include <RotaryEncoder.h>
//#include <Compass.h>
//#include <Ultrasonic.h>
//#include <Mapper.h>
//#include <RF.h>
//#include <PosTracker.h>

HBridge hbridge(6, 7, 4, 5, 10, 11);
//SoftwareSerial bluetooth(50, 51);

//MetalDetector rdetector(10), ldetector(11);
//RotaryEncoder encoder(0.025);
//Compass compass;
//Ultrasonic usonic(10, 9);
//Mapper mapper(encoder, compass, usonic);

//RF radio(49, 48);

void setup() {
  Serial.begin(9600);
  //bluetooth.begin(9600);
  //compass.begin();
  //compass.init();
  
  //radio.begin(1);
}

void loop() {
/*
  if (bluetooth.available() > 0) {
    int code = bluetooth.read();

    switch (code) {
      case 0x53: hbridge.stop(); break;
      case 0x46: hbridge.forward(); break;
      case 0x42: hbridge.backward(); break;
      case 0x52: hbridge.right(); break;
      case 0x4C: hbridge.left(); break;
    }

    Serial.println(code, HEX);
  }
*/

  if (Serial.available() > 0) {

  }
}
