/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Demo.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:45:14 by hoomen            #+#    #+#             */
/*   Updated: 2022/12/21 17:29:49 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEMO_HPP
#define DEMO_HPP

// #include <string>
// #include <iostream>
#include "Layout.hpp"


class Demo {
 //private:
  char testTableEntry;
  int testNr;

  void (Demo::*testTable[10])() const;

  void getInput();
  void printPrompt() const;
  void rePrompt() const;
  void setTestTableEntry();

  void testCopyAssignmentOperator() const;
  void testCopyConstructor() const;
  void testValidPromotion() const;
  void testInValidPromotion() const;
  void testValidDegradation() const;
  void testInvalidDegradation() const;
  void testMaximumPromotion() const;
  void testMaximumDegradation() const;
  void testPromoteOneGradeTooMany() const;
  void testDegradeOneGradeTooMany() const;

  Layout layout;

 //protected:

 public:
  /* default constructor */
  Demo();

  /* copy constructor */
  Demo(Demo const& src);

  /* copy assignment operator */
  Demo& operator=(Demo const& rhs);

  /* default destructor */
  ~Demo();

  /* getters */

  /* setters */

  /* public methods */
  void run();
};

/* insertion operator */
// std::ostream& operator<<(std::ostream& o, Demo const& cname);

#endif