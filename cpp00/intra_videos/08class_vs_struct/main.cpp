/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:00:58 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/20 11:38:48 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample1.class.hpp"
#include "Sample2.class.hpp"

int	main() {

	Sample1	instance1; // structure
	Sample2	instance2; // class

	return 0;
}

// If you compile this, it gives you a compilation error saying that the constructor
// of Sample 2 is private and so it the destructor:
//		Sample2.class.hpp: In function 'int main()':
//		Sample2.class.hpp::17:2: error: 'Sample2::Sample2()' is private
//			Sample2( void );
//			^
//		main.cpp.16:10: error: wiithin this context
//			Sample2 intance2;
//					^


// On the other hand, there is no error for the struct! (Sample1)
// In other words: structures will compile without problems if you do not specify
// public or private.
// For a class, it gives a compilation error.

// The difference between a class and a struct in C++ is that the scope of a struct
// is public by default and the scope of a class is private by default

// This difference has little impact if you program in a clean way and specifiy
// systematically.
// The difference isn't interesting. We will preferably use classes instead of struct.
// Everything that can be done with structures in C, can be done with classes
// in C++. The advantage is that you have with a class better control over its
// attributes and have member functions.