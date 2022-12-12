
#include "ColorAndRendition.hpp"
#include <iostream>

/* ************************************************************************** */
/* Symbolic constants                                                         */
/* ************************************************************************** */

std::string const RESET = "0";

std::string const BOLD = "1";
std::string const FAINT = "2";
std::string const ITALIC = "3";
std::string const UNDERLINE = "4";
std::string const REVERSE = "5";

std::string const BLACK = "30";
std::string const RED = "31";
std::string const GREEN = "32";
std::string const YELLOW = "33";
std::string const BLUE = "34";
std::string const MAGENTA = "35";
std::string const CYAN = "36";
std::string const WHITE = "37";



/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
ColorAndRendition::ColorAndRendition() {
}

/* Copy constructor */
ColorAndRendition::ColorAndRendition(ColorAndRendition const& src) {
  *this = src;
}

/* Copy assignment operator */
ColorAndRendition& ColorAndRendition::operator=(ColorAndRendition const& rhs) {
  return *this;
}

/* Destructor */
ColorAndRendition::~ColorAndRendition() {
}


/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

void ColorAndRendition::setColorAndRendition(std::string color, std::string 
    rendition) {
  std::cout << "\033[" << color << ";" << rendition << "m";
}

void ColorAndRendition::resetColorAndRendition() {
  std::cout << "\033[0m";
}
