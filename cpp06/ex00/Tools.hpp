/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tools.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/10 22:01:08 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <string>
// #include <iostream>

class Tools {
  // private:

  // /* private methods*/

  // protected:

  // /* protected methods */

 public:
  /* default constructor */
  Tools();

  /* copy constructor */
  Tools(Tools const& src);

  /* copy assignment operator */
  Tools& operator=(Tools const& rhs);

  /* default destructor */
  ~Tools();

  /* getters */

  /* setters */

  /* exceptions */

  /* public methods */
  static bool isPseudoLiteral(std::string const& s);
  static float inff();
  static double inf();
  static std::string intMaxString();
  static std::string intMinString();

  static int const nbrOfPseudoLiterals = 8;
};

/* insertion operator */
// std::ostream& operator<<(std::ostream& o, Tools const& cname);

#endif