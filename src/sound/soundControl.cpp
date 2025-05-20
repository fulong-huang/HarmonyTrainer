#include "soundControl.h"

SoundControl::SoundControl() {
  this->playing = false;

  // Set random seed as current time
  // 	to generate different number each time program ran
  srand(time(NULL));

  harmonyDuration = answerWaitTime = newQuestionWaitTime = 2;
  melodyDuration = 1;
  phase = 0;

  this->harmonyGaps = {3, 7};
}

SoundControl::~SoundControl() {
	if(this->noteGenerator){
		delete this->noteGenerator;
	}
}

void SoundControl::trigger() {
  if (this->playing) {
    this->stop();
  } else {
    this->start();
  }
}

void SoundControl::start() {
	if(!this->noteGenerator){
		std::cerr << "Note Generator Failed to Load" << std::endl;
		this->noteGenerator = new NoteGenHarmonic();
		this->noteGenerator->setChords({3, 5});
	}
  this->playing = true;
  this->begin = std::chrono::steady_clock::now();
  phase = 0;
  this->currWaitTime = 0;
  // this->currWaitTime = harmonyDuration;
}
void SoundControl::stop() {
  this->playing = false;
	this->noteGenerator->stopAllNotes();
}

bool SoundControl::isPlaying() { return this->playing; }

void SoundControl::playSound() {
  if (this->playing) {
    this->current = std::chrono::steady_clock::now();
    float timePassed = std::chrono::duration_cast<std::chrono::microseconds>(
                           this->current - this->begin)
                           .count() /
                       1000000.0;
    if (timePassed > this->currWaitTime) {
      switch (this->phase) {
      case 0:
				// TODO: 
				//  Generate randomw note is slow
        this->noteGenerator->generateRandomNote();
				this->noteGenerator->playSelectedChord();
        this->currWaitTime = this->harmonyDuration;
        this->phase = 1;
        break;
      case 1:
				this->noteGenerator->stopSelectedChord();
        this->currWaitTime = this->answerWaitTime;
        this->phase = 2;
        break;
      case 2:
				if(this->noteGenerator->playValidationNotes()){
					this->currWaitTime = this->melodyDuration;
				}
				else{
					this->phase = 0;
					this->currWaitTime = this->newQuestionWaitTime;
				}
        break;
//       case 3:
//         this->phase = 0;
//         break;
      }
		this->begin = std::chrono::steady_clock::now();
    }
  }
}

void SoundControl::setSoundControl(TrainingSettings* setting){
	if(setting->playBackMode == MELODIC){
		this->noteGenerator = new NoteGenMelodic();
	}
	else{
		this->noteGenerator = new NoteGenHarmonic();
	}
	this->noteGenerator->setChords(setting->chordChoice);
	this->noteUpperBound = setting->chordRange[0];
	this->noteLowerBound = setting->chordRange[1];
	this->answerWaitTime = setting->waitTime;
	this->harmonyDuration = setting->harmonicDuration;
	this->melodyDuration = setting->melodicDuration;
	this->newQuestionWaitTime = setting->newQuestionWaitTime;
}

