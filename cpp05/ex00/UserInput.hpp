/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserInput.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/21 17:35:10 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USERINPUT_HPP
#define USERINPUT_HPP

// #include <string>
// #include <iostream>

class UserInput {
 private:
  int value;
  bool quit;
  char quitSymbol;
  bool valid;
  int min;
  int max;


 //protected:

 public:
  /* default constructor */
  UserInput();
  UserInput(int min, int max, char quitSymbol);

  /* copy constructor */
  UserInput(UserInput const& src);

  /* copy assignment operator */
  UserInput& operator=(UserInput const& rhs);

  /* default destructor */
  ~UserInput();

  /* getters */
  int getValue() const;
  bool quitIsSet() const;
  bool IsValid() const;

  /* public methods */
  void getIntValue();

  /* setters */
};

/* insertion operator */
// std::ostream& operator<<(std::ostream& o, UserInput const& cname);

#endif