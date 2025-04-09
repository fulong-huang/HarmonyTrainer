#include "manager.h"

Manager::Manager(): display(800, 600){
	this->isRunning = true;
	this->isPlaying = false;

	// Set random seed as current time 
	// 	to generate different number each time program ran
	srand(time(NULL));
}

Manager::~Manager(){
}

void Manager::run() {
  sf::Event event;
	std::chrono::steady_clock::time_point begin;
	std::chrono::steady_clock::time_point current;

	// 0: first chord
	// 1: first pause
	// 2: second chord
	// 3: second pause
	int phase;

	float waitTime = 2;
  while (this->isRunning) {
		if(this->isPlaying){
			current = std::chrono::steady_clock::now();
			float timePassed = std::chrono::duration_cast<std::chrono::microseconds>(current-begin).count()/1000000.0;
			if(timePassed > waitTime){
				begin = std::chrono::steady_clock::now();
				phase = (phase + 1)%6;
				switch(phase){
					case 0:
						this->note1.start();
						this->note2.start();
						break;
					case 1:
						this->note1.stop();
						this->note2.stop();
						break;
					case 2:
						waitTime = 0.5;
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
						waitTime = 2;
						this->generateRandomNote();
						break;
				}
			}
		}
    while (this->display.window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        if (this->isPlaying) {
					this->isPlaying = false;
          this->note1.stop();
          this->note2.stop();
          this->note3.stop();
				}
				// Exit program
				this->isRunning = false;
      } else if (event.type == sf::Event::MouseButtonPressed) {
        if (this->isPlaying) {
          this->note1.stop();
          this->note2.stop();
          this->note3.stop();
					this->isPlaying = false;
        } else {
					begin = std::chrono::steady_clock::now();
					phase = 0;
					waitTime = 2;
					this->isPlaying = true;
					this->generateRandomNote();
          this->note1.start();
          this->note2.start();
        }
      }
    };
    this->display.draw();
  };
}

void Manager::generateRandomNote(){
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


