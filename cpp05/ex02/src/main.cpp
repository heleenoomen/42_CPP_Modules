/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:39:00 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/27 21:03:20 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <string>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
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

void testInsertionOverloadForm(char const* message, AForm const& f) {
  std::cout << layout::cyanItalic << message << "Print form:\n"
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

void standardExceptionHandler(std::exception& e) {
  std::cerr << layout::redBold << "Standard exception: " << e.what() << '\n'
            << layout::reset;
}

/* ************************************************************************** */
/* Unit Tests                                                                 */
/* ************************************************************************** */

void shrubberyTests() {
  Bureaucrat benji("Benji", ShrubberyCreationForm::gradeRequiredToExecute);
  testInsertionOverloadBureaucrat("Bureaucrat Benji created. ", benji);
  Bureaucrat benjisSecretary("Benji's secretary",
                             ShrubberyCreationForm::gradeRequiredToSign);
  testInsertionOverloadBureaucrat("Bureaucrat Benji's secretary created. ",
                                  benjisSecretary);
  ShrubberyCreationForm newShrubForm("City Park 789");
  testInsertionOverloadForm("Shrubbery Plan 13b created. ", newShrubForm);
  testExecuteForm(benji, newShrubForm);
  testSignForm(benjisSecretary, newShrubForm);
  testExecuteForm(benji, newShrubForm);
  testExecuteForm(benji, newShrubForm);
  testExecuteForm(benjisSecretary, newShrubForm);
}

void robotomyTests() {
  Bureaucrat joleen("Joleen", RobotomyRequestForm::gradeRequiredToExecute);
  testInsertionOverloadBureaucrat("Bureaucrat Joleen has been created. ",
                                  joleen);
  Bureaucrat chris("Chris", RobotomyRequestForm::gradeRequiredToSign - 3);
  testInsertionOverloadBureaucrat("Bureaucrat Chris has been creacted. ",
                                  chris);
  RobotomyRequestForm robotizeForm("Android Prototype 07");
  testInsertionOverloadForm("RobotomyRequestForm has been created",
                            robotizeForm);
  testExecuteForm(joleen, robotizeForm);
  testSignForm(chris, robotizeForm);
  for (int i = 0; i < 10; ++i) testExecuteForm(joleen, robotizeForm);
  testExecuteForm(chris, robotizeForm);
}

void presidentialPardonTests() {
  Bureaucrat undersec1("Undersecretary Gustav",
                       PresidentialPardonForm::gradeRequiredToExecute - 1);
  testInsertionOverloadBureaucrat("Undersecretary Gustav created. ", undersec1);
  Bureaucrat technocrat("Technocrat Claude",
                        PresidentialPardonForm::gradeRequiredToSign - 2);
  testInsertionOverloadBureaucrat("Technocrat Claude created. ", technocrat);
  PresidentialPardonForm pardonForm("Jacob DeLuny");
  testInsertionOverloadForm("Presidential Pardon Form created. ", pardonForm);
  testExecuteForm(undersec1, pardonForm);
  testSignForm(technocrat, pardonForm);
  testExecuteForm(technocrat, pardonForm);
  testExecuteForm(undersec1, pardonForm);
}

/* ************************************************************************** */
/* Main                                                                       */
/* ************************************************************************** */

typedef void (*unitTests)();

void runTests(unitTests tests) {
  try {
    tests();
  } catch (std::exception& e) {
    standardExceptionHandler(e);
  }
}

void testUnit(unitTests tests, char const* testHeader) {
  printTestHeader(testHeader);
  runTests(tests);
  printTestTrailer();
}

int main() {
  printUnitTestHeader();
  testUnit(&shrubberyTests, "Test Execute Shrubbery Creation Form");
  testUnit(&robotomyTests, "Test Execute Robotomy Form");
  testUnit(&presidentialPardonTests, "Test Execute Presidential Pardon Form");
  return 0;
}
