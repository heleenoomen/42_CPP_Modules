#include <iostream>
#include <string>

#include "Layout.hpp"
#include "iter.h"

void printStars() {
  std::cout << "\n\t   ";
  for (int i = 0; i < 3; ++i) std::cout << Layout::emojiStar;
  std::cout << "\n\n";
}

void printTestTimesTwo() {
  std::cout << Layout::green << "Test " << Layout::cyanBold << "iter"
            << Layout::green
            << " timesTwo() function on:\n"
               "int array[5] = {1, 3, 5, 6, 9}\n\n"
            << Layout::brightYellow;
}

void printTestWithTemplate() {
  std::cout << '\n';
  std::cout << Layout::green << "Test " << Layout::cyanBold << "iter"
            << Layout::green
            << " instantiated template function\n"
               "testTemplate() on:\n"
               "float arrayF[5] = {3.2f, 5.8f, 7.0f, 18.4f, 47.33f}\n\n"
            << Layout::brightYellow;
}

void printTestWithStringManip() {
  std::cout << '\n';
  std::cout
      << Layout::green << "Test " << Layout::cyanBold << "iter" << Layout::green
      << " strToUpper() function on:\n"
      << "std::string s[5] = {\"Hello you!\", \"Coca-Cola\", \"Love C++\",\n"
      << "\"Sunny days\", \"Please Go to 4aBxl16$\"}\n\n"
      << Layout::brightYellow;
}

void timesTwo(int& value) { value *= 2; }

void strToUpper(std::string& s) {
  std::string::iterator it;
  for (it = s.begin(); it != s.end(); ++it) *it = std::toupper(*it);
}

void testWithNormalFunction() {
  printTestTimesTwo();
  int array[5] = {1, 3, 5, 6, 9};
  iter<int>(array, 5, &timesTwo);
  for (int i = 0; i < 5; ++i) std::cout << '\t' << array[i] << '\n';
}

void testWithStringManip() {
  printTestWithStringManip();
  std::string s[5] = {"Hello you!", "Coca-Cola", "Love C++", "Sunny days",
                      "Please Go to 4aBxl16$"};
  iter<std::string>(s, 5, &strToUpper);
  std::cout << Layout::brightYellow;
  for (int i = 0; i < 5; ++i) std::cout << '\t' << s[i] << '\n';
}

void testWithTemplate() {
  printTestWithTemplate();
  float arrayF[5] = {3.2f, 5.8f, 7.0f, 18.4f, 47.33f};
  iter<float>(arrayF, 5, &testTemplate<float>);
  std::cout << Layout::brightYellow;
  for (int i = 0; i < 5; ++i) std::cout << '\t' << arrayF[i] << '\n';
}

int main() {
  printStars();
  testWithNormalFunction();
  testWithStringManip();
  testWithTemplate();
  printStars();
}
