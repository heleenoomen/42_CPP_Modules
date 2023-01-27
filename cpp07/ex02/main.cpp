#include <iostream>

#include "Array.hpp"
#include "layout.hpp"

void arrayOfStrings() {
  try {
    std::cout << layout::cyanItalicBold
              << "Make an array of 5 strings, fill first two elements, then\n"
              << "print array:" << layout::reset << std::endl;
    Array<std::string> a(5);
    a[0] = "Goodbye!";
    a[1] = "Hello!";
    std::cout << layout::greenBold;
    for (unsigned int i = 0; i < a.size(); ++i)
      std::cout << '\t' << a[i] << '\n';
    std::cout << "\tArray size is: " << a.size() << '\n';
    std::cout << layout::reset << std::endl
              << layout::cyanItalicBold
              << "Try to acces the 100th element of the array:" << layout::reset
              << std::endl;
    std::cout << a[100] << '\n';
  } catch (std::exception& e) {
    std::cout << layout::redBold << "\tException: " << e.what() << layout::reset
              << '\n'
              << std::endl;
  }
}

void arrayOfFloats() {
  try {
    std::cout << layout::cyanItalicBold
              << "Make an array of 7 floats, fill 2nd and 3d element, then\n"
              << "print array:" << layout::reset << std::endl;
    Array<float> a(5);
    a[2] = 2.3f;
    a[3] = 4.1f;
    std::cout << layout::greenBold;
    for (unsigned int i = 0; i < a.size(); ++i)
      std::cout << '\t' << a[i] << '\n';
    std::cout << "\tArray size is: " << a.size() << '\n';
    std::cout << layout::reset << std::endl
              << layout::cyanItalicBold
              << "Try to acces the 8th element of the array:" << layout::reset
              << std::endl;
    std::cout << a[7] << '\n';
  } catch (std::exception& e) {
    std::cout << layout::redBold << "\tException: " << e.what() << layout::reset
              << '\n'
              << std::endl;
  }
}

void copyAssignment() {
  std::cout << layout::cyanItalicBold
            << "Make an array of 4 ints and fill all elements, then print\n"
            << "them:" << layout::reset << std::endl;
  Array<int> a1(4);
  a1[0] = 5;
  a1[1] = 7;
  a1[2] = 12;
  a1[3] = -39;
  std::cout << layout::greenBold;
  for (unsigned int i = 0; i < a1.size(); ++i)
    std::cout << '\t' << a1[i] << '\n';
  std::cout << "\tArray size is: " << a1.size() << '\n';
  std::cout << layout::reset << std::endl;
  std::cout << layout::cyanItalicBold
            << "Make a second array that is empty and and print it:"
            << layout::reset << std::endl
            << layout::greenBold;
  Array<int> a2;
  for (unsigned int i = 0; i < a2.size(); ++i)
    std::cout << '\t' << a2[i] << '\n';
  std::cout << "\tArray size is: " << a2.size() << '\n';
  std::cout << '\n'
            << layout::cyanItalicBold
            << "Assign the filled array to the empty array, then print the\n"
               "formerly empty array again:"
            << layout::reset << std::endl
            << layout::greenBold;
  a2 = a1;
  for (unsigned int i = 0; i < a2.size(); ++i)
    std::cout << '\t' << a2[i] << '\n';
  std::cout << "\tArray size is: " << a2.size() << '\n';
  std::cout << '\n'
            << layout::cyanItalicBold
            << "Change the first element of the second array to 3000, then\n"
            << "print the second array again:" << layout::reset << std::endl
            << layout::greenBold;
  a2[0] = 3000;
  for (unsigned int i = 0; i < a2.size(); ++i)
    std::cout << '\t' << a2[i] << '\n';
  std::cout << "\tArray size is: " << a2.size() << '\n';
  std::cout << '\n'
            << layout::cyanItalicBold
            << "Confirm that the first array remains unchanged:"
            << layout::reset << std::endl
            << layout::greenBold;
  for (unsigned int i = 0; i < a1.size(); ++i)
    std::cout << '\t' << a1[i] << '\n';
  std::cout << "\tArray size is: " << a1.size() << '\n';
}

void checkForLeaks() {
  std::cout << layout::reset << std::endl
            << layout::cyanItalicBold << "Check for leaks:" << layout::reset
            << layout::yellowBold << std::endl;
  system("leaks array");
  std::cout << std::endl;
}

void copyConstructor() {
  std::cout
      << layout::reset << std::endl
      << layout::cyanItalicBold
      << "Create an Array a of 6 doubles and assign values to some of its\n"
      << "elements. Print the Array:" << layout::reset << std::endl
      << layout::greenBold;
  Array<double>* a = new Array<double>(6);
  (*a)[0] = 3.14;
  (*a)[1] = 6.181;
  (*a)[2] = -15.1;
  (*a)[4] = -6;
  for (unsigned int i = 0; i < (*a).size(); ++i) {
    std::cout << '\t' << (*a)[i] << '\n';
  }
  std::cout << "\tArray size is: " << a->size() << '\n';
  std::cout << layout::reset << std::endl << layout::cyanItalicBold;
  std::cout << "Invoke the copy constructor to create Array b, a copy of\n"
            << "Array a. Delete Array a, then print array b to check if the\n"
            << "copy performed by the copy constructor was deep:\n"
            << layout::reset << std::endl
            << layout::greenBold;
  Array<double> b(*a);
  delete a;
  for (unsigned int i = 0; i < b.size(); ++i) {
    std::cout << '\t' << b[i] << '\n';
  }
  std::cout << "\tArray size is: " << b.size() << '\n';
}

int main() {
  arrayOfStrings();
  arrayOfFloats();
  copyAssignment();
  copyConstructor();
  checkForLeaks();
  return 0;
}
