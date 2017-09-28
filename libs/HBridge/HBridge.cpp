#include <Arduino.h>
#include <HBridge.h>

HBridge::HBridge(int m1, int m2, int m3, int m4) {
  this->m1 = m1;
  this->m2 = m2;
  this->m3 = m3;
  this->m4 = m4;

  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
}

void HBridge::moving(boolean m1, boolean m2, boolean m3, boolean m4) {
  digitalWrite(this->m1, m1);
  digitalWrite(this->m2, m2);
  digitalWrite(this->m3, m3);
  digitalWrite(this->m4, m4);
}

void HBridge::forward() {
  moving(0, 1, 1, 0);
}

void HBridge::backward() {
  moving(1, 0, 0, 1);
}

void HBridge::left() {
  moving(0, 1, 0, 1);
}

void HBridge::right() {
  moving(1, 0, 1, 0);
}

void HBridge::stop() {
  moving(0, 0, 0, 0);
}
