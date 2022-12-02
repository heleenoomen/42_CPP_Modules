/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:23:39 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/02 10:24:43 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include<string>

class ClapTrap {
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

 private:
  std::string _name;
  int _hitPoints;
  int _energyPoints;
  int _attackDamage;
  
};

#endif