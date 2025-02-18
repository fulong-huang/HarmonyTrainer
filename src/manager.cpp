#include "manager.h"

Manager::Manager(){

}

Manager::~Manager(){
}

void Manager::run() {
  sf::Event event;
  while (this->display.window.isOpen()) {
    while (this->display.window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        if (this->note1.isPlaying) {
          this->note1.stop();
          this->note2.stop();
				}
				// Exit program
				return;
      } else if (event.type == sf::Event::MouseButtonPressed) {
        if (this->note1.isPlaying) {
          this->note1.stop();
          this->note2.stop();
        } else {
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
	int start = 36; 
	int end = 60;
	int randomNoteNumber = start + (std::rand() % (end - start + 1));
	this->note1.setNote(randomNoteNumber);
	bool isMajor = std::rand() % 2;
	this->note2.setNote(randomNoteNumber + isMajor + 3);
	std::cout << "IS MAJOR: " << (isMajor? "True": "False") << std::endl;
}


