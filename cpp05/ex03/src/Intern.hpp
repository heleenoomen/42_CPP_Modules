/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/21 17:49:46 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
// #include <iostream>

class Intern {
 private:
  typedef struct formProductionTable {
    std::string formName;
    AForm* (Intern::*productionMethod)(std::string const& target) const;
  } formProductionTable;

  static int const nbrOfExistingForms = 3;

  formProductionTable table[Intern::nbrOfExistingForms];

  AForm* makeShrubberyCreationForm(std::string const& target) const;
  AForm* makeRobotomyRequestForm(std::string const& target) const;
  AForm* makePresidentialPardonForm(std::string const& target) const;
  AForm* produceForm(std::string const& name, std::string const& target) const;

  void launchFormTable();
  // protected:

 public:
  /* default constructor */
  Intern();

  /* copy constructor */
  Intern(Intern const& src);

  /* copy assignment operator */
  Intern& operator=(Intern const& rhs);

  /* destructor */
  ~Intern();

  /* public methods */
  AForm* makeForm(std::string const& name, std::string const& target) const;

  // /* exceptions */
  class FormDoesNotExistException : public std::exception {
   public:
    FormDoesNotExistException();
    ~FormDoesNotExistException() throw();
    virtual const char* what() const throw();
  };
};

#endif