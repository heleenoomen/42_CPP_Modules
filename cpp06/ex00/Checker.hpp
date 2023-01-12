/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Checker.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/12 15:27:32 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_HPP
#define CHECKER_HPP

#include <string>
// #include <iostream>

enum { charType, intType, floatType, doubleType };

typedef void (Checker::*typeChecker)() const;

class Checker {
 private:
  int type_;
  std::string const inputString_;
  static int const nbrOfTypes_ = 4;
  static int const baseTen_ = 10;
  typeChecker typeCheckerTable_[nbrOfTypes_];

  /* private methods*/
  void checkEndptr_(char* endptr) const;
  void checkEndptrFloat_(char* endptr) const;
  void checkFalseInf_(double strtodResult) const;
  void checkFalseInff_(float strtofResult) const;
  void intCheckOverflow_(long strtolResult) const;
  void checkFalseIntMin_(long strtolResult) const;
  void checkFalseIntMax_(long strtolResult) const;
  void checkInt_() const;
  void checkFloat_() const;
  void checkDouble_() const;
  void performCheck_() const;
  void defineType_();
  void launchTypeCheckerTable_();

  /* default constructor */
  Checker();
  Checker(std::string const&);

  /* copy constructor */
  Checker(Checker const& src);

  /* copy assignment operator */
  Checker& operator=(Checker const& rhs);

  /* default destructor */
  ~Checker();

 public:
  /* exceptions */
  class InvalidInputException : std::exception {
   public:
    InvalidInputException();
    ~InvalidInputException() throw();
    char const* what() const throw();
  };

  /* public methods */
  static void checkInput(std::string const&);
};

#endif