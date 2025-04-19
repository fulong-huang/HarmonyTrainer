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
	this->currentPage = Page::LIST;
	gap = 150;


	CustomTrainingItem* item1 = new CustomTrainingItem("First traning item", width - 2 * margin.x, margin);
	items.push_back(item1);
	margin.y += gap;
	items.push_back(new CustomTrainingItem("SECOND TRANING ITEM", width-2*margin.x, margin));
	margin.y += gap;
	items.push_back(new CustomTrainingItem("THIRD TRANING ITEM", width-2*margin.x, margin));
};

void CustomTraining::draw(sf::RenderWindow *window){
	switch(this->currentPage){
		case LIST:
			for(CustomTrainingItem* item : items){
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
			std::cout << "unknown page" << std::endl;
			break;
	};
}

void CustomTraining::handleMouseClick(SoundControl* soundControl, sf::Vector2i mousePos){
	switch(this->currentPage){
		case LIST:
			for(CustomTrainingItem* item : this->items){
				int status = item->handleMouseClick(mousePos);
				if(status == 1){
					this->currentPage = Page::CONTENT;
					std::cout << "Opening custom training Content" << item->getTitle() << std::endl;
					break;
				}
				else if(status == 2){
					this->currentPage = Page::SETTING;
					std::cout << "Opening custom training Setting" << item->getTitle() << std::endl;
					break;
				}
			}
			break;
		case SETTING:
			this->currentPage = Page::LIST;
			std::cout << "CLOSING SETTING" << std::endl;
			std::cout << "RETURN TO LIST IEW" << std::endl;
			break;
		case CONTENT:
			std::cout << "CLOSING CONTENT" << std::endl;
			this->currentPage = Page::LIST;
			std::cout << "RETURN TO LIST IEW" << std::endl;
			break;
		default:
			std::cout << "unknown page" << std::endl;
			this->currentPage = Page::LIST;
			std::cout << "RETURN TO LIST IEW" << std::endl;
			break;
	}
}




