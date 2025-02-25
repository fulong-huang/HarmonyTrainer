#include "display.h"

Display::Display(int width, int height): width(width), height(height){
	this->setup();
}
void Display::setup(){
	this->window.create(sf::VideoMode(this->width, this->height), "Harmony Trainer");
	this->window.setFramerateLimit(FRAMERATE);

	Menu m({0, 20}, this->width, 30, {20, 0});
	this->drawables = m.getDrawables();
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

