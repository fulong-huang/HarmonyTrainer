#include "manager.h"

Manager::Manager():
	width(800), height(600), customTraining(800, {30, 60})
{
	this->isRunning = true;
	this->isPlaying = false;

	this->window.create(sf::VideoMode(this->width, this->height), "Harmony Trainer");
	this->window.setFramerateLimit(FRAMERATE);

	// Set random seed as current time 
	// 	to generate different number each time program ran
	srand(time(NULL));

	waitTime = 2;
	phase = 0;
}

Manager::~Manager(){
	this->window.close();
	this->note1.stop();
	this->note2.stop();
	this->note3.stop();
}

void Manager::run() {
  sf::Event event;

	// 0: first chord
	// 1: first pause
	// 2: second chord
	// 3: second pause

  while (this->isRunning) {

		// soundControl();

    while (this->window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				if (this->isPlaying) {
					this->isPlaying = false;
				}
				// Exit program
				this->isRunning = false;
			}
			else if(event.type == sf::Event::MouseButtonPressed){
				this->handleMouseClick(sf::Mouse::getPosition(this->window));
			}
//       } else if (event.type == sf::Event::MouseButtonPressed) {
//         if (this->isPlaying) {
//           this->note1.stop();
//           this->note2.stop();
//           this->note3.stop();
// 					this->isPlaying = false;
//         } else {
// 					this->begin = std::chrono::steady_clock::now();
// 					this->phase = 0;
// 					this->waitTime = 2;
// 					this->isPlaying = true;
// 					this->generateRandomNote();
//           this->note1.start();
//           this->note2.start();
//         }
//       }
    };
    this->draw();
  };
}

void Manager::handleMouseClick(sf::Vector2i mousePos){
	std::cout << "POSITION: " << mousePos.x << ", " << mousePos.y << std::endl;
	customTraining.handleMouseClick(mousePos);
}

void Manager::draw(){
	
	this->window.clear();
	this->customTraining.draw(&this->window);
	this->window.display();
}

void Manager::soundControl(){
		if(this->isPlaying){
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

