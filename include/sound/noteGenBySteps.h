#pragma once
#include "noteGenerator.h"
#include <SFML/Audio.hpp>
#include <iostream>

class NoteGenBySteps : public NoteGenerator {
public:
  NoteGenBySteps();
  ~NoteGenBySteps() override;

  void generateRandomNote(std::vector<Notes *> &harmonyNotes,
                          std::vector<Notes *> &melodyNotes,
                          std::vector<int> harmonyGaps,
													int lowerBound = 36, int upperBound = 60) override;

private:
  NoteGenBySteps(const NoteGenBySteps &n);
  NoteGenBySteps operator=(const NoteGenBySteps &n);
};
