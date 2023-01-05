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

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <string>
// #include <iostream>



class Intern {
 private:

	typedef struct formProductionTable {
		std::string	formName;
		AForm* (Intern::*productionMethod)(std::string& target) const;
	} formProductionTable;

  static int const nbrOfExistingForms = 3;

  formProductionTable table[Intern::nbrOfExistingForms];

  AForm* makeShrubberyCreationForm(std::string& target) const;
  AForm* makeRobotomyRequestForm(std::string& target) const;
  AForm* makePresidentialPardonForm(std::string& target) const;

  void launchFormTable();
 //protected:

 public:
  /* default constructor */
  Intern();

  /* copy constructor */
  Intern(Intern const& src);

  /* copy assignment operator */
  Intern& operator=(Intern const& rhs);

  /* default destructor */
  ~Intern();

  /* public methods */
  AForm* makeForm(std::string& name, std::string& target) const;
};

#endif