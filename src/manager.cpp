#include "manager.h"

Manager::Manager():
	width(800), height(600), customTraining(800, {30, 60})
{
	this->isRunning = true;

	this->window.create(sf::VideoMode(this->width, this->height), "Harmony Trainer");
	this->window.setFramerateLimit(FRAMERATE);

	this->customTraining.setSoundControl(&this->soundControl);
}

Manager::~Manager(){
	this->window.close();
}

void Manager::run() {
  sf::Event event;
  while (this->isRunning) {
		this->soundControl.playSound();
    while (this->window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				// Call sound control and stop sound
				this->isRunning = false;
			}
			else if(event.type == sf::Event::MouseButtonPressed){
				this->handleMouseClick(sf::Mouse::getPosition(this->window));
				// this->soundControl.trigger();
			}
// 			else if(event.type == sf::Event::KeyPressed){
// 				if(event.key.code == sf::Keyboard::Down){
// 					this->customTraining.scroll(-10);
// 				}
// 				else if(event.key.code == sf::Keyboard::Up){
// 					this->customTraining.scroll(10);
// 				}
// 			}
			else if(event.type == sf::Event::MouseWheelScrolled){
				float delta = event.mouseWheelScroll.delta;
				if(delta != 0){
					this->customTraining.scroll(delta * 10);
				}
			}
    };
    this->draw();
  };
}

void Manager::handleMouseClick(sf::Vector2i mousePos){
	// TODO: 
	// 	Either handle mouse click:
	// 	- Directly control over [soundControl] object
	//	- [Prefered] Return a value/object and let manager modify soundControl
	//	??? Return pointer to a new [soundControl] object
	customTraining.handleMouseClick(&soundControl, mousePos);

}

void Manager::draw(){
	
	this->window.clear();
	this->customTraining.draw(&this->window);
	this->window.display();
}

