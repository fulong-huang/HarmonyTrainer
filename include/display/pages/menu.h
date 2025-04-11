#include "SFML/Graphics.hpp"
#include <iostream>
#include "rectangle.h"
#include "circle.h"
#include "text.h"

class Menu {
public:
  Menu();
  ~Menu();

	std::vector<sf::Drawable *> getDrawables();

private:
  Menu(const Menu &d);
  Menu operator=(const Menu &d);
  std::vector<sf::Drawable *> drawables;
	std::vector<Shape *> shapes;

  void setup();

};


