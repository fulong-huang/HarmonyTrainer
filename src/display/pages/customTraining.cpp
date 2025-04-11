#include "customTraining.h"

CustomTraining::CustomTraining() {
	this->setup();
}

CustomTraining::~CustomTraining(){
	for(CustomTrainingItem* item : items){
		delete item;
	}
};

void CustomTraining::setup(){
	CustomTrainingItem* item1 = new CustomTrainingItem("First traning item", {30, 50});
	items.push_back(item1);
	items.push_back(new CustomTrainingItem("SECOND TRANING ITEM", {30, 250}));
};

void CustomTraining::draw(sf::RenderWindow *window){
	for(CustomTrainingItem* item : items){
		item->draw(window);
	}

}





