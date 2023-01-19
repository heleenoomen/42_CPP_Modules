#include <iostream>

#include "Vertex.class.cpp"

int main() {
  Vertex<int> v1(12, 23, 34);
  Vertex<> v2(12, 23, 34);
  std::cout << v1 << '\n';
  std::cout << v2 << '\n';
  return 0;
}
