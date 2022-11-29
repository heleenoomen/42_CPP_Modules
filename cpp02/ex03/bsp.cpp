/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:38:53 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/29 20:37:24 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static int orient(Point const a, Point const b, Point const c) {
  Point v_ab(b.getX() - a.getX(), b.getY() - a.getY());
  Point v_ac(c.getX() - a.getX(), c.getY() - a.getY());
  Fixed crossproduct;
  float crossp;

  crossproduct = v_ab.getX() * v_ac.getY() - v_ab.getY() * v_ac.getX();
  crossp = crossproduct.toFloat();
  if (crossp > 0) return 1;
  return -1;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  int turns;

  turns = orient(a, b, point) + orient(b, c, point) + orient(c, a, point);
  if (turns == 3 || turns == -3) return true;
  return false;
}

/* the mathematical idea is explained as the "Orientation approach" here:
https://www.baeldung.com/cs/check-if-point-is-in-2d-triangle
*/