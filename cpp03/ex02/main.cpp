/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:06:42 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/05 15:20:00 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
  ClapTrap bobby("Bobby");
  ScavTrap drake("Drake");
  FragTrap julie("Julie");

  drake.attack("Debby");
  bobby.attack("Grace");
  julie.highFiveGuys();
  julie.attack("a horde of robots");
  drake.guardGate();
  bobby.takeDamage(10);
  bobby.beRepaired(5);
  drake.attack("four thousand robots");
  drake.takeDamage(10);
  julie.beRepaired(5);
  drake.beRepaired(5);
  drake.guardGate();
  for (int i = 0; i < 50; i++)
    julie.attack("Perry");
  julie.beRepaired(10);
  for (int i = 0; i < 50; i++)
    julie.attack("Ray");
  julie.beRepaired(1);
}
