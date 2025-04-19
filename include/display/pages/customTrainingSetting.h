#include "SFML/Graphics.hpp"
#include <iostream>
#include "rectangle.h"
#include "circle.h"
#include "text.h"

class CustomTrainingSetting {
public:
  CustomTrainingSetting(int width=0, sf::Vector2i margin={100, 300});
  ~CustomTrainingSetting();
	
	void draw(sf::RenderWindow *window);

	void handleMouseClick(sf::Vector2i mousePos);

private:
  CustomTrainingSetting(const CustomTrainingSetting &d);
  CustomTrainingSetting operator=(const CustomTrainingSetting &d);

  void setup();

	int width;
	sf::Vector2i margin;

	Text* trainingSettingText;

};





