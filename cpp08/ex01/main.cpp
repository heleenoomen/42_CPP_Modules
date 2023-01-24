#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <set>

#include "Span.hpp"

void subjectPDF() {
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
}

void addTooManyNbrs() {
  Span sp(10);
  try {
    for (int i = 0; i < 11; ++i) sp.addNumber(i * 3);
  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
  }
}

void unsortedNbrs() {
  Span sp(8);
  sp.addNumber(-9);
  sp.addNumber(3);
  sp.addNumber(15);
  sp.addNumber(400);
  sp.addNumber(36);
  sp.addNumber(89);
  sp.addNumber(2);
  sp.addNumber(7);
  std::cout << sp.longestSpan() << std::endl;
  std::cout << sp.shortestSpan() << std::endl;
}

void sortedNbrs() {
  Span sp(8);
  sp.addNumber(-9);
  sp.addNumber(2);
  sp.addNumber(3);
  sp.addNumber(7);
  sp.addNumber(15);
  sp.addNumber(36);
  sp.addNumber(89);
  sp.addNumber(400);
  std::cout << sp.longestSpan() << std::endl;
  std::cout << sp.shortestSpan() << std::endl;
}

void tooFewElements() {
  Span sp(8);
  try {
    std::cout << sp.longestSpan() << std::endl;
    std::cout << sp.shortestSpan() << std::endl;
  } catch (std::exception& e) {
    std::cout << "Exception: " << e.what() << '\n';
  }
  sp.addNumber(9);
  try {
    std::cout << sp.longestSpan() << std::endl;
    std::cout << sp.shortestSpan() << std::endl;
  } catch (std::exception& e) {
    std::cout << "Exception: " << e.what() << '\n';
  }
}

int main() {
  subjectPDF();
  addTooManyNbrs();
  unsortedNbrs();
  sortedNbrs();
  tooFewElements();
  return 0;
}
