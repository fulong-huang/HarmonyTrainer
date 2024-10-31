#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

// TODO: Move notes to other files
#include "notes.h"

const int FRAMERATE = 30;

class Display{
	public:
		Display();
		~Display();

		// TODO: Move control to another files
		// 	All states need to be managed elsewhere
		void run();

		void draw(sf::RenderWindow& window);
		void handleMouseClick(sf::Vector2i mousePos);

		void addShape(sf::Drawable*);

	private:
		Display(const Display& d);
		Display operator=(const Display& d);
		sf::RenderWindow window;
		std::vector<sf::Drawable *> drawables;

		void setup();

		// TODO: Move notes out of display
		Notes note1;
		Notes note2;
};
