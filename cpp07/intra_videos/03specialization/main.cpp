#include <string>
#include <iostream>

#include "Pair.class.hpp"

int main() {
  Pair<int, int> p1(4, 2);
  Pair<std::string, float> p2(std::string("Pi"), 3.14f);
  Pair<float, bool> p3(3.2f, true);
  Pair<bool, bool> p4(true, false);

  std::cout << p1 << '\n';
  std::cout << p2 << '\n';
  std::cout << p3 << '\n';
  std::cout << p4 << '\n';

  return 0;
}
