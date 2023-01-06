/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:12:11 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/06 18:02:53 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
 protected:
  int _hitPoints;
  int _attackDamage;
  int _energyPoints;

 public:
  ScavTrap();
  ScavTrap(std::string const& name);
  ScavTrap(ScavTrap const& src);

  ScavTrap& operator=(ScavTrap const& rhs);

  ~ScavTrap();
  void guardGate() const;
  void attack(std::string const& target);
};

#endif