#include "SFML/Graphics.hpp"
#include <iostream>
#include "rectangle.h"
#include "text.h"

class Menu {
public:
  Menu(sf::Vector2i pos, int width, int height,
			sf::Vector2i padding={0, 0}, sf::Vector2i margin={0, 0});
  ~Menu();

	std::vector<sf::Drawable *> getDrawables();

private:
  Menu(const Menu &d);
  Menu operator=(const Menu &d);
  std::vector<sf::Drawable *> drawables;

  void setup();
	sf::Vector2i position;
	sf::Vector2i padding;
	sf::Vector2i margin;
	int width;
	int height;
};


