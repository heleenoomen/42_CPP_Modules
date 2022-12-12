/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:58:09 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/12 13:02:37 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

#include <iostream>

IMateriaSource::IMateriaSource() {
  std::cout << "IMateriaSource default constructor called" << std::endl;
}

IMateriaSource::IMateriaSource(IMateriaSource const& src) {
  std::cout << "IMateriaSource copy constructor called" << std::endl;
  *this = src;
}

IMateriaSource& IMateriaSource::operator=(IMateriaSource const&) {
  return *this;
}

IMateriaSource::~IMateriaSource() {
  std::cout << "IMateriaSource destructor called" << std::endl;
}
