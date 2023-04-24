/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:26:22 by hoomen            #+#    #+#             */
/*   Updated: 2023/04/24 19:44:36 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>

#include "layout.hpp"

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

Bureaucrat::Bureaucrat() : name_("Unnamed"), grade_(150) {
  std::cout << layout::grey << "Bureaucrat default constructor called\n"
            << layout::reset;
}

Bureaucrat::Bureaucrat(std::string const& name, int grade)
    : name_(name), grade_(grade) {
  std::cout << layout::grey << "Bureaucrat parametric constructor called\n"
            << layout::reset;
}

Bureaucrat::Bureaucrat(Bureaucrat const& src) : name_(src.getName()) {
  std::cout << layout::grey << "Bureaucrat copy constructor called\n"
            << layout::reset;
  *this = src;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs) {
  std::cout << layout::grey << "Bureaucrat copy assignment operator called\n"
            << layout::reset;
  grade_ = rhs.getGrade();
  return *this;
}

Bureaucrat::~Bureaucrat() {
  std::cout << layout::grey << "Bureaucrat destructor called\n"
            << layout::reset;
}

/* ************************************************************************** */
/* Getters                                                                    */
/* ************************************************************************** */

std::string const& Bureaucrat::getName() const { return name_; }

int Bureaucrat::getGrade() const { return grade_; }

/* ************************************************************************** */
/* Setters                                                                    */
/* ************************************************************************** */

void Bureaucrat::promote() {
  if (grade_ == maximumGrade)
    throw GradeTooHighException();
  else
    --grade_;
}

void Bureaucrat::degrade() {
  if (grade_ == minimumGrade)
    throw GradeTooLowException();
  else
    ++grade_;
}

/* ************************************************************************** */
/* Nested exception classes                                                   */
/* ************************************************************************** */

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "Promotion not possible: resulting grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "Degradation not possible: resulting grade is too low";
}

Bureaucrat::GradeTooHighException::GradeTooHighException() {
  std::cout << layout::grey
            << "Bureaucrat::GradeTooHighException default constructor\n"
            << layout::reset;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {
  std::cout << layout::grey
            << "Bureaucrat::GradeTooHighException destructor\n"
            << layout::reset;
}

Bureaucrat::GradeTooLowException::GradeTooLowException() {
  std::cout << layout::grey
            << "Bureaucrat::GradeTooLowException default constructor\n"
            << layout::reset;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {
  std::cout << layout::grey
            << "Bureaucrat::GradeTooLowException destructor\n"
            << layout::reset;
}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

void Bureaucrat::signForm(AForm& form) const {
  try {
    form.beSigned(*this);
    std::cout << layout::greenBold << name_ << " signed \"" << form.getName()
              << "\"\n"
              << layout::reset;
  } catch (std::exception& e) {
    std::cout << layout::redBold << name_ << " couldn't sign \""
              << form.getName() << "\" because: " << e.what() << '\n'
              << layout::reset;
  }
}

void Bureaucrat::executeForm(AForm const& form) const {
  try {
    form.execute(*this);
    std::cout << layout::greenBold << name_ << " executed \"" << form.getName()
              << "\"\n"
              << layout::reset;
  } catch (std::exception& e) {
    std::cout << layout::redBold << name_ << " couldn't execute \""
              << form.getName() << "\" because: " << e.what() << '\n'
              << layout::reset;
  }
}

/* ************************************************************************** */
/* Insertion operator                                                         */
/* ************************************************************************** */

std::ostream& operator<<(std::ostream& o, Bureaucrat const& bureaucrat) {
  o << layout::greenBold << bureaucrat.getName() << ", bureaucrat grade "
    << bureaucrat.getGrade() << layout::reset;
  return o;
}
