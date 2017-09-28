#include <Arduino.h>
#include <Ultrasonic.h>

Ultrasonic::Ultrasonic(int e0, int e1, int t0, int t1) {
  this->echo[0] = e0;
  this->echo[1] = e1;
  this->trig[0] = t0;
  this->trig[1] = t1;

  pinMode(e0, INPUT);
  pinMode(t0, OUTPUT);
  pinMode(e1, INPUT);
  pinMode(t1, OUTPUT);
}

void Ultrasonic::outPulse(int trig) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2); 
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
}

int Ultrasonic::getDistance(int channel) {
  outPulse(trig[channel]);
  double time = pulseIn(echo[channel], HIGH);
  double distance = time / 29 / 2;

  return distance == 0 ? 1000 : distance;
}
