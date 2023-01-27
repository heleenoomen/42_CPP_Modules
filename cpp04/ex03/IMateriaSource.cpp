/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:58:09 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/27 16:58:59 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

#include <iostream>

#include "layout.hpp"

IMateriaSource::IMateriaSource() {
  std::cout << layout::grey << "IMateriaSource default constructor called\n"
            << layout::reset;
}

IMateriaSource::IMateriaSource(IMateriaSource const& src) {
  std::cout << layout::grey << "IMateriaSource copy constructor called\n"
            << layout::reset;
  *this = src;
}

IMateriaSource& IMateriaSource::operator=(IMateriaSource const&) {
  return *this;
}

IMateriaSource::~IMateriaSource() {
  std::cout << layout::grey << "IMateriaSource destructor called\n"
            << layout::reset;
}
