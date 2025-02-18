#include "manager.h"

Manager::Manager() : note2("C4"){

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
          this->note1.start();
          this->note2.start();
        }
      }
    };
    this->display.draw();
  };
}
