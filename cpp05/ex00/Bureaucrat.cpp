/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:26:22 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/12 21:10:56 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

Bureaucrat::Bureaucrat() : name_("Unnamed"), grade_(150) {
  std::cout << "\033[0;2mBureaucrat default constructor called\033[0;22m\n";
}

Bureaucrat::Bureaucrat(std::string const& name, int grade)
    : name_(name),
      grade_(grade) {
  std::cout << "\033[0;2mBureaucrat parametric constructor called\033[0;22m\n";
}

Bureaucrat::Bureaucrat(Bureaucrat const& src) : name_(src.getName()) {
  std::cout << "\033[0;2mBureaucrat copy constructor called\033[0;22m\n";
  *this = src;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs) {
  std::cout << "\033[0;2mBureaucrat copy assignment operator called\033[0;22m\n";
  grade_ = rhs.getGrade();
  return *this;
}

Bureaucrat::~Bureaucrat() {
  std::cout << "\033[0;2mBureaucrat destructor called\033[0;22m\n";
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

void Bureaucrat::promote(int gradesUp) {
  if (grade_ - gradesUp < 1)
    throw GradeTooHighException();
  else
    grade_ -= gradesUp;
}

void Bureaucrat::degrade(int gradesDown) {
  if (grade_ + gradesDown > 150)
    throw GradeTooLowException();
  else
    grade_ += gradesDown;
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
  std::cout << "\033[0;2mBureaucrat::GradeTooHighException default constructor" 
            << "called\033[0m\n";
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {
  std::cout << "\033[0;2mBureaucrat::GradeTooHighException default destructor"
            << "called\033[0m\n";
}

Bureaucrat::GradeTooLowException::GradeTooLowException() {
  std::cout << "\033[0;2mBureaucrat::GradeTooLowException default constructor"
            << "called\033[0m\n";
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {
  std::cout << "\033[0;2mBureaucrat::GradeTooLowException default destructor"
            << "called\033[0m\n";
}
/* ************************************************************************** */
/* Insertion operator                                                         */
/* ************************************************************************** */

std::ostream& operator<<(std::ostream& o, Bureaucrat const& bureaucrat) {
  o << "\033[0;32m"
    << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade()
    << "\033[0m";
  return o;
}