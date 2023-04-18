#include <iostream>
#include <vector>

int main() {
  std::vector<int> v;
  std::vector<int>::iterator ib = v.begin();
  std::vector<int>::iterator ie = v.end();
  if (ib == ie) std::cout << "Same!\n";
  std::cout << "Size = " << v.size() << std::endl;
}