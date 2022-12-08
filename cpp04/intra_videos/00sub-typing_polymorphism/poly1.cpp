#include <string>
#include <iostream>

class Character {
 public:
  virtual void sayHello(std::string const& target);
};

class Warrior : public Character {
 public:
  void sayHello(std::string const& target); // function overwriting
};

class Cat {
  //[...]
};

void Character::sayHello(std::string const& target) {
  std::cout<<"Hello "<< target << "!" << std::endl;
}

void Warrior::sayHello(std::string const& target) {
  std::cout<<"F*** off "<<target<<", I don't like you!"<<std::endl;
}

int main() {
  Warrior* a = new Warrior();
  Character* b = new Warrior();
  /* Warrior* c = new Character(); this will not compile */
  /* Character* d = new Cat(); this will not compile */
  a->sayHello("students");
  b->sayHello("students");
  delete a;
  delete b;
}

/* VIRTUAL MEMBER FUNCTION == METHOD */
// a virtual member function is called a method: a member function
// which resolution will be dynamic, i.e. will happen during
// execution.