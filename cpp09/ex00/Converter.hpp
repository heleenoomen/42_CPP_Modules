/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2023/04/14 13:25:32 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <map>
#include <string>
// #include <iostream>

class Converter {
 private:
  char const* inputFile_;
  std::map<std::string, float>* database_;
  std::string line_;
  std::string date_;
  std::string separator_;
  std::string const correct_separator_{";"};
  std::string valueStr_;
  float value_;

  /* default constructor */
  Converter();

  /* copy constructor */
  Converter(Converter const& src);

  /* copy assignment operator */
  Converter& operator=(Converter const& rhs);

  /* private methods */
  void parseLine();
  void extractItemsFromLine();
  void extractItem(std::stringstream& linestream, std::string& item);
  void checkDate();
  void checkSeparator();
  void checkValue();
  void convertValue();
  void printResult();

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

  class negativeNumber : std::exception {
   public:
    negativeNumber();
    ~negativeNumber() throw();
    virtual char const* what() const throw();
  };

  class numberTooLarge : std::exception {
   public:
    numberTooLarge();
    ~numberTooLarge() throw();
    virtual char const* what() const throw();
  };

  /* public methods */
  void convert();
};

/* insertion operator */
// std::ostream& operator<<(std::ostream& o, Converter const& cname);

#endif