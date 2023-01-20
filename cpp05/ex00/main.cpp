/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:54:45 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/20 10:04:22 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"

/* ************************************************************************** */
/* Printing headers                                                           */
/* ************************************************************************** */
void printTestHeader(std::string header) {
  std::cout << "\033[1;33m ---" << header << "---\033[0m\n";
}

void printTestStep(std::string step) {
  std::cout << "\033[0;33m ---" << step << "---\033[0m\n";
}

/* ************************************************************************** */
/* Test Basic Class creation, destruction & insertion overload                */
/* ************************************************************************** */
void testInsertionOverload() {
  printTestHeader("Test insertion overload");
  Bureaucrat barry("Barry", 140);
  std::cout << barry << "\n";
}

/* ************************************************************************** */
/* Test Promotions & Degradations: Printing utils                             */
/* ************************************************************************** */

void printInfoBefore(Bureaucrat& bureaucrat, std::string action) {
  std::cout << "This is our bureaucrat at the start:\n\n";
  std::cout << "\t" << bureaucrat << "\n\n";
  std::cout << "Try to " << action << " " << bureaucrat.getName() << ":\n";
}

void printInfoAfter(Bureaucrat& bureaucrat) {
  std::cout << "This is our bureaucrat after the operation:\n\n";
  std::cout << "\t" << bureaucrat << "\n\n";
}

/* ************************************************************************** */
/*  Test Promotions & degradations: General test frames                       */
/* ************************************************************************** */

void testPromotions(std::string name, int actualGrade) {
  Bureaucrat bureaucrat(name, actualGrade);
  printInfoBefore(bureaucrat, "promote");
  try {
    bureaucrat.promote();
  } catch (std::exception& e) {
    std::cerr << "\033[1;31m"
              << "Standard exception: " << e.what() << "\033[0m\n";
  }
  printInfoAfter(bureaucrat);
}

void testDegradations(std::string name, int actualGrade) {
  Bureaucrat bureaucrat(name, actualGrade);
  printInfoBefore(bureaucrat, "degrade");
  try {
    bureaucrat.degrade();
  } catch (std::exception& e) {
    std::cerr << "\033[1;31m"
              << "Standard exception: " << e.what() << "\033[0m\n";
  }
  printInfoAfter(bureaucrat);
}

/* ************************************************************************** */
/*  Test promotions and degradations: specific tests                          */
/* ************************************************************************** */

void testValidPromotion() {
  printTestHeader("Test valid promotion");
  testPromotions("Barry", 140);
}

void testInvalidPromotion() {
  printTestHeader("Test invalid promotion");
  testPromotions("Barry", 1);
}

void testValidDegradation() {
  printTestHeader("Test valid degradation");
  testDegradations("Barry", 140);
}

void testInvalidDegradation() {
  printTestHeader("Test invalid degradation");
  testDegradations("Barry", 150);
}

void testMaximumPromotion() {
  printTestHeader("Test maximum promotion");
  testPromotions("Kaitlin", 2);
}

void testMaximumDegradation() {
  printTestHeader("Test maximum degradation");
  testDegradations("Kaitlin", 149);
}

void testCreateBureaucratWithInvalidGrade() {
  printTestHeader("Test creating a bureaucrat with invalid initial grade (1)");
  try {
    std::cout
        << "We will try to create a bureaucrat named Barry, with the invalid "
        << "initial grade of 151:\n";
    Bureaucrat b("Barry", 151);
  } catch (std::exception& e) {
    std::cerr << "\033[31;1m"
              << "Standard exception: " << e.what() << '\n'
              << "\033[0m";
  }
  std::cout << '\n';
  printTestHeader("Test creating a bureaucrat with invalid initial grade (2)");
  try {
    std::cout
        << "We will try to create a bureaucrat named Barry, with the invalid "
        << "initial grade of -16:\n";
    Bureaucrat b("Barry", -16);
  } catch (std::exception& e) {
    std::cerr << "\033[31;1m"
              << "Standard exception: " << e.what() << '\n'
              << "\033[0m";
  }
}

/* ************************************************************************** */
/* Test Copy constructor                                                      */
/* ************************************************************************** */

void testCopyConstructor() {
  printTestHeader("Test Copy Constructor");
  printTestStep("parametric constructor for barry");
  Bureaucrat barry("Barry", 140);
  printTestStep("copy constructor for barry2");
  Bureaucrat barry2(barry);
  printTestStep("barry to std::cout");
  std::cout << barry << "\n";
  printTestStep("barry2 to std::cout");
  std::cout << barry2 << "\n";
  printTestStep("promote barry by 1 grade");
  barry.promote();
  printTestStep("copy constructor for barry3");
  Bureaucrat barry3(barry);
  printTestStep("barry 3 to std::cout");
  std::cout << barry3 << "\n";
}

/* ************************************************************************** */
/* Test assignment operator                                                   */
/* ************************************************************************** */

void testCopyAssignmentOperator() {
  printTestHeader("Test Copy Assignment Operator");
  printTestStep("Parametric constructor for barry");
  Bureaucrat barry("Barry", 140);
  printTestStep("Default constructor for barry2");
  Bureaucrat barry2;
  printTestStep("Assign barry to barry2");
  barry2 = barry;
  printTestStep("barry to std::cout");
  std::cout << barry << "\n";
  printTestStep("barry2 to std::cout");
  std::cout << barry2 << "\n";
  printTestStep("promote barry by 1 grade");
  barry.promote();
  printTestStep("Default constructor for barry3");
  Bureaucrat barry3;
  printTestStep("Assign barry to barry3");
  barry3 = barry;
  printTestStep("barry3 to std::cout");
  std::cout << barry3 << "\n";
}

int main() {
  testInsertionOverload();
  std::cout << "\n";
  testCopyConstructor();
  std::cout << "\n";
  testCopyAssignmentOperator();
  std::cout << "\n";
  testValidPromotion();
  std::cout << "\n";
  testInvalidPromotion();
  std::cout << "\n";
  testValidDegradation();
  std::cout << "\n";
  testInvalidDegradation();
  std::cout << "\n";
  testMaximumPromotion();
  std::cout << "\n";
  testMaximumDegradation();
  std::cout << "\n";
  testCreateBureaucratWithInvalidGrade();
}
