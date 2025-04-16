#include "SFML/Graphics.hpp"
#include <iostream>
#include <chrono>
#include <ctime>

#include "soundControl.h"
#include "menu.h"
#include "customTraining.h"

const int FRAMERATE = 30;
class Manager {
public:
  Manager();
  ~Manager();

  // TODO: Move control to another files
  // 	All states need to be managed elsewhere
  void run();

private:
  Manager(const Manager &m);
  Manager operator=(const Manager &m);

  sf::RenderWindow window;

  void draw();
  void handleMouseClick(sf::Vector2i mousePos);

	CustomTraining customTraining;


	// Display: 
	int width, height;

	bool isRunning; 

};
