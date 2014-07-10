#include <Arduino.h>
#include "FireSequencePlayer.h"

FireSequencePlayer::FireSequencePlayer(FireSequence sequence, unsigned int delay) : _sequence(sequence) {
  _startTime = millis() + delay;
  _noteStates = (uint8_t *) malloc(sequence.numberOfNotes() * sizeof(uint8_t));
  _actualNoteStartTimes = (unsigned int *) malloc(sequence.numberOfNotes() * sizeof(unsigned int));
}

void FireSequencePlayer::play() {
  unsigned long currentSequenceTime = millis() - _startTime;
  while (_nextNoteToStartIndex < _sequence.numberOfNotes() && _sequence.startTime(_nextNoteToStartIndex) >= currentSequenceTime) {
    digitalWrite(_sequence.note(_nextNoteToStartIndex).pin(), HIGH);
    _actualNoteStartTimes[_nextNoteToStartIndex] = currentSequenceTime;
    _nextNoteToStartIndex++;
  }

  int i = 0;
  while (i < _nextNoteToStartIndex && _noteStates[i] != FINISHED_STATE) {
    FireNote note = _sequence.note(i);
    if(note.duration() + _actualNoteStartTimes[i] >= currentSequenceTime) {
      digitalWrite(note.pin(), LOW);
      _noteStates[i] = FINISHED_STATE;
    }
  }
}
