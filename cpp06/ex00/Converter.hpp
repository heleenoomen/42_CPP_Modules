/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/12 18:21:42 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <string>
// #include <iostream>


class Converter {
 private:
  std::string const inputString_;
  double value_;

  // /* private methods*/
  bool charOverflow() const;
  bool charImpossible() const;
  bool charNonDisplayable() const;
  bool intOverflow() const;
  bool intImpossible() const;
  bool floatOverflow() const;
  bool floatImpossible() const;
  void printChar_() const;
  void printInt_() const;
  void printFloat_() const;
  void printDouble_() const;
  void printConversions_() const;

  // protected:

  // /* protected methods */

 public:
  /* default constructor */
  Converter();
  Converter(std::string const& inputString);

  /* copy constructor */
  Converter(Converter const& src);

  /* copy assignment operator */
  Converter& operator=(Converter const& rhs);

  /* default destructor */
  ~Converter();

  /* getters */

  /* setters */

  /* exceptions */

  /* public methods */
  static void convertLiteral(std::string const& input);
};

/* insertion operator */
// std::ostream& operator<<(std::ostream& o, Converter const& cname);

#endif