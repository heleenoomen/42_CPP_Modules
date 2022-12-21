
#include "UserInput.hpp"
#include <iostream>
#include <limits>

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
UserInput::UserInput() :
    quit(false),
    quitSymbol('q'),
    min(1),
    max(10),
    valid(false) {
  std::cout << "\033[0;2m" << "UserInput default constructor called\033[0m\n";
}

/* Parametric constructor*/
UserInput::UserInput(int mi, int ma, char quitSym) : 
    quit(false),
    quitSymbol(quitSym),
    min(mi),
    max(ma),
    valid(false) {
  // std::cout << "\033[0;2m" << "UserInput parametric constructor called\033[0m\n";
}

/* Copy constructor */
UserInput::UserInput(UserInput const& src) {
  std::cout << "\033[0;2m" << "UserInput copy constructor called\033[0m\n";
  *this = src;
}

/* Copy assignment operator */
UserInput& UserInput::operator=(UserInput const& rhs) {
  std::cout << "\033[0;2m" << "UserInput copy assignment operator called\033[0m\n";
  /* assign values here */
  return *this;
}

/* Destructor */
UserInput::~UserInput() {
  // std::cout << "\033[0;2m" << "UserInput destructor called\033[0m\n";
}

/* ************************************************************************** */
/* Getters                                                                    */
/* ************************************************************************** */

int UserInput::getValue() const {
  return value;
}

bool UserInput::quitIsSet() const {
  return quit;
}

bool UserInput::IsValid() const {
  return valid;
}

/* ************************************************************************** */
/* Setters                                                                    */
/* ************************************************************************** */


/* ************************************************************************** */
/* Public                                                                     */
/* ************************************************************************** */

void UserInput::getIntValue() { // TODO: handle std::cin.bad() (throw exception for serious errors)
  char c;
  std::cin >> c;
  if (std::cin.eof()) {
    quit = true;
    std::cin.clear();
    return ;
  }
  if (std::cin.fail()) {
    std::cin.clear();
  }
  else if (c == quitSymbol) {
    quit = true;
    return ;
  }
  std::cin.putback(c);
  std::cin >> value;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  if (std::cin.fail()) {
    std::cin.clear();
    return ;
  }
  if (value >= min && value <= max) {
    valid = true;
    return ;
  }
}


/* ************************************************************************** */
/* Insertion operator                                                         */
/* ************************************************************************** */

// std::ostream& operator<<(std::ostream& o, UserInput const& cname) {
//   o << "\033[0;32m"
//     // << some info here
//     << "\033[0m";
//   return o;
// }
