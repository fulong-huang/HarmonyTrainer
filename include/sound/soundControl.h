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

	void start();
	void stop();
	void playSound();
	bool isPlaying();


private:
  SoundControl(const SoundControl &m);
  SoundControl operator=(const SoundControl &m);

	bool playing;

  Notes note1;
  Notes note2;
	Notes note3;

	// Sound
	std::chrono::steady_clock::time_point begin;
	std::chrono::steady_clock::time_point current;

	float waitTime;
	int phase;

	void generateRandomNote();
};


