#include "SFML/Graphics.hpp"
#include <iostream>
#include <chrono>
#include <ctime>

#include "notes.h"
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

	Menu menu;
	CustomTraining customTraining;


	int width, height;

  Notes note1;
  Notes note2;
	Notes note3;

	bool isRunning; 
	bool isPlaying;


	void generateRandomNote();
};
