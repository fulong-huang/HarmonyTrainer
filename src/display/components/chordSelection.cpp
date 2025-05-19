#include "chordSelection.h"

ChordSelectionItem::ChordSelectionItem(sf::Vector2i position, std::string name):
	position(position)
{
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
	delete this->background;
	delete this->text;
}

void ChordSelectionItem::draw(sf::RenderWindow *window){
	this->background->draw(window);
	this->text->draw(window);
}

void ChordSelectionItem::setPosition(sf::Vector2i position){
	this->background->setPosition(position);
	this->text->setPosition(position);
	this->position = position;
}

void ChordSelectionItem::scroll(int amount){
	this->background->scroll(amount);
	this->text->scroll(amount);
}
void ChordSelectionItem::resetScroll(){
	this->background->resetScroll();
	this->text->resetScroll();
}
	


ChordSelection::ChordSelection(){
	// chord selections are set amount, thus hard coded;
	int diameter = 100;

	int currX = this->margin + diameter / 2;
	int currY = this->startHeight;
	bool alterRows = false;
	for(std::string chordName : NoteStepNames){
		this->selections.push_back(
				new ChordSelectionItem({currX, currY}, chordName)
				);
		currX += diameter + this->padding;
		if(currX > this->maxWidth - diameter - this->margin){
			currX = this->margin + diameter / 2;
			currY += diameter + this->padding;
			alterRows = !alterRows;
			if(alterRows){
				currX += this->padding / 2 + diameter/2;
			}
		}
	}

}

ChordSelection::~ChordSelection(){
	for(ChordSelectionItem* item: this->selections){
		delete item;
	}
}

void ChordSelection::draw(sf::RenderWindow *window){
	for(ChordSelectionItem* selection : this->selections){
		selection->draw(window);
	}
}

void ChordSelection::scroll(int amount){
	for(ChordSelectionItem* item : this->selections){
		item->scroll(amount);
	}
}

void ChordSelection::resetScroll(){
	for(ChordSelectionItem* item: this->selections){
		item->resetScroll();
	}
}



