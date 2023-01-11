/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DoubleConverter.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/21 17:49:46 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLECONVERTER_HPP
#define DOUBLECONVERTER_HPP

// #include <string>
// #include <iostream>

class DoubleConverter {
 private:
  double doubleValue_;

 /* private methods */
  double NaN() const;
  double inf() const;
  float inff() const;
  bool charOverflow() const;
  bool charNonDisplayable() const;
  bool intOverflow() const;
  bool floatOverflow() const;
  void printInt_() const;
  void printChar_() const;
  void printFloat_() const;
  void printDouble_() const;

 public:
  /* default constructor */
  DoubleConverter(char c);

  /* copy constructor */
  DoubleConverter(DoubleConverter const& src);

  /* copy assignment operator */
  DoubleConverter& operator=(DoubleConverter const& rhs);

  /* default destructor */
  ~DoubleConverter();

  /* getters */

  /* setters */

  /* exceptions */

  /* public methods */
  void printConversions() const;
};

#endif