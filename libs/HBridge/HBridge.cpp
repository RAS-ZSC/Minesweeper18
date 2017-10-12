#include <Arduino.h>
#include <HBridge.h>

HBridge::HBridge(int lm1, int lm2, int rm1, int rm2, int pwm1, int pwm2) {
  this->m1 = lm1;
  this->m2 = lm2;
  this->m3 = rm3;
  this->m4 = rm4;
  this->pwm1 = pwm1;
  this->pwm2 = pwm2;

  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);

  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
}

void HBridge::moving(boolean m1, boolean m2, boolean m3, boolean m4, unsigned pwm1, unsigned pwm2) {
  digitalWrite(this->m1, m1);
  digitalWrite(this->m2, m2);
  digitalWrite(this->m3, m3);
  digitalWrite(this->m4, m4);

  analogWrite(this->pwm1, pwm1);
  analogWrite(this->pwm2, pwm2);
}

void HBridge::move(int left, int right) {
  if (left < 0)
    if (right < 0)
      moving(1, 0, 1, 0, -left, -right);
    else
      moving(1, 0, 0, 1, -left, right);
  else
    if (right < 0)
      moving(0, 1, 1, 0, left, -right);
    else
      moving(0, 1, 0, 1, left, right);
  }
}

#if 0
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
#endif
