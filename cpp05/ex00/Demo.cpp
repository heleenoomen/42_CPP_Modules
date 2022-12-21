
#include "Demo.hpp"
#include "UserInput.hpp"
#include <iostream>
#include <limits>

const int noValidInputYet = 0;
const int copyConstructor = 1;
const int copyAssignmentOp = 2;
const int validPromotion = 3;
const int invalidPromotion = 4;
const int validDegradation = 5;
const int invalidDegradation = 6;
const int maxPromotion = 7;
const int maxDegradation = 8;
const int promoteOneTooMany = 9;
const int degradeOneTooMany = 10;
const int firstTest = copyConstructor;
const int lastTest = degradeOneTooMany;
const char quitSymbol = 'q';

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
Demo::Demo() : testNr(noValidInputYet) {
  std::cout << "\033[0;2m" << "Demo default constructor called\033[0m\n";
  testTable[copyConstructor] = &Demo::testCopyConstructor;
  testTable[copyAssignmentOp] = &Demo::testCopyAssignmentOperator;
  testTable[validPromotion] = &Demo::testValidPromotion;
  testTable[invalidPromotion] = &Demo::testInValidPromotion;
  testTable[validDegradation] = &Demo::testValidDegradation;
  testTable[invalidDegradation] = &Demo::testInvalidDegradation;
  testTable[maxPromotion] = &Demo::testMaximumPromotion;
  testTable[maxDegradation] = &Demo::testMaximumDegradation;
  testTable[promoteOneTooMany] = &Demo::testPromoteOneGradeTooMany;
  testTable[degradeOneTooMany] = &Demo::testDegradeOneGradeTooMany;
}

/* Copy constructor */
Demo::Demo(Demo const& src) {
  std::cout << "\033[0;2m" << "Demo copy constructor called\033[0m\n";
  *this = src;
}

/* Copy assignment operator */
Demo& Demo::operator=(Demo const& rhs) {
  std::cout << "\033[0;2m" << "Demo copy assignment operator called\033[0m\n";
  /* assign values here */
  return *this;
}

/* Destructor */
Demo::~Demo() {
  std::cout << "\033[0;2m" << "Demo destructor called\033[0m\n";
}

/* ************************************************************************** */
/* Getters                                                                    */
/* ************************************************************************** */


/* ************************************************************************** */
/* Setters                                                                    */
/* ************************************************************************** */


/* ************************************************************************** */
/* Public                                                                     */
/* ************************************************************************** */

void Demo::run() {
  printPrompt();
  getInput();
  std::cout << "Input is: " << testNr << '\n';
}

/* ************************************************************************** */
/* Private methods                                                            */
/* ************************************************************************** */

void Demo::printPrompt() const {
  layout.set(std::cout, Layout::BLUE, Layout::BOLD);
  std::cout << "*************************************************************\n"
               "*   Welcome to the bureaucrats demo!                        *\n"
               "*************************************************************\n"
               "\n"
               " This program produces bureaucrats, who all have a name and\n"
               " a grade. Grades range from 150 (the lowest) to 1 (the\n"
               " highest grade a bureaucrat can achieve).\n"
               " The program allows for valid promotions within the 1-150\n"
               " range. It trows an exception that prints an error message\n"
               " when invalid promotions or degradations are attempted,\n"
               " for example, trying to degrade a bureaucrat to grade 200, or\n"
               " promote a bureaucrat to grade 0.\n"
               " What functionality of the bureaucrats would you like to test?"
               "\n\n"
               " 1.  Test Copy Constructor\n"
               " 2.  Test Copy Assignment Operator\n"
               " 3.  Test Valid Promotion\n"
               " 4.  Test Invalid Promotion\n"
               " 5.  Test Valid Degradation\n"
               " 6.  Test Invalid Degradation\n"
               " 7.  Test Maximum Promotion\n"
               " 8.  Test Maximum Degradation\n"
               " 9.  Test Promoting a bureacrat one grade too many\n"
               " 10. Test Degrading a bureaucrat one grade too many\n"
               "\n"
               " Please enter a number. Enter " << quitSymbol << " to quit this demo.\n"
               " > ";
  layout.reset(std::cout);
} 

void Demo::rePrompt() const {
    layout.set(std::cerr, Layout::YELLOW, Layout::BOLD);
    std::cout << " Please enter valid a number (1-10). "
                  "Enter " << quitSymbol << " to quit this demo\n";
    layout.reset(std::cerr);
    layout.set(std::cout, Layout::BLUE, Layout::BOLD);
    std::cout << " > ";
    layout.reset(std::cerr);
}

void Demo::getInput() {
  UserInput input(firstTest, lastTest, quitSymbol);
  while (true) {
    input.getIntValue();
    if (input.quitIsSet())
      return ;
    if (!input.IsValid()) {
      rePrompt();
    }
    else {
      testNr = input.getValue();
      return ;
    }
  }
}

void Demo::setTestTableEntry() {};
void Demo::testCopyAssignmentOperator() const {};
void Demo::testCopyConstructor() const {};
void Demo::testValidPromotion() const {};
void Demo::testInValidPromotion() const {};
void Demo::testValidDegradation() const {};
void Demo::testInvalidDegradation() const {};
void Demo::testMaximumPromotion() const {};
void Demo::testMaximumDegradation() const {};
void Demo::testPromoteOneGradeTooMany() const {};
void Demo::testDegradeOneGradeTooMany() const {};

/* ************************************************************************** */
/* Insertion operator                                                         */
/* ************************************************************************** */

std::ostream& operator<<(std::ostream& o, Demo const& cname) {
  o << "\033[0;32m"
    // << some info here
    << "\033[0m";
  return o;
}
