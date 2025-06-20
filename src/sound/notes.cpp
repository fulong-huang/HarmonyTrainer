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

Notes::Notes(int noteNumber) {
  this->setNote(noteNumber);
  this->isPlaying = false;
}

double Notes::parseNote(std::string strName) {
  // ASSUME INPUT ARE CORRECT!!!
  int octave = strName[strName.size() - 1] - '0';
	int index;
	if(strName.size() == 3){
		index = NoteIndex.at(strName.substr(0, 2));
	}
	else{
		index = NoteIndex.at(strName.substr(0, 1));
	}

  this->currentPitch = NotePitches[index];
  while (octave > 0) {
    this->currentPitch *= 2;
    octave--;
  };
  return this->currentPitch;
};

double Notes::parseNote(int noteNumber) {
  int octave = noteNumber / 12;
  int idx = noteNumber % 12;

  this->currentPitch = NotePitches[idx];
  while (octave > 0) {
    this->currentPitch *= 2;
    octave--;
  };
  return this->currentPitch;
};

void Notes::setNote(std::string noteName) {
	// Not using double because of the uninvestigated issue:
	// 	When multiple notes playing at the same time, 
	// 	a audible beat starts clicking. 
  this->parseNote(noteName);
  sf::Int16 raw[SAMPLES];
  double increment = this->currentPitch / SAMPLES;
  double x = 0;
  for (unsigned i = 0; i < SAMPLES; i++) {
    raw[i] = AMPLITUDE * sin(x * TWO_PI);
    x += increment;
  };
  if (!this->noteBuffer.loadFromSamples(raw, SAMPLES, 1, SAMPLE_RATE)) {
    std::cerr << "Note Buffer Loading From Samples Failed!!!" << std::endl;
    return;
  };
  this->noteSound.setBuffer(this->noteBuffer);
  this->noteSound.setLoop(true);
};

void Notes::setNote(int noteNumber) {
	// Not using double because of the uninvestigated issue:
	// 	When multiple notes playing at the same time, 
	// 	a audible beat starts clicking. 
  this->parseNote(noteNumber);
  sf::Int16 raw[SAMPLES];
  double increment = this->currentPitch / SAMPLES;
  double x = 0;
  for (unsigned i = 0; i < SAMPLES; i++) {
    raw[i] = AMPLITUDE * sin(x * TWO_PI);
    x += increment;
  };
  if (!this->noteBuffer.loadFromSamples(raw, SAMPLES, 1, SAMPLE_RATE)) {
    std::cerr << "Buffer Loading From Samples Failed!!!" << std::endl;
    return;
  };
  this->noteSound.setBuffer(this->noteBuffer);
  this->noteSound.setLoop(true);
};

void Notes::incrementNote(int halfSteps){
	// TODO: 
	// Increment note by number of half steps
}


void Notes::start() {
  if (this->isPlaying) {
    return;
  }
  this->isPlaying = true;
  this->noteSound.play();
}

void Notes::stop() {
	if(!this->isPlaying){
		return;
	}
	this->noteSound.stop();
	this->isPlaying = false; 
}

void Notes::setPitch(double pitch){
	this->currentPitch = pitch;
  sf::Int16 raw[SAMPLES];
  double increment = this->currentPitch / SAMPLES;
  double x = 0;
  for (unsigned i = 0; i < SAMPLES; i++) {
    raw[i] = AMPLITUDE * sin(x * TWO_PI);
    x += increment;
  };
  if (!this->noteBuffer.loadFromSamples(raw, SAMPLES, 1, SAMPLE_RATE)) {
    std::cerr << "Buffer Loading From Samples Failed!!!" << std::endl;
    return;
  };
  this->noteSound.setBuffer(this->noteBuffer);
  this->noteSound.setLoop(true);
}

double Notes::getPitch(){
	return this->currentPitch;
}

