#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iomanip>
#include <iostream>
#include <string>

/* ************************************************************************** */
/* Print utils                                                                */
/* ************************************************************************** */

static int const testHeaderWidth = 56;

// #ifndef to_file
// #define to_file
// #endif

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

void testInsertionOverloadForm(char const* message, Form const& f) {
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

void testSignForm(Bureaucrat const& b, Form& f) {
    std::cout << cyanItalic
              << "Let bureaucrat " << b.getName()
              << " try to sign " << f.getName() << ":\n"
              << resetLayout;
    b.signForm(f);
}

void tryToConstructForm(char const* name, int gradeToExecute,\
int gradeToSign) {
  try {
    Form f(name, gradeToExecute, gradeToSign);
    testInsertionOverloadForm("Form created. ", f);
  }     
  catch(std::exception &e) {
    std::cerr << redBold
              << "Standard exception: " << e.what() << '\n'
              << resetLayout;
  }
}

void tryToSignForm(char const* bureacratName, int bureacratGrade,\
char const* formName, int gradeToSign, int gradeToExecute) {
  try {
    Bureaucrat b(bureacratName, bureacratGrade);
    testInsertionOverloadBureaucrat("Bureaucrat created. ", b);
    Form f(formName, gradeToSign, gradeToExecute);
    testInsertionOverloadForm("Form created. ", f);
    testSignForm(b, f);
    testInsertionOverloadForm("", f);
  }
  catch(std::exception &e) {
    std::cerr << redBold
              << "Standard exception: " << e.what() << '\n'
              << resetLayout;
  }
}

/* ************************************************************************** */
/* Tests                                                                      */
/* ************************************************************************** */


void constructFormWithValidGrades() {
  printTestHeader("Test construct form with valid grades");
  tryToConstructForm("Regulation 1a", 100, 20);
  printTestTrailer();
}

void constructFormWithInvalidGrades() {
  printTestHeader("Test construct form with invalid grades");
  tryToConstructForm("Regulation 1b", -3, 20);
  printTestTrailer();
}

void signWithRequiredGrade() {
  printTestHeader("Test sign form by bureaucrat with adequate grade");
  tryToSignForm("Andrea", 19, "Regulation 18b", 20, 40);
  printTestTrailer();
}

void signWithoutRequiredGrade() {
  printTestHeader("Test sign form by bureaucrat with inadequate grade");
  tryToSignForm("Andrea", 19, "Regulation 18b", 10, 5);
  printTestTrailer();
}

/* ************************************************************************** */
/* Main                                                                       */
/* ************************************************************************** */

int main() {

  constructFormWithValidGrades();
  constructFormWithInvalidGrades();
  signWithRequiredGrade();
  signWithoutRequiredGrade();
  return 0;
}
