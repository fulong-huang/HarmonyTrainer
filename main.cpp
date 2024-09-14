#include <iostream>
#include "display.h"

int main(){
	std::cout << "HELLO WORLD" << std::endl;
	Display display;
	display.run();
	std::cout << "BYE WORLD" << std::endl;
	return 0;
}

