/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:27:49 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/27 16:59:09 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "layout.hpp"
#include "MateriaSource.hpp"

/* ************************************************************************** */
/* Print utils                                                                */
/* ************************************************************************** */

static int const testHeaderWidth = 56;
static int const newLinesBeforeFirstTest = 1;

void printUnitTestHeader() {
  for (int i = 0; i < newLinesBeforeFirstTest; ++i) std::cout << '\n';
}

void printStars() {
  for (int i = 0; i < testHeaderWidth; ++i) std::cout << '*';
}

void printTestHeader(char const* testname) {
  std::cout << layout::brightYellow;
  printStars();
  std::cout << "\n";
  std::cout << "* " << std::left << std::setw(testHeaderWidth - 3) << testname
            << "*\n";
  printStars();
  std::cout << "\n" << layout::reset;
}

void printTestTrailer() { std::cout << "\n"; }

void printTestStep(std::string const& message) {
  std::cout << layout::cyanItalic << message << ":\n" << layout::reset;
}

void printTestStepName(std::string const& message, std::string const& name) {
  std::cout << layout::cyanItalic << message << " \"" << name << "\":\n"
            << layout::reset;
}

/* ************************************************************************** */
/* Create MateriaSource                                                       */
/* ************************************************************************** */

MateriaSource* testCreateMateriaSource(std::string const& name) {
  printTestStepName("Construct MateriaSource", name);
  return new MateriaSource(name);
}

/* ************************************************************************** */
/* Learn materia's                                                            */
/* ************************************************************************** */
void testMateriaLearnIce(MateriaSource& src) {
  printTestStep("Let MateriaSource src learn materia \"Ice\"");
  src.learnMateria(new Ice());
  printTestStep("Print MateriaSource");
  std::cout << src;
}

void testMateriaLearnCure(MateriaSource& src) {
  printTestStep("Let MateriaSource src learn materia \"Cure\"");
  src.learnMateria(new Cure());
  printTestStep("Print MateriaSource");
  std::cout << src;
}

/* ************************************************************************** */
/* Create Character                                                           */
/* ************************************************************************** */
Character* testCreateCharacter(std::string const& name) {
  printTestStepName("Create Character", name);
  return new Character(name);
}

/* ************************************************************************** */
/* Create Materia                                                             */
/* ************************************************************************** */
void printTestCreateMateriaFromSource(MateriaSource const& src,
                                      std::string const& materiaType) {
  std::cout << layout::cyanItalic << "Create Materia of type " << materiaType
            << " from " << src.getName() << ":\n"
            << layout::reset;
}

AMateria* testCreateMateriaFromSource(MateriaSource const& src,
                                      std::string const& type) {
  printTestCreateMateriaFromSource(src, type);
  return src.createMateria(type);
}

/* ************************************************************************** */
/* Equip Character                                                            */
/* ************************************************************************** */
void printTestEquipCharacter(Character& c, AMateria& m) {
  std::cout << layout::cyanItalic << "Equip character " << c.getName()
            << " with " << m.getType() << ":\n"
            << layout::reset;
}

void testEquipCharacter(Character& c, AMateria& m) {
  printTestEquipCharacter(c, m);
  c.equip(&m);
}

/* ************************************************************************** */
/* use Materia                                                                */
/* ************************************************************************** */
void printTestUseMateria(Character& actor, Character& target, int materiaNbr) {
  std::cout << layout::cyanItalic << "Let " << actor.getName()
            << " try to attack " << target.getName() << " with Materia nr "
            << materiaNbr << " in inventory:\n"
            << layout::reset;
}

void testUseMateria(Character& actor, Character& target, int materiaNbr) {
  printTestUseMateria(actor, target, materiaNbr);
  actor.use(materiaNbr, target);
}

/* ************************************************************************** */
/* Test deletion                                                              */
/* ************************************************************************** */
void testDeleteCharacter(Character const& character) {
  printTestStepName("Delete Character", character.getName());
  delete &character;
}

void testDeleteMateriaSource(MateriaSource const& src) {
  printTestStepName("Delete MateriaSource", src.getName());
  delete &src;
}

/* ************************************************************************** */
/* Test printing inventory of Character                                       */
/* ************************************************************************** */
void testCharacterPrintInventory(Character const& c) {
  printTestStepName("Print inventory of Character", c.getName());
  c.printInventory();
}

/* ************************************************************************** */
/* Check for leaks                                                            */
/* ************************************************************************** */
void testLeaks() {
  printTestStep("Check leaks");
  std::cout.flush();
  system("leaks materia");
}

/* ************************************************************************** */
/* Tests                                                                      */
/* ************************************************************************** */

void testEquipping(Character& c, AMateria& ice, AMateria& cure) {
  printTestHeader("Test equipping character");
  testCharacterPrintInventory(c);
  testEquipCharacter(c, ice);
  testEquipCharacter(c, cure);
  testCharacterPrintInventory(c);
  printTestTrailer();
}

void testEquippingFirstFreeSlot(Character& c, AMateria& newMateria) {
  printTestHeader("Test equipping character in first free slot");
  testCharacterPrintInventory(c);
  testEquipCharacter(c, newMateria);
  testCharacterPrintInventory(c);
  printTestTrailer();
}

void testUsingMaterias(Character& actor, Character& target) {
  printTestHeader("Test using materias in inventory");
  testUseMateria(actor, target, 0);
  testUseMateria(actor, target, 1);
  printTestTrailer();
}

void testUsingMateriasOutOfRange(Character& actor, Character& target) {
  printTestHeader("Test using materias out of range");
  testCharacterPrintInventory(actor);
  testUseMateria(actor, target, -1);
  testUseMateria(actor, target, 25);
  testUseMateria(actor, target, 4);
  testUseMateria(actor, target, 3);
  printTestTrailer();
}

void deleteClasses(Character& me, Character& bob, MateriaSource& src) {
  printTestHeader("Delete class instances");
  testDeleteCharacter(me);
  testDeleteCharacter(bob);
  testDeleteMateriaSource(src);
  printTestTrailer();
}

void testOverequipping(Character& me) {
  printTestHeader("Test adding too many materia's to inventory");
  printTestStep("First, fully fill the inventory");
  testEquipCharacter(me, *(new Ice));
  testEquipCharacter(me, *(new Ice));
  testCharacterPrintInventory(me);
  printTestStep("Create one more materia");
  Cure* cure = new Cure;
  testEquipCharacter(me, *cure);
  testCharacterPrintInventory(me);
  printTestStep(
      "Destroy the new materia that could not be added to the "
      "inventory");
  delete cure;
}

void testUnequipping(Character& c) {
  printTestHeader("Test unequipping");
  std::cout << layout::cyanItalic << c.getName() << " leaves materia " << 1
            << " on the floor:\n"
            << layout::reset;
  c.unequip(1);
  c.printInventory();
}

void testDeepCopyMateriaSource() {
  printTestHeader("Test deep copy MateriaSource");
  MateriaSource* src1 = testCreateMateriaSource("src1");
  printTestStep("Let MateriaSource src1 learn two materias of type \"ice\"");
  src1->learnMateria(new Ice);
  src1->learnMateria(new Ice);
  printTestStep("Print MateriaSource src1");
  std::cout << *src1;
  MateriaSource* copy = testCreateMateriaSource("copy");
  printTestStep("assign src1 to copy");
  *copy = *src1;
  testDeleteMateriaSource(*src1);
  printTestStep("Print MateriaSource copy after src1 has been deleted");
  std::cout << *copy;
  testDeleteMateriaSource(*copy);
  printTestTrailer();
}

void testDeepCopyCharacter() {
  printTestHeader("Test Deep Copy Character");
  Character* louis = testCreateCharacter("louis");
  printTestStep("Equip louis with two materia's of type cure");
  louis->equip(new Cure);
  louis->equip(new Cure);
  printTestStep("Print Character louis");
  std::cout << *louis;
  Character* copy = testCreateCharacter("copy");
  printTestStep("Assign louis to copy");
  *copy = *louis;
  testDeleteCharacter(*louis);
  printTestStep("Print Character copy after louis has been deleted");
  std::cout << *copy;
  testDeleteCharacter(*copy);
}

int main() {
  printTestHeader("Instantiate Classes & learn Materias");
  MateriaSource* src = testCreateMateriaSource("src");
  testMateriaLearnCure(*src);
  testMateriaLearnIce(*src);
  Character* me = testCreateCharacter("me");
  Character* bob = testCreateCharacter("bob");
  AMateria* ice = testCreateMateriaFromSource(*src, "ice");
  AMateria* cure = testCreateMateriaFromSource(*src, "cure");
  printTestTrailer();
  testEquipping(*me, *ice, *cure);
  testUsingMaterias(*me, *bob);
  testUsingMateriasOutOfRange(*me, *bob);
  testOverequipping(*me);
  testUnequipping(*me);
  printTestStep("Delete materia left on the ground by Character");
  delete cure;
  testDeepCopyMateriaSource();
  testDeepCopyCharacter();
  testEquippingFirstFreeSlot(*me, *(new Cure));
  deleteClasses(*me, *bob, *src);
  testLeaks();
  return 0;
}
