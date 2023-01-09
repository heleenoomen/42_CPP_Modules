/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:27:49 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/08 20:29:55 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Layout.hpp"

#include <iostream>
#include <iomanip>

/* ************************************************************************** */
/* Print utils                                                                */
/* ************************************************************************** */

static int const testHeaderWidth = 56;
static int const newLinesBeforeFirstTest = 1;

void printUnitTestHeader() {
  for (int i = 0; i < newLinesBeforeFirstTest; ++i)
    std::cout << '\n';
}

void printStars() {
  for (int i = 0; i < testHeaderWidth; ++i)
    std::cout << '*';
}

void printTestHeader(char const* testname) {
  std::cout << Layout::cyanBold;
  printStars();
  std::cout << "\n";
  std::cout << "* " << std::left << std::setw(testHeaderWidth - 3)
            << testname << "*\n";
  printStars();
  std::cout << "\n" << Layout::reset;
}

void printTestTrailer() {
  std::cout << Layout::cyanBold;
  printStars();
  std::cout << "\n\n\n" 
            << Layout::reset;
}

void printTestStep(std::string const& message) {
  std::cout << Layout::cyanItalic << message << ":\n" << Layout::reset;
}

/* ************************************************************************** */
/* Print utils                                                                */
/* ************************************************************************** */

void testAttackingBob() {
  printTestHeader("Test attacking Bob");
  printTestStep("Construct MateriaSource src");
  IMateriaSource* src = new MateriaSource();
  printTestStep("Let MateriaSource src learn materia \"Ice\"");
  src->learnMateria(new Ice());
  printTestStep("Let MateriaSource src lear materia \"Cure\"");
  src->learnMateria(new Cure());
  printTestStep("Construct Character \"me\"");
  ICharacter* me = new Character("me");
  AMateria* tmp;
  printTestStep("Create a Materia of type ice from src");
  tmp = src->createMateria("ice");
  printTestStep("Equip \"me\" with the newly created Materia of type ice");
  me->equip(tmp);
  printTestStep("Create a Materia of type cure from src");
  tmp = src->createMateria("cure");
  printTestStep("Equip \"me\" with the newly created Materia of type cure");
  me->equip(tmp);
  printTestStep("Construct Character \"bob\"");
  ICharacter* bob = new Character("bob");
  printTestStep("Let \"me\" use the first Materia in my inventory with target bob");
  me->use(0, *bob);
  printTestStep("Let \"me\" use the first Materia in my inventory with target bob");
  me->use(1, *bob);
  printTestStep("Delete Character bob");
  delete bob;
  printTestStep("Delete Character me");
  delete me;
  printTestStep("Delete MateriaSource src");
  delete src;
  printTestTrailer();
}

void deepCopies() {
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  ICharacter *me = new Character("me");
  AMateria* tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  delete me;
  delete src;
}

int main()
{
  testAttackingBob();
  deepCopies();
  std::cout << std::endl;
  system("leaks materia");
  return 0;
}