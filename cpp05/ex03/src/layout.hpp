/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/21 17:49:46 by hoomen           ###   ########.fr       */
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
extern char const* grey;
extern char const* reset;

/* emoji's */
extern char const* emojiRobot;
extern char const* emojiSkull;
}

#endif