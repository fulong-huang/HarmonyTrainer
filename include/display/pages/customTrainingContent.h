#include "SFML/Graphics.hpp"
#include <iostream>
#include "rectangle.h"
#include "circle.h"
#include "text.h"

class CustomTrainingContent {
public:
  CustomTrainingContent(int width=0, sf::Vector2i margin={100, 300});
  ~CustomTrainingContent();
	
	void draw(sf::RenderWindow *window);

	void scroll(int amount);
	void resetScroll();

	void handleMouseClick(sf::Vector2i mousePos);

private:
  CustomTrainingContent(const CustomTrainingContent &d);
  CustomTrainingContent operator=(const CustomTrainingContent &d);

  void setup();

	int width;
	sf::Vector2i margin;

	Text* trainingContentText;

};





