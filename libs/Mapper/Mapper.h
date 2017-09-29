#ifndef _MAPPER_H
#define _MAPPER_H

#include <RotaryEncoder.h>
#include <Compass.h>
#include <Ultrasonic.h>

class Mapper {
private:
  int x = 0, y = 0;
  float lastDistance = 0;

  RotaryEncoder &encoder;
  Compass &compass;
  Ultrasonic &usonic;

public:
  Mapper(RotaryEncoder&, Compass&, Ultrasonic&);
  void updateCoordinates();
  void map(bool, bool);
};

#endif
