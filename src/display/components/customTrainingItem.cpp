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

// 	itemContainer = new Rectangle(
// 			sf::Color(100, 0, 0),
// 			{(int)globSize.left - menuPadding.x, (int)globSize.top - menuPadding.y},
// 			globSize.width + menuPadding.x * 2 + optionWidth + optionPadding, globSize.height + menuPadding.y * 2,
// 			false, 9, sf::Color::Blue
// 			);

	itemContainer = new Rectangle(
			sf::Color(100, 0, 0),
			{(int)globSize.left - menuPadding.x, (int)globSize.top - menuPadding.y},
			this->width, globSize.height + menuPadding.y * 2,
			false, 9, sf::Color::Blue
			);

	optionButton = new Rectangle(
			sf::Color(100, 100, 100),
			{(int)globSize.left + (int)globSize.width + optionPadding, (int)globSize.top - menuPadding.y},
			optionWidth + menuPadding.x, globSize.height + menuPadding.y * 2
			);
// 
// 	float rectHeight = globSize.height + menuPadding.y * 2;
// 	float radius = optionWidth / 6.0;
// 	Circle* dot1 = new Circle(
// 			sf::Color(150, 150, 150),
// 			{
// 				(int)globSize.left + (int)globSize.width + optionPadding + optionWidth / 2,
// 				(int)(globSize.top - menuPadding.y + rectHeight/4 - radius)
// 			},
// 			radius
// 			);
// 	Circle* dot2 = new Circle(
// 			sf::Color(150, 150, 150),
// 			{
// 				(int)globSize.left + (int)globSize.width + optionPadding + optionWidth / 2,
// 				(int)(globSize.top - menuPadding.y + rectHeight/2 - radius)
// 			},
// 			radius
// 			);
// 	Circle* dot3 = new Circle(
// 			sf::Color(150, 150, 150),
// 			{
// 				(int)globSize.left + (int)globSize.width + optionPadding + optionWidth / 2,
// 				(int)(globSize.top - menuPadding.y + 3 * rectHeight/4 - radius)
// 			},
// 			radius
// 			);

};

void CustomTrainingItem::draw(sf::RenderWindow *window){
	itemContainer->draw(window);
	nameDisplay->draw(window);
	optionButton->draw(window);
}






