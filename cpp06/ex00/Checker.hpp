/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Checker.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/18 12:54:57 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_HPP
#define CHECKER_HPP

#include <string>
// #include <iostream>
class Checker;

enum types { pseudoLiteral, charType, intType, floatType, doubleType };

typedef void (Checker::*typeChecker)() const;

class Checker {
 private:
  int type_;
  std::string const inputString_;
  static int const nbrOfTypes_ = 5;
  static int const baseTen_ = 10;
  typeChecker typeCheckerTable_[nbrOfTypes_];

  /* private methods*/
  void checkEndptr_(char* endptr) const;
  void checkEndptrFloat_(std::string const& endptr) const;
  void doubleCheckOverflow_(double strtodResult) const;
  void floatCheckOverflow_(float strtofResult) const;
  void intCheckOverflow_(long strtolResult) const;
  void checkFalseIntMin_(long strtolResult) const;
  void checkFalseIntMax_(long strtolResult) const;
  void checkPseudoLiteral() const;
  void checkChar() const;
  void checkInt_() const;
  void checkFloat_() const;
  void checkDouble_() const;
  void checkIfValid_() const;
  void determineType_();
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
  class InvalidInputException : public std::exception {
   public:
    InvalidInputException();
    ~InvalidInputException() throw();
    char const* what() const throw();
  };

  /* public methods */
  static void checkInput(std::string const&);
};

#endif