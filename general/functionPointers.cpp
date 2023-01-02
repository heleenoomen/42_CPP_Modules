#include <iostream>
void printA() {
  std::cout << "A\n";
}

void printB() {
  std::cout << "B\n";
}

void printC() {
  std::cout << "C\n";
}

class MyClass;


class MyClass {
 public:

  MyClass();
  void (*f)();

  typedef struct lookup{
    void (MyClass::*f)() const;
  } lookup;
  
  lookup table[2];
  lookup* dynamic_table;
  void aFunction() const;
  void anotherFunction() const;

  void runFunctions() const;
};

MyClass::MyClass() {
  table[0].f = &MyClass::aFunction;
  table[1].f = &MyClass::anotherFunction;

  dynamic_table = new lookup[2];
  dynamic_table[0].f = &MyClass::aFunction;
  dynamic_table[1].f = &MyClass::anotherFunction;

}

void MyClass::aFunction() const {
  std::cout << "A member function called\n";
}

void MyClass::anotherFunction() const {
  std::cout << "Another member function called\n";
}

void MyClass::runFunctions() const {
  (this->*table[0].f)();
	(this->*table[1].f)();
  (this->*dynamic_table[0].f)();
  (this->*dynamic_table[1].f)();
}

int main() {
  MyClass myclass;

  myclass.runFunctions();
}
