/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:38:21 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/27 21:03:10 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#include <iostream>

#include "layout.hpp"

static char const* insertionOverloadlayout = layout::greenBold;

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
AForm::AForm()
    : name_("Default"),
      signed_(false),
      gradeRequiredToSign_(1),
      gradeRequiredToExecute_(1) {
  std::cout << layout::grey << "AForm default constructor called\n"
            << layout::reset;
  checkGrade();
}

AForm::AForm(std::string const& name, int gradeToSign, int gradeToExecute)
    : name_(name),
      signed_(false),
      gradeRequiredToSign_(gradeToSign),
      gradeRequiredToExecute_(gradeToExecute) {
  std::cout << layout::grey << "AForm parametric constructor called\n"
            << layout::reset;
  checkGrade();
}

/* Copy constructor */
AForm::AForm(AForm const& src)
    : name_(src.getName()),
      gradeRequiredToSign_(src.getGradeRequiredToSign()),
      gradeRequiredToExecute_(src.getGradeRequiredToExecute()) {
  std::cout << layout::grey << "AForm copy constructor called\n"
            << layout::reset;
  *this = src;
}

/* Copy assignment operator */
AForm& AForm::operator=(AForm const& rhs) {
  std::cout << layout::grey << "AForm copy assignment operator called\n"
            << layout::reset;
  if (this == &rhs) return *this;
  signed_ = rhs.isSigned();
  return *this;
}

/* Destructor */
AForm::~AForm() {
  std::cout << layout::grey << "AForm destructor called\n" << layout::reset;
}

/* ************************************************************************** */
/* Getters                                                                    */
/* ************************************************************************** */

std::string const& AForm::getName() const { return name_; }

bool AForm::isSigned() const { return signed_; }

int AForm::getGradeRequiredToSign() const { return gradeRequiredToSign_; }

int AForm::getGradeRequiredToExecute() const { return gradeRequiredToExecute_; }

/* ************************************************************************** */
/* Setters                                                                    */
/* ************************************************************************** */

void AForm::beSigned(Bureaucrat const& b) {
  if (gradeHighEnoughToSign(b))
    signed_ = true;
  else
    throw(GradeTooLowException());
}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

void AForm::checkExecutionRequirements(Bureaucrat const& b) const {
  if (!signed_)
    throw(FormNotSignedException());
  else if (!gradeHighEnoughToExecute(b))
    throw(GradeTooLowException());
}

/* ************************************************************************** */
/* Private methods                                                            */
/* ************************************************************************** */

bool AForm::oneOrBothGradesTooHigh() const {
  if (gradeRequiredToExecute_ < Bureaucrat::maximumGrade) return true;
  if (gradeRequiredToSign_ < Bureaucrat::maximumGrade) return true;
  return false;
}

bool AForm::oneOrBothGradesTooLow() const {
  if (gradeRequiredToExecute_ > Bureaucrat::minimumGrade) return true;
  if (gradeRequiredToSign_ > Bureaucrat::minimumGrade) return true;
  return false;
}

void AForm::checkGrade() const {
  if (oneOrBothGradesTooLow()) throw(GradeTooLowException());
  if (oneOrBothGradesTooHigh()) throw(GradeTooHighException());
}

bool AForm::gradeHighEnoughToSign(Bureaucrat const& b) const {
  if (b.getGrade() <= gradeRequiredToSign_) return true;
  return false;
}

bool AForm::gradeHighEnoughToExecute(Bureaucrat const& b) const {
  if (b.getGrade() <= gradeRequiredToExecute_) return true;
  return false;
}

/* ************************************************************************** */
/* Nested exception classes                                                   */
/* ************************************************************************** */

const char* AForm::GradeTooHighException::what() const throw() {
  return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
  return "Grade too low";
}

AForm::GradeTooHighException::GradeTooHighException() {
  std::cout << layout::grey
            << "AForm::GradeTooHighException default constructor\n"
            << " called\n"
            << layout::reset;
}

AForm::GradeTooHighException::~GradeTooHighException() throw() {
  std::cout << layout::grey << "AForm::GradeTooHighException destructor"
            << " called\n"
            << layout::reset;
}

AForm::GradeTooLowException::GradeTooLowException() {
  std::cout << layout::grey << "AForm::GradeTooLowException default constructor"
            << " called\n"
            << layout::reset;
}

AForm::GradeTooLowException::~GradeTooLowException() throw() {
  std::cout << layout::grey << "AForm::GradeTooLowException destructor"
            << " called\n"
            << layout::reset;
}

AForm::FormNotSignedException::FormNotSignedException() {
  std::cout << layout::grey << "AForm::GradeTooLowException default constructor"
            << " called\n"
            << layout::reset;
}
AForm::FormNotSignedException::~FormNotSignedException() throw() {
  std::cout << layout::grey << "AForm::GradeTooLowException destructor"
            << " called\n"
            << layout::reset;
}

const char* AForm::FormNotSignedException::what() const throw() {
  return "Form not signed";
}

/* ************************************************************************** */
/* Insertion operator                                                         */
/* ************************************************************************** */

std::ostream& operator<<(std::ostream& o, AForm const& f) {
  o << insertionOverloadlayout << "Form: \"" << f.getName() << "\", "
    << "Signed: ";
  f.isSigned() ? o << "yes\n" : o << "no\n";
  o << "Grade required to sign: " << f.getGradeRequiredToSign() << ","
    << " Grade required to execute: " << f.getGradeRequiredToExecute()
    << layout::reset;
  return o;
}
