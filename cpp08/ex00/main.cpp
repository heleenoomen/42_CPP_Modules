#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <array>
#include <forward_list>

#include "easyfind.hpp"

namespace testconst {
static int const firstElem = 3;
static int const secondElem = 15;
static int const thirdElem = -27;
static int const fourthElem = 38;
};  // namespace testconst

template <typename Container>
void testFilledContainer(Container& c) {
  try {
    std::cout << *::easyfind(c, -3) << '\n';
  } catch (std::exception& e) {
    std::cout << e.what() << '\n';
  }
  try {
    std::cout << *::easyfind(c, -27) << '\n';
  } catch (std::exception& e) {
    std::cout << e.what() << '\n';
  }
}

template <typename Container>
void fillContainer(Container& c) {
  c.push_back(testconst::firstElem);
  c.push_back(testconst::secondElem);
  c.push_back(testconst::thirdElem);
  c.push_back(testconst::fourthElem);
}

template <typename Container>
void testContainer() {
  Container c;
  fillContainer(c);
  testFilledContainer<Container>(c);
}

void testArray() {
  std::array<int, 4> arr;
  arr[0] = testconst::firstElem;
  arr[1] = testconst::secondElem;
  arr[2] = testconst::thirdElem;
  arr[3] = testconst::fourthElem;
  testFilledContainer(arr);
}

void testForwardList() {
  std::forward_list<int> f;
  f.push_front(testconst::fourthElem);
  f.push_front(testconst::thirdElem);
  f.push_front(testconst::secondElem);
  f.push_front(testconst::firstElem);
  testFilledContainer(f);
}
int main() {
  testContainer<std::vector<int> >();
  testContainer<std::list<int> >();
  testContainer<std::deque<int> >();
  testArray();
  testForwardList();
  return 0;
}