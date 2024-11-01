#include "SFML/Graphics.hpp"
#include <iostream>

#include "display.h"
#include "notes.h"

class Manager {
public:
  Manager();
  ~Manager() {}

  // TODO: Move control to another files
  // 	All states need to be managed elsewhere
  void run();

private:
  Manager(const Manager &m);
  Manager operator=(const Manager &m);

  Display display;

  Notes note1;
  Notes note2;
};
