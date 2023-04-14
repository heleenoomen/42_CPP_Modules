
#include "Converter.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

#include "tools.hpp"

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
Converter::Converter() : inputFile_(NULL) {}

/* Constructor */
Converter::Converter(char const* inputFile) : inputFile_(inputFile) {}

/* Copy constructor */
Converter::Converter(Converter const& src) : inputFile_(src.inputFile_) {
  *this = src;
}

/* Copy assignment operator */
Converter& Converter::operator=(Converter const& rhs) { return *this; }

/* Destructor */
Converter::~Converter() {}

/* ************************************************************************** */
/* Exceptions                                                                 */
/* ************************************************************************** */

/* ************************************************************************** */
/* Private methods                                                            */
/* ************************************************************************** */
void Converter::extractItem(std::stringstream& linestream, std::string& item) {
  linestream >> item;
  if (linestream.fail()) throw badInput();
  if (linestream.bad()) throw std::runtime_error("Unable to read file");
}

void Converter::extractItemsFromLine() {
  std::stringstream linestream(line_);
  extractItem(linestream, date_);
  extractItem(linestream, separator_);
  extractItem(linestream, valueStr_);
  if (linestream.eof()) throw badInput();
}

void Converter::checkDate() {
  if (!tools::isValidDate(date_)) throw badInput();
}

void Converter::checkSeparator() {
  if (separator_ != correct_separator_) throw badInput();
}

void Converter::checkValue() {
  try {
    value_ = tools::stringToFloat(valueStr_);
  } catch (tools::badStringStream()) {
    throw std::runtime_error("Unable to read file");
  } catch (tools::invalidFloat()) {
    throw badInput();
  }
  if (value_ < 0) throw negativeNumber();
  if (value_ > 999) throw numberTooLarge();
}

void Converter::parseLine() {
  extractItemsFromLine();
  checkDate();
  checkSeparator();
  checkValue();
}

void Converter::convertValue() {
  std::map<std::string, float>::iterator firstGreater =
      database_->upper_bound(date_);
  std::map<std::string, float>::iterator beginDatabase = database_->begin();
  std::map<std::string, float>::iterator lookupDate;
  if (firstGreater == beginDatabase)
    lookupDate = beginDatabase;
  else
    lookupDate = firstGreater--;
  float exchangeRate = lookupDate->second;
  value_ *= exchangeRate;
}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

void Converter::convert() {
  std::ifstream ifs(inputFile_);
  if (!ifs) throw std::runtime_error("Unable to open inputfile");
  while (!ifs.eof()) {
    std::getline(ifs, line_);
    if (ifs.bad() | ifs.fail()) throw std::runtime_error("Unable to read file");
    parseLine();
    convertValue();
    printResult();
  }
}