#pragma once

#include "FireNote.h"

class FireSequence {
  public:
    FireSequence(int numberOfNotes);
    ~FireSequence();

  private:
    FireNote *_notes;
    unsigned int *_startTimes;
    unsigned int _noteIndex;
    int _numberOfNotes;

  public:
    void addNote(FireNote note);
    int numberOfNotes();
    FireNote note(int index);
    unsigned int startTime(int index);
};