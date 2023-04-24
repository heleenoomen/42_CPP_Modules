/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                        :+:      :+:
 * :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/10 22:01:08 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <utility>

class BitcoinExchange {
 private:
  const char* inputFile_;
  const char* dbFile_;
  std::map<std::string, float> database_;

  /* default constructor */
  BitcoinExchange();

  /* copy constructor */
  BitcoinExchange(BitcoinExchange const& src);

  /* copy assignment operator */
  BitcoinExchange& operator=(BitcoinExchange const& rhs);

 public:
  /* constructors */
  BitcoinExchange(const char* inputFile);

  /* destructor */
  ~BitcoinExchange();

  /* public methods */
  void run();
};

#endif