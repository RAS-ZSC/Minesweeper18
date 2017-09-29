#include <Compass.h>

Compass::Compass(): Adafruit_HMC5883_Unified(12345) {
  
}

void Compass::begin() {
  if (!Adafruit_HMC5883_Unified::begin()) { // to make sure that the connection is right 
    Serial.println("Ooops, no HMC5883 detected ... Check your wiring!");
    while (1);
  }
}

float Compass::getDegree() {
  sensors_event_t event;
  getEvent(&event);

  float heading  = atan2(event.magnetic.x, event.magnetic.z);
  float heading2 = atan2(event.magnetic.y, event.magnetic.x);

  float declinationAngle = 0.22;
  heading  += declinationAngle;
  heading2 += declinationAngle;  

  if (heading < 0)
    heading += 2 * PI;
  if (heading > 2 * PI)
    heading -= 2 * PI;

  if (heading2 < 0)
    heading2 += 2 * PI;
  if (heading2 > 2 * PI)
    heading2 -= 2 * PI;
    
  headingDegrees = heading * 180 / M_PI;
  headingDegrees2 = heading2 * 180 / M_PI;
  float s = 2.3;
  degree = ((H + headingDegrees) + ((H2 + headingDegrees2) / s));

  if (degree < 0)
    degree += 2 * 180;
  if (degree > 2 * 180)
    degree -= 2 * 180;

  return degree;
}

void Compass::init() {
  getDegree();
  H = -headingDegrees;
  H2 = -headingDegrees2;
}
