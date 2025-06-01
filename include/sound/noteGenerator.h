#pragma once
#include "notes.h"
#include <SFML/Audio.hpp>
#include <iostream>

enum TunningMode{
	EQUAL,
	PYTHAGOREAN,
	JUST,
};

class NoteGenerator {
public:
  NoteGenerator(){
		this->tunningMode = JUST;
	};
  virtual ~NoteGenerator(){};

  virtual void generateRandomNote() = 0;
	virtual void setChords(std::vector<int> chords) = 0;

	virtual void playSelectedChord() = 0;
	virtual bool playValidationNotes() = 0;

	virtual void stopSelectedChord() = 0;
	virtual void stopAllNotes() = 0;

	void setBounds(int lower, int upper){
		this->lowerBound = lower;
		this->upperBound = upper;
	}

protected:
	virtual void cleanupNotes() = 0;
	TunningMode tunningMode;
	int lowerBound = 36;
	int upperBound = 60;

};
