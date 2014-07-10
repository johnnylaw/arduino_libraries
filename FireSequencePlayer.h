#pragma once

#include "FireSequence.h"

#define UNFINISHED_STATE 0
#define FINISHED_STATE 1

class FireSequencePlayer {
  public:
    FireSequencePlayer(FireSequence sequence, unsigned int delay);

  private:
    FireSequence _sequence;
    unsigned int _startTime;
    uint8_t *_noteStates;
    unsigned int *_actualNoteStartTimes;
    unsigned int _nextNoteToStartIndex;

  public:
    void play();
};