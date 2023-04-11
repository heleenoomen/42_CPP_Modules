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
  char* inputFile_;
  std::map<std::string, int> database_;
  const char* dbFile_ = "cpp_09/data.csv";

  /* default constructor */
  BitcoinExchange();

  /* private methods */
  bool isValidDate(std::string& date);
  void loadDatabase();
  void dbParseLine(std::string& line, std::pair<std::string, float>& pair);
  void dbCheckDate(std::string& date);
  void dbCheckValue(float value);

 public:
  /* constructors */
  BitcoinExchange(char* inputFile);

  /* copy constructor */
  BitcoinExchange(BitcoinExchange const& src);

  /* copy assignment operator */
  BitcoinExchange& operator=(BitcoinExchange const& rhs);

  /* default destructor */
  ~BitcoinExchange();

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