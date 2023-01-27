/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:29:53 by hoomen            #+#    #+#             */
/*   Updated: 2023/01/27 15:32:40 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <iostream>
#include <list>
#include <vector>

#include "MutantStack.hpp"

template<typename Container>
void fillContainer(Container& c) {
  c.push_back(5);
  c.push_back(17);
  c.pop_back();
  c.push_back(3);
  c.push_back(5);
  c.push_back(737);
  c.push_back(0);
}

void fillStack(std::stack<int>& s) {
  s.push(5);
  s.push(17);
  s.pop();
  s.push(3);
  s.push(5);
  s.push(737);
  s.push(0);
}

void subjectPDF() {
  std::cout << "TEST MUTANTSTACK\n";
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << "On top is: " << mstack.top() << std::endl;
  mstack.pop();
  std::cout << "Size is: " << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);
  std::cout << '\n';
}

void compareVector() {
  std::cout << "COMPARE VECTOR\n";
  std::vector<int> v;
  v.push_back(5);
  v.push_back(17);
  std::cout << "On top is: " << v.back() << std::endl;
  v.pop_back();
  std::cout << "Size is: " << v.size() << std::endl;
  v.push_back(3);
  v.push_back(5);
  v.push_back(737);
  //[...]
  v.push_back(0);
  std::vector<int>::iterator it = v.begin();
  std::vector<int>::iterator ite = v.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int, std::vector<int> > s(v);
  MutantStack<int, std::vector<int> > mstack(v);
  std::cout << '\n';
}

void compareList() {
  std::cout << "COMPARE LIST\n";
  std::list<int> l;
  l.push_back(5);
  l.push_back(17);
  std::cout << "On top is: " << l.back() << std::endl;
  l.pop_back();
  std::cout << "Size is: " << l.size() << std::endl;
  l.push_back(3);
  l.push_back(5);
  l.push_back(737);
  l.push_back(0);
  std::list<int>::iterator it = l.begin();
  std::list<int>::iterator ite = l.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int, std::list<int> > s(l);
  MutantStack<int, std::list<int> > ms(l);
  std::cout << '\n';
}

void testMakeMutantStackFromVector() {
  std::cout << "PRINT MUTANT STACK FROM VECTOR WITH VECTOR ITERATORS:\n";
  std::vector<int> v;
  fillContainer<std::vector<int> >(v);
  MutantStack<int, std::vector<int> > mstack(v);
  std::vector<int>::iterator it = mstack.begin();
  std::vector<int>::iterator ite = mstack.end();
  for (; it != ite; ++it) std::cout << *it << '\n';
  std::cout << '\n';
  std::cout << "PRINT MUTANT STACK FROM VECTOR WITH MUTANT STACK ITERATORS:\n";
  MutantStack<int, std::vector<int> >::iterator ms_it = mstack.begin();
  MutantStack<int, std::vector<int> >::iterator ms_ite = mstack.end();
  for (; ms_it != ms_ite; ++ms_it) std::cout << *ms_it << '\n';
  std::cout << '\n';
}

void testCopyConstructor() {
  std::cout << "TEST COPY CONSTRUCTOR:\n";
  MutantStack<int>* mstack = new MutantStack<int>;
  fillStack(*mstack);
  MutantStack<int> cpy(*mstack);
  delete mstack;
  MutantStack<int>::iterator it = cpy.begin();
  MutantStack<int>::iterator ite = cpy.end();
  for (; it != ite; ++it) std::cout << *it << '\n';
  std::cout << '\n';
  std::cout << "TEST COPY CONSTRUCTOR WITH MUTANTSTACK BASED ON LIST:\n";
  std::list<int> l;
  fillContainer<std::list<int> >(l);
  MutantStack<int, std::list<int> > mstack2(l);
  MutantStack<int, std::list<int> > mstack3(mstack2);
  MutantStack<int, std::list<int> >::iterator itl = mstack3.begin();
  MutantStack<int, std::list<int> >::iterator itle = mstack3.end();
  for (; itl != itle; ++itl) std::cout << *itl << '\n';
  std::cout << '\n';
}

void testCopyAssignmentVectorStack() {
  std::cout << "TEST COPY ASSIGNMENT WITH MUTANT STACK FROM VECTOR:\n";
  std::vector<int> v;
  fillContainer<std::vector<int> >(v);
  MutantStack<int, std::vector<int> > mstack(v);
  MutantStack<int, std::vector<int> > mstack2;
  mstack2 = mstack;
  MutantStack<int, std::vector<int> >::iterator it = mstack2.begin();
  MutantStack<int, std::vector<int> >::iterator ite = mstack2.end();
  for (; it != ite; ++it) std::cout << *it << '\n';
  std::cout << '\n';
}

void testCopyAssignment() {
  std::cout << "TEST COPY ASSIGNMENT:\n";
  MutantStack<int> mstack;
  fillStack(mstack);
  MutantStack<int> mstack2;
  mstack2 = mstack;
  MutantStack<int>::iterator it = mstack2.begin();
  MutantStack<int>::iterator ite = mstack2.end();
  for (; it != ite; ++it) std::cout << *it << '\n';
  std::cout << '\n';
}

int main() {
  subjectPDF();
  compareList();
  compareVector();
  testMakeMutantStackFromVector();
  testCopyConstructor();
  testCopyAssignment();
  testCopyAssignmentVectorStack();
  system("leaks mutantstack");
  return 0;
}