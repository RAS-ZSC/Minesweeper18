#include <Arduino.h>
#include <MetalDetector.h>

MetalDetector::MetalDetector(int pin) {
  this->pin = pin;
  pinMode(pin, INPUT);
}

int MetalDetector::detect() {
  return digitalRead(pin);
}
