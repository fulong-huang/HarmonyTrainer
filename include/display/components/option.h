#include "SFML/Graphics.hpp"
#include <iostream>
#include "rectangle.h"
#include "circle.h"

class Option{
	public:
		Option(sf::Vector2i position, sf::Vector2i dimension, int radius);
		~Option();

		void draw(sf::RenderWindow *window);
		bool handleMouseClick(sf::Vector2i mousePos);
	
		void scroll(int amount);
		void resetScroll();
	
	
	private:
		Option(const Option& o);
		Option operator=(const Option& o);

		void setup();
		sf::Vector2i position;
		sf::Vector2i dimension;
		int radius;

		Rectangle* background = NULL;
		Circle* dot1 = NULL;
		Circle* dot2 = NULL;
		Circle* dot3 = NULL;

};

