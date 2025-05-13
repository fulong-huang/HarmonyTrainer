#include "customTrainingContent.h"

CustomTrainingContent::CustomTrainingContent(int width,
		sf::Vector2i margin,
		int padding):
	width(width), margin(margin), padding(padding)
{
	this->setup();
}

CustomTrainingContent::~CustomTrainingContent(){
	delete this->trainingContentTitle;
	if(this->trainingContentName){
		delete this->trainingContentName;
	}
}

void CustomTrainingContent::setup(){
	this->trainingContentTitle = new Text(
			sf::Color(50, 50, 50),
			{this->width / 2, this->margin.y},
			"Content Page",
			150,
			true);
	this->trainingContentTitle->setMaxWidth(this->width - 2 * this->margin.x);
}

void CustomTrainingContent::open(std::string name){
	sf::Vector2i prevPosition = this->trainingContentTitle->getPosition();
	sf::Vector2i prevSize = this->trainingContentTitle->getSize();
	if(this->trainingContentName){
		delete this->trainingContentName;
	}
	this->trainingContentName = new Text(
			sf::Color(50, 50, 50),
			{this->width / 2, prevPosition.y + prevSize.y + this->padding},
			name,
			50,
			true);
	this->trainingContentName->setMaxWidth(this->width - 2 * this->margin.x);
	this->trainingContentName->setXPosition(this->width / 2);
}

void CustomTrainingContent::draw(sf::RenderWindow* window){
	this->trainingContentTitle->draw(window);
	if(this->trainingContentName)
		this->trainingContentName->draw(window);
}

void CustomTrainingContent::scroll(int amount){
	this->trainingContentTitle->scroll(amount);
	if(this->trainingContentName)
		this->trainingContentName->scroll(amount);
}

void CustomTrainingContent::resetScroll(){
	this->trainingContentTitle->resetScroll();
	if(this->trainingContentName)
		this->trainingContentName->resetScroll();
}


void CustomTrainingContent::changeWidth(int newWidth){
	this->width = newWidth;
	this->trainingContentTitle->setMaxWidth(this->width - 2 * this->margin.x);
	this->trainingContentTitle->setXPosition(this->width / 2);
	if(this->trainingContentName){
		this->trainingContentName->setMaxWidth(this->width - 2 * this->margin.x);
		this->trainingContentName->setXPosition(this->width / 2);
	}
}

