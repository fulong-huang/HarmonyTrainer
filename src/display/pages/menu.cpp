#include "menu.h"

Menu::Menu(sf::Vector2i pos, int width, int height,
			sf::Vector2i padding, sf::Vector2i margin):
	position(pos), width(width), height(height), padding(padding), margin(margin){
	this->setup();
}
Menu::~Menu(){
};

void Menu::setup(){
	Text* name = new Text(
			sf::Color(50, 50, 50),
			this->position + this->padding,	// Position
			"Name of item",
			50,
			false);
	sf::FloatRect globSize = name->getTextObject()->getGlobalBounds();
	Rectangle* container = new Rectangle(
			sf::Color(100, 0, 0),				// Color
			{(int)globSize.left, (int)globSize.top},
			globSize.width, globSize.height
			);
	this->drawables.push_back(container->getDrawable());
	this->drawables.push_back(name->getDrawable());
};

std::vector<sf::Drawable *> Menu::getDrawables(){
	return this->drawables;
}




