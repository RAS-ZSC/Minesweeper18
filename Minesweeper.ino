//#include <SoftwareSerial.h>

// Custom Libs
#include <HBridge.h>
#include <MetalDetector.h>
#include <RotaryEncoder.h>
#include <Compass.h>
#include <Ultrasonic.h>
#include <Mapper.h>
#include <RF.h>

//HBridge hbridge(6, 7, 4, 5);
//SoftwareSerial BT(9, 10);
MetalDetector rdetector(10), ldetector(11);
RotaryEncoder encoder;
Compass compass;
Ultrasonic usonic(7, 8, 5, 6);
Mapper mapper(encoder, compass, usonic);

RF radio(49, 48);

void setup() {
  Serial.begin(9600);
  radio.begin();
  compass.begin();
}

void loop() {
}
