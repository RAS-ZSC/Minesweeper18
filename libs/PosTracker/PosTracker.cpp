#include <Arduino.h>
#include <EEPROM.h>
#include <PosTracker.h>

void PosTracker::savePos(float val, int first, int last) {
  float value = abs(val);
  for (first; first <= last; first++)
  {
    if (value >= 255)
      EEPROM.write(first , 255);
    else if (value > 0 && value < 255)
      EEPROM.write(first, value);
    else
      EEPROM.write(first, 0);
    value = value - 255;
  }
  if (val < 0)
    EEPROM.write(last + 1, 1);
  else
    EEPROM.write(last + 1, 0);

}

float PosTracker::findPos(int first, int last) {
  float pos = 0;
  for ( first ; first <= last ; first++) {
    pos = pos + EEPROM.read(first);
  }
  if (EEPROM.read(last + 1))
    pos = pos * (-1);
  return pos;
}

void PosTracker::clear() {
  for (int i = 0; i < 100; ++i)
    EEPROM.write(i, 0);
}
