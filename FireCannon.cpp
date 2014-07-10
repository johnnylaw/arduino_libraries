#include <Arduino.h>
#include "FireCannon.h"

FireCannon::FireCannon(unsigned int pin) : _pin(pin), _state(LOW) {
  pinMode(pin, OUTPUT);
}

void FireCannon::fire() {
  digitalWrite(_pin, HIGH);
  _state = HIGH;
}

void FireCannon::kill() {
  digitalWrite(_pin, LOW);
  _state = LOW;
}

bool FireCannon::isOn() {
  return _state == HIGH;
}