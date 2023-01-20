/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:02:15 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/20 11:02:26 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Converter.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Wrong arguments\n";
    return EXIT_FAILURE;
  }
  Converter::convertLiteral(argv[1]);
  return 0;
}
