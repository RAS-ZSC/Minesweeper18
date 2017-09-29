#ifndef _COMPASS_H
#define _COMPASS_H

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>

class Compass:  Adafruit_HMC5883_Unified {
  float H = 0, H2 = 0, headingDegrees, headingDegrees2, degree;
public:
  Compass();
  void begin();
  void init();
  float getDegree();
};

#endif
