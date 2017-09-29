#include <Mapper.h>

Mapper::Mapper(RotaryEncoder& enc, Compass& com, Ultrasonic& us):
  encoder(enc), compass(com), usonic(us) {

}

void Mapper::updateCoordinates() {
  float distance = encoder.getDistance();
  float angle = (compass.getDegree() * PI) / 180;

  y = y + (distance - lastDistance) * cos(angle);
  x = x + (distance - lastDistance) * sin(angle);

  lastDistance = distance;
}

void Mapper::map(bool m1, bool m2) {
  // TODO
}
