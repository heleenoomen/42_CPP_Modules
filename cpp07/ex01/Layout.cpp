/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Layout.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:04:47 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/27 21:11:24 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "layout.hpp"

#include <iostream>

/* colored output when not redirecting to file */
#ifndef redirect_to_file

char const* layout::greenBold = "\033[32;1m";
char const* layout::green = "\033[32;22m";
char const* layout::yellowBold = "\033[33;1m";
char const* layout::yellow = "\033[33;22m";
char const* layout::brightYellow = "\033[93;22m";
char const* layout::redBold = "\033[31;1m";
char const* layout::magentaBold = "\033[35;1m";
char const* layout::magenta = "\033[35;22m";
char const* layout::cyan = "\033[35;22m";
char const* layout::cyanBold = "\033[36;1m";
char const* layout::cyanItalic = "\033[36;3m";
char const* layout::grey = "\033[0;2m";
char const* layout::reset = "\033[0m";

#else

char const* layout::greenBold = "";
char const* layout::green = "";
char const* layout::yellowBold = "";
char const* layout::yellow = "";
char const* layout::brightYellow = "";
char const* layout::redBold = "";
char const* layout::magentaBold = "";
char const* layout::magenta = "";
char const* layout::cyan = "";
char const* layout::cyanBold = "";
char const* layout::cyanItalic = "";
char const* layout::grey = "";
char const* layout::reset = "";

#endif

/* emoji's */
char const* layout::emojiRobot = "\U0001F916";
char const* layout::emojiSkull = "\U0001F480";
char const* layout::emojiStar = "\u2B50";
