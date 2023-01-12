/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntConverter.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/21 17:49:46 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTCONVERTER_HPP
#define INTCONVERTER_HPP

// #include <string>
// #include <iostream>

class IntConverter {
 private:
  int intValue_;

 /* private methods */
  void printInt_() const;
  void printChar_() const;
  void printFloat_() const;
  void printDouble_() const;

 public:
  /* default constructor */
  IntConverter(int i);

  /* copy constructor */
  IntConverter(IntConverter const& src);

  /* copy assignment operator */
  IntConverter& operator=(IntConverter const& rhs);

  /* default destructor */
  ~IntConverter();

  /* getters */

  /* setters */

  /* exceptions */

  /* public methods */
  void printConversions() const;
};

#endif