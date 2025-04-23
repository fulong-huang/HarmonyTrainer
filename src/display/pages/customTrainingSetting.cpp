#include "customTrainingSetting.h"

CustomTrainingSetting::CustomTrainingSetting(int width, sf::Vector2i margin):
	width(width), margin(margin)
{
	this->setup();
}

CustomTrainingSetting::~CustomTrainingSetting(){

}

void CustomTrainingSetting::setup(){
	this->scrollPosition = 0;
	this->trainingSettingText = new Text(
			sf::Color(50, 50, 50),
			this->margin,
			"Setting Page long text",
			100,
			false);
}

void CustomTrainingSetting::draw(sf::RenderWindow* window){
	this->trainingSettingText->draw(window);
}

void CustomTrainingSetting::scroll(int amount){
	this->scrollPosition += amount;
	this->trainingSettingText->setPosition(
			{this->margin.x, this->margin.y + this->scrollPosition}
			);
}



