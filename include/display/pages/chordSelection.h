#include "SFML/Graphics.hpp"
#include <iostream>
#include "rectangle.h"
#include "circle.h"
#include "text.h"

class SelectionDisplay{
public:
	SelectionDisplay(sf::Vector2i position);
	~SelectionDisplay();

	void draw(sf::RenderWindow *window);

private:
  SelectionDisplay(const SelectionDisplay &s);
  SelectionDisplay operator=(const SelectionDisplay &s);

	Circle *background;
	Text *text;


};

class ChordSelection {
public:
	// width for width of screen
	// position for height of scroll
	// margin for spaces(margin) on both side
  ChordSelection();
  ~ChordSelection();
	
	// TODO: 
	// 	Create new custom training
	void createTraining();

	void draw(sf::RenderWindow *window);

	void handleMouseClick(sf::Vector2i mousePos);


private:
  ChordSelection(const ChordSelection &c);
  ChordSelection operator=(const ChordSelection &c);

  void setup();

	int startPos = 300;
	int scrollPos = 0;

	std::vector<SelectionDisplay*> selections;

};





