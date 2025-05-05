#include "soundControl.h"

SoundControl::SoundControl(){
	this->playing = false;

	// Set random seed as current time 
	// 	to generate different number each time program ran
	srand(time(NULL));

	harmonyDuration = answerWaitTime = newQuestionWaitTime = 2;
	melodyDuration = 1;
	phase = 0;

	this->harmonyGaps = {3, 7};

	this->generateRandomNote();
}

SoundControl::~SoundControl(){
	this->cleanUpNotes();
}

void SoundControl::cleanUpNotes(){
	std::cout << "CLEANING UP NOTES WITH SIZE: " << this->melodyNotes.size() << std::endl;
	for(Notes* note : this->melodyNotes){
		note->stop();
		std::cout << "Delete a note" << std::endl;
		delete note;
	}
	std::cout << "CLEARING NOTE" << std::endl;
	this->melodyNotes.clear();
	this->harmonyNotes.clear();
	std::cout << "RETURNING FROM CLEAN UP" << std::endl;
}

void SoundControl::trigger(){
	if(this->playing){
		this->stop();
	}
	else{
		this->start();
	}
}

void SoundControl::start(){
	this->playing = true;
	this->begin = std::chrono::steady_clock::now();
	phase = 0;
	this->currWaitTime = 0;
	this->noteIndex = 0;
	// this->currWaitTime = harmonyDuration;
}
void SoundControl::stop(){
	this->playing = false;
	this->cleanUpNotes();
}

bool SoundControl::isPlaying(){
	return this->playing;
}

void SoundControl::playSound(){
		if(this->playing){
			this->current = std::chrono::steady_clock::now();
			float timePassed = std::chrono::duration_cast<std::chrono::microseconds>(this->current-this->begin).count()/1000000.0;
			if(timePassed > this->currWaitTime){
				this->begin = std::chrono::steady_clock::now();
				switch(this->phase){
					case 0:
						std::cout << "CASE 0 " << std::endl;
						this->generateRandomNote();
						std::cout << "GENERATED NOTE" << std::endl;
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
						if(this->noteIndex > 0){
							this->melodyNotes[this->noteIndex-1]->stop();
						}
						if(this->noteIndex < this->melodyNotes.size()){
							this->melodyNotes[this->noteIndex]->start();
							this->noteIndex++;
						}
						else{
							this->phase = 3;
							this->noteIndex = 0;
						}
						break;
					case 3:
						this->phase = 0;
						this->cleanUpNotes();
						this->currWaitTime = this->newQuestionWaitTime;
						break;
				}
			}
		}
}

void SoundControl::generateRandomNote(){
	int start = 36; 
	int end = 60;
	int currNoteNumber = start + (std::rand() % (end - start + 1));
	bool isFirstHarmony = std::rand() % 2;
	int lastNote = currNoteNumber + harmonyGaps[isFirstHarmony];

	// TODO:
	// 	!!!!!!!!!!!!!!!!!!!!!!!
	// 	REUSE NOTE OBJECTS DURING EACH NOTE GENERATION
	// 	!!!!!!!!!!!!!!!!!!!!!!!
	Notes* currNote = new Notes(currNoteNumber);
	this->harmonyNotes.push_back(currNote);
	this->melodyNotes.push_back(currNote);
	for(int i = 0; i < 7; i++){
		currNoteNumber += MajorSteps[i];
		if(currNoteNumber >= lastNote){
			break;
		}
		currNote = new Notes(currNoteNumber);
		this->melodyNotes.push_back(currNote);
	}
	currNote = new Notes(lastNote);
	this->harmonyNotes.push_back(currNote);
	this->melodyNotes.push_back(currNote);

	return;
}

