/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:23:39 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/06 18:50:52 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
 private:
  std::string _name;
  int _hitPoints;
  int _energyPoints;
  int _attackDamage;

 protected:
  void noPointsLeft() const;
  void printPoints(unsigned int amount) const;

 public:
  ClapTrap();
  ClapTrap(ClapTrap const& src);
  ClapTrap(std::string const& name);
  ClapTrap& operator=(ClapTrap const& rhs);
  ~ClapTrap();

  std::string const& getName() const;
  int getHitPoints() const;
  int getEnergyPoints() const;
  int getAttackDamage() const;

  void attack(std::string const& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};

#endif