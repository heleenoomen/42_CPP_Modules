/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:29:05 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/27 21:06:22 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#include <iostream>

#include "layout.hpp"

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
Intern::Intern() {
  std::cout << layout::grey << "Intern default constructor called\n"
            << layout::reset;
  launchFormTable();
}

/* Copy constructor */
Intern::Intern(Intern const& src) {
  std::cout << layout::grey << "Intern copy constructor called\n"
            << layout::reset;
  *this = src;
}

/* Copy assignment operator */
Intern& Intern::operator=(Intern const& rhs) {
  std::cout << layout::grey << "Intern copy assignment operator called\n"
            << layout::reset;
  if (this == &rhs) return *this;
  return *this;
}

/* Destructor */
Intern::~Intern() {
  std::cout << layout::grey << "Intern destructor called\n" << layout::reset;
}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

AForm* Intern::makeForm(std::string const& formName,
                        std::string const& target) const {
  try {
    AForm* newForm = produceForm(formName, target);
    std::cout << layout::greenBold << formName
              << " was produced succesfully by intern\n"
              << layout::reset;
    return newForm;
  } catch (Intern::FormDoesNotExistException& e) {
    std::cerr << layout::redBold << formName
              << " could not be produced because: " << e.what() << '\n'
              << layout::reset;
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

AForm* Intern::produceForm(std::string const& formName,
                           std::string const& target) const {
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
  std::cout << layout::grey
            << "Intern::FormDoesNtExistException default constructor called\n"
            << layout::reset;
}

Intern::FormDoesNotExistException::~FormDoesNotExistException() throw() {
  std::cout << layout::grey
            << "Intern::FormDoesNtExistException destructor called\n"
            << layout::reset;
}

const char* Intern::FormDoesNotExistException::what() const throw() {
  return "Form does not exist";
}
