#include "manager.h"

Manager::Manager():
	width(800), height(600), customTraining(800, {30, 60})
{
	this->isRunning = true;

	this->window.create(sf::VideoMode(this->width, this->height), "Harmony Trainer");
	this->window.setFramerateLimit(FRAMERATE);
	soundControl = new SoundControl();
}

Manager::~Manager(){
	this->window.close();
	if(soundControl){
		delete soundControl;
	}
}

void Manager::run() {
  sf::Event event;
  while (this->isRunning) {
		if(this->soundControl->isPlaying()){
			this->soundControl->playSound();
		}
    while (this->window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				// Call sound control and stop sound
				this->isRunning = false;
			}
			else if(event.type == sf::Event::MouseButtonPressed){
				this->handleMouseClick(sf::Mouse::getPosition(this->window));
				if(this->soundControl->isPlaying()){
					this->soundControl->stop();
				}
				else{
					this->soundControl->start();
				}
			}
    };
    this->draw();
  };
}

void Manager::handleMouseClick(sf::Vector2i mousePos){
	std::cout << "POSITION: " << mousePos.x << ", " << mousePos.y << std::endl;
	// TODO: 
	// 	Either handle mouse click:
	// 	- Directly control over [soundControl] object
	//	- [Prefered] Return a value/object and let manager modify soundControl
	//	??? Return pointer to a new [soundControl] object
	customTraining.handleMouseClick(mousePos);

}

void Manager::draw(){
	
	this->window.clear();
	this->customTraining.draw(&this->window);
	this->window.display();
}

