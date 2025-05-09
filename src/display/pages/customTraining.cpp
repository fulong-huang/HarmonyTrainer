#include "customTraining.h"

CustomTraining::CustomTraining(int width, sf::Vector2i margin):
	width(width), margin(margin)
{
	this->setup();
}

CustomTraining::~CustomTraining(){
	for(CustomTrainingItem* item : this->trainingItems){
		delete item;
	}
};

void CustomTraining::setup(){
	this->currentPage = Page::LIST;
	gap = 150;


	this->trainingItems.push_back(new CustomTrainingItem("FIRST TRAINING ITEM", width-2*margin.x, margin));
	margin.y += gap;
	this->trainingItems.push_back(new CustomTrainingItem("SECOND TRANING ITEM", width-2*margin.x, margin));
	margin.y += gap;
	this->trainingItems.push_back(new CustomTrainingItem("THIRD TRANING ITEM", width-2*margin.x, margin));
};

void CustomTraining::draw(sf::RenderWindow *window){
	switch(this->currentPage){
		case LIST:
			for(CustomTrainingItem* item : this->trainingItems){
				item->draw(window);
			}
			break;
		case SETTING:
			this->customTrainingSetting.draw(window);
			break;
		case CONTENT:
			this->customTrainingContent.draw(window);
			break;
		default:
			break;
	};
}
void CustomTraining::handleMouseClick(SoundControl* soundControl, sf::Vector2i mousePos){
	switch(this->currentPage){
		case LIST:
			for(CustomTrainingItem* item : this->trainingItems){
				int status = item->handleMouseClick(mousePos);
				if(status == 1){
					this->currentPage = Page::CONTENT;
					break;
				}
				else if(status == 2){
					this->currentPage = Page::SETTING;
					break;
				}
			}
			break;
		case SETTING:
			this->currentPage = Page::LIST;
			this->customTrainingSetting.resetScroll();
			break;
		case CONTENT:
			this->currentPage = Page::LIST;
			break;
		default:
			this->currentPage = Page::LIST;
			break;
	}
}

void CustomTraining::scroll(int amount){
	if(this->currentPage == Page::SETTING){
		this->customTrainingSetting.scroll(amount);
	}
	else if(this->currentPage == Page::CONTENT){
		this->customTrainingContent.scroll(amount);
	}
	else if(this->currentPage == Page::LIST){
		for(CustomTrainingItem *item : this->trainingItems){
			item->scroll(amount);
		}
	}
}

void CustomTraining::resetScroll(){
	this->customTrainingSetting.resetScroll();
}




