
#include "Intern.hpp"
#include <iostream>

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
Intern::Intern() {
  std::cout << "\033[0;2m" << "Intern default constructor called\033[0m\n";
  launchFormTable();
}

/* Copy constructor */
Intern::Intern(Intern const& src) {
  std::cout << "\033[0;2m" << "Intern copy constructor called\033[0m\n";
  *this = src;
}

/* Copy assignment operator */
Intern& Intern::operator=(Intern const& rhs) {
  std::cout << "\033[0;2m" << "Intern copy assignment operator called\033[0m\n";
  if (this == &rhs)
    return *this;
  return *this;
}

/* Destructor */
Intern::~Intern() {
  std::cout << "\033[0;2m" << "Intern destructor called\033[0m\n";
}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

AForm* Intern::makeForm(std::string& formName, std::string& target) const {
  for (int i = 0; i < nbrOfExistingForms; ++i)
    if (table[i].formName == formName)
       return (this->*table[i].productionMethod)(target);
  return NULL;
}

/* ************************************************************************** */
/* Private methods                                                            */
/* ************************************************************************** */

AForm* Intern::makeShrubberyCreationForm(std::string& target) const {
  AForm* newForm = new ShrubberyCreationForm(target);
  return newForm;
}

AForm* Intern::makeRobotomyRequestForm(std::string& target) const {
  AForm* newForm = new RobotomyRequestForm(target);
  return newForm;
}

AForm* Intern::makePresidentialPardonForm(std::string& target) const {
  AForm* newForm = new PresidentialPardonForm(target);
  return newForm;
}


void Intern::launchFormTable() {
  table[0].formName = ShrubberyCreationForm::formName;
  table[0].productionMethod = &Intern::makeShrubberyCreationForm;
  table[1].formName = RobotomyRequestForm::formName;
  table[1].productionMethod = &Intern::makeRobotomyRequestForm;
  table[2].formName = PresidentialPardonForm::formName;
  table[2].productionMethod = &Intern::makePresidentialPardonForm;
}
