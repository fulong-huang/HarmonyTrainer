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

void CustomTraining::handleMouseClick(sf::Vector2i mousePos){
	for(CustomTrainingItem* item : this->items){
		int status = item->handleMouseClick(mousePos);
		if(status == 1){
			std::cout << "Starting custom training " << item->getTitle() << std::endl;
			break;
		}
		else if(status == 2){
			std::cout << "Opening option of " << item->getTitle() << std::endl;
			break;
		}
	}
}




