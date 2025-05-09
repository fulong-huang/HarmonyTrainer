#include "option.h"

Option::~Option(){

}

Option::Option(sf::Vector2i position, sf::Vector2i dimension, int radius):
	position(position), dimension(dimension), radius(radius)
{
	this->setup();
}

void Option::setup(){
	background = new Rectangle(
			sf::Color(100, 100, 100),
			this->position,
			this->dimension.x, this->dimension.y
			);

	int posX = this->position.x + this->dimension.x / 2 - radius;
	int posY = this->position.y + this->dimension.y / 4 - radius; 
	dot1 = new Circle(
			sf::Color(150, 150, 150),
			{posX, posY},
			this->radius
			);
	posY += this->dimension.y/4;
	dot2 = new Circle(
			sf::Color(150, 150, 150),
			{posX, posY},
			this->radius
			);
	posY += this->dimension.y/4;
	dot3 = new Circle(
			sf::Color(150, 150, 150),
			{posX, posY},
			this->radius
			);

}

bool Option::handleMouseClick(sf::Vector2i mousePos){
	return this->background->boundCheck(mousePos);
}

void Option::draw(sf::RenderWindow *window){
	background->draw(window);
	dot1->draw(window);
	dot2->draw(window);
	dot3->draw(window);
}

void Option::scroll(int amount){
	this->background->scroll(amount);
	this->dot1->scroll(amount);
	this->dot2->scroll(amount);
	this->dot3->scroll(amount);
}

void Option::resetScroll(){
	this->background->resetScroll();
	this->dot1->resetScroll();
	this->dot2->resetScroll();
	this->dot3->resetScroll();
}



