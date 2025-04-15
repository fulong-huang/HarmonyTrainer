#include "customTrainingItem.h"

CustomTrainingItem::CustomTrainingItem(std::string title, int width, sf::Vector2i startingPosition): 
	startingPosition(startingPosition), title(title), width(width)
{
	std::cout << "STARTING: " << startingPosition.x << ", " << startingPosition.y << std::endl;
	this->setup();
}

CustomTrainingItem::~CustomTrainingItem(){
	delete nameDisplay;
	delete itemContainer;
	delete optionButton;
};

void CustomTrainingItem::setup(){
	sf::Vector2i menuPadding = {20, 30};
	int optionWidth = 50;
	int optionPadding = 30;

	nameDisplay = new Text(
			sf::Color(50, 50, 50),
			this->startingPosition + menuPadding,	// Position
			"Name of item",
			50,
			false);

	sf::FloatRect globSize = this->nameDisplay->getTextObject()->getGlobalBounds();
	this->endingPosition = this->startingPosition + sf::Vector2i{
		this->width, (int)globSize.height + menuPadding.y * 2
	};

	itemContainer = new Rectangle(
			sf::Color(100, 0, 0),
			this->startingPosition,
			this->width, globSize.height + menuPadding.y * 2,
			false, 9, sf::Color::Blue
			);

	optionButton = new Option(
			// {(int)globSize.left + (int)globSize.width + optionPadding, (int)globSize.top - menuPadding.y},
			{(int)this->width - optionPadding - menuPadding.x/2, (int)globSize.top - menuPadding.y},
			{optionWidth + menuPadding.x, (int)globSize.height + menuPadding.y * 2},
			5
			);
};

void CustomTrainingItem::draw(sf::RenderWindow *window){
	itemContainer->draw(window);
	nameDisplay->draw(window);
	optionButton->draw(window);
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





