#include "shape.h"

class Rectangle : public Shape{
public:
	Rectangle(sf::Color color, sf::Vector2i pos, int width, int height, 
			bool transparent = false, float outlineThickness = 0, sf::Color outlineColor = sf::Color::Transparent);
	~Rectangle() override;
	Rectangle(const Rectangle& c);
	Rectangle operator=(const Rectangle& c);

	sf::Drawable* getDrawable() override;
	void setColor(sf::Color color) override;
	void setPosition(sf::Vector2i pos) override;
	void setSize(int r, int diff) override;
	void setTransparency(bool transparent) override;

	sf::Color getColor() override;
	sf::Vector2i getPosition() override;
	sf::Vector2i getSize() override;

	bool boundCheck(sf::Vector2i pos) override;
private:
	sf::RectangleShape shape;
	sf::Color color;
	sf::Vector2i pos;
	int width;
	int height;
	bool transparent;
	float outlineThickness;
	sf::Color outlineColor;

};



