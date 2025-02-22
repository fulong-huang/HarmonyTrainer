#include "menu.h"

Menu::Menu(){
	this->setup();
}
Menu::~Menu(){
};

void Menu::setup(){
	Rectangle* options = new Rectangle(sf::Color(200, 200, 200), {10, 10}, 200, 50);
	this->drawables.push_back(options->getDrawable());
	Text* name = new Text(sf::Color(50, 50, 50), {10, 0}, "Name of item", 50, false);
	this->drawables.push_back(name->getDrawable());
};

std::vector<sf::Drawable *> Menu::getDrawables(){
	return this->drawables;
}




