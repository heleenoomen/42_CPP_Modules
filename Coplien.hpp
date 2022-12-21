/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Coplien.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/21 17:49:46 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COPLIEN_HPP
#define COPLIEN_HPP

// #include <string>
// #include <iostream>

class Coplien {
 //private:

 //protected:

 public:
  /* default constructor */
  Coplien();

  /* copy constructor */
  Coplien(Coplien const& src);

  /* copy assignment operator */
  Coplien& operator=(Coplien const& rhs);

  /* default destructor */
  ~Coplien();

  /* getters */

  /* setters */
};

/* insertion operator */
// std::ostream& operator<<(std::ostream& o, Coplien const& cname);

#endif