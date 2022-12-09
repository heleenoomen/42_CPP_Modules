/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:07:20 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/09 13:12:26 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
 public:
  Point();
  Point(Fixed const& x, Fixed const& y);
  Point(Point const& src);

  ~Point();

  Point& operator=(Point const& rhs);
  /* NB: this copy assignment operator is useless, since _x and _y are const
     in c++11 you would say here:
          Point& operator=(Point const& rhs) = delete;
     to prohibit assignment by definition.
  */

  Fixed const& getX() const;
  Fixed const& getY() const;

 private:
  Fixed const _x;
  Fixed const _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif