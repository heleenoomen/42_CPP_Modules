
#include "BitcoinExchange.hpp"

#include <iostream>

#include "Converter.hpp"
#include "DatabaseParser.hpp"
#include "constants.hpp"

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
BitcoinExchange::BitcoinExchange()
    : inputFile_(NULL), dbFile_(constants::databaseFile) {}

/* Constructor */
BitcoinExchange::BitcoinExchange(char const* inputFile)
    : inputFile_(inputFile), dbFile_(constants::databaseFile) {}

/* Copy constructor */
BitcoinExchange::BitcoinExchange(BitcoinExchange const& src) { *this = src; }

/* Copy assignment operator */
BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& rhs) {
  if (this == &rhs) return *this;
  return *this;
}

/* Destructor */
BitcoinExchange::~BitcoinExchange() {}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

void BitcoinExchange::run() {
  DatabaseParser dbParser(&database_, dbFile_);
  dbParser.parse();
  Converter converter(inputFile_, &database_);
  converter.convert();
}