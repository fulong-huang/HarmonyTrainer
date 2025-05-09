#include "customTrainingContent.h"

CustomTrainingContent::CustomTrainingContent(int width, sf::Vector2i margin):
	width(width), margin(margin)
{
	this->setup();
}

CustomTrainingContent::~CustomTrainingContent(){

}

void CustomTrainingContent::setup(){
	this->trainingContentText = new Text(
			sf::Color(50, 50, 50),
			this->margin,
			"Content Page",
			150,
			false);
}

void CustomTrainingContent::draw(sf::RenderWindow* window){
	this->trainingContentText->draw(window);
}

void CustomTrainingContent::scroll(int amount){
	this->trainingContentText->scroll(amount);
}

void CustomTrainingContent::resetScroll(){
	this->trainingContentText->resetScroll();
}


