#include "rectangle.h"
#include <iostream>

Rectangle::Rectangle(sf::Color color, sf::Vector2i pos, int width, int height,
		bool transparent, float outlineThickness, sf::Color outlineColor): 
	color(color), pos(pos), width(width), height(height), 
	transparent(transparent), outlineThickness(outlineThickness), outlineColor(outlineColor)
{
	this->shape.setSize({float(this->width), float(this->height)});
	if(this->transparent){
		this->shape.setFillColor(sf::Color::Transparent);
	}
	else{
		this->shape.setFillColor(this->color);
		if(this->outlineThickness){
			this->shape.setOutlineThickness(this->outlineThickness);
			this->shape.setOutlineColor(this->outlineColor);
		}
	};
	this->setPosition({this->pos.x, this->pos.y});
};

Rectangle::~Rectangle(){

};

Rectangle::Rectangle(const Rectangle& c):
	color(c.color), pos(c.pos), width(c.width), height(c.height), transparent(c.transparent)
{
	this->shape.setSize({float(this->width), float(this->height)});
	if(this->transparent){
		this->shape.setFillColor(sf::Color::Transparent);
	}
	else{
		this->shape.setFillColor(this->color);
	};
	this->setPosition({this->pos.x, this->pos.y});
};

Rectangle Rectangle::operator=(const Rectangle
	& c){
	this->color = c.color;
	this->width = c.width;
	this->height = c.height;
	this->pos = c.pos;
	this->transparent = c.transparent;
	this->shape.setSize({float(this->width), float(this->height)});
	if(this->transparent){
		this->shape.setFillColor(sf::Color::Transparent);
	}
	else{
		this->shape.setFillColor(this->color);
	};
	this->setPosition({this->pos.x, this->pos.y});
	return *this;
};

void Rectangle::draw(sf::RenderWindow *window){
	window->draw(this->shape);
};

void Rectangle::setColor(sf::Color color){
	this->setTransparency(false);
	this->color = color;
	this->shape.setFillColor(color);
};

void Rectangle::setPosition(sf::Vector2i pos) {
	this->scrollPosition = 0;
	this->pos = pos;
	this->shape.setPosition(this->pos.x, this->pos.y);
};

void Rectangle::setSize(int width, int height){
	this->width = width;
	this->height = height;
	this->shape.setSize({float(this->width), float(this->height)});
};

void Rectangle::setTransparency(bool transparent){
	this->transparent = transparent;
	if(this->transparent){
		this->shape.setFillColor(sf::Color::Transparent);
	}
	else{
		this->shape.setFillColor(this->color);
	}
};

sf::Color Rectangle::getColor() {
	return this->color;
};

sf::Vector2i Rectangle::getPosition() {
	return this->pos;
};
sf::Vector2i Rectangle::getSize() {
	return {this->width, this->height};
};

bool Rectangle::boundCheck(sf::Vector2i pos) {
	bool inBound = !this->transparent &&
		this->pos.x <= pos.x &&
		this->pos.y <= pos.y &&
		this->pos.x + this->width >= pos.x &&
		this->pos.y + this->height >= pos.y;
	return inBound;
};

void Rectangle::scroll(int amount){
	this->scrollPosition += amount;
	if(this->scrollPosition > 0){
		this->scrollPosition = 0;
	}
	this->shape.setPosition(this->pos.x, this->pos.y + this->scrollPosition);
}

void Rectangle::resetScroll(){
	this->scrollPosition = 0;
	this->shape.setPosition(this->pos.x, this->pos.y);
}


