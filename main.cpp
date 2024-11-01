#include "manager.h"
#include <iostream>

int main() {
  std::cout << "Running" << std::endl;
  Manager manager;
  manager.run();
  std::cout << "Stopped" << std::endl;
  return 0;
}
