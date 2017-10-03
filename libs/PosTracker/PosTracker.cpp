#include <Arduino.h>
#include <EEPROM.h>
#include <PosTracker.h>

// Store floats
union float_t {
  float f;
  byte b[4];
} __attribute__((packed));

void PosTracker::savePos(int idx, float val) {
  float_t v = {.f = val};
  EEPROM.write(idx*4+0 , v.b[0]);
  EEPROM.write(idx*4+1 , v.b[1]);
  EEPROM.write(idx*4+2 , v.b[2]);
  EEPROM.write(idx*4+3 , v.b[3]);
}

float PosTracker::findPos(int idx) {
  float_t v;
  v.b[0] = EEPROM.read(idx*4+0);
  v.b[1] = EEPROM.read(idx*4+1);
  v.b[2] = EEPROM.read(idx*4+2);
  v.b[3] = EEPROM.read(idx*4+3);
  return v.f;
}

void PosTracker::clear() {
  for (int i = 0; i < EEPROM.length(); ++i)
    EEPROM.write(i, 0);
}
