/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/05 19:00:18 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

#include <string>
#include <iostream>
#include <fstream>

class ShrubberyCreationForm : public AForm {
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
  void executeShrubberyCreationForm() const;

    /* c) return copy */
  AForm* newForm() const;

 public:
  /* default constructor */
  ShrubberyCreationForm();
  /* parametric constructor */
  ShrubberyCreationForm(std::string const& name);

  /* copy constructor */
  ShrubberyCreationForm(ShrubberyCreationForm const& src);

  /* copy assignment operator */
  ShrubberyCreationForm& operator=(ShrubberyCreationForm const& rhs);

  /* default destructor */
  ~ShrubberyCreationForm();

  /* public methods */
  virtual void execute(Bureaucrat const& b) const;

  /* symbolic constants */
  static int const gradeRequiredToSign = 145;
  static int const gradeRequiredToExecute = 137;
  static std::string const formName;
};

#endif