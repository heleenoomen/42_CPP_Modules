/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OCF.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/12 20:54:05 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CNAME_HPP
#define CNAME_HPP

// #include <string>
// #include <iostream>

class CName {
 //private:

 //protected:

 public:
  /* default constructor */
  CName();

  /* copy constructor */
  CName(CName const& src);

  /* copy assignment operator */
  CName& operator=(CName const& rhs);

  /* default destructor */
  ~CName();

  /* getters */

  /* setters */
};

/* insertion operator */
// std::ostream& operator<<(std::ostream& o, CName const& cname);

#endif