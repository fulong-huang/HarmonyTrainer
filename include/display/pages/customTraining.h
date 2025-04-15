#include "SFML/Graphics.hpp"
#include <iostream>
#include "rectangle.h"
#include "circle.h"
#include "text.h"
#include "customTrainingItem.h"

class CustomTraining {
public:
	// width for width of screen
	// position for height of scroll
	// margin for spaces(margin) on both side
  CustomTraining(int width, sf::Vector2i margin);
  ~CustomTraining();
	
	// TODO: 
	// 	Create new custom training
	void createTraining();

	void draw(sf::RenderWindow *window);

	void handleMouseClick(sf::Vector2i mousePos);

private:
  CustomTraining(const CustomTraining &d);
  CustomTraining operator=(const CustomTraining &d);

	std::vector<CustomTrainingItem*> items;

	sf::Vector2i margin;
	int width, height, gap;

  void setup();

};



