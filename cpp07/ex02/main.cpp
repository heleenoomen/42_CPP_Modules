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

void copyAssignment() {
  std::cout << Layout::cyanItalicBold
            << "Make an array of 4 ints and fill all elements, then print\n" 
            << "them:" << Layout::reset << std::endl;
  Array<int> a1(4);
  a1[0] = 5;
  a1[1] = 7;
  a1[2] = 12;
  a1[3] = -39;
  std::cout << Layout::greenBold;
  for (unsigned int i = 0; i < a1.size(); ++i) std::cout << '\t' << a1[i] << '\n';
  std::cout << Layout::reset << std::endl;
  std::cout << Layout::cyanItalicBold
            << "Make a second array that is empty and and print it:\n"
            << Layout::greenBold;
  Array<int> a2;
  for (unsigned int i = 0; i < a2.size(); ++i) std::cout << '\t' << a2[i] << '\n';
  std::cout << '\n' << Layout::cyanItalicBold
            << "Assign the filled array to the empty array, then print the\n"
               "formerly empty array again:"
            << Layout::reset << std::endl << Layout::greenBold;
  a2 = a1;
  for (unsigned int i = 0; i < a2.size(); ++i) std::cout << '\t' << a2[i] << '\n';
  std::cout << '\n' << Layout::cyanItalicBold
            << "Change the first element of the second array to 3000, then\n"
            << "print the second array again:"
            << Layout::reset << std::endl << Layout::greenBold;
  a2[0] = 3000;
  for (unsigned int i = 0; i < a2.size(); ++i) std::cout << '\t' << a2[i] << '\n';
  std::cout << '\n' << Layout::cyanItalicBold
            << "Confirm that the first array remains unchanged:"
            << Layout::reset << std::endl << Layout::greenBold;
  for (unsigned int i = 0; i < a1.size(); ++i) std::cout << '\t' << a1[i] << '\n';
}

void checkForLeaks() {
  std::cout << Layout::reset << std::endl << Layout::cyanItalicBold
            << "Check for leaks:"
            << Layout::reset << Layout::yellowBold << std::endl;
  system("leaks array");
  std::cout << std::endl;
}

void copyConstructor() {
  std::cout << Layout::reset << std::endl << Layout::cyanItalicBold
           << "Create an Array a of 6 doubles and assign values to some of its\n"
           << "elements. Print the Array:"
           << Layout::reset << std::endl << Layout::greenBold;
  Array<double>* a = new Array<double>(6);
  (*a)[0] = 3.14;
  (*a)[1] = 6.181;
  (*a)[2] = -15.1;
  (*a)[4] = -6;
  for (unsigned int i = 0; i < (*a).size(); ++i) {
    std::cout << '\b' << (*a)[i] << '\n';
  }
  std::cout << Layout::reset << std::endl << Layout::cyanItalicBold;
  std::cout << "Invoke the copy constructor to create Array b, a copy of\n"
            << "Array a. Delete Array a, then print array b to check if the\n"
            << "copy performed by the copy constructor was deep:\n"
            << Layout::reset << std::endl << Layout::greenBold;
  Array<double> b(*a);
  delete a;
  for (unsigned int i = 0; i < b.size(); ++i) {
    std::cout << '\b' << b[i] << '\n';
  }
}

int main() {
  arrayOfStrings();
  arrayOfFloats();
  copyAssignment();
  copyConstructor();
  checkForLeaks();
  return 0;
}
