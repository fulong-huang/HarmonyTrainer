#include "SFML/Graphics.hpp"
#include <iostream>
#include "menu.h"

const int FRAMERATE = 30;

class Display {
public:
  Display(int width, int height);
  ~Display();

  sf::RenderWindow window;

  void draw();
  void handleMouseClick(sf::Vector2i mousePos);

  void addShape(sf::Drawable *);

private:
  Display(const Display &d);
  Display operator=(const Display &d);
  std::vector<sf::Drawable *> drawables;
	Menu menu;

  void setup();
	int width;
	int height;
};
