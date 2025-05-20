#pragma once
#include "noteGenerator.h"
#include <SFML/Audio.hpp>
#include <iostream>

class NoteGenHarmonic : public NoteGenerator {
public:
  NoteGenHarmonic();
  ~NoteGenHarmonic() override;

  void generateRandomNote() override;

	void playSelectedChord() override;
	bool playValidationNotes() override;

	void stopSelectedChord() override;
	void stopAllNotes() override;

	void setChords(std::vector<int> chords) override;

private:
  NoteGenHarmonic(const NoteGenHarmonic &n);
  NoteGenHarmonic operator=(const NoteGenHarmonic &n);

	void cleanupNotes() override;

	std::vector<int> chordChoices;
	std::vector<Notes*> chordNotes;
	Notes* rootNote = NULL;

	int chosenIndex, currentNoteIndex;
};

