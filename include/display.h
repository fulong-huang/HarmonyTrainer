#include "SFML/Graphics.hpp"
const int FRAMERATE = 30;

class Display{
public:
    Display();
	~Display();

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
};
