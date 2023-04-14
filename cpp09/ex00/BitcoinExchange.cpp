
#include "BitcoinExchange.hpp"

#include <iostream>

#include "Converter.hpp"
#include "DatabaseParser.hpp"

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
BitcoinExchange::BitcoinExchange() {}

/* Constructor */
BitcoinExchange::BitcoinExchange(char const* inputFile)
    : inputFile_(inputFile) {}

/* Copy constructor */
BitcoinExchange::BitcoinExchange(BitcoinExchange const& src) { *this = src; }

/* Copy assignment operator */
BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& rhs) {
  if (this == &rhs) return *this;
  /* assign values here */
  return *this;
}

/* Destructor */
BitcoinExchange::~BitcoinExchange() {}

/* ************************************************************************** */
/* Exceptions                                                                 */
/* ************************************************************************** */

/* ************************************************************************** */
/* Private methods                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

void BitcoinExchange::run() {
  DatabaseParser dbParser(&database_, dbFile_);
  dbParser.parse();
}