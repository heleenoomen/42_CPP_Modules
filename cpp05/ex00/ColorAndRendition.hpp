/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ColorAndRendition.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:28:47 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/12 21:35:06 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORANDRENDITION_HPP
#define COLORANDRENDITION_HPP

#include <string>

class ColorAndRendition {
 private:
  /* reset value */
  static std::string const RESET;

  /* rendering options */
  static std::string const BOLD;
  static std::string const FAINT;
  static std::string const ITALIC;
  static std::string const UNDERLINE;
  static std::string const REVERSE;

  /* colors */
  static std::string const BLACK;
  static std::string const RED;
  static std::string const GREEN;
  static std::string const YELLOW;
  static std::string const BLUE;
  static std::string const MAGENTA;
  static std::string const CYAN;
  static std::string const WHITE;

 public:
  /* default constructor */
  ColorAndRendition();

  /* copy constructor */
  ColorAndRendition(ColorAndRendition const& src);

  /* copy assignment operator */
  ColorAndRendition& operator=(ColorAndRendition const& rhs);

  /* default destructor */
  ~ColorAndRendition();

  /* public methods */
  void setColorAndRendition(std::string color, std::string rendition);
  void resetColorAndRendition();
};

#endif
