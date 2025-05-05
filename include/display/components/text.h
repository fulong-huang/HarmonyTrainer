#pragma once
#include <filesystem>
#include <iostream>
#include "shape.h"

class Text : public Shape{
public:
	Text(sf::Color color, sf::Vector2i pos, std::string str, int fontSize = 50,
			bool centered=false, bool verticalCentered=false, bool transparent = false, sf::Uint32 style = 0,
			int maxWidth = 700);
	~Text() override;
	Text(const Text& t);
	Text operator=(const Text& t);

	void draw(sf::RenderWindow *window) override;
	sf::Text* getTextObject();
	void setColor(sf::Color color) override;
	void setPosition(sf::Vector2i pos) override;
	void setSize(int width, int height) override;
	void setTransparency(bool transparent) override;

	sf::Color getColor() override;
	sf::Vector2i getPosition() override;
	sf::Vector2i getSize() override;

	void setString(std::string str);

	bool boundCheck(sf::Vector2i pos) override;
	
	void setText(std::string str);
	void recenter();
	std::string getText();
private:
	void findDimensions();
	void setup();
	
	sf::Text text;
	sf::Color color;
	sf::Vector2i pos;
	sf::Uint32 style;
	std::string str;
	int fontSize;
	int maxWidth;
	bool transparent;
	bool centered, verticalCentered;

};



