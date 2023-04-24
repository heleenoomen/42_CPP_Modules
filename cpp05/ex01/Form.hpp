/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/21 17:49:46 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

class Bureaucrat;

class Form {
 private:
  std::string const name_;
  bool signed_;
  int const gradeRequiredToSign_;
  int const gradeRequiredToExecute_;

  bool oneOrBothGradesTooLow() const;
  bool oneOrBothGradesTooHigh() const;
  void gradeCheck() const;
  bool gradeHighEnoughTooSign(Bureaucrat const& b) const;

 public:
  /* default constructor */
  Form();
  Form(std::string const& name, int gradeToSign, int gradeToExecute);

  /* copy constructor */
  Form(Form const& src);

  /* copy assignment operator */
  Form& operator=(Form const& rhs);

  /* destructor */
  ~Form();

  /* getters */
  std::string const& getName() const;
  bool isSigned() const;
  int getGradeRequiredToSign() const;
  int getGradeRequiredToExecute() const;

  /* setters */
  void beSigned(Bureaucrat const& b);

  /* exception classes */
  class GradeTooHighException : public std::exception {
   public:
    GradeTooHighException();
    ~GradeTooHighException() throw();
    virtual const char* what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    GradeTooLowException();
    ~GradeTooLowException() throw();
    virtual const char* what() const throw();
  };
};

/* insertion operator */
std::ostream& operator<<(std::ostream& o, Form const& cname);

#endif