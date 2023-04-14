/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2023/04/14 15:08:02 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <map>
#include <sstream>
#include <string>

class Converter {
 private:
  char const* inputFile_;
  std::map<std::string, float>* database_;
  std::string line_;
  std::string date_;
  std::string separator_;
  float value_;
  float exchangeRate_;

  /* default constructor */
  Converter();

  /* copy constructor */
  Converter(Converter const& src);

  /* copy assignment operator */
  Converter& operator=(Converter const& rhs);

  /* private methods */
  void parseLine();
  void extractFromLine();
  void checkDate();
  void checkSeparator();
  void checkValue();
  void checkTrailingCharacters(std::stringstream& linestream);
  void lookupConversion();
  void printResult();

  template <typename T>
  void extract(std::stringstream& linestream, T& type) {
    linestream >> type;
    if (linestream.fail()) throw badInput();
    if (linestream.bad()) throw std::runtime_error("unable to read file");
  }

 public:
  /* constructor */
  Converter(char const* inputFile);

  /* default destructor */
  ~Converter();

  /* exceptions */
  class badInput : std::exception {
   public:
    badInput();
    ~badInput() throw();
    virtual char const* what() const throw();
  };

  class inputError : std::exception {
   public:
    inputError();
    ~inputError() throw();
    virtual char const* what() const throw();
  };

  class negativeNumber : inputError {
   public:
    negativeNumber();
    ~negativeNumber() throw();
    virtual char const* what() const throw();
  };

  class numberTooLarge : inputError {
   public:
    numberTooLarge();
    ~numberTooLarge() throw();
    virtual char const* what() const throw();
  };

  class noBitcoinsYet : std::exception {
   public:
    noBitcoinsYet();
    ~noBitcoinsYet() throw();
    virtual char const* what() const throw();
  };

  /* public methods */
  void convert();
};

/* insertion operator */
// std::ostream& operator<<(std::ostream& o, Converter const& cname);

#endif