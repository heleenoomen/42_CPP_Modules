
#include "Base.hpp"

#include <cstdlib>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

/* Destructor */
Base::~Base() {}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

Base* Base::generateA() { return new A; }

Base* Base::generateB() { return new B; }

Base* Base::generateC() { return new C; }

Base* Base::generate() {
  Base* (Base::*generateDerived[3])() = {&Base::generateA, &Base::generateB,
                                         &Base::generateC};
  return (this->*generateDerived[rand() % 3])();
}

void Base::identify(Base& p) {
  try {
    (void)dynamic_cast<A&>(p);
    std::cout << "Type is A\n";
    return;
  } catch (std::bad_cast& c) {
  };
  try {
    (void)dynamic_cast<B&>(p);
    std::cout << "Type is B\n";
    return;
  } catch (std::bad_cast& c) {
  }
  try {
    (void)dynamic_cast<C&>(p);
    std::cout << "Type is C\n";
  } catch (std::bad_cast& c) {
  }
}

void Base::identify(Base* p) {
  try {
    if (dynamic_cast<A*>(p) != NULL)
      std::cout << "Type is A\n";
    else if (dynamic_cast<B*>(p) != NULL)
      std::cout << "Type is B\n";
    else if (dynamic_cast<C*>(p) != NULL)
      std::cout << "Type is C\n";
  } catch (std::bad_cast& c) {
    std::cout << c.what() << '\n';
  }
}
