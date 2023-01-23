#include <iostream>
#include <string>
#include <vector>

#include "easyfind.hpp"

int main() {
  std::vector<int> v;
  v.push_back(3);
  v.push_back(15);
  v.push_back(-27);
  v.push_back(58);

  try {
    std::cout << *easyfind(v, -3) << '\n';
  } catch (std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  return 0;
}