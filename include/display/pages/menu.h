#include "SFML/Graphics.hpp"
#include <iostream>
#include "rectangle.h"
#include "circle.h"
#include "text.h"

class Menu {
public:
  Menu();
  ~Menu();


private:
  Menu(const Menu &d);
  Menu operator=(const Menu &d);

  void setup();

};


