/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DatabaseParser.hpp                                        :+:      :+:
 * :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/10 22:01:08 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATABASEPARSER_HPP
#define DATABASEPARSER_HPP

#include <fstream>
#include <map>
#include <string>
#include <utility>

class DatabaseParser {
 private:
  std::map<std::string, float>* database_;
  char const* databasePath_ = "cpp_09/data.csv";
  std::ifstream ifs{databasePath_};

  /* default constructor */
  DatabaseParser();

  /* private methods*/
  void skipFirstLine(std::ifstream& ifs) const;
  void parseLine(std::string& line, std::pair<std::string, float>& pair) const;
  void parseData(std::ifstream& ifs);
  size_t findCommaPosition(std::string& line) const;
  std::string extractDate(std::string& line, size_t commaPosition) const;
  float extractExchangeRate(std::string& line, size_t commaPosition) const;
  void checkDate(std::string& date);
  void checkValue(float value);

 public:
  /* constructor */
  DatabaseParser(std::map<std::string, float>* db);

  /* copy constructor */
  DatabaseParser(DatabaseParser const& src);

  /* copy assignment operator */
  DatabaseParser& operator=(DatabaseParser const& rhs);

  /* default destructor */
  ~DatabaseParser();

  /* public methods */
  void parse();

  /* exceptions */
  class invalidLine : std::exception {
   public:
    invalidLine();
    ~invalidLine() throw();
    virtual const char* what() const throw();
  };
};

#endif