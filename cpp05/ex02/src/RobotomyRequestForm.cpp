/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:39:21 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/27 21:03:29 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <climits>
#include <cstdlib>
#include <fstream>

#include "layout.hpp"

std::string const RobotomyRequestForm::formName = "Robotomy Request";

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Parametric constructors */
RobotomyRequestForm::RobotomyRequestForm()
    : AForm(formName, gradeRequiredToSign, gradeRequiredToExecute),
      target_("Default") {
  std::cout << layout::grey
            << "RobotomyRequestForm parametric constructor called\n"
            << layout::reset;
  checkGrade();
}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
    : AForm(formName, gradeRequiredToSign, gradeRequiredToExecute),
      target_(target) {
  std::cout << layout::grey
            << "RobotomyRequestForm parametric constructor called\n"
            << layout::reset;
  checkGrade();
}

/* Copy constructor */
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src)
    : AForm(src.getName(), gradeRequiredToSign, gradeRequiredToExecute),
      target_(src.target_) {
  std::cout << layout::grey << "RobotomyRequestForm copy constructor called\n"
            << layout::reset;
  *this = src;
}

/* Copy assignment operator */
RobotomyRequestForm& RobotomyRequestForm::operator=(
    RobotomyRequestForm const& rhs) {
  std::cout << layout::grey
            << "RobotomyRequestForm copy assignment operator called\n"
            << layout::reset;
  if (this == &rhs) return *this;
  AForm::operator=(rhs);
  return *this;
}

/* Destructor */
RobotomyRequestForm::~RobotomyRequestForm() {
  std::cout << layout::grey << "RobotomyRequestForm destructor called\n"
            << layout::reset;
}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

void RobotomyRequestForm::execute(Bureaucrat const& b) const {
  checkExecutionRequirements(b);
  executeRobotomyRequestForm();
}

/* ************************************************************************** */
/* Private                                                                    */
/* ************************************************************************** */

/* std::rand() is a poor quality PRNG. In c++11, the best option would be to
   use the mersenne twister and seed it with the system clock */
void RobotomyRequestForm::executeRobotomyRequestForm() const {
  std::cout << layout::magenta << "Robotomy of " << target_
            << " in process... Random drilling noises: "
            << " #$%&((^$@!@@##$&\n"
            << layout::reset;
  if (std::rand() % 2)
    std::cout << layout::emojiRobot << " " << layout::green << target_
              << " has been robotomized succesfully\n"
              << layout::reset;
  else
    std::cout << layout::emojiSkull << " " << layout::yellow << "Robotomy of "
              << target_ << " failed\n"
              << layout::reset;
}
