/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:23:39 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/08 17:39:44 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include<string>

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
  /* Constructors */
  ClapTrap();
  ClapTrap(ClapTrap const& src);
  ClapTrap(std::string const& name);
  ClapTrap(std::string const& name, int hitPoints, int energyPoints, int attackDamage);
  
  /* Assginment operator overload */
  ClapTrap& operator=(ClapTrap const& rhs);
  
  /* Destructor */
  virtual ~ClapTrap();

  /* Getters */
  std::string const& getName() const;
  int getHitPoints() const;
  int getEnergyPoints() const;
  int getAttackDamage() const;

  /* Setters */
  void decrEnergyPoints();
  
  /* Public methods */
  void attack(std::string const& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};

#endif