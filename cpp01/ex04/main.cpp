/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:44:27 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/26 13:57:53 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int argc, char **argv) {

	if (argc != 4) {
		
		std::cerr << "Error: Wrong parameters" << std::endl;
		return 1;
	}

	std::ifstream	ifs(argv[1], std::ifstream::in);
	if (ifs.fail())
	{
		std::cerr << "Error: Cannot open " << argv[1] << std::endl;
		return 2;
	}

	(void)argv[2];
	(void)argv[3];
	return 0;
}