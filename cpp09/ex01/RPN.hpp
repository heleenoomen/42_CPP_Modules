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

#include <deque>
#include <sstream>
#include <stack>

class RPN {
 private:
  char const* input_;
  std::stack<int> stack_;

  /* lookup table for different operations + - / * */
  typedef struct Operations {
    char symbol;
    int (RPN::*func)(int n1, int n2) const;
  } Operations;

  static int const numberOfOperators_ = 4;
  Operations operations_[numberOfOperators_];

  /* operator-functions */
  int add(int n1, int n2) const;
  int subtract(int n1, int n2) const;
  int multiplicate(int n1, int n2) const;
  int divide(int n1, int n2) const;

  /* helper functions */
  void initLookupTable();
  bool isOperator(std::string& token) const;
  int strToInt(std::string& token) const;
  int popNumber();
  void performOperation(char symbol);
  int processInput();

  /* default constructor */
  RPN();

 public:
  /* constructor */
  RPN(char const* input);

  /* copy constructor */
  RPN(RPN const& src);

  /* copy assignment operator */
  RPN& operator=(RPN const& rhs);

  /* destructor */
  ~RPN();

  /* exceptions */
  class invalidInputException : public std::exception {
   public:
    invalidInputException();
    ~invalidInputException() throw();
    virtual char const* what() const throw();
  };

  /* public methods */
  void calculate();
};

#endif