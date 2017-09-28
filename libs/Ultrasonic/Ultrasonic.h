#ifndef _ULTRASONIC_H
#define _ULTRASONIC_H

class Ultrasonic {
private:
  int echo[2], trig[2];
  void outPulse(int);

public:
  Ultrasonic(int, int, int, int);
  int getDistance(int);
};

#endif
