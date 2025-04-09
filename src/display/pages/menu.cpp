#include "menu.h"

Menu::Menu(){
	this->setup();
}
Menu::~Menu(){
	for(Shape *s : shapes){
		delete s;
	}
};

void Menu::setup(){
	sf::Vector2i startingPosition = {30, 20};
	sf::Vector2i menuPadding = {20, 30};
	int optionWidth = 50;
	int optionPadding = 30;

	// TODO: 
	//  !!!!!!!!!!!!! MEMORY LEAK !!!!!!!!!!!!!!!
	//  Clean up pointers when menu was destroyed  

	Text* name = new Text(
			sf::Color(50, 50, 50),
			startingPosition + menuPadding,	// Position
			"Name of item",
			50,
			false);
	sf::FloatRect globSize = name->getTextObject()->getGlobalBounds();

	Rectangle* container = new Rectangle(
			sf::Color(100, 0, 0),
			{(int)globSize.left - menuPadding.x, (int)globSize.top - menuPadding.y},
			globSize.width + menuPadding.x * 2 + optionWidth + optionPadding, globSize.height + menuPadding.y * 2,
			false, 9, sf::Color::Blue
			);

	Rectangle* option = new Rectangle(
			sf::Color(100, 100, 100),
			{(int)globSize.left + (int)globSize.width + optionPadding, (int)globSize.top - menuPadding.y},
			optionWidth + menuPadding.x, globSize.height + menuPadding.y * 2
			);

	this->drawables.push_back(container->getDrawable());
	this->drawables.push_back(name->getDrawable());
	this->drawables.push_back(option->getDrawable());

	this->shapes.push_back(container);
	this->shapes.push_back(name);
	this->shapes.push_back(option);
};

std::vector<sf::Drawable *> Menu::getDrawables(){
	return this->drawables;
}




