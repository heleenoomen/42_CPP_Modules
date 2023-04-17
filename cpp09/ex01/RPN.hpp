/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/10 22:01:08 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

// #include <string>
// #include <iostream>
#include <deque>
#include <sstream>
#include <stack>

class RPN {
 private:
  typedef struct OperatorLookup {
    char const operator_;
    void (RPN::*operatorOverload)(void) const;
  } OperatorLookup;

  char const* input_;
  std::string token_;
  int result_;
  std::stack<int> numbers_;
  OperatorLookup const operatorLookup[4];
  char const operators_[4] = {'+', '-', '*', '/'};
  char operator_;
  int const numberOfOperators_ = 4;

  /* private methods*/

  void processInput();
  bool isOperator();
  int strToInt() const;
  void putOnStack();
  void performOperation();

  /* default constructor */
  RPN();

 public:
  /* constructor */
  RPN(char const* input);

  /* copy constructor */
  RPN(RPN const& src);

  /* copy assignment operator */
  RPN& operator=(RPN const& rhs);

  /* default destructor */
  ~RPN();

  /* exceptions */
  class invalidInputExecption : std::exception {
   public:
    invalidInputExecption();
    ~invalidInputExecption() throw();
    char const* what() const throw();
  };

  /* public methods */
  void calculate();
};

/* insertion operator */
// std::ostream& operator<<(std::ostream& o, RPN const& cname);

#endif