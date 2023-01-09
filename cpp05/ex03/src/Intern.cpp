
#include "Intern.hpp"
#include "Layout.hpp"
#include <iostream>

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
Intern::Intern() {
  std::cout << Layout::grey << "Intern default constructor called\n" << Layout::reset;
  launchFormTable();
}

/* Copy constructor */
Intern::Intern(Intern const& src) {
  std::cout << Layout::grey << "Intern copy constructor called\n" << Layout::reset;
  *this = src;
}

/* Copy assignment operator */
Intern& Intern::operator=(Intern const& rhs) {
  std::cout << Layout::grey << "Intern copy assignment operator called\n" << Layout::reset;
  if (this == &rhs)
    return *this;
  return *this;
}

/* Destructor */
Intern::~Intern() {
  std::cout << Layout::grey << "Intern destructor called\n" << Layout::reset;
}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

AForm* Intern::makeForm(std::string const& formName, std::string const& target) const {
  try {
    AForm* newForm = produceForm(formName, target);
    std::cout << Layout::greenBold
              << formName << " was produced succesfully by intern\n"
              << Layout::reset;
    return newForm;
  }
  catch (Intern::FormDoesNotExistException& e) {
    std::cerr << Layout::redBold
              << formName << " could not be produced because: "
              << e.what() << '\n'
              << Layout::reset;
    throw;
    return NULL;
  }
}

/* ************************************************************************** */
/* Private methods                                                            */
/* ************************************************************************** */

AForm* Intern::makeShrubberyCreationForm(std::string const& target) const {
  AForm* newForm = new ShrubberyCreationForm(target);
  return newForm;
}

AForm* Intern::makeRobotomyRequestForm(std::string const& target) const {
  AForm* newForm = new RobotomyRequestForm(target);
  return newForm;
}

AForm* Intern::makePresidentialPardonForm(std::string const& target) const {
  AForm* newForm = new PresidentialPardonForm(target);
  return newForm;
}

AForm* Intern::produceForm(std::string const& formName, std::string const& target) const {
  for (int i = 0; i < nbrOfExistingForms; ++i)
    if (table[i].formName == formName) {
       return (this->*table[i].productionMethod)(target);
    }
  throw(Intern::FormDoesNotExistException());
}

void Intern::launchFormTable() {
  table[0].formName = ShrubberyCreationForm::formName;
  table[0].productionMethod = &Intern::makeShrubberyCreationForm;
  table[1].formName = RobotomyRequestForm::formName;
  table[1].productionMethod = &Intern::makeRobotomyRequestForm;
  table[2].formName = PresidentialPardonForm::formName;
  table[2].productionMethod = &Intern::makePresidentialPardonForm;
}

/* ************************************************************************** */
/* Exception classes                                                          */
/* ************************************************************************** */

Intern::FormDoesNotExistException::FormDoesNotExistException() {
  std::cout << Layout::grey
            << "Intern::FormDoesNtExistException default constructor called\n"
            << Layout::reset;
}

Intern::FormDoesNotExistException::~FormDoesNotExistException() throw() {
  std::cout << Layout::grey
            << "Intern::FormDoesNtExistException destructor called\n"
            << Layout::reset;
}

const char* Intern::FormDoesNotExistException::what() const throw() {
  return "Form does not exist";
}
