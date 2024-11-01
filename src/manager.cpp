#include "manager.h"

Manager::Manager() : note2("C4"){

}

void Manager::run() {
  sf::Event event;
  while (display.window.isOpen()) {
    while (display.window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        display.window.close();
      } else if (event.type == sf::Event::MouseButtonPressed) {
        if (note1.isPlaying) {
          note1.stop();
          note2.stop();
        } else {
          note1.start();
          note2.start();
        }
      }
    };
    display.draw(display.window);
  };
}
