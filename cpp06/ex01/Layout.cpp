/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Layout.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:04:47 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/20 11:04:50 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Layout.hpp"

#include <iostream>

/* ************************************************************************** */
/* Symbolic constants                                                         */
/* ************************************************************************** */

/* colored output when not redirecting to file */
#ifndef redirect_to_file
char const* Layout::greenBold = "\033[32;1m";
char const* Layout::green = "\033[32;22m";
char const* Layout::yellowBold = "\033[33;1m";
char const* Layout::yellow = "\033[33;22m";
char const* Layout::brightYellow = "\033[93;22m";
char const* Layout::redBold = "\033[31;1m";
char const* Layout::magentaBold = "\033[35;1m";
char const* Layout::magenta = "\033[35;22m";
char const* Layout::cyan = "\033[35;22m";
char const* Layout::cyanBold = "\033[36;1m";
char const* Layout::cyanItalic = "\033[36;3m";
char const* Layout::grey = "\033[0;2m";
char const* Layout::reset = "\033[0m";
#else
char const* Layout::greenBold = "";
char const* Layout::green = "";
char const* Layout::yellowBold = "";
char const* Layout::yellow = "";
char const* Layout::brightYellow = "";
char const* Layout::redBold = "";
char const* Layout::magentaBold = "";
char const* Layout::magenta = "";
char const* Layout::cyan = "";
char const* Layout::cyanBold = "";
char const* Layout::cyanItalic = "";
char const* Layout::grey = "";
char const* Layout::reset = "";
#endif

/* emoji's */
char const* Layout::emojiRobot = "\U0001F916";
char const* Layout::emojiSkull = "\U0001F480";
char const* Layout::emojiStar = "\u2B50";

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
Layout::Layout() {}

/* Copy constructor */
Layout::Layout(Layout const& src) { *this = src; }

/* Copy assignment operator */
Layout& Layout::operator=(Layout const& rhs) {
  if (this == &rhs) return *this;
  return *this;
}

/* Destructor */
Layout::~Layout() {}
