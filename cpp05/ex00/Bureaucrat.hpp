/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:17:14 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/20 10:04:05 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <string>

class Bureaucrat {
 private:
  std::string const name_;
  int grade_;

  /* private methods*/
  void checkGrade() const;

 public:
  /* default constructor */
  Bureaucrat();

  /* parametric constructor */
  Bureaucrat(std::string const& name, int grade_);

  /* copy constructor */
  Bureaucrat(Bureaucrat const& src);

  /* copy assignment operator */
  Bureaucrat& operator=(Bureaucrat const& rhs);

  /* destructor */
  ~Bureaucrat();

  /* getters */
  int getGrade() const;
  std::string const& getName() const;

  /* setters */
  void promote();
  void degrade();

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

  /* symbolic constants */
  static int const minimumGrade = 150;
  static int const maximumGrade = 1;
};

std::ostream& operator<<(std::ostream& o, Bureaucrat const& Bureaucrat);

#endif

/* NB: throw() means that a function will never throw exceptions
 https://en.cppreference.com/w/cpp/language/noexcept_spec */