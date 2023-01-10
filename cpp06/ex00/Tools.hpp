/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tools.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/21 17:49:46 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <string>
// #include <iostream>

class Tools {
 private:
  /* symbolic constants */
  static char const endOfString = '\0';
  static char const base_ = 10;

  /* private methods */
  static std::string intMaxToString();
  static std::string intMinToString();
  static void checkOutOfBounds(long strtolResult);
  static void checkIntMax(long strtolResult,
                          std::string const& intputString);
  static void checkIntMin(long strtolResult,
                          std::string const& intputString);
  static void checkEndptr(char* strtolEndptr);
  static void checkZero(long strtolResult,
                        std::string const& intputString);
  static void checkForInvalidInput(long strtolResult, char* endptr,
                                   std::string const& intputString);

 public:
  /* default constructor */
  Tools();

  /* copy constructor */
  Tools(Tools const& src);

  /* copy assignment operator */
  Tools& operator=(Tools const& rhs);

  /* default destructor */
  ~Tools();

  /* exceptions */
  class invalidInputException : public std::exception {
   public:
    invalidInputException();
    ~invalidInputException() throw();
    char const* what() const throw();
  };

  /* public methods */
  static int myStrtoi(std::string const& inputString);
};

#endif