/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:06:42 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/01 16:33:13 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
  std::string b("Bobby");
  std::string e("Elaine");

  ClapTrap bobby(b);
  ClapTrap elaine(e);

  bobby.attack(e);
  elaine.takeDamage(6);
  elaine.beRepaired(4);
  bobby.attack(e);
  elaine.takeDamage(3);
  elaine.beRepaired(5);
  elaine.attack(b);
  bobby.takeDamage(8);
  bobby.beRepaired(1);
  bobby.beRepaired(1);
  bobby.beRepaired(1);
  bobby.attack(e);
  elaine.takeDamage(1);
  bobby.attack(e);
  elaine.takeDamage(1);
  elaine.attack(b);
  bobby.takeDamage(8);
  bobby.attack(e);
  bobby.beRepaired(1);
  bobby.beRepaired(1);
  bobby.beRepaired(1);
  bobby.beRepaired(1);
}