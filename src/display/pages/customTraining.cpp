#include "customTraining.h"

CustomTraining::CustomTraining(int width, sf::Vector2i margin):
	width(width), margin(margin)
{
	this->setup();
}

CustomTraining::~CustomTraining(){
	for(CustomTrainingItem* item : items){
		delete item;
	}
};

void CustomTraining::setup(){
	gap = 150;

	sf::Vector2i currPos = margin;

	CustomTrainingItem* item1 = new CustomTrainingItem("First traning item", width - 2 * margin.x, margin);
	items.push_back(item1);
	margin.y += gap;
	items.push_back(new CustomTrainingItem("SECOND TRANING ITEM", width-2*margin.x, margin));
	margin.y += gap;
	items.push_back(new CustomTrainingItem("THIRD TRANING ITEM", width-2*margin.x, margin));
};

void CustomTraining::draw(sf::RenderWindow *window){
	for(CustomTrainingItem* item : items){
		item->draw(window);
	}

}





