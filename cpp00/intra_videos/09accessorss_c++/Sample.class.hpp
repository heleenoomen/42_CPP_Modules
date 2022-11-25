/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:45:22 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/20 11:49:27 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H


class Sample {

public:

	Sample( void );
	~Sample( void );

	int		getFoo( void ) const; // proxy function (getter) to get the value of Foo
	void	setFoo( int v ); // proxy funtion (setter) to set the value of Foo

private:

	int	_foo; // private, but accessible for reading and writing by the proxyfunction getFoo and setFoo

};

#endif

// We like to know the value of some private attributes or change it, but without
// causing any mess in our class.
// Therefore, you want to offer proxy functions. They are the interface between the
// user and the private attributes, to be sure that the values are always correct.
// These little writing and reading functions are called 'getters'
// They are usually prefixed by 'get' or 'set' (just a convention)

// Note that getFoo is const, because the getter can only access the variable in 
// readonly mode, it cannot alter the content of the class.


