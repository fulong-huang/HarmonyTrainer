#include "SFML/Graphics.hpp"
#include <iostream>
#include "rectangle.h"
#include "circle.h"
#include "text.h"
#include "customTrainingItem.h"
#include "customTrainingSetting.h"
#include "customTrainingContent.h"
#include "soundControl.h"

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

	void handleMouseClick(SoundControl* soundControl, sf::Vector2i mousePos);

	void scroll(int amount){
		if(this->currentPage == Page::SETTING){
			this->customTrainingSetting.scroll(amount);
		}
	}

private:
  CustomTraining(const CustomTraining &d);
  CustomTraining operator=(const CustomTraining &d);

	enum Page{
		LIST, SETTING, CONTENT,
	};

	std::vector<CustomTrainingItem*> items;
	CustomTrainingSetting customTrainingSetting;
	CustomTrainingContent customTrainingContent;

	sf::Vector2i margin;
	int width, height, gap;

	Page currentPage;
  void setup();

};



