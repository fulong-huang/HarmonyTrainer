#include "customTrainingSetting.h"

CustomTrainingSetting::CustomTrainingSetting(int width, sf::Vector2i margin):
	width(width), margin(margin)
{
	this->setup();
}

CustomTrainingSetting::~CustomTrainingSetting(){

}

void CustomTrainingSetting::setup(){
	this->trainingSettingText = new Text(
			sf::Color(50, 50, 50),
			this->margin,
			"Setting Page",
			150,
			false);
}

void CustomTrainingSetting::draw(sf::RenderWindow* window){
	this->trainingSettingText->draw(window);
}



