/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/21 17:49:46 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
 private:
  std::string const name_;
  bool signed_;
  int const gradeRequiredToSign_;
  int const gradeRequiredToExecute_;
  virtual AForm* newForm() const = 0;

 protected:
  bool oneOrBothGradesTooLow() const;
  bool oneOrBothGradesTooHigh() const;
  void checkGrade() const;
  bool gradeHighEnoughToSign(Bureaucrat const& b) const;
  bool gradeHighEnoughToExecute(Bureaucrat const& b) const;
  virtual void checkExecutionRequirements(Bureaucrat const& b) const;

 public:
  /* default constructor */
  AForm();
  AForm(std::string const& name, int gradeToSign, int gradeToExecute);

  /* copy constructor */
  AForm(AForm const& src);

  /* copy assignment operator */
  AForm& operator=(AForm const& rhs);

  /* destructor */
  virtual ~AForm();

  /* getters */
  std::string const& getName() const;
  bool isSigned() const;
  int getGradeRequiredToSign() const;
  int getGradeRequiredToExecute() const;

  /* setters */
  void beSigned(Bureaucrat const& b);

  /* public methods */
  virtual void execute(Bureaucrat const& b) const = 0;

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

  class FormNotSignedException : public std::exception {
   public:
    FormNotSignedException();
    ~FormNotSignedException() throw();
    virtual const char* what() const throw();
  };
};

/* insertion operator */
std::ostream& operator<<(std::ostream& o, AForm const& aForm);

#endif