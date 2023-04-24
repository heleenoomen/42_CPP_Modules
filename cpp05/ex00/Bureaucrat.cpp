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

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

Bureaucrat::Bureaucrat() : name_("Unnamed"), grade_(150) {
  std::cout << "\033[0;2mBureaucrat default constructor called\033[0;22m\n";
  checkGrade();
}

Bureaucrat::Bureaucrat(std::string const& name, int grade)
    : name_(name), grade_(grade) {
  std::cout << "\033[0;2mBureaucrat parametric constructor called\033[0;22m\n";
  checkGrade();
}

Bureaucrat::Bureaucrat(Bureaucrat const& src) : name_(src.getName()) {
  std::cout << "\033[0;2mBureaucrat copy constructor called\033[0;22m\n";
  *this = src;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs) {
  std::cout
      << "\033[0;2mBureaucrat copy assignment operator called\033[0;22m\n";
  if (this == &rhs) return *this;
  grade_ = rhs.getGrade();
  return *this;
}

Bureaucrat::~Bureaucrat() {
  std::cout << "\033[0;2mBureaucrat destructor called\033[0;22m\n";
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
  if (grade_ == maximumGrade) throw(GradeTooHighException());
  --grade_;
}

void Bureaucrat::degrade() {
  if (grade_ == minimumGrade) throw(GradeTooLowException());
  ++grade_;
}

/* ************************************************************************** */
/* Private methods                                                            */
/* ************************************************************************** */

void Bureaucrat::checkGrade() const {
  if (grade_ < maximumGrade) throw(GradeTooHighException());
  if (grade_ > minimumGrade) throw(GradeTooLowException());
}

/* ************************************************************************** */
/* Nested exception classes                                                   */
/* ************************************************************************** */

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

Bureaucrat::GradeTooHighException::GradeTooHighException() {
  std::cout << "\033[0;2mBureaucrat::GradeTooHighException default constructor"
            << "called\033[0m\n";
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {
  std::cout << "\033[0;2mBureaucrat::GradeTooHighException destructor"
            << "called\033[0m\n";
}

Bureaucrat::GradeTooLowException::GradeTooLowException() {
  std::cout << "\033[0;2mBureaucrat::GradeTooLowException default constructor"
            << "called\033[0m\n";
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {
  std::cout << "\033[0;2mBureaucrat::GradeTooLowException destructor"
            << "called\033[0m\n";
}

/* ************************************************************************** */
/* Insertion operator                                                         */
/* ************************************************************************** */

std::ostream& operator<<(std::ostream& o, Bureaucrat const& bureaucrat) {
  o << "\033[0;32m" << bureaucrat.getName() << ", bureaucrat grade "
    << bureaucrat.getGrade() << "\033[0m";
  return o;
}