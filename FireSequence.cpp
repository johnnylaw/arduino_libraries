#include <Arduino.h>
#include "FireSequence.h"

FireSequence::FireSequence(int numberOfNotes) : _numberOfNotes(numberOfNotes), _noteIndex(0) {
  _notes = (FireNote *) malloc(numberOfNotes * sizeof(FireNote));
  _startTimes = (unsigned int *) malloc(numberOfNotes * sizeof(unsigned int));
}

FireSequence::~FireSequence() {
  free (_notes);
  free (_startTimes);
}

void FireSequence::addNote(FireNote note) {
  if (_noteIndex < _numberOfNotes) {
    _notes[_noteIndex] = note;
    _noteIndex++;
  }
}

int FireSequence::numberOfNotes() {
  return _numberOfNotes;
}

FireNote FireSequence::note(int index) {
  return _notes[index];
}

unsigned int FireSequence::startTime(int index) {
  return _startTimes[index];
}