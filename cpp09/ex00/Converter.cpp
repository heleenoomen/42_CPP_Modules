
#include "Converter.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

#include "constants.hpp"
#include "tools.hpp"

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
Converter::Converter() : inputFile_(NULL) {}

/* Constructor */
Converter::Converter(char const* inputFile,
                     std::map<std::string, float>* database)
    : inputFile_(inputFile), database_(database) {}

/* Copy constructor */
Converter::Converter(Converter const& src) : inputFile_(src.inputFile_) {
  *this = src;
}

/* Copy assignment operator */
Converter& Converter::operator=(Converter const& rhs) {
  if (this == &rhs) return *this;
  return *this;
}

/* Destructor */
Converter::~Converter() {}

/* ************************************************************************** */
/* Exceptions                                                                 */
/* ************************************************************************** */

Converter::badInput::badInput() {}
Converter::badInput::~badInput() throw() {}
char const* Converter::badInput::what() const throw() { return "bad input"; }

Converter::inputError::inputError() {}
Converter::inputError::~inputError() throw() {}
char const* Converter::inputError::what() const throw() {
  return "input error";
}

Converter::negativeNumber::negativeNumber() {}
Converter::negativeNumber::~negativeNumber() throw() {}
char const* Converter::negativeNumber::what() const throw() {
  return "not a positive number";
}

Converter::noBitcoinsYet::noBitcoinsYet() {}
Converter::noBitcoinsYet::~noBitcoinsYet() throw() {}
char const* Converter::noBitcoinsYet::what() const throw() {
  return "no bitcoins yet";
}

Converter::numberTooLarge::numberTooLarge() {}
Converter::numberTooLarge::~numberTooLarge() throw() {}
char const* Converter::numberTooLarge::what() const throw() {
  return "too large a number";
}

/* ************************************************************************** */
/* Private methods                                                            */
/* ************************************************************************** */

void Converter::checkTrailingCharacters(std::stringstream& linestream) {
  std::string trailingChars;
  linestream >> trailingChars;
  if (!linestream.fail() || !linestream.eof()) throw badInput();
  if (linestream.bad()) throw std::runtime_error("cannot read file");
}

void Converter::extractFromLine() {
  std::stringstream linestream(line_);
  extract<std::string>(linestream, date_);
  extract<std::string>(linestream, separator_);
  extract<float>(linestream, value_);
  checkTrailingCharacters(linestream);
}

void Converter::checkDate() {
  if (!tools::isValidDate(date_)) throw badInput();
}

void Converter::checkSeparator() {
  if (separator_ != constants::allowedSeparator) throw badInput();
}

void Converter::checkValue() {
  if (value_ < 0) throw negativeNumber();
  if (value_ > 999) throw numberTooLarge();
}

void Converter::parseLine() {
  extractFromLine();
  checkDate();
  checkSeparator();
  checkValue();
}

void Converter::lookupConversion() {
  std::map<std::string, float>::iterator firstGreater =
      database_->upper_bound(date_);
  std::map<std::string, float>::iterator beginDatabase = database_->begin();
  std::map<std::string, float>::iterator lookupDate;
  if (firstGreater == beginDatabase)
    throw noBitcoinsYet();
  else
    lookupDate = firstGreater--;
  exchangeRate_ = lookupDate->second;
}

void Converter::printResult() {
  std::cout << date_ << " => " << value_ << " = " << value_ * exchangeRate_
            << '\n';
}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

void Converter::convert() {
  std::ifstream ifs(inputFile_);
  if (!ifs) throw std::runtime_error("cannot open file");
  while (!ifs.eof()) {
    try {
      std::getline(ifs, line_);
      if (ifs.bad() | ifs.fail()) throw std::runtime_error("cannot read file");
      parseLine();
      lookupConversion();
      printResult();
    } catch (badInput& e) {
      std::cerr << "Error: " << e.what() << " => " << line_ << '\n';
    } catch (inputError& e) {
      std::cerr << e.what() << '\n';
    } catch (noBitcoinsYet& e) {
      std::cerr << "Error: " << e.what() << date_ << '\n';
    }
  }
}
