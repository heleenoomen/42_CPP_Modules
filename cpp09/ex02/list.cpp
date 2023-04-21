#include <algorithm>
#include <iostream>
#include <list>

int main() {
  std::list<int> l;
  l.push_back(2);
  l.push_back(-4);
  l.push_back(3);
  l.push_back(5);
  l.push_back(1);

  // std::list<int>::iterator it = l.begin();
  // std::advance(it, 2);
  // std::cout << *it << '\n';
  std::cout << std::distance(l.begin(), l.begin()) << '\n';
  // if (std::distance(l.end(), l.begin()) >= 0) std::cout << "valid\n";
}