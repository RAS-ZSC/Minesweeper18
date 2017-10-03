#ifndef _COMPASS_H
#define _COMPASS_H

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>

class Compass:  Adafruit_HMC5883_Unified {
private:
  float preHeading = 0, headingDegrees, degree;
public:
  Compass();
  void begin();
  void init();
  float getDegree();
  float *getField();
};

#endif
