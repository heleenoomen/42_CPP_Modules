/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:01:09 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/09 18:18:13 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Layout.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/* ************************************************************************** */
/* Print utils                                                                */
/* ************************************************************************** */

static int const testHeaderWidth = 56;

void printStars() {
  for (int i = 0; i < testHeaderWidth; ++i) std::cout << '*';
}

void printTestHeader(char const* testname) {
  std::cout << Layout::brightYellow;
  printStars();
  std::cout << "\n";
  std::cout << "* " << std::left << std::setw(testHeaderWidth - 3) << testname
            << "*\n";
  printStars();
  std::cout << "\n" << Layout::reset;
}

void printTestTrailer() { std::cout << "\n"; }

void printTestStep(std::string const& message) {
  std::cout << Layout::cyanItalic << message << ":\n" << Layout::reset;
}

void printTestStepName(std::string const& message, std::string const& name) {
  std::cout << Layout::cyanItalic << message << " " << name << ":\n"
            << Layout::reset;
}

/* ************************************************************************** */
/* Test utils animal                                                          */
/* ************************************************************************** */

/* Delete Animal */
void testDeleteAnimal(AAnimal& a, char const* varName) {
  printTestStepName("Delete", varName);
  delete &a;
}

/* Print Animal */
void testPrintAnimal(AAnimal& a, char const* varName) {
  printTestStepName("Print", varName);
  std::cout << a;
}

/* ************************************************************************** */
/* Test utils cat                                                             */
/* ************************************************************************** */

/* Default Constructor Cat */
Cat* testDefaultConstructorCat(char const* varName) {
  printTestStepName("Default constructor for", varName);
  return new Cat;
}

/* Copy Constructor Cat */
Cat* testCopyConstructorCat(Cat& src, char const* varName, char const* varNameSrc) {
  std::cout << Layout::cyanItalic << "Copy constructor for " << varName
            << ", copying " << varNameSrc << '\n' << Layout::reset;
  return new Cat(src);
}

/* Copy Assignment Cat */
void testCopyAssignmentCat(Cat& c, Cat& src, char const* varName,
                           char const* varNameSrc) {
  std::cout << Layout::cyanItalic << "Copy assignment: " << varName << " = "
            << varNameSrc << "\n"
            << Layout::reset;
  c = src;
}
/* Cat Brain */
void setIdeasCat(Cat& cat) {
  printTestStep("cat1 is getting some ideas...");
  cat.setIdea(0, "Meeeow, I am a beautiful cat");
  cat.setIdea(1, "Meeeow, gotta sleep");
  cat.setIdea(
      2, "Seems like my hoooooman left the kitchen, gotta steal cheese now");
  cat.setIdea(3, "Caught a mouse for my hooman");
  cat.setIdea(4,
              "Let's be honest: hooooomans are pretty stupid, but you got "
              "to love them");
  cat.setIdea(5, "More food please!");
}

/* Print Ideas Cat*/
void testCatPrintIdeas(Cat& c, char const* varName) {
  printTestStepName("Print ideas of", varName);
  c.printIdeas();
}

/* Print Ideas Cat after Deletion of Source */
void testCatPrintIdeasAfterDeletionSrc(Cat& c, char const* varName,
                                       char const* varNameSrc) {
  std::cout << Layout::cyanItalic << "Print ideas " << varName
            << " after deletion of " << varNameSrc << "\n"
            << Layout::reset;
  c.printIdeas();
}

/* ************************************************************************** */
/* Test utils dog                                                             */
/* ************************************************************************** */
/* Default Constructor Dog */
Dog* testDefaultConstructorDog(char const* varName) {
  printTestStepName("Default constructor for", varName);
  return new Dog;
}

/* Copy Constructor Dog */
Dog* testCopyConstructorDog(Dog& src, char const* varName, char const* varNameSrc) {
  std::cout << Layout::cyanItalic << "Copy constructor for " << varName
            << ", copying " << varNameSrc << '\n' << Layout::reset;
  return new Dog(src);
}

/* Copy Assignment Dog */
void testCopyAssignmentDog(Dog& d, Dog& src, char const* varName,
                           char const* varNameSrc) {
  std::cout << Layout::cyanItalic << "Copy assignment: " << varName << " = "
            << varNameSrc << "\n"
            << Layout::reset;
  d = src;
}
/* Dog Brain */
void setIdeasDog(Dog& d) {
  printTestStep("Plant ideas in the brain of dog1");
  d.setIdea(0, "I would really like a walk in the park");
  d.setIdea(1, "Gotta sniff this");
  d.setIdea(2, "Gotta catch that dove!");
  d.setIdea(3, "I love my owner");
  d.setIdea(4, "They trew a stick! This is great, run!");
}

/* Print Ideas Dog*/
void testDogPrintIdeas(Dog& d, char const* varName) {
  printTestStepName("Print ideas of", varName);
  d.printIdeas();
}

/* Print Ideas Dog after Deletion of Source */
void testDogPrintIdeasAfterDeletionSrc(Dog& d, char const* varName,
                                       char const* varNameSrc) {
  std::cout << Layout::cyanItalic << "Print ideas " << varName
            << " after deletion of " << varNameSrc << "\n"
            << Layout::reset;
  d.printIdeas();
}

/* ************************************************************************** */
/* Tests                                                                      */
/* ************************************************************************** */

void testAnimalInheritance() {
  printTestStep("AAnimal* j = new Dog()");
  const AAnimal* j = new Dog();
  printTestStep("AAnimal* i = new Cat()");
  const AAnimal* i = new Cat();

  printTestStep("j->getType()");
  std::cout << j->getType() << " \n";
  printTestStep("i->getType()");
  std::cout << i->getType() << " \n";
  printTestStep("i->makeSound()");
  i->makeSound();
  printTestStep("j->makeSound()");
  j->makeSound();

  printTestStep("Delete Dog and Cat");
  delete j;
  delete i;
}

void testAnimalInheritanceWrongClasses() {
  const WrongAnimal* wrongMeta = new WrongAnimal();
  const WrongAnimal* wrongCat = new WrongCat();

  std::cout << wrongCat->getType() << " " << std::endl;
  wrongCat->makeSound();
  wrongMeta->makeSound();

  delete wrongMeta;
  delete wrongCat;
}

void testCopying() {
  printTestStep("Default constructor for dog1");
  Dog dog1;
  printTestStep("Print dog1");
  std::cout << dog1;
  printTestStep("Copy constructor for dog2, copy from dog1");
  Dog dog2(dog1);
  printTestStep("Print dog2");
  std::cout << dog2;
  printTestStep("Destructors");
}

void testDeletionCatDogViaPointerToAnimal() {
  printTestStep(
      "Construct an array of 6 animals: const AAnimal* animalArray[6]");
  const AAnimal* animalArray[6];
  printTestStep("Fill array with half Dogs, half Cats");
  for (int i = 0; i < 2; ++i) animalArray[i] = new Dog;
  for (int i = 2; i < 4; ++i) animalArray[i] = new Cat;
  printTestStep("Print animals in array");
  for (int i = 0; i < 4; ++i) {
    std::cout << *animalArray[i];
  }
  printTestStep("Destroy Cat and Dog objects in array");
  for (int i = 0; i < 4; ++i) {
    delete animalArray[i];
  }
}

void testDeepCopiesDog() {
  Dog* dog1 = testDefaultConstructorDog("dog1");
  testPrintAnimal(*dog1, "dog1");
  setIdeasDog(*dog1);
  testDogPrintIdeas(*dog1, "dog1");
  Dog* dog2 = testDefaultConstructorDog("dog2");
  testCopyAssignmentDog(*dog2, *dog1, "dog2", "dog1");
  testPrintAnimal(*dog2, "dog2");
  testDeleteAnimal(*dog1, "dog1");
  testDogPrintIdeasAfterDeletionSrc(*dog2, "dog2", "dog1");
  Dog* dog3 = testCopyConstructorDog(*dog2, "dog3", "dog2");
  testDeleteAnimal(*dog2, "dog2");
  testDogPrintIdeasAfterDeletionSrc(*dog3, "dog3", "dog2");
  testDeleteAnimal(*dog3, "dog3");
}

void testDeepCopiesCat() {
  Cat* cat1 = testDefaultConstructorCat("cat1");
  testPrintAnimal(*cat1, "cat1");
  setIdeasCat(*cat1);
  testCatPrintIdeas(*cat1, "cat1");
  Cat* cat2 = testDefaultConstructorCat("cat2");
  testCopyAssignmentCat(*cat2, *cat1, "cat2", "cat1");
  testPrintAnimal(*cat2, "cat2");
  testDeleteAnimal(*cat1, "cat1");
  testCatPrintIdeasAfterDeletionSrc(*cat2, "cat2", "cat1");
  Cat* cat3 = testCopyConstructorCat(*cat2, "cat3", "cat2");
  testDeleteAnimal(*cat2, "cat2");
  testCatPrintIdeasAfterDeletionSrc(*cat3, "cat3", "cat2");
  testDeleteAnimal(*cat3, "cat3");
}

void checkLeaks() {
  std::cout.flush();
  system("leaks animals");
}

typedef void (*test)();

void testUnit(test t, char const* testHeader) {
  printTestHeader(testHeader);
  t();
  printTestTrailer();
}

int main() {
  testUnit(&testAnimalInheritance,
           "Test AAnimal Class Inheritance (Correct Classes)");
  testUnit(&testAnimalInheritanceWrongClasses,
           "Test Wrong Animal Class Inheritance");
  testUnit(&testCopying, "Test Copying");
  testUnit(&testDeletionCatDogViaPointerToAnimal,
           "Test Deletion Cat/Dog Via Pointer To Animal");
  testUnit(&testDeepCopiesDog, "Test Deep Copies Dog Class");
  testUnit(&testDeepCopiesCat, "Test Deep Copies Cat Class");
  testUnit(&checkLeaks, "Check leaks");
}
