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
  static std::string const floatSuffix;

  /* private methods */
  static std::string intMaxToString();
  static std::string intMinToString();
  static void checkOutOfBounds(long strtolResult);
  static void checkIntMax(long strtolResult,
                          std::string const& intputString);
  static void checkIntMin(long strtolResult,
                          std::string const& intputString);
  static void checkEndptr(char* strtolEndptr);
  static void intCheckInvalidInput(long strtolResult, char* endptr,
                                   std::string const& intputString);
  static void floatCheckInvalidInput(double strtofResult, char* endprt,
                                     std::string const& inputString);
  static void floatCheckEndptr(const char* endptr);
  static void floatCheckInff(float strtofResult, std::string const& inputString);
  static void floatCheckMinusInff(float strtofResult,
                                  std::string const& inputString);
  static void floatCheckInvalidInput(float strtofResult, char* endptr,
                                   std::string const& inputString);

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
  static void checkInt(std::string const& inputString);
  static void checkFloat(std::string const& inputString);
  static double inf();
  static float inff();
};

#endif