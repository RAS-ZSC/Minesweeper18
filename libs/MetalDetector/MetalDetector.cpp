#include <Arduino.h>
#include <MetalDetector.h>

MetalDetector::MetalDetector(int pin) {
  this->pin = pin;
  pinMode(pin, OUTPUT);
}

int MetalDetector::detect() {
  return digitalRead(pin);
}
