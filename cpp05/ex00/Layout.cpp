
#include "Layout.hpp"
#include <iostream>

/* ************************************************************************** */
/* Symbolic constants                                                         */
/* ************************************************************************** */

char const* Layout::RESET = "0";
char const* Layout::NORMAL = "0";
char const* Layout::BOLD = "1";
char const* Layout::FAINT = "2";
char const* Layout::ITALIC = "3";
char const* Layout::UNDERLINE = "4";
char const* Layout::BLACK = "30";
char const* Layout::RED = "31";
char const* Layout::GREEN = "32";
char const* Layout::YELLOW = "33";
char const* Layout::BLUE = "34";
char const* Layout::MAGENTA = "35";
char const* Layout::CYAN = "36";
char const* Layout::WHITE = "37";
char const* Layout::PREFIX = "\033[";
char const* Layout::SUFFIX = "m";
char const* Layout::INTERFIX = ";";

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
Layout::Layout() {
  // : formatString_(Layout::PREFIX + Layout::RESET + Layout::SUFFIX) {
}

// /* Parametric constructor */
// Layout::Layout(std::string const& color, std::string const& rendition )
//   // : formatString_(Layout::PREFIX + color + ";" + rendition + Layout::SUFFIX) {
// }

/* Copy constructor */
Layout::Layout(Layout const& src) {
  *this = src;
}

/* Copy assignment operator */
Layout& Layout::operator=(Layout const& rhs) {
  // formatString_ = rhs.getFormatString();
  return *this;
}

/* Destructor */
Layout::~Layout() {
}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

// std::string const& Layout::getFormatString() const {
//   return formatString_;
// }


/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

void Layout::set(std::ostream& o, std::string const& color, std::string const& 
    rendition) const {
  o << Layout::PREFIX + color + ";" + rendition + Layout::SUFFIX;
}

void Layout::reset(std::ostream& o) const {
  o << Layout::PREFIX + static_cast<std::string>(Layout::RESET) + Layout::SUFFIX;
}

// Layout& Layout::end() {
//   reset();
//   return *this;
// }

/* ************************************************************************** */
/* Insertion operator                                                         */
/* ************************************************************************** */

// std::ostream& operator<<(std::ostream& o, Layout const& l) {
//   o << l.getFormatString();
//   return o;
// }
