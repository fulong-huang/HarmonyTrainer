#include "SFML/Graphics.hpp"
#include <iostream>
#include "rectangle.h"
#include "circle.h"
#include "text.h"
#include "customTrainingItem.h"

class CustomTraining {
public:
  CustomTraining();
  ~CustomTraining();
	
	// TODO: 
	// 	Create new custom training
	void createTraining();

	void draw(sf::RenderWindow *window);

private:
  CustomTraining(const CustomTraining &d);
  CustomTraining operator=(const CustomTraining &d);

	std::vector<CustomTrainingItem*> items;
  void setup();

};



