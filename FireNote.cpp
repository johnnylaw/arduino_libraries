#include <Arduino.h>
#include "FireNote.h"

#define FIRE_CANNON_MAX_DURATION 3000

FireNote::FireNote(unsigned int pin, unsigned int duration) : _pin(pin) {
  _duration = min(duration, FIRE_CANNON_MAX_DURATION);
}

unsigned int FireNote::pin() {
  return _pin;
}

unsigned int FireNote::duration() {
  return _duration;
}