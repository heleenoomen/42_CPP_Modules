/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:29:37 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/27 21:06:31 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <string>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "layout.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/* ************************************************************************** */
/* Print utils                                                                */
/* ************************************************************************** */

static int const testHeaderWidth = 56;
static int const newLinesBeforeFirstTest = 1;

void printUnitTestHeader() {
  for (int i = 0; i < newLinesBeforeFirstTest; ++i) std::cout << '\n';
}

void printStars() {
  for (int i = 0; i < testHeaderWidth; ++i) std::cout << '*';
}

void printTestHeader(char const* testname) {
  std::cout << layout::cyanBold;
  printStars();
  std::cout << "\n";
  std::cout << "* " << std::left << std::setw(testHeaderWidth - 3) << testname
            << "*\n";
  printStars();
  std::cout << "\n" << layout::reset;
}

void printTestTrailer() {
  std::cout << layout::cyanBold;
  printStars();
  std::cout << "\n\n\n" << layout::reset;
}

/* ************************************************************************** */
/* Test utils                                                                 */
/* ************************************************************************** */

void testInsertionOverloadForm(AForm const& f) {
  std::cout << layout::cyanItalic << "Print form:\n"
            << layout::reset << f << '\n';
}

void testInsertionOverloadBureaucrat(char const* message, Bureaucrat const& b) {
  std::cout << layout::cyanItalic << message << "Print bureaucrat:\n"
            << layout::reset << b << '\n';
}

void testSignForm(Bureaucrat const& b, AForm& f) {
  std::cout << layout::cyanItalic << "Let bureaucrat " << b.getName()
            << " try to sign " << f.getName() << ":\n"
            << layout::reset;
  b.signForm(f);
}

void testExecuteForm(Bureaucrat const& b, AForm& f) {
  std::cout << layout::cyanItalic << "Let bureaucrat " << b.getName()
            << " try to execute " << f.getName() << ":\n"
            << layout::reset;
  b.executeForm(f);
}

AForm* testInternCreateForm(std::string const& formName,
                            std::string const& target) {
  Intern i;
  std::cout << layout::cyanItalic << "An intern was created. "
            << "Let intern try to create form \"" << formName << "\""
            << " with target " << target << ":\n"
            << layout::reset;
  AForm* form = i.makeForm(formName, target);
  testInsertionOverloadForm(*form);
  return form;
}

void standardExceptionHandler(std::exception& e) {
  std::cerr << layout::redBold << "Standard exception: " << e.what() << '\n'
            << layout::reset;
}

/* ************************************************************************** */
/* Unit Tests                                                                 */
/* ************************************************************************** */

void testFormsWithIntern(std::string const& formName,
                         std::string const& target) {
  Bureaucrat benji("Benji", 1);
  testInsertionOverloadBureaucrat("Bureaucrat Benji created. ", benji);
  Bureaucrat benjisSecretary("Benji's secretary", 3);
  testInsertionOverloadBureaucrat("Bureaucrat Benji's secretary created. ",
                                  benjisSecretary);
  AForm* form = testInternCreateForm(formName, target);
  testExecuteForm(benji, *form);
  testSignForm(benjisSecretary, *form);
  testExecuteForm(benji, *form);
  delete form;
}

void shrubberyTestsWithIntern() {
  testFormsWithIntern(ShrubberyCreationForm::formName, "Green area 42b");
}

void robotomyTestsWithIntern() {
  testFormsWithIntern(RobotomyRequestForm::formName, "Prototype sed14a.1");
}

void pardonTestsWithIntern() {
  testFormsWithIntern(PresidentialPardonForm::formName, "Ilias Barnaby");
}

void nonExistingFormTest() {
  testFormsWithIntern("Some Misspelled Form Name", "Jojo 994b");
}

/* ************************************************************************** */
/* Main                                                                       */
/* ************************************************************************** */

typedef void (*unitTest)();

void runTests(unitTest tests) {
  try {
    tests();
  } catch (std::exception& e) {
    standardExceptionHandler(e);
  }
}

void testUnit(unitTest tests, char const* testHeader) {
  printTestHeader(testHeader);
  runTests(tests);
  printTestTrailer();
}

int main() {
  printUnitTestHeader();
  testUnit(&shrubberyTestsWithIntern,
           "Test Shrubbery Creation Form With Intern");
  testUnit(&robotomyTestsWithIntern, "Test Robotomy Form With Intern");
  testUnit(&pardonTestsWithIntern, "Test Presidential Pardon Form With Intern");
  testUnit(&nonExistingFormTest, "Test Non Existing Form With Intern");
  std::cout << layout::reset;
  system("leaks bureaucrats");
  return 0;
}
