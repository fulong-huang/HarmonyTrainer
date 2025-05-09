#include "customTrainingItem.h"

CustomTrainingItem::CustomTrainingItem(std::string title, int width, sf::Vector2i startingPosition): 
	startingPosition(startingPosition), title(title), width(width)
{
	this->setup();
}

CustomTrainingItem::~CustomTrainingItem(){
	delete nameDisplay;
	delete itemContainer;
	delete optionButton;
};

void CustomTrainingItem::setup(){
	this->nameDisplay = new Text(
			sf::Color(50, 50, 50),
			this->startingPosition + this->menuPadding,	// Position
			this->title,
			50,
			false);

	sf::FloatRect globSize = this->nameDisplay->getTextObject()->getGlobalBounds();
	this->endingPosition = this->startingPosition + sf::Vector2i{
		this->width, (int)globSize.height + this->menuPadding.y * 2
	};

	this->itemContainer = new Rectangle(
			sf::Color(100, 0, 0),
			this->startingPosition,
			this->width, globSize.height + this->menuPadding.y * 2,
			false, 9, sf::Color::Blue
			);

	this->optionButton = new Option(
			// {(int)globSize.left + (int)globSize.width + optionPadding, (int)globSize.top - this->menuPadding.y},
			{(int)this->width - optionPadding - this->menuPadding.x/2, (int)globSize.top - this->menuPadding.y},
			{optionWidth + this->menuPadding.x, (int)globSize.height + this->menuPadding.y * 2},
			5
			);
};

void CustomTrainingItem::draw(sf::RenderWindow *window){
	itemContainer->draw(window);
	nameDisplay->draw(window);
	optionButton->draw(window);
}

void CustomTrainingItem::scroll(int amount){
	this->nameDisplay->scroll(amount);
	this->itemContainer->scroll(amount);
	this->optionButton->scroll(amount);

}
void CustomTrainingItem::resetScroll(){
	this->nameDisplay->resetScroll();
	this->itemContainer->resetScroll();
	this->optionButton->resetScroll();
}

int CustomTrainingItem::handleMouseClick(sf::Vector2i mousePos){

	if(this->itemContainer->boundCheck(mousePos)){
		if(this->optionButton->handleMouseClick(mousePos)){
			return 2;
		}
		else{
			return 1;
		}

	}
	return 0;
}

std::string CustomTrainingItem::getTitle(){
	return this->title;
}





