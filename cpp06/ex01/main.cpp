/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:39:17 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/20 11:05:32 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>

#include "Data.hpp"
#include "Layout.hpp"
#include "Serializer.hpp"

void printIntro() {
  std::cout << "\t\t\t    " << Layout::emojiStar << Layout::emojiStar
            << Layout::emojiStar << "\n\n"
            << Layout::cyanItalic
            << "Hey you! Welcome to the fabulous the world of\n\n"
            << Layout::magentaBold << "\t\t\tREINTERPRET CAST\n\n"
            << Layout::reset << Layout::cyanItalic << "You will love this.\n\n"
            << "First off, we create a structure of type " << Layout::cyan
            << "Data" << Layout::cyanItalic << ".\nIt contains a "
            << Layout::cyan << "char const* name" << Layout::cyanItalic
            << ", say \"Nina\",\n"
            << "and an " << Layout::cyan << "int age" << Layout::cyanItalic
            << ", say 36.\n\n";
}

void printStory0() {
  std::cout
      << "Now, let's serialize the address of our Data structure containing\n"
      << "Nina. Serializing will reinterpret_cast the address of Data into a "
      << Layout::reset << Layout::cyan << "uintptr_t\n\n";
}

void printStory1() {
  std::cout
      << Layout::cyanItalic
      << "If all is well, the address of nina's structure should be the\n"
      << "same as the address of our data structure. Let's print them!\n\n";
}

void printStory2() {
  std::cout << Layout::cyanItalic << "Amazing! They are indeed the same.\n\n"
            << "Now, let's go wild and deserialize our uintptr.\n"
            << "This will reinterpret_cast our serializedPtr of type "
            << Layout::cyan << "uintptr_t\n"
            << Layout::cyanItalic << "into a pointer to " << Layout::cyan
            << "Data" << Layout::cyanItalic
            << ". We will assign the result to a pointer to " << Layout::cyan
            << "Data" << Layout::cyanItalic
            << ",\nwhich we will call data2.\n\n";
}

void printStory3() {
  std::cout << "data2 now is our deserialized pointer. Let's check if the\n"
            << "address it contains is indeed the address where the struct\n"
            << "containing Nina's data live... Let's print data2!\n\n";
}

void printOutro() {
  std::cout << Layout::cyanItalic
            << "Amazing!! It seems like our serializer AND our deserializer\n"
            << "are working perfectly. I am so excited.\n\n"
            << "A big thank you to the star of this show, the one and only\n\n"
            << Layout::magentaBold << "\t\t\tREINTERPRET CAST\n\n"
            << "\t\t\t    " << Layout::emojiStar << Layout::emojiStar
            << Layout::emojiStar << "\n\n"
            << Layout::reset;
  std::cout.flush();
}

int main() {
  printIntro();
  Data data;
  data.name = "Nina";
  data.age = 36;
  printStory0();
  uintptr_t serializedDataPtr = serialize(&data);
  printStory1();
  std::cout << Layout::magenta << std::setw(30) << std::left
            << "serializedDataPtr has value: " << std::setw(1) << "0x"
            << std::setbase(16) << serializedDataPtr << '\n'
            << "Data structure is at address: " << &data << "\n\n"
            << Layout::reset << std::setbase(10);
  printStory2();
  struct Data* data2 = deserialize(serializedDataPtr);
  printStory3();
  std::cout << Layout::cyan << std::setw(30)
            << "data2->name is: " << std::setw(1) << data2->name << '\n'
            << std::setw(30) << "data2->age is: " << std::setbase(10)
            << std::setw(1) << data2->age << '\n'
            << std::setw(30) << "data2 contains the address: " << std::setw(1)
            << data2 << "\n\n";
  printOutro();
}
