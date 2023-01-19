#include <iostream>

#include "Array.hpp"
#include "Layout.hpp"

void arrayOfStrings() {
  try {
    std::cout << Layout::cyanItalicBold
              << "Make an array of 5 strings, fill first two elements, then\n"
              << "print array:" << Layout::reset << std::endl;
    Array<std::string> a(5);
    a[0] = "Goodbye!";
    a[1] = "Hello!";
    std::cout << Layout::greenBold;
    for (unsigned int i = 0; i < a.size(); ++i)
      std::cout << '\t' << a[i] << '\n';
    std::cout << Layout::reset << std::endl << Layout::cyanItalicBold
              << "Try to acces the 100th element of the array:"
              << Layout::reset << std::endl;
    std::cout << a[100] << '\n';
  } catch (std::exception& e) {
    std::cout << Layout::redBold << "\tException: " << e.what() << Layout::reset
              << '\n'
              << std::endl;
  }
}

void arrayOfFloats() {
  try {
    std::cout << Layout::cyanItalicBold
              << "Make an array of 7 floats, fill 2nd and 3d element, then\n"
              << "print array:" << Layout::reset << std::endl;
    Array<float> a(5);
    a[2] = 2.3f;
    a[3] = 4.1f;
    std::cout << Layout::greenBold;
    for (unsigned int i = 0; i < a.size(); ++i)
      std::cout << '\t' << a[i] << '\n';
    std::cout << Layout::reset << std::endl << Layout::cyanItalicBold
              << "Try to acces the 8th element of the array:"
              << Layout::reset << std::endl;
    std::cout << a[7] << '\n';
  } catch (std::exception& e) {
    std::cout << Layout::redBold << "\tException: " << e.what() << Layout::reset
              << '\n'
              << std::endl;
  }
}

void checkForLeaks() {
  std::cout << Layout::reset << std::endl << Layout::cyanItalicBold
            << "Check for leaks:"
            << Layout::reset << Layout::yellowBold << std::endl;
  system("leaks array");
  std::cout << std::endl;
}

int main() {
  arrayOfStrings();
  arrayOfFloats();
  checkForLeaks();
  return 0;
}
