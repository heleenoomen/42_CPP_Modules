
#include "DatabaseParser.hpp"

#include <iostream>
#include <sstream>

#include "tools.hpp"

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
DatabaseParser::DatabaseParser() : database_(NULL), databasePath_(NULL) {}

/* Constructor */
DatabaseParser::DatabaseParser(std::map<std::string, float>* db,
                               char const* dbPath)
    : database_(db), databasePath_(dbPath) {}

/* Copy constructor */
DatabaseParser::DatabaseParser(DatabaseParser const& src) { *this = src; }

/* Copy assignment operator */
DatabaseParser& DatabaseParser::operator=(DatabaseParser const& rhs) {
  if (this == &rhs) return *this;
  database_ = rhs.database_;
  databasePath_ = rhs.databasePath_;
  return *this;
}

/* Destructor */
DatabaseParser::~DatabaseParser() {}

/* ************************************************************************** */
/* Exceptions                                                                 */
/* ************************************************************************** */

DatabaseParser::invalidLine::invalidLine() {}

DatabaseParser::invalidLine::~invalidLine() throw() {}

const char* DatabaseParser::invalidLine::what() const throw() {
  return "Warning: Database contains invalid lines!\n";
}

/* ************************************************************************** */
/* Private methods                                                            */
/* ************************************************************************** */

void DatabaseParser::skipFirstLine(std::ifstream& ifs) const {
  std::string firstLine;
  ifs >> firstLine;
  if (ifs.bad()) throw std::runtime_error("Unable to read from database");
}

size_t DatabaseParser::findCommaPosition(std::string& line) const {
  size_t commaPosition = line.find(',');
  if (commaPosition == std::string::npos) throw invalidLine();
  return commaPosition;
}

std::string DatabaseParser::extractDate(std::string& line,
                                        size_t commaPosition) const {
  std::string date = line.substr(0, commaPosition);
  if (!tools::isValidDate(date)) throw invalidLine();
  return date;
}

float DatabaseParser::extractExchangeRate(std::string& line,
                                          size_t commaPosition) const {
  std::stringstream exchangeRateSs(line.substr(commaPosition + 1));
  try {
    float exchangeRate = tools::stringToFloat(line);
    if (exchangeRate < 0) throw invalidLine();
    return exchangeRate;
  } catch (tools::invalidFloat& e) {
    throw invalidLine();
  } catch (tools::badStringStream& e) {
    throw std::runtime_error("Unable to read from database");
  }
}

void DatabaseParser::parseLine(std::string& line,
                               std::pair<std::string, float>& pair) const {
  size_t commaPosition = findCommaPosition(line);
  pair.first = extractDate(line, commaPosition);
  pair.second = extractExchangeRate(line, commaPosition);
}

void DatabaseParser::parseData(std::ifstream& ifs) {
  std::pair<std::string, float> pair;
  for (std::string line; ifs >> line;) {
    try {
      parseLine(line, pair);
    } catch (DatabaseParser::invalidLine& e) {  // ignore invalid lines
      continue;
    }
    database_->insert(pair);
  }
  if (ifs.bad()) throw std::runtime_error("Unable to read from database");
}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

void DatabaseParser::parse() {
  std::ifstream ifs(databasePath_);
  if (!ifs) throw std::runtime_error("Unable to open database");
  skipFirstLine(ifs);
  parseData(ifs);
}
