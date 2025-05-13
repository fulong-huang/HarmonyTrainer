#include "SFML/Graphics.hpp"
#include <iostream>
#include "rectangle.h"
#include "circle.h"
#include "text.h"

class CustomTrainingContent {
public:
  CustomTrainingContent(int width=0,
			sf::Vector2i margin={100, 100},
			int padding = 20);
  ~CustomTrainingContent();
	
	void draw(sf::RenderWindow *window);

	void scroll(int amount);
	void resetScroll();

	void handleMouseClick(sf::Vector2i mousePos);

	void open(std::string name);
	
	void changeWidth(int newWidth);

private:
  CustomTrainingContent(const CustomTrainingContent &d);
  CustomTrainingContent operator=(const CustomTrainingContent &d);

  void setup();

	sf::Vector2i margin;
	int width;
	int padding;

	Text* trainingContentTitle = NULL;
	Text* trainingContentName = NULL;

};





