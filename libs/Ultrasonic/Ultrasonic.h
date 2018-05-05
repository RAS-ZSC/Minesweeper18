#ifndef _ULTRASONIC_H
#define _ULTRASONIC_H

class Ultrasonic {
private:
  int echo, trig;

public:
  Ultrasonic(int, int);
  long getDistance();
};

#endif
