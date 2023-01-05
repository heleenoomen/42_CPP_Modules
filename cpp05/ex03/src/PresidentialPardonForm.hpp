/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/03 13:01:25 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

#include <string>
#include <iostream>
#include <fstream>

class PresidentialPardonForm : public AForm {
 private:
  std::string const target_;

 /* private methods */
  void executePresidentialPardonForm() const;
  AForm* newForm() const;

 public:
  /* default constructor */
  PresidentialPardonForm();
  /* parametric constructor */
  PresidentialPardonForm(std::string const& name);

  /* copy constructor */
  PresidentialPardonForm(PresidentialPardonForm const& src);

  /* copy assignment operator */
  PresidentialPardonForm& operator=(PresidentialPardonForm const& rhs);

  /* default destructor */
  ~PresidentialPardonForm();

  /* public methods */
  virtual void execute(Bureaucrat const& b) const;

  /* symbolic constants */
  static int const gradeRequiredToSign = 25;
  static int const gradeRequiredToExecute = 5;
  static std::string const formName;
};

#endif