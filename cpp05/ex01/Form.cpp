/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:35:33 by hoomen            #+#    #+#             */
/*   Updated: 2023/04/24 19:44:36 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "layout.hpp"
#include <iostream>

static char const* insertionOverloadlayout = layout::greenBold;

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
Form::Form()
  : name_("Default"),
    signed_(false),
    gradeRequiredToSign_(1),
    gradeRequiredToExecute_(1) {
  std::cout << layout::grey << "Form default constructor called\n" << layout::reset;
  gradeCheck();
}

Form::Form(std::string const& name, int gradeToSign, int gradeToExecute)
  : name_(name),
    signed_(false),
    gradeRequiredToSign_(gradeToSign),
    gradeRequiredToExecute_(gradeToExecute) {
  std::cout << layout::grey << "Form parametric constructor called\n" << layout::reset;
  gradeCheck();
}

/* Copy constructor */
Form::Form(Form const& src)
  : name_(src.getName()),
    gradeRequiredToSign_(src.getGradeRequiredToSign()),
    gradeRequiredToExecute_(src.getGradeRequiredToExecute()) {
  std::cout << layout::grey << "Form copy constructor called\n" << layout::reset;
  *this = src;
}

/* Copy assignment operator */
Form& Form::operator=(Form const& rhs) {
  std::cout << layout::grey << "Form copy assignment operator called\n" << layout::reset;
  if (this == &rhs)
    return *this;
  signed_ = rhs.isSigned();
  return *this;
}

/* Destructor */
Form::~Form() {
  std::cout << layout::grey << "Form destructor called\n" << layout::reset;
}

/* ************************************************************************** */
/* Getters                                                                    */
/* ************************************************************************** */

std::string const& Form::getName() const { return name_; }

bool Form::isSigned() const { return signed_; }

int Form::getGradeRequiredToSign() const { return gradeRequiredToSign_; }

int Form::getGradeRequiredToExecute() const { return gradeRequiredToExecute_; }

/* ************************************************************************** */
/* Setters                                                                    */
/* ************************************************************************** */

void Form::beSigned(Bureaucrat const& b) {
  if (gradeHighEnoughTooSign(b))
    signed_ = true;
  else
    throw(GradeTooLowException());
}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

/* ************************************************************************** */
/* Private methods                                                            */
/* ************************************************************************** */

bool Form::oneOrBothGradesTooHigh() const {
  if (gradeRequiredToExecute_ < Bureaucrat::maximumGrade)
    return true;
  if (gradeRequiredToSign_ < Bureaucrat::maximumGrade)
    return true;
  return false;
}

bool Form::oneOrBothGradesTooLow() const {
  if (gradeRequiredToExecute_ > Bureaucrat::minimumGrade)
    return true;
  if (gradeRequiredToSign_ > Bureaucrat::minimumGrade)
    return true;
  return false;
}

void Form::gradeCheck() const {
  if (oneOrBothGradesTooLow())
    throw (GradeTooLowException());
  if (oneOrBothGradesTooHigh())
    throw (GradeTooHighException());
}

bool Form::gradeHighEnoughTooSign(Bureaucrat const& b) const {
  if (b.getGrade() <= gradeRequiredToSign_)
    return true;
  return false;
}

/* ************************************************************************** */
/* Nested exception classes                                                   */
/* ************************************************************************** */

const char* Form::GradeTooHighException::what() const throw() {
  return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
  return "Grade too low";
}

Form::GradeTooHighException::GradeTooHighException() {
  std::cout << layout::grey << "Form::GradeTooHighException default constructor\n" 
            << " called\n" << layout::reset;
}

Form::GradeTooHighException::~GradeTooHighException() throw() {
  std::cout << layout::grey << "Form::GradeTooHighException destructor"
            << " called\n" << layout::reset;
}

Form::GradeTooLowException::GradeTooLowException() {
  std::cout << layout::grey << "Form::GradeTooLowException default constructor"
            << " called\n" << layout::reset;
}

Form::GradeTooLowException::~GradeTooLowException() throw() {
  std::cout << layout::grey << "Form::GradeTooLowException destructor"
            << " called\n" << layout::reset;
}

/* ************************************************************************** */
/* Insertion operator                                                         */
/* ************************************************************************** */

std::ostream& operator<<(std::ostream& o, Form const& f) {
  o << insertionOverloadlayout
    << "Form: " << f.getName() << ", "
    << "Signed: ";
  f.isSigned()? o << "yes\n": o << "no\n";
  o << "Grade required to sign: " << f.getGradeRequiredToSign() << ","
    << " Grade required to execute: " << f.getGradeRequiredToExecute()
    << layout::reset;
  return o;
}
