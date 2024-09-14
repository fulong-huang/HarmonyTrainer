#include <iostream>
#include "display.h"

Display::Display(){
	this->setup();
}
void Display::setup(){
	this->window.create(sf::VideoMode(800, 600), "Harmony Trainer");
	this->window.setFramerateLimit(FRAMERATE);
};

Display::~Display(){};

void Display::draw(sf::RenderWindow& window){
	
	window.clear();

	for(sf::Drawable* s : drawables){
		window.draw(*s);
	};
	window.display();
}

void Display::handleMouseClick(sf::Vector2i mousePos){
}

void Display::addShape(sf::Drawable* s){
	this->drawables.push_back(s);
};

void Display::run(){
	sf::Event event;
	while(this->window.isOpen()){
		while(this->window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				this->window.close();
			}
			else if(event.type == sf::Event::MouseButtonPressed){
			}
		};
		this->draw(this->window);
	};

}