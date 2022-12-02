/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:06:42 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/02 15:16:08 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
  ClapTrap bobby("Bobby");
  ScavTrap drake("Drake");

  drake.attack("Debby");
  bobby.attack("Grace");
  bobby.attack("a horde of robots");
  bobby.takeDamage(10);
  bobby.beRepaired(5);
  drake.attack("four thousand robots");
  drake.takeDamage(10);
  drake.beRepaired(5);
  drake.guardGate();
}
