/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:36:09 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/20 10:37:53 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Layout.hpp"

/* ************************************************************************** */
/* Print utils                                                                */
/* ************************************************************************** */

static int const testHeaderWidth = 56;

void printStars() {
  for (int i = 0; i < testHeaderWidth; ++i) std::cout << "*";
}

void printTestHeader(char const* testname) {
  std::cout << Layout::cyanBold;
  printStars();
  std::cout << "\n";
  std::cout << "* " << std::left << std::setw(testHeaderWidth - 3) << testname
            << "*\n";
  printStars();
  std::cout << "\n" << Layout::reset;
}

void printTestTrailer() {
  std::cout << Layout::cyanBold;
  printStars();
  std::cout << "\n\n\n" << Layout::reset;
}

/* ************************************************************************** */
/* Test utils                                                                 */
/* ************************************************************************** */

void testInsertionOverloadForm(char const* message, Form const& f) {
  std::cout << Layout::cyanItalic << message << "Print form:\n"
            << Layout::reset << f << '\n';
}

void testInsertionOverloadBureaucrat(char const* message, Bureaucrat const& b) {
  std::cout << Layout::cyanItalic << message << "Print bureaucrat:\n"
            << Layout::reset << b << '\n';
}

void testSignForm(Bureaucrat const& b, Form& f) {
  std::cout << Layout::cyanItalic << "Let bureaucrat " << b.getName()
            << " try to sign " << f.getName() << ":\n"
            << Layout::reset;
  b.signForm(f);
}

void tryToConstructForm(char const* name, int gradeToExecute, int gradeToSign) {
  try {
    Form f(name, gradeToExecute, gradeToSign);
    testInsertionOverloadForm("Form created. ", f);
  } catch (std::exception& e) {
    std::cerr << Layout::redBold << "Standard exception: " << e.what() << '\n'
              << Layout::reset;
  }
}

void tryToSignForm(char const* bureacratName, int bureacratGrade,
                   char const* formName, int gradeToSign, int gradeToExecute) {
  try {
    Bureaucrat b(bureacratName, bureacratGrade);
    testInsertionOverloadBureaucrat("Bureaucrat created. ", b);
    Form f(formName, gradeToSign, gradeToExecute);
    testInsertionOverloadForm("Form created. ", f);
    testSignForm(b, f);
    testInsertionOverloadForm("", f);
  } catch (std::exception& e) {
    std::cerr << Layout::redBold << "Standard exception: " << e.what() << '\n'
              << Layout::reset;
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
