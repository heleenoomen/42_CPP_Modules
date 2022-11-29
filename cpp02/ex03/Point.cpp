/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:19:00 by hoomen            #+#    #+#             */
/*   Updated: 2022/11/29 20:34:18 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* ************************************************************************** */
/* CONSTRUCTORS                                                               */
/* ************************************************************************** */

Point::Point() : _x(0), _y(0) { return; }

Point::Point(Fixed const x, Fixed const y) : _x(x), _y(y) { return; }

Point::Point(float const x, float const y) :_x(x), _y(y) { return; }

Point::Point(Point const &src) : _x(src.getX()), _y(src.getY()) { return; }

/* ************************************************************************** */
/* DECONSTRUCTOR                                                              */
/* ************************************************************************** */

Point::~Point() { return; }

/* ************************************************************************** */
/* GETTERS                                                               */
/* ************************************************************************** */

float Point::getXFloat() const { return _x.toFloat(); }

float Point::getFloat() const { return _y.toFloat(); }

int Point::getXraw() const { return _x.getRawBits(); }

int Point::getYraw() const { return _y.getRawBits(); }

Fixed const& Point::getX() const { return _x; }

Fixed const& Point::getY() const { return _y; }