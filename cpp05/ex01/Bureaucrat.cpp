/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:26:22 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/03 21:03:27 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>

// #ifndef to_file
// #define to_file
// #endif

  #ifndef to_file
  static char const* greenBold = "\033[32;1m";
  static char const* redBold = "\033[31;1m";
  static char const* resetLayout = "\033[0m";
  static char const* grey = "\033[0;2m";
  #else
  static char const* greenBold = "";
  static char const* redBold = "";
  static char const* resetLayout = "";
  static char const* grey = "";
  #endif

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

Bureaucrat::Bureaucrat() : name_("Unnamed"), grade_(150) {
  std::cout << grey << "Bureaucrat default constructor called\n" << resetLayout;
}

Bureaucrat::Bureaucrat(std::string const& name, int grade)
    : name_(name),
      grade_(grade) {
  std::cout << grey << "Bureaucrat parametric constructor called\n" << resetLayout;
}

Bureaucrat::Bureaucrat(Bureaucrat const& src) : name_(src.getName()) {
  std::cout << grey << "Bureaucrat copy constructor called\n" << resetLayout;
  *this = src;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs) {
  std::cout << grey << "Bureaucrat copy assignment operator called\n" << resetLayout;
  if (this == &rhs)
    return *this;
  grade_ = rhs.getGrade();
  return *this;
}

Bureaucrat::~Bureaucrat() {
  std::cout << grey << "Bureaucrat destructor called\n" << resetLayout;
}

/* ************************************************************************** */
/* Getters                                                                    */
/* ************************************************************************** */

std::string const& Bureaucrat::getName() const {
  return name_;
}

int Bureaucrat::getGrade() const {
  return grade_;
}

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
  std::cout << grey << "Bureaucrat::GradeTooHighException default constructor\n" 
            << resetLayout;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {
  std::cout << grey << "Bureaucrat::GradeTooHighException default destructor\n"
            << resetLayout;
}

Bureaucrat::GradeTooLowException::GradeTooLowException() {
  std::cout << grey << "Bureaucrat::GradeTooLowException default constructor\n"
            << resetLayout;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {
  std::cout << grey << "Bureaucrat::GradeTooLowException default destructor\n"
            << resetLayout;
}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

void Bureaucrat::signForm(Form& form) const {
  try {
    form.beSigned(*this);
    std::cout << greenBold
              << name_ << " signed " << form.getName() << '\n'
              << resetLayout;
  }
  catch (std::exception &e) {
    std::cout << redBold
              << name_ << " couldn't sign " << form.getName() << " because: "
              << e.what() << '\n'
              << resetLayout;
  }
}

/* ************************************************************************** */
/* Insertion operator                                                         */
/* ************************************************************************** */

std::ostream& operator<<(std::ostream& o, Bureaucrat const& bureaucrat) {
  o << greenBold
    << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade()
    << resetLayout;
  return o;
}
