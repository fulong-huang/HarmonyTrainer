#pragma once
#include "notes.h"
#include <SFML/Audio.hpp>
#include <iostream>

class NoteGenerator {
public:
  NoteGenerator(){};
  virtual ~NoteGenerator(){};

  virtual void generateRandomNote(std::vector<Notes *> &harmonyNotes,
                                  std::vector<Notes *> &melodyNotes,
                                  std::vector<int> harmonyGaps,
                                  int lowerBound = 36, int upperBound = 60) = 0;

};
