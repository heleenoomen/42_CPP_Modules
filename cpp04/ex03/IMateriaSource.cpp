/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:58:09 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/09 18:02:23 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

#include <iostream>

#include "Layout.hpp"

IMateriaSource::IMateriaSource() {
  std::cout << Layout::grey << "IMateriaSource default constructor called\n"
            << Layout::reset;
}

IMateriaSource::IMateriaSource(IMateriaSource const& src) {
  std::cout << Layout::grey << "IMateriaSource copy constructor called\n"
            << Layout::reset;
  *this = src;
}

IMateriaSource& IMateriaSource::operator=(IMateriaSource const&) {
  return *this;
}

IMateriaSource::~IMateriaSource() {
  std::cout << Layout::grey << "IMateriaSource destructor called\n"
            << Layout::reset;
}
