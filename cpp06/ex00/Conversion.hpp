/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/21 17:49:46 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_HPP
#define CONVERSION_HPP

#include <string>
// #include <iostream>

class Conversion;

enum InputType { charType, intType, floatType, doubleType };

typedef void (Conversion::*convertType)() const;

class Conversion {
 //private:
  std::string const input_;
  int type_;
  convertType conversionTable_[4];

  void convertChar() const;
  void convertInt() const;
  void convertFloat() const;
  void convertDouble() const;

  void launchConversionTable();
  void determineType();
  bool floatIsPseudoLiteral() const;
  bool doubleIsPseudoLiteral() const;

 //protected:

 public:
  /* default constructor */
  Conversion();
  Conversion(std::string const& input);

  /* copy constructor */
  Conversion(Conversion const& src);

  /* copy assignment operator */
  Conversion& operator=(Conversion const& rhs);

  /* default destructor */
  ~Conversion();

  /* getters */
  std::string const& getInput() const;

  /* setters */

  /* public methods */
  void convert() const;
};

/* insertion operator */
// std::ostream& operator<<(std::ostream& o, Conversion const& cname);

#endif