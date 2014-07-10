#pragma once

class FireNote {
public:
  FireNote(unsigned int pin, unsigned int duration);

private:
  unsigned int _pin;
  unsigned int _duration;

public:
  unsigned int pin();
  unsigned int duration();
};