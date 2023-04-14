/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                        :+:      :+:
 * :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/10 22:01:08 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COPLIEN_HPP
#define COPLIEN_HPP

#include <iostream>
#include <map>
#include <string>
#include <utility>

class BitcoinExchange {
 private:
  const char* inputFile_;
  const char* dbFile_ = "cpp_09/data.csv";
  std::map<std::string, float> database_;

  /* default constructor */
  BitcoinExchange();

  /* copy constructor */
  BitcoinExchange(BitcoinExchange const& src);

  /* copy assignment operator */
  BitcoinExchange& operator=(BitcoinExchange const& rhs);

  /* private methods */

 public:
  /* constructors */
  BitcoinExchange(const char* inputFile);

  /* default destructor */
  ~BitcoinExchange();

  /* public methods */
  void run();

  /* exceptions */
  class FileException : std::exception {
   public:
    FileException();
    ~FileException() throw();
    virtual const char* what() const throw();
  };

  class NegativeNumberException : std::exception {
   public:
    NegativeNumberException();
    ~NegativeNumberException() throw();
    virtual const char* what() const throw();
  };

  class BadInput : std::exception {
   public:
    BadInput();
    ~BadInput();
    virtual const char* what() const throw();
  };

  class NumTooLargeException : std::exception {
   public:
    NumTooLargeException();
    ~NumTooLargeException();
    virtual const char* what() const throw();
  };
};

#endif