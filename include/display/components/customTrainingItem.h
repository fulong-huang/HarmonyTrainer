#include "SFML/Graphics.hpp"
#include <iostream>
#include "rectangle.h"
#include "circle.h"
#include "text.h"

class CustomTrainingItem {
public:
  CustomTrainingItem(std::string title, sf::Vector2i startingPosition);
  ~CustomTrainingItem();

	void draw(sf::RenderWindow *window);

private:
  CustomTrainingItem(const CustomTrainingItem &d);
  CustomTrainingItem operator=(const CustomTrainingItem &d);

	sf::Vector2i startingPosition;
  void setup();
	std::string title;

	Text* nameDisplay;
	Rectangle* itemContainer;

	// TODO: 
	// 	Create new class for optionButton
	// 	Class should also check collision and take in functions to execute if in bound
	Rectangle* optionButton;


};




