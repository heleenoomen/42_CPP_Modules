/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:45:22 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/20 12:36:51 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H


class Sample {

public:

	Sample( int v );
	~Sample( void );

	int		getFoo( void ) const;
	int		compare( Sample * ohter ) const;

private:

	int	_foo;

};

#endif

// the compare function takes as a parameter the address of a sample instance
// and makes a comparisson between the current instance and the one passed as
// a parameter.