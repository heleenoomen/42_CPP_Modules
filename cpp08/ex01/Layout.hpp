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

namespace Layout {
#ifndef redirect_to_file
static char const* greenBold = "\033[32;1m";
static char const* green = "\033[32;22m";
static char const* yellowBold = "\033[33;1m";
static char const* yellow = "\033[33;22m";
static char const* brightYellow = "\033[93;22m";
static char const* redBold = "\033[31;1m";
static char const* magentaBold = "\033[35;1m";
static char const* magenta = "\033[35;22m";
static char const* cyan = "\033[35;22m";
static char const* cyanBold = "\033[36;1m";
static char const* cyanItalic = "\033[36;3m";
static char const* grey = "\033[0;2m";
static char const* reset = "\033[0m";
#else
static char const* greenBold = "";
static char const* green = "";
static char const* yellowBold = "";
static char const* yellow = "";
static char const* brightYellow = "";
static char const* redBold = "";
static char const* magentaBold = "";
static char const* magenta = "";
static char const* cyan = "";
static char const* cyanBold = "";
static char const* cyanItalic = "";
static char const* grey = "";
static char const* reset = "";
#endif
static char const* emojiRobot = "\U0001F916";
static char const* emojiSkull = "\U0001F480";
static char const* emojiStar = "\u2B50";
};  // namespace Layout

#endif