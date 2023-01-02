#include <iostream>

class Parent {
  protected:
    int varA;
    int varB;

  public:
    virtual int getVarA() const = 0;
    virtual int getVarB() const = 0;
};

class Child : public Parent {
  public:
    virtual int getVarA() const;
    virtual int getVarB() const;
};

int Child::getVarA() const {
  return varA;
}

int Child::getVarB() const {
  return varB;
}