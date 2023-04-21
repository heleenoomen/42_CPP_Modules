#include <iostream>
#include <vector>

int main() {
  std::vector<int> l;
  l.push_back(2);
  l.push_back(-4);
  l.push_back(3);
  l.push_back(5);
  l.push_back(1);

  std::vector<int>::iterator it = l.begin();
  std::advance(it, 2);
  std::cout << *it << '\n';
}