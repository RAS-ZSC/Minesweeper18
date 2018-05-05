#include <Arduino.h>
#include <Ultrasonic.h>

Ultrasonic::Ultrasonic(int echo, int trig) : echo(echo), trig(trig) {
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
}

long Ultrasonic::getDistance() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2); 
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);
  long time = pulseIn(echo, HIGH, 38000);
  double distance = 340.0 * time / 2000;
  return distance == 0 ? 1000 : distance;
}
