#include <iostream>

#include "lib.h"
#include "other_lib.h"

int main() {
  std::cout << message() << '\n'; 
  std::cout << otherMessage() << '\n';
  std::cout << otherLibMessage() << '\n';
}
