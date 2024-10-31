#include "notes.h"

#include <cmath>

Notes::Notes() {
  this->setNote("A3");
  this->isPlaying = false;
}

Notes::Notes(const std::string& note) {
  this->setNote(note);
  this->isPlaying = false;
}

int Notes::parseNote(std::string strName) {
  // ASSUME INPUT ARE CORRECT!!!
  int octave = strName[strName.size() - 1] - '0';

  int idx = strName[0] - 'A';
  if (strName.size() == 3) {
    switch (strName[0]) {
    case 'A':
      idx += 7;
      break;
    case 'C':
    case 'D':
      idx += 6;
      break;
    default:
      idx += 5;
    };
  };

  NoteName noteName = static_cast<NoteName>(idx);
  float pitch = pitches.at(noteName);
  while (octave > 0) {
    pitch *= 2;
    octave--;
  };
  std::cout << pitch << std::endl;
  return pitch;
};

void Notes::setNote(std::string noteName) {
  int pitch = this->parseNote(noteName);
  sf::Int16 raw[SAMPLES];
  double increment = (float)pitch / SAMPLES;
  double x = 0;
  for (unsigned i = 0; i < SAMPLES; i++) {
    raw[i] = AMPLITUDE * sin(x * TWO_PI);
    x += increment;
  };
  if (!this->noteBuffer.loadFromSamples(raw, SAMPLES, 1, SAMPLE_RATE)) {
    std::cout << "Loading From Samples Failed!!!" << std::endl;
    return;
  };
  this->noteSound.setBuffer(this->noteBuffer);
  this->noteSound.setLoop(true);
};


void Notes::start() {
  if (this->isPlaying) {
    return;
  }
  this->isPlaying = true;
  this->noteSound.play();
  std::cout << "Is playing: " << this->isPlaying << std::endl;
}

void Notes::stop() {
	this->noteSound.stop();
	this->isPlaying = false; 
	std::cout << "Stop Playing" << std::endl;
}

