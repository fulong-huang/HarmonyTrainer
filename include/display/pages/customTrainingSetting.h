#include "SFML/Graphics.hpp"
#include <iostream>
#include "rectangle.h"
#include "circle.h"
#include "text.h"
#include "chordSelection.h"

class CustomTrainingSetting {
public:
  CustomTrainingSetting(int width=800);
  ~CustomTrainingSetting();
	
	void draw(sf::RenderWindow *window);

	void handleMouseClick(sf::Vector2i mousePos);

	void scroll(int amount);


private:
  CustomTrainingSetting(const CustomTrainingSetting &d);
  CustomTrainingSetting operator=(const CustomTrainingSetting &d);

  void setup();

	ChordSelection chordsSetting;

	int width;
	int margin = 100;

	Text* trainingSettingText;

	int scrollPosition; 


};





