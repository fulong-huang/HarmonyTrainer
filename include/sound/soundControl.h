#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <chrono>
#include <ctime>

#include "notes.h"

class SoundControl {
public:
  SoundControl();
  ~SoundControl();

	void trigger();
	void playSound();

	void start();
	void stop();
	bool isPlaying();


private:
  SoundControl(const SoundControl &m);
  SoundControl operator=(const SoundControl &m);

	bool playing;

	std::chrono::steady_clock::time_point begin;
	std::chrono::steady_clock::time_point current;

	std::vector<Notes*> harmonyNotes;
	std::vector<Notes*> melodyNotes;

	std::vector<int> harmonyGaps;

	float harmonyDuration, answerWaitTime, melodyDuration, newQuestionWaitTime;
	int phase, noteIndex;
	int currWaitTime;

	void generateRandomNote();
	void cleanUpNotes();
};


