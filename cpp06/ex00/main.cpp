/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 14:34:04 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/12 07:53:45 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Conversion.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Wrong arguments\n";
    return EXIT_FAILURE;
  }
  Conversion conv(argv[1]);
  conv.convert();
}