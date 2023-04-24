/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2023/04/24 19:44:36 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <string>

class Converter;

enum types { pseudoLiteral, charType, intType, floatType, doubleType };

typedef void (Converter::*check)() const;

class Converter {
 private:
  std::string const inputString_;
  double value_;
  char* endptrStrtod_;
  bool hasDot_;
  bool hasF_;
  int type_;
  static int const nbrOfTypes_ = 5;
  static int const nbrOfPseudoliterals_ = 8;
  check checkTable_[nbrOfTypes_];

  /* private methods*/
  bool isPseudoliteral() const;
  void determineType_();
  void determineValue_();
  void launchCheckTable_();
  bool charNonDisplayable_() const;
  bool charOverflow_() const;
  bool intOverflow_() const;
  bool floatOverflow_() const;
  void printChar_() const;
  void printInt_() const;
  void printFloat_() const;
  void printDouble_() const;
  void printConversions_() const;
  void empty_() const;
  void checkInt_() const;
  void checkDouble_() const;
  void checkFloat_() const;
  void checkInput_() const;

 public:
  /* default constructor */
  Converter();
  Converter(std::string const& inputString);

  /* copy constructor */
  Converter(Converter const& src);

  /* copy assignment operator */
  Converter& operator=(Converter const& rhs);

  /* destructor */
  ~Converter();

  /* getters */

  /* setters */

  /* exceptions */
  class InvalidInputException : public std::exception {
   public:
    InvalidInputException();
    ~InvalidInputException() throw();
    char const* what() const throw();
  };

  /* public methods */
  static void convertLiteral(std::string const& input);
};

/* insertion operator */
// std::ostream& operator<<(std::ostream& o, Converter const& cname);

#endif