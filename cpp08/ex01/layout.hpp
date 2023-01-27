/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Layout.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:30:46 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/27 21:31:09 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAYOUT_HPP
#define LAYOUT_HPP

/* layout namespace for easy color printing. Define redirect_to_file if
   recirecting output to log file in order not to print escape codes
*/

// #ifndef redirect_to_file
// #define redirect_to_file
// #endif

namespace layout {
  extern char const* greenBold;
  extern char const* green;

  extern char const* yellowBold;
  extern char const* yellow;

  extern char const* brightYellow;

  extern char const* redBold;

  extern char const* magentaBold;
  extern char const* magenta;

  extern char const* cyanBold;
  extern char const* cyanItalic;
  extern char const* cyanItalicBold;
  extern char const* cyan;

  extern char const* grey;

  extern char const* reset;

  extern char const* emojiRobot;
  extern char const* emojiSkull;
  extern char const* emojiStar;
}

#endif