#include "SFML/Graphics.hpp"
#include <iostream>
#include "rectangle.h"
#include "circle.h"
#include "text.h"

class CustomTraining {
public:
  CustomTraining();
  ~CustomTraining();
	
	// TODO: 
	// 	Create new custom training
	void createTraining();

	// TODO: 
	// 	Draw custom training page
	void draw(sf::RenderWindow *window);

private:
  CustomTraining(const CustomTraining &d);
  CustomTraining operator=(const CustomTraining &d);
  std::vector<sf::Drawable *> drawables;
	std::vector<Shape *> shapes;

  void setup();

};



