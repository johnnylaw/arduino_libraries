#pragma once

class FireCannon {
public:
  FireCannon(unsigned int pin);

private:
  unsigned int _pin;
  bool _state;

public:
  void fire();
  void kill();
  bool isOn();
};