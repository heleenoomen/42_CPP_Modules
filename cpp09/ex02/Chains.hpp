/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Chains.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/10 22:01:08 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAINS_HPP
#define CHAINS_HPP

#include "typedefs.hpp"

class Chains {
 private:
  vecInt* mainChain_;
  vecInt* pending_;
  vecPairs pairs_;
  
  /* private methods*/

  // protected:

  // /* protected methods */

 public:
  /* default constructor */
  Chains();

  /* copy constructor */
  Chains(Chains const& src);

  /* copy assignment operator */
  Chains& operator=(Chains const& rhs);

  /* default destructor */
  ~Chains();

  /* getters */

  /* setters */

  /* exceptions */

  /* public methods */
};

/* insertion operator */
// std::ostream& operator<<(std::ostream& o, Chains const& cname);

#endif