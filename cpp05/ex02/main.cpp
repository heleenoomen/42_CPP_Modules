#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iomanip>
#include <iostream>
#include <string>

/* ************************************************************************** */
/* Print utils                                                                */
/* ************************************************************************** */

static int const testHeaderWidth = 56;

#ifndef to_file
static char const* redBold = "\033[31;1m";
static char const* resetLayout = "\033[0m";
static char const* cyanBold = "\033[36;1m";
static char const* cyanItalic = "\033[36;3m";
#else
static char const* redBold = "";
static char const* resetLayout = "";
static char const* cyanBold = "";
static char const* cyanItalic = "";
#endif

void printStars() {
  for (int i = 0; i < testHeaderWidth; ++i)
    std::cout << "*";
}

void printTestHeader(char const* testname) {
  std::cout << cyanBold;
  printStars();
  std::cout << "\n";
  std::cout << "* " << std::left << std::setw(testHeaderWidth - 3)
            << testname << "*\n";
  printStars();
  std::cout << "\n" << resetLayout;
}

void printTestTrailer() {
  std::cout << cyanBold;
  printStars();
  std::cout << "\n\n\n" << resetLayout;
}

/* ************************************************************************** */
/* Test utils                                                                 */
/* ************************************************************************** */

void testInsertionOverloadForm(char const* message, AForm const& f) {
    std::cout << cyanItalic
              << message
              << "Print form:\n"
              << resetLayout
              << f 
              << '\n';
}

void testInsertionOverloadBureaucrat(char const* message, Bureaucrat const& b) {
  std::cout << cyanItalic
            << message
            << "Print bureaucrat:\n"
            << resetLayout
            << b 
            << '\n';
}

void testSignForm(Bureaucrat const& b, AForm& f) {
    std::cout << cyanItalic
              << "Let bureaucrat " << b.getName()
              << " try to sign " << f.getName() << ":\n"
              << resetLayout;
    b.signForm(f);
}

void testExecuteForm(Bureaucrat const& b, AForm& f) {
  std::cout << cyanItalic
            << "Let bureaucrat " << b.getName()
            << " try to execute " << f.getName() << ":\n"
            << resetLayout;
  b.executeForm(f);
}

// void tryToConstructForm(char const* name, int gradeToExecute,
// int gradeToSign) {
//   try {
//     AForm f(name, gradeToExecute, gradeToSign);
//     testInsertionOverloadForm("Form created. ", f);
//   }     
//   catch(std::exception &e) {
//     std::cerr << redBold
//               << "Standard exception: " << e.what() << '\n'
//               << resetLayout;
//   }
// }

// void tryToSignForm(char const* bureacratName, int bureacratGrade,
// char const* formName, int gradeToSign, int gradeToExecute) {
//   try {
//     Bureaucrat b(bureacratName, bureacratGrade);
//     testInsertionOverloadBureaucrat("Bureaucrat created. ", b);
//     AForm f(formName, gradeToSign, gradeToExecute);
//     testInsertionOverloadForm("Form created. ", f);
//     testSignForm(b, f);
//     testInsertionOverloadForm("", f);
//   }
//   catch(std::exception &e) {
//     std::cerr << redBold
//               << "Standard exception: " << e.what() << '\n'
//               << resetLayout;
//   }
// }

// /* ************************************************************************** */
// /* Tests                                                                      */
// /* ************************************************************************** */

void testShrubbery() {
  printTestHeader("Execute Shrubbery Creation Form correctly");
  try {
    Bureaucrat benji("Benji", ShrubberyCreationForm::gradeRequiredToExecute);
    testInsertionOverloadBureaucrat("Bureaucrat Benji created. ", benji);
    Bureaucrat benjisSecretary("Benji's secretary", ShrubberyCreationForm::gradeRequiredToSign);
    testInsertionOverloadBureaucrat("Bureaucrat Benji's secretary created. ", benjisSecretary);
    ShrubberyCreationForm newShrubForm("Shrubbery Plan 13b", "City Park 789");
    testInsertionOverloadForm("Shrubbery Plan 13b created. ", newShrubForm);
    testExecuteForm(benji, newShrubForm);
    testSignForm(benjisSecretary, newShrubForm);
    testExecuteForm(benji, newShrubForm);
    testExecuteForm(benji, newShrubForm);
    testExecuteForm(benjisSecretary, newShrubForm);
  }
  catch (std::exception& e) {
    std::cerr << redBold
              << "Standard exception: "
              << e.what()
              << '\n'
              << resetLayout;
  }
}

// void test


/* ************************************************************************** */
/* Main                                                                       */
/* ************************************************************************** */

int main() {

  testShrubbery();
  // constructFormWithValidGrades();
  // constructFormWithInvalidGrades();
  // signWithRequiredGrade();
  // signWithoutRequiredGrade();
  return 0;
}
