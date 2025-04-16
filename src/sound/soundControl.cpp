#include "soundControl.h"

SoundControl::SoundControl(){
	this->playing = false;

	// Set random seed as current time 
	// 	to generate different number each time program ran
	srand(time(NULL));

	waitTime = 2;
	phase = 0;
	this->generateRandomNote();
}

SoundControl::~SoundControl(){
	this->note1.stop();
	this->note2.stop();
	this->note3.stop();
}

void SoundControl::start(){
	this->playing = true;
	this->begin = std::chrono::steady_clock::now();
	this->note1.start();
	this->note2.start();
}
void SoundControl::stop(){
	this->playing = false;
	this->note1.stop();
	this->note2.stop();
	this->note3.stop();
}

bool SoundControl::isPlaying(){
	return this->playing;
}

void SoundControl::playSound(){
		if(this->playing){
			this->current = std::chrono::steady_clock::now();
			float timePassed = std::chrono::duration_cast<std::chrono::microseconds>(this->current-this->begin).count()/1000000.0;
			if(timePassed > this->waitTime){
				this->begin = std::chrono::steady_clock::now();
				this->phase = (this->phase + 1)%6;
				switch(this->phase){
					case 0:
						this->note1.start();
						this->note2.start();
						break;
					case 1:
						this->note1.stop();
						this->note2.stop();
						break;
					case 2:
						this->waitTime = 0.5;
						this->note2.start();
						break;
					case 3:
						this->note2.stop();
						this->note3.start();
						break;
					case 4:
						this->note3.stop();
						this->note1.start();
						break;
					case 5:
						this->note1.stop();
						this->waitTime = 2;
						this->generateRandomNote();
						break;
				}
			}
		}
}

void SoundControl::generateRandomNote(){
	int start = 45; 
	int end = 70;
	int randomNoteNumber = start + (std::rand() % (end - start + 1));
	this->note1.setNote(randomNoteNumber);
	int rand = std::rand();
	bool isMajor = rand % 2;
	std::cout << "RAND: "<< rand << std::endl;
	this->note2.setNote(randomNoteNumber - isMajor - 3);
	this->note3.setNote(randomNoteNumber - 1 - isMajor);
	std::cout << "IS MAJOR: " << (isMajor? "True": "False") << std::endl;

	return;
// 	int start = 36; 
// 	int end = 60;
// 	int randomNoteNumber = start + (std::rand() % (end - start + 1));
// 	this->note1.setNote(randomNoteNumber);
// 	bool isMajor = std::rand() % 2;
// 	this->note2.setNote(randomNoteNumber + isMajor + 3);
// 	this->note3.setNote(randomNoteNumber + !isMajor + 3);
// 	std::cout << "IS MAJOR: " << (isMajor? "True": "False") << std::endl;
}

