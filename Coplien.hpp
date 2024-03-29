/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Coplien.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2023/04/24 19:44:36 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COPLIEN_HPP
#define COPLIEN_HPP

// #include <string>
// #include <iostream>

class Coplien {
  // private:

  // /* private methods*/

  // protected:

  // /* protected methods */

 public:
  /* default constructor */
  Coplien();

  /* copy constructor */
  Coplien(Coplien const& src);

  /* copy assignment operator */
  Coplien& operator=(Coplien const& rhs);

  /* destructor */
  ~Coplien();

  /* getters */

  /* setters */

  /* exceptions */

  /* public methods */
};

/* insertion operator */
// std::ostream& operator<<(std::ostream& o, Coplien const& cname);

#endif