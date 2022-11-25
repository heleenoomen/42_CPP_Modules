/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:03:34 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/19 12:48:05 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	gl_var = 1;
int	f( void ) { return 2; }


namespace	Foo {

	int	gl_var = 3;
	int	f( void ) { return 4;}

}


namespace	Bar {

	int	gl_var = 5;
	int	f( void ) { return 6; }

}


namespace Muf = Bar;  //alias for a long namespace. They will now be equivalent


int	main(void) {

	printf( "gl_var:			[%d]\n", gl_var );
	printf( "f():			[%d]\n", f() );

	printf( "Foo::gl_var:		[%d]\n", Foo::gl_var );  // :: is called: 'scope resolution operator'. You make this call now inside the Foo namespace.
	printf( "Foo::f():		[%d]\n", Foo::f() );
	
	printf( "Bar::gl_var:		[%d]\n", Bar::gl_var );
	printf( "Bar::f():		[%d]\n", Bar::f() );

	printf( "Muf::gl_var:		[%d]\n", Muf::gl_var );
	printf( "Muf::f():		[%d]\n", Muf::f() );

	printf( "::gl_var:		[%d]\n", ::gl_var ); // exact same as line 40. It is the empty namespace. You can use the notation that you like the most.
	printf( "::f():			[%d]\n", ::f() ); // same as line 41. In front of normal functions, the colons are a bit of an overkill. Better just to refer to the function like in line 41

	return 0;
}


// Compiling C++:
//		g++ -Wall -Wextra -Werror main.cpp
// Output:
// gl_var:                 [1]
// f():                    [2]
// Foo::gl_var:            [3]
// Foo::f():               [4]
// Bar::gl_var:            [5]
// Bar::f():               [6]
// Muf::gl_var:            [5]
// Muf::f():               [6]
// ::gl_var:               [1]
// ::f():                  [2]

// Standard namespace: std::
// Here you can find the whole c++ standard library