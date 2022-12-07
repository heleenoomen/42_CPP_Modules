#include <string>
#include <iostream>

class ACharacter {
 public:
  virtual void attack(std::string const& target) = 0; // this makes it a pure function
  void sayHello(std::string const& target);
};
/* the =0 means that there is literally no definition for this method,
   there is no implementation in any way. As a consequence, we cannot
   instantiate this class. Therefore, this class is abstract.
   Prefix A is used to indicate that we are dealing with a pure abstract
   class.
   It means that when a class inherits ACharacter, it should implement
   this behaviour. It is saying that all child classes should have the
   attack behaviour.
*/

class Warrior : public ACharacter {
 private:
  std::string _name;
 public:
  virtual void attack(std::string const& target);
};

void ACharacter::sayHello(std::string const& target) {
  std::cout<<"Hello "<<target<<"!"<<std::endl;
}

void Warrior::attack(std::string const& target) {
  std::cout<<"*attacks "<<target<<" with a sword*"<<std::endl;
}

class ICoffee {};
class IWaterSource {};

class ICoffeeMaker {
 public:
  virtual void fillWaterTank(IWaterSource* src) = 0;
  virtual ICoffee* makeCoffee(std::string const& type) = 0;
};
// The above class is an INTERFACE since it has only pure functions (only abstract behaviours)
// Interface classes prefix with I
// Interfaces cannot have attributes
// Interfaces define what behaviours derived classes should have
// It is a way of telling developers what behaviours the concrete classes should always be there
// Useful when you work with other people.
// Other uses, for instance: manipulate an array of objects, even if they
// do not have the same type.

int main() {
 ACharacter* a = new Warrior();

 //ACharacter* b = new ACharacter(); // not possible, since ACharacter is abstract

 a->sayHello("students");
 a->attack("roger");
}
