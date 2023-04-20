#include <iostream>
#include <list>

int main() {
  std::list<int> l_;
  l_.push_back(1);
  l_.push_back(3);
  l_.push_back(5);
  for (std::list<int>::iterator it = l_.begin(); it != l_.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
  l_.insert(l_.end(), 2);
  for (std::list<int>::iterator it = l_.begin(); it != l_.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
  // std::list<int>::iterator it = l_.begin();
  // it = it--;
}