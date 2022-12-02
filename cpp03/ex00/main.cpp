/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:06:42 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/02 10:52:28 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
  ClapTrap bobby("Bobby");
  ClapTrap gus("Gus");

  gus.attack("Sicko");
  gus.attack("George");
  gus.attack("Gwendolyn");
  bobby.attack("Dowdy");
  gus.takeDamage(13);
  gus.beRepaired(4);
  bobby.attack("a random robot");
  bobby.attack("another random robot");
  bobby.attack("Gus");
  bobby.takeDamage(1);
  bobby.beRepaired(1);
  bobby.attack("Julia");
  bobby.takeDamage(3);
  bobby.beRepaired(3);
  bobby.attack("an android");
  bobby.attack("Claudia");
  bobby.attack("Some robots");
  bobby.attack("Some other robot");
}