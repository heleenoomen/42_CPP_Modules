/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:12:11 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/06 11:13:14 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
 public:
  /* Constructors */
  ScavTrap();
  ScavTrap(std::string const& name);
  ScavTrap(ScavTrap const& src);
  
  /* Assignment operator overload */
  ScavTrap& operator=(ScavTrap const& rhs);

  /* Destructor */
  ~ScavTrap();

  /* Public methods */
  void guardGate() const;
  void attack(std::string const& target);
};

#endif