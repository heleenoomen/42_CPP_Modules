/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Layout.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/21 17:49:46 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAYOUT_HPP
#define LAYOUT_HPP

/* Comment the following three lines on when redirecting output to a file to
   avoid escape codes being printed: */

// #ifndef redirect_to_file
// #define redirect_to_file
// #endif

class Layout {
 public:
  /* default constructor */
  Layout();

  /* copy constructor */
  Layout(Layout const& src);

  /* copy assignment operator */
  Layout& operator=(Layout const& rhs);

  /* default destructor */
  ~Layout();

  /* symbolic constants */
  static char const* greenBold;
  static char const* green;

  static char const* yellowBold;
  static char const* yellow;

  static char const* brightYellow;

  static char const* redBold;

  static char const* magentaBold;
  static char const* magenta;

  static char const* cyanBold;
  static char const* cyanItalic;

  static char const* grey;

  static char const* reset;

  static char const* emojiRobot;
  static char const* emojiSkull;
};

#endif