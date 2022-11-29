/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:07:20 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/29 20:34:31 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
 public:
  Point();
  Point(Fixed const x, Fixed const y);
  Point(float const x, float const y);
  Point(Point const& src);

  ~Point();

  Point& operator=(Point const& rhs);

  float getXFloat() const;
  float getFloat() const;
  int getXraw() const;
  int getYraw() const;
  Fixed const& getX() const;
  Fixed const& getY() const;

 private:
  Fixed const _x;
  Fixed const _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif