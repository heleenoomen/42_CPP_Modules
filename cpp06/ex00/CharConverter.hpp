/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharConverter.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/21 17:49:46 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARCONVERTER_HPP
#define CHARCONVERTER_HPP

// #include <string>
// #include <iostream>

class CharConverter {
 private:
  char charValue_;

 /* private methods */
  void printInt_() const;
  void printChar_() const;
  void printFloat_() const;
  void printDouble_() const;

 public:
  /* default constructor */
  CharConverter(char c);

  /* copy constructor */
  CharConverter(CharConverter const& src);

  /* copy assignment operator */
  CharConverter& operator=(CharConverter const& rhs);

  /* default destructor */
  ~CharConverter();

  /* getters */

  /* setters */

  /* exceptions */

  /* public methods */
  void printConversions() const;
};

#endif