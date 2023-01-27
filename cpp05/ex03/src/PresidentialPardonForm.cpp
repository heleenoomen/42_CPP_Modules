/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:29:41 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/27 21:06:36 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

#include <climits>
#include <cstdlib>
#include <fstream>

#include "layout.hpp"

std::string const PresidentialPardonForm::formName = "Presidential Pardon";

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
PresidentialPardonForm::PresidentialPardonForm()
    : AForm(formName, gradeRequiredToSign, gradeRequiredToExecute),
      target_("default") {
  std::cout << layout::grey
            << "PresidentialPardonForm default constructor called\n"
            << layout::reset;
  checkGrade();
}

/* Parametric constructors */
PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
    : AForm(formName, gradeRequiredToSign, gradeRequiredToExecute),
      target_(target) {
  std::cout << layout::grey
            << "PresidentialPardonForm parametric constructor called\n"
            << layout::reset;
  checkGrade();
}

/* Copy constructor */
PresidentialPardonForm::PresidentialPardonForm(
    PresidentialPardonForm const& src)
    : AForm(src.getName(), gradeRequiredToSign, gradeRequiredToExecute),
      target_(src.target_) {
  std::cout << layout::grey
            << "PresidentialPardonForm copy constructor called\n"
            << layout::reset;
  *this = src;
}

/* Copy assignment operator */
PresidentialPardonForm& PresidentialPardonForm::operator=(
    PresidentialPardonForm const& rhs) {
  std::cout << layout::grey
            << "PresidentialPardonForm copy assignment operator called\n"
            << layout::reset;
  if (this == &rhs) return *this;
  AForm::operator=(rhs);
  return *this;
}

/* Destructor */
PresidentialPardonForm::~PresidentialPardonForm() {
  std::cout << layout::grey << "PresidentialPardonForm destructor called\n"
            << layout::reset;
}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

void PresidentialPardonForm::execute(Bureaucrat const& b) const {
  checkExecutionRequirements(b);
  executePresidentialPardonForm();
}

/* ************************************************************************** */
/* Private                                                                    */
/* ************************************************************************** */

void PresidentialPardonForm::executePresidentialPardonForm() const {
  std::cout << layout::brightYellow << target_
            << " has been pardoned by Zaphod Beeblebrox\n"
            << layout::reset;
}

AForm* PresidentialPardonForm::newForm() const {
  PresidentialPardonForm* newForm = new PresidentialPardonForm(*this);
  return newForm;
}