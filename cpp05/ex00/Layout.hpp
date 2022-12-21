/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Layout.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:28:47 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/13 11:55:43 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAYOUT_HPP
#define LAYOUT_HPP

#include <string>

class Layout {
 public:

  /* prefix / suffix */
  static char const* PREFIX;
  static char const* SUFFIX;
  static char const* INTERFIX;

  static char const* RESET;

  /* rendition */
  static char const* NORMAL;
  static char const* BOLD;
  static char const* FAINT;
  static char const* ITALIC;
  static char const* UNDERLINE;

  /* color */
  static char const* BLACK;
  static char const* RED;
  static char const* GREEN;
  static char const* YELLOW;
  static char const* BLUE;
  static char const* MAGENTA;
  static char const* CYAN;
  static char const* WHITE;

  /* default constructor */
  Layout();

  /* parametric constructor */
  // Layout(std::string const& color, std::string const& rendition);

  /* copy constructor */
  Layout(Layout const& src);

  /* copy assignment operator */
  Layout& operator=(Layout const& rhs);

  /* default destructor */
  ~Layout();

  /* getter */
  // std::string const& getFormatString() const;

  // /* public methods */
  void set(std::ostream& o, std::string const& color, std::string const& rendition) const;
  void reset(std::ostream& o) const;
  // Layout& end();
};

/* insertion operator */
// std::ostream& operator<<(std::ostream& o, Layout const& l);

#endif
