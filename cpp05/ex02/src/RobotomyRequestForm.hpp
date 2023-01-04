/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/03 13:01:25 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

#include <string>
#include <iostream>
#include <fstream>

class RobotomyRequestForm : public AForm {
 private:
  std::string const target_;

 /* private methods */
    /* a) helpers */
  std::string toString(int value) const;
  std::string pickRandomTreeFileName() const;

    /* b) private methods */
  void openTargetFile(std::ofstream& targetFile) const;
  void openTreeFile(std::ifstream& treeFile) const;
  void copyTreeFileToTargetFile(std::ifstream& treeFile, std::ofstream& targetFile) const;
  void executeRobotomyRequestForm() const;

 public:
  /* default constructor */
  RobotomyRequestForm();
  /* parametric constructor */
  RobotomyRequestForm(std::string const& name);
  RobotomyRequestForm(std::string const& name, std::string const& target);

  /* copy constructor */
  RobotomyRequestForm(RobotomyRequestForm const& src);

  /* copy assignment operator */
  RobotomyRequestForm& operator=(RobotomyRequestForm const& rhs);

  /* default destructor */
  ~RobotomyRequestForm();

  /* public methods */
  virtual void execute(Bureaucrat const& b) const;

  /* symbolic constants */
  static int const gradeRequiredToSign = 72;
  static int const gradeRequiredToExecute = 45;
};

#endif