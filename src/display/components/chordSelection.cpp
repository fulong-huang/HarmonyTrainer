#include "chordSelection.h"

ChordSelectionItem::ChordSelectionItem(sf::Vector2i position, std::string name){
	this->background = new Circle(
			sf::Color(150, 150, 150),
			position,
			50,
			true
			);
	this->text = new Text(
			sf::Color(50, 50, 50),
			position,
			name,
			50,
			true,
			true);
}

ChordSelectionItem::~ChordSelectionItem(){
}

void ChordSelectionItem::draw(sf::RenderWindow *window){
	this->background->draw(window);
	this->text->draw(window);
}

void ChordSelectionItem::setPosition(sf::Vector2i position){
	this->background->setPosition(position);
	this->text->setPosition(position);
}


ChordSelection::ChordSelection(){
	// chord selections are set amount, thus hard coded;
	int diameter = 100;

	int currX = this->margin + diameter / 2;
	int currY = this->startHeight;
	for(std::string chordName : NoteStepNames){
		this->selections.push_back(
				new ChordSelectionItem({currX, currY}, chordName)
				);
		currX += diameter + this->padding;
		if(currX > this->maxWidth - diameter - this->margin){
			currX = this->margin + diameter / 2;
			currY += diameter + this->padding;
		}
	}

}

ChordSelection::~ChordSelection(){

}

void ChordSelection::draw(sf::RenderWindow *window){
	for(ChordSelectionItem* selection : this->selections){
		selection->draw(window);
	}
}



