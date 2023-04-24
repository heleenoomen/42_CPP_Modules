/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2023/04/24 19:44:36 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include <iostream>
#include <string>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
 private:
  std::string const target_;

  /* private methods */
  std::string toString(int value) const;
  std::string pickRandomTreeFileName() const;
  void openTargetFile(std::ofstream& targetFile) const;
  void openTreeFile(std::ifstream& treeFile) const;
  void copyTreeFileToTargetFile(std::ifstream& treeFile,
                                std::ofstream& targetFile) const;
  void executeShrubberyCreationForm() const;

 public:
  /* default constructor */
  ShrubberyCreationForm();
  /* parametric constructor */
  ShrubberyCreationForm(std::string const& name);
  ShrubberyCreationForm(std::string const& name, std::string const& target);

  /* copy constructor */
  ShrubberyCreationForm(ShrubberyCreationForm const& src);

  /* copy assignment operator */
  ShrubberyCreationForm& operator=(ShrubberyCreationForm const& rhs);

  /* destructor */
  ~ShrubberyCreationForm();

  /* public methods */
  virtual void execute(Bureaucrat const& b) const;

  /* symbolic constants */
  static int const gradeRequiredToSign = 145;
  static int const gradeRequiredToExecute = 137;
  static std::string const formName;
};

#endif