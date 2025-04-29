#include "customTrainingSetting.h"

CustomTrainingSetting::CustomTrainingSetting(int width):
	width(width)
{
	this->setup();
}

CustomTrainingSetting::~CustomTrainingSetting(){

}

void CustomTrainingSetting::setup(){
	this->scrollPosition = 0;
	this->trainingSettingText = new Text(
			sf::Color(50, 50, 50),
			// this->margin,
			{this->width/2, this->margin},
			"Setting Page long text",
			100,
			true);
}

void CustomTrainingSetting::draw(sf::RenderWindow* window){
	this->trainingSettingText->draw(window);
	this->chordsSetting.draw(window);
}

void CustomTrainingSetting::scroll(int amount){
	this->scrollPosition += amount;
	this->trainingSettingText->setPosition(
			{this->width/2, this->margin + this->scrollPosition}
			);
}



