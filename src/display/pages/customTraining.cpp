#include "customTraining.h"

CustomTraining::CustomTraining(){
	this->setup();
}
CustomTraining::~CustomTraining(){
	for(Shape *s : shapes){
		delete s;
	}
};

void CustomTraining::setup(){
	sf::Vector2i startingPosition = {30, 20};
	sf::Vector2i menuPadding = {20, 30};
	int optionWidth = 50;
	int optionPadding = 30;

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

	float rectHeight = globSize.height + menuPadding.y * 2;
	float radius = optionWidth / 6.0;
	Circle* dot1 = new Circle(
			sf::Color(150, 150, 150),
			{
				(int)globSize.left + (int)globSize.width + optionPadding + optionWidth / 2,
				(int)(globSize.top - menuPadding.y + rectHeight/4 - radius)
			},
			radius
			);
	Circle* dot2 = new Circle(
			sf::Color(150, 150, 150),
			{
				(int)globSize.left + (int)globSize.width + optionPadding + optionWidth / 2,
				(int)(globSize.top - menuPadding.y + rectHeight/2 - radius)
			},
			radius
			);
	Circle* dot3 = new Circle(
			sf::Color(150, 150, 150),
			{
				(int)globSize.left + (int)globSize.width + optionPadding + optionWidth / 2,
				(int)(globSize.top - menuPadding.y + 3 * rectHeight/4 - radius)
			},
			radius
			);

	this->drawables.push_back(container->getDrawable());
	this->drawables.push_back(name->getDrawable());
	this->drawables.push_back(option->getDrawable());
	this->drawables.push_back(dot1->getDrawable());
	this->drawables.push_back(dot2->getDrawable());
	this->drawables.push_back(dot3->getDrawable());

	// Save pointers for destructor
	this->shapes.push_back(container);
	this->shapes.push_back(name);
	this->shapes.push_back(option);
	this->shapes.push_back(dot1);
	this->shapes.push_back(dot2);
	this->shapes.push_back(dot3);
};

void CustomTraining::draw(sf::RenderWindow *window){
	for(sf::Drawable* s : drawables){
		window->draw(*s);
	}
}





