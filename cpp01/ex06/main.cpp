/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:45:03 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/27 12:53:02 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(int argc, char **argv) {
	
	if (argc != 2) {

		std::cerr << "Error: Wrong arguments" << std::endl;
		return 1;
	}
	
	Harl				harl;
	std::string const	arg(argv[1]);

	harl.complain(arg);

}