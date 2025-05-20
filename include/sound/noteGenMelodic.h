#pragma once
#include "noteGenerator.h"
#include <SFML/Audio.hpp>
#include <iostream>

class NoteGenMelodic : public NoteGenerator {
public:
  NoteGenMelodic();
  ~NoteGenMelodic() override;

  void generateRandomNote() override;

	void playSelectedChord() override;
	bool playValidationNotes() override;

	void stopSelectedChord() override;
	void stopAllNotes() override;

	void setChords(std::vector<int> chords) override;

private:
  NoteGenMelodic(const NoteGenMelodic &n);
  NoteGenMelodic operator=(const NoteGenMelodic &n);

	void cleanupNotes() override;

	std::vector<Notes*> harmonicNotes;
	std::vector<Notes*> melodicNotes;

	std::vector<int> chordChoices;
	int endingNoteIndex;
	int currentNoteIndex;

};
