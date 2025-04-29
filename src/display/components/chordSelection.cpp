#include "chordSelection.h"

SelectionDisplay::SelectionDisplay(sf::Vector2i position){
	this->background = new Circle(
			sf::Color(150, 150, 150),
			position,
			50,
			true
			);
	this->text = new Text(
			sf::Color(50, 50, 50),
			position,
			"M3",
			50,
			true,
			true);
}

SelectionDisplay::~SelectionDisplay(){
}

void SelectionDisplay::draw(sf::RenderWindow *window){
	this->background->draw(window);
	this->text->draw(window);
}


ChordSelection::ChordSelection(){
	this->selections.push_back(
			new SelectionDisplay({100, 450})
			);
	this->selections.push_back(
			new SelectionDisplay({250, 450})
			);
}

ChordSelection::~ChordSelection(){

}

void ChordSelection::draw(sf::RenderWindow *window){
	for(SelectionDisplay* selection : this->selections){
		selection->draw(window);
	}
}



