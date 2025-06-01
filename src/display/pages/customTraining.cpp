#include "customTraining.h"

CustomTraining::CustomTraining(int width, sf::Vector2i margin):
	customTrainingContent(width),width(width), margin(margin)
{
	this->setup();
}

CustomTraining::~CustomTraining(){
	for(CustomTrainingItem* item : this->trainingItems){
		delete item;
	}
};

std::string keepAlNum(std::string s){
	std::string result;
	for(char c : s){
		if(std::isalnum(c)){
			result += c;
		}
	}
	return result;
}

void CustomTraining::setup(){
	this->currentPage = Page::LIST;
	gap = 150;

	for(std::string item : this->trainingListIO.getListContent()){
		this->trainingItems.push_back(
				new CustomTrainingItem(item, width-2*margin.x, margin)
				);

// 		TrainingSettings trainingSetting;
// 		this->trainingListIO.createTrainingSettings(keepAlNum(item) + ".txt", &trainingSetting);
		margin.y += gap;
	}
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

					this->customTrainingContent.open(item->getTitle());

					this->trainingListIO.loadTrainingSettings(
							keepAlNum(item->getTitle())+".txt",
							soundControl
							);
					this->soundControl->trigger();
					break;
				}
				else if(status == 2){
					this->currentPage = Page::SETTING;
					// Do not reset, as user might miss click 
					// 	and want to come back for neighbor item
					// this->resetItemsScroll();
					break;
				}
			}
			break;
		case SETTING:
			this->currentPage = Page::LIST;
			this->customTrainingSetting.resetScroll();
			break;
		case CONTENT:
			this->soundControl->trigger();
			this->currentPage = Page::LIST;
			this->customTrainingContent.resetScroll();
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
	this->customTrainingContent.resetScroll();
	this->resetItemsScroll();
}

void CustomTraining::resetItemsScroll(){
	for(CustomTrainingItem* item: this->trainingItems){
		item->resetScroll();
	}
}

void CustomTraining::setSoundControl(SoundControl* soundControl){
	this->soundControl = soundControl;
}


