#include "display.h"

Display::Display(){
	this->setup();
}
void Display::setup(){
	this->window.create(sf::VideoMode(800, 600), "Harmony Trainer");
	this->window.setFramerateLimit(FRAMERATE);
};

Display::~Display(){
	this->window.close();
};

void Display::draw(){
	
	this->window.clear();

	for(sf::Drawable* s : drawables){
		this->window.draw(*s);
	};
	this->window.display();
}

void Display::handleMouseClick(sf::Vector2i mousePos){
}

void Display::addShape(sf::Drawable* s){
	this->drawables.push_back(s);
};

