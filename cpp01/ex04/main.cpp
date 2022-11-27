/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:44:27 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/27 15:49:48 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <istream>
#include <string>

void	replace(char **argv, std::ifstream& ifs, std::ofstream& ofs) {

	std::string	word(argv[2]);
	std::string	replace_word(argv[3]);

	std::string	line;

	size_t	pos;

	while ( !ifs.eof() ) {
		getline( ifs, line );
		while ( true ) {
			pos = line.find( word );
			if ( pos >= line.length() )
			{
				ofs << line;
				break ;
			}
			else
			{
				ofs << line.substr(0, pos);
				line = line.substr(pos + word.length());
				ofs << replace_word;
			}
		}
		if (ifs.peek() != EOF)
			ofs << std::endl;
	}
}


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

	std::string		ofname(argv[1]);
	std::ofstream	ofs(ofname += ".replace", std::ofstream::out);
	if (ofs.fail()) {
		std::cerr << "Error: Cannot open " << ofname << std::endl;
		return 2;
	}

	replace(argv, ifs, ofs);


	return 0;
}

// NB: open filestreams are automatically closed when the object is destroyed
// https://cplusplus.com/reference/fstream/ifstream/close/