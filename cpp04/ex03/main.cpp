/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:27:49 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/09 18:04:38 by hoomen           ###   ########.fr       */
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
#include "Layout.hpp"
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
  std::cout << Layout::cyanItalic << message << " \"" << name << "\":\n"
            << Layout::reset;
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
}

void testMateriaLearnCure(MateriaSource& src) {
  printTestStep("Let MateriaSource src learn materia \"Cure\"");
  src.learnMateria(new Cure());
}

/* ************************************************************************** */
/* Create Character                                                           */
/* ************************************************************************** */
Character* testCreateCharacter(std::string const& name) {
  printTestStepName("Construct Character ", name);
  return new Character(name);
}

/* ************************************************************************** */
/* Create Materia                                                             */
/* ************************************************************************** */
void printTestCreateMateriaFromSource(MateriaSource const& src,
                                      std::string const& materiaType) {
  std::cout << Layout::cyanItalic << "Create Materia of type " << materiaType
            << " from " << src.getName() << ":\n"
            << Layout::reset;
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
  std::cout << Layout::cyanItalic << "Equip character " << c.getName()
            << " with " << m.getType() << ":\n"
            << Layout::reset;
}

void testEquipCharacter(Character& c, AMateria& m) {
  printTestEquipCharacter(c, m);
  c.equip(&m);
}

/* ************************************************************************** */
/* use Materia                                                                */
/* ************************************************************************** */
void printTestUseMateria(Character& actor, Character& target, int materiaNbr) {
  std::cout << Layout::cyanItalic << "Let " << actor.getName()
            << " try to attack " << target.getName() << " with Materia nr "
            << materiaNbr << " in inventory:\n"
            << Layout::reset;
}

void testUseMateria(Character& actor, Character& target, int materiaNbr) {
  printTestUseMateria(actor, target, materiaNbr);
  actor.use(materiaNbr, target);
}

/* ************************************************************************** */
/* Test deletion                                                              */
/* ************************************************************************** */
void testDeleteCharacter(Character const& character) {
  printTestStepName("Delete Character ", character.getName());
  delete &character;
}

void testDeleteMateriaSource(MateriaSource const& src) {
  printTestStepName("Delete MateriaSource ", src.getName());
  delete &src;
}

/* ************************************************************************** */
/* Test printing inventory of Character                                       */
/* ************************************************************************** */
void testCharacterPrintInventory(Character const& c) {
  printTestStepName("Print inventory of Character ", c.getName());
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
  std::cout << Layout::cyanItalic << c.getName() << " leaves materia " << 1
            << " on the floor:\n"
            << Layout::reset;
  c.unequip(1);
  c.printInventory();
}

void testDeepCopyMateriaSource(MateriaSource& src) {
  printTestHeader("Test deep copy MateriaSource");
  MateriaSource* copy = testCreateMateriaSource("copy");
  printTestStep("Print MateriaSource \"copy\"");
  std::cout << *copy;
  printTestStep("Assign src to copy");
  *copy = src;
  printTestStep("Print MateriaSource \"src\"");
  std::cout << src;
  printTestStep("Print MateriaSource after assigning \"copy\"");
  std::cout << *copy;
  testDeleteMateriaSource(*copy);
  printTestTrailer();
}

void testDeepCopyCharacter(Character& src) {
  printTestHeader("Test deep copy Character");
  Character* copy = testCreateCharacter("copy");
  printTestStep("Print character \"copy\"");
  std::cout << *copy;
  printTestStep("Assign \"me\" to copy");
  *copy = src;
  printTestStep("Print character \"me\"");
  std::cout << src;
  printTestStep("Print character \"copy\" after assigning \"me\" to it");
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
  testDeepCopyMateriaSource(*src);
  testDeepCopyCharacter(*me);
  testEquippingFirstFreeSlot(*me, *(new Cure));
  deleteClasses(*me, *bob, *src);
  testLeaks();
  return 0;
}
