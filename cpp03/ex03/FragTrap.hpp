/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:12:11 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/06 18:03:00 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
 protected:
  int _hitPoints;
  int _attackDamage;
  int _energyPoints;

 public:
  FragTrap();
  FragTrap(std::string const& name);
  FragTrap(FragTrap const& src);

  FragTrap& operator=(FragTrap const& rhs);

  ~FragTrap();
  void highFiveGuys() const;
  void attack(std::string const& target);
};

#endif