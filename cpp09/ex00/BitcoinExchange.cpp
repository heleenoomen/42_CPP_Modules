#include "BitcoinExchange.hpp"

#include <ctime>
#include <fstream>
#include <sstream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(char* inputFile) : inputFile_(inputFile) {
  loadDatabase();
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isValidDate(std::string& date) {
  struct tm time;
  const char* format = "%Y-%m-%d";
  char* ptr;
  char* endOfdate = strptime(date.c_str(), format, &time);
  if (endOfdate == NULL || *endOfdate) return false;
  return true;
}

void BitcoinExchange::dbCheckDate(std::string& date) {
  if (!isValidDate(date)) throw std::runtime_error("Database corrupted");
}

void BitcoinExchange::dbCheckValue(float value) {
  if (value < 0) throw std::runtime_error("Database corrupted");
}

void BitcoinExchange::dbParseLine(std::string& line,
                                  std::pair<std::string, float>& pair) {
  size_t commaPosition = line.find(',');
  if (commaPosition == std::string::npos)
    throw std::runtime_error("Database corrupted");
  pair.first = line.substr(0, commaPosition);
  std::stringstream value(line.substr(commaPosition + 1));
  value >> pair.second;
  if (!value) throw std::runtime_error("Database corrupted");
  dbCheckDate(pair.first);
  dbCheckValue(pair.second);
}

void BitcoinExchange::loadDatabase() {
  std::ifstream ist(dbFile_);
  if (!ist) throw std::runtime_error("Unable to open database");
  std::pair<std::string, float> pair;
  for (std::string line; ist >> line;) {
    dbParseLine(line, pair);
    if ((database_.insert(pair)).second == false)
      throw std::runtime_error("Database corrupted");
  }
}
