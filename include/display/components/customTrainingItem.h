#include "SFML/Graphics.hpp"
#include <iostream>
#include "rectangle.h"
#include "circle.h"
#include "text.h"
#include "option.h"

class CustomTrainingItem {
public:
  CustomTrainingItem(std::string title, int width, sf::Vector2i startingPosition);
  ~CustomTrainingItem();

	void draw(sf::RenderWindow *window);
	void scroll(int amount);

	void resetScroll();

	// Return status:
	// 	0: no action / miss click
	// 	1: active item
	// 	2: open setting
	int handleMouseClick(sf::Vector2i mousePos);
	
	// TODO: 
	// 	Change width of item for rendering
	void setWidth(int width);
	std::string getTitle();

private:
  CustomTrainingItem(const CustomTrainingItem &d);
  CustomTrainingItem operator=(const CustomTrainingItem &d);

	sf::Vector2i startingPosition;
	sf::Vector2i endingPosition;
	sf::Vector2i menuPadding = {20, 30};
	std::string title;
	int width;
	int optionWidth = 50;
	int optionPadding = 30;


  void setup();

	Text* nameDisplay;
	Rectangle* itemContainer;

	// TODO: 
	// 	Create new class for optionButton
	// 	Class should also check collision and take in functions to execute if in bound
	Option* optionButton;


};




