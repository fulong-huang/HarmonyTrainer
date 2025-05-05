#include "SFML/Graphics.hpp"
#include <iostream>
#include "rectangle.h"
#include "circle.h"
#include "text.h"
#include "notes.h"

class ChordSelectionItem{
public:
	ChordSelectionItem(sf::Vector2i position, std::string name);
	~ChordSelectionItem();

	void draw(sf::RenderWindow *window);
	void setPosition(sf::Vector2i position);
	void scroll(int amount);

	void resetScroll(){
		this->scrollPosition = 0;
		this->background->setPosition(position);
		this->text->setPosition(position);
	}
	

	// Not needed? size is part of the input during construction;
	sf::Vector2i getSize();


private:
  ChordSelectionItem(const ChordSelectionItem &s);
  ChordSelectionItem operator=(const ChordSelectionItem &s);

	Circle *background;
	Text *text;

	int scrollPosition = 0;
	sf::Vector2i position;


};

class ChordSelection {
public:
	// TODO: Add the following items 
	// 	width for width of screen
	// 	height for starting Y position
	// 	margin for spaces(margin) on both side
	// 	(Optional) circle size
  ChordSelection();
  ~ChordSelection();
	
	// TODO: 
	// 	Create new custom training
	void createTraining();
	void setStartPosition(int startHeight);
	
	void scroll(int amount);
	void resetScroll();


	void draw(sf::RenderWindow *window);

	void handleMouseClick(sf::Vector2i mousePos);


private:
  ChordSelection(const ChordSelection &c);
  ChordSelection operator=(const ChordSelection &c);

  void setup();

	int startHeight = 300;
	int scrollPosition = 0;
	int maxWidth = 800;
	int margin = 60;
	int padding = 50;

	std::vector<ChordSelectionItem*> selections;


};





