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
	this->cleanUpNotes();
}

void SoundControl::cleanUpNotes() {
  for (Notes *note : this->melodyNotes) {
    note->stop();
    delete note;
  }
  this->melodyNotes.clear();
  this->harmonyNotes.clear();
	std::cout << "STOPPING" << std::endl;
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
		this->noteGenerator = new NoteGenBySteps();
	}
  this->playing = true;
  this->begin = std::chrono::steady_clock::now();
  phase = 0;
  this->currWaitTime = 0;
  this->noteIndex = 0;
  // this->currWaitTime = harmonyDuration;
}
void SoundControl::stop() {
  this->playing = false;
	this->cleanUpNotes();
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
        this->noteGenerator->generateRandomNote(
						this->harmonyNotes,
						this->melodyNotes,
						this->harmonyGaps,
						this->noteUpperBound,
						this->noteLowerBound
						);
        this->harmonyNotes[0]->start();
        this->harmonyNotes[1]->start();
        this->currWaitTime = this->harmonyDuration;
        this->phase = 1;
        break;
      case 1:
        this->harmonyNotes[0]->stop();
        this->harmonyNotes[1]->stop();
        this->currWaitTime = this->answerWaitTime;
        this->phase = 2;
        break;
      case 2:
        this->currWaitTime = this->melodyDuration;
        if (this->noteIndex > 0) {
          this->melodyNotes[this->noteIndex - 1]->stop();
        }
        if (this->noteIndex < this->melodyNotes.size()) {
          this->melodyNotes[this->noteIndex]->start();
          this->noteIndex++;
        } else {
          this->phase = 0;
          this->noteIndex = 0;
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
	this->noteUpperBound = setting->chordRange[0];
	this->noteLowerBound = setting->chordRange[1];
	this->answerWaitTime = setting->waitTime;
	this->harmonyDuration = setting->harmonicDuration;
	this->melodyDuration = setting->melodicDuration;
	this->newQuestionWaitTime = setting->newQuestionWaitTime;
}

