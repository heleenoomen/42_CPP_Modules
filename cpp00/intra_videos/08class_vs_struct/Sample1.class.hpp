/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:45:22 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/20 11:25:54 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE1_CLASS_H
# define SAMPLE1_CLASS_H


struct Sample1 {

	int	Foo;

	Sample1( void );
	~Sample1( void );

	void	bar( void ) const;
};

#endif

// Above is a structure in C++
// Structures and classes work exactly the same in C++

// Then why two keywords? Why not use struct only or class only?
// There is actually a difference!