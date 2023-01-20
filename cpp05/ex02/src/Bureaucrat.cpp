/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:26:22 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/20 10:18:28 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>

#include "Layout.hpp"

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

Bureaucrat::Bureaucrat() : name_("Unnamed"), grade_(150) {
  std::cout << Layout::grey << "Bureaucrat default constructor called\n"
            << Layout::reset;
}

Bureaucrat::Bureaucrat(std::string const& name, int grade)
    : name_(name), grade_(grade) {
  std::cout << Layout::grey << "Bureaucrat parametric constructor called\n"
            << Layout::reset;
}

Bureaucrat::Bureaucrat(Bureaucrat const& src) : name_(src.getName()) {
  std::cout << Layout::grey << "Bureaucrat copy constructor called\n"
            << Layout::reset;
  *this = src;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs) {
  std::cout << Layout::grey << "Bureaucrat copy assignment operator called\n"
            << Layout::reset;
  grade_ = rhs.getGrade();
  return *this;
}

Bureaucrat::~Bureaucrat() {
  std::cout << Layout::grey << "Bureaucrat destructor called\n"
            << Layout::reset;
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
  std::cout << Layout::grey
            << "Bureaucrat::GradeTooHighException default constructor\n"
            << Layout::reset;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {
  std::cout << Layout::grey
            << "Bureaucrat::GradeTooHighException default destructor\n"
            << Layout::reset;
}

Bureaucrat::GradeTooLowException::GradeTooLowException() {
  std::cout << Layout::grey
            << "Bureaucrat::GradeTooLowException default constructor\n"
            << Layout::reset;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {
  std::cout << Layout::grey
            << "Bureaucrat::GradeTooLowException default destructor\n"
            << Layout::reset;
}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

void Bureaucrat::signForm(AForm& form) const {
  try {
    form.beSigned(*this);
    std::cout << Layout::greenBold << name_ << " signed \"" << form.getName()
              << "\"\n"
              << Layout::reset;
  } catch (std::exception& e) {
    std::cout << Layout::redBold << name_ << " couldn't sign \""
              << form.getName() << "\" because: " << e.what() << '\n'
              << Layout::reset;
  }
}

void Bureaucrat::executeForm(AForm const& form) const {
  try {
    form.execute(*this);
    std::cout << Layout::greenBold << name_ << " executed \"" << form.getName()
              << "\"\n"
              << Layout::reset;
  } catch (std::exception& e) {
    std::cout << Layout::redBold << name_ << " couldn't execute \""
              << form.getName() << "\" because: " << e.what() << '\n'
              << Layout::reset;
  }
}

/* ************************************************************************** */
/* Insertion operator                                                         */
/* ************************************************************************** */

std::ostream& operator<<(std::ostream& o, Bureaucrat const& bureaucrat) {
  o << Layout::greenBold << bureaucrat.getName() << ", bureaucrat grade "
    << bureaucrat.getGrade() << Layout::reset;
  return o;
}
