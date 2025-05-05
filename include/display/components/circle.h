#pragma once

#include "SFML/Graphics.hpp"
#include "shape.h"

class Circle : public Shape{
public:
	Circle(sf::Color color, sf::Vector2i pos, int radius,
			bool centered = false, bool transparent = false);
	~Circle();
	Circle(const Circle& c);
	Circle operator=(const Circle& c);

	void draw(sf::RenderWindow *window) override;
	void setColor(sf::Color color) override;
	void setPosition(sf::Vector2i pos) override;
	void setSize(int r, int diff) override;
	void setTransparency(bool transparent) override;

	sf::Color getColor() override;
	sf::Vector2i getPosition() override;
	sf::Vector2i getSize() override;

	bool boundCheck(sf::Vector2i pos) override;
private:
	sf::CircleShape shape;
	sf::Color color;
	sf::Vector2i pos;
	bool transparent, centered;
	int radius;

};
