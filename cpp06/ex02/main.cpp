/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:21:39 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/20 11:21:41 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include "Layout.hpp"

void printStars() {
  std::cout << "\n\t\t\t    ";
  for (int i = 0; i < 3; ++i) std::cout << Layout::emojiStar;
  std::cout << std::endl;
}

int main() {
  printStars();
  std::cout
      << Layout::magentaBold
      << "\nConstruct objects of type A, B, and C and print their type:\n\n"
      << Layout::reset;
  A a;
  Base base;
  std::cout << '\t';
  base.identify(&a);
  B b;
  std::cout << '\t';
  base.identify(&b);
  std::cout << '\t';
  C c;
  base.identify(&c);

  std::cout << Layout::magentaBold
            << "\nGenerate 10 random derived classes and identify their type "
               "passing pointers:\n\n"
            << Layout::reset;
  for (int i = 0; i < 10; ++i) {
    Base* someDerivedClass = base.generate();
    std::cout << '\t';
    base.identify(someDerivedClass);
  }

  std::cout << Layout::magentaBold
            << "\nGenerate 10 random derived classes and identify their type "
               "passing references:\n\n"
            << Layout::reset;
  for (int i = 0; i < 10; ++i) {
    Base* someDerivedClass = base.generate();
    std::cout << '\t';
    base.identify(*someDerivedClass);
  }
  printStars();
  std::cout << std::endl;
  return 0;
}
