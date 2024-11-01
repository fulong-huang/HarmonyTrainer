#include "SFML/Graphics.hpp"
#include <iostream>

const int FRAMERATE = 30;

class Display {
public:
  Display();
  ~Display();

  sf::RenderWindow window;

  void draw(sf::RenderWindow &window);
  void handleMouseClick(sf::Vector2i mousePos);

  void addShape(sf::Drawable *);

private:
  Display(const Display &d);
  Display operator=(const Display &d);
  std::vector<sf::Drawable *> drawables;

  void setup();
};
