#ifndef PME_HPP
#define PME_HPP

#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>
#include <utility>

namespace pme {
int stoi(char const* token);

int Jacobsthal(int n);

class invalidInputException : public std::exception {
 public:
  invalidInputException();
  ~invalidInputException() throw();
  virtual char const* what() const throw();
};

std::pair<int, int> sortedPair(int n1, int n2);

/* binary search with iterators: search a container of integers recursively */
template <typename Iterator>
Iterator binSearch(int i, Iterator begin, Iterator end) {
  if (std::distance(begin, end) == 1) {
    if (i <= *begin) return begin;
    return end;
  }
  if (std::distance(begin, end) == 0) return begin;
  int mid = (std::distance(begin, end)) / 2;
  Iterator midIt = begin;
  std::advance(midIt, mid);
  if (i <= *midIt)
    return binSearch<Iterator>(i, begin, midIt);
  else
    return binSearch<Iterator>(i, midIt, end);
}

/* merge sort (merge part) for container of pairs, using iterators:
sort left and right based on the first element of each pair. Use the
preallocated tmp container for temporary storage. Then, copy all elements to
leftBegin, so that they will be in their final place in the original container.
We use std::distance and std::advance instead of arithmetic operators so that
the template can also handle lists.
*/
template <typename I>
void merge(I leftBegin, I leftEnd, I rightBegin, I rightEnd, I dest) {
  I lBCpy = leftBegin;
  I dCpy = dest;
  int size =
      std::distance(leftBegin, leftEnd) + std::distance(rightBegin, rightEnd);
  while (leftBegin != leftEnd && rightBegin != rightEnd) {
    if (leftBegin->first <= rightBegin->first) {
      *dest = *leftBegin;
      ++leftBegin;
    } else {
      *dest = *rightBegin;
      ++rightBegin;
    }
    ++dest;
  }
  std::copy(leftBegin, leftEnd, dest);
  std::copy(rightBegin, rightEnd, dest);
  I dCpyEnd = dCpy;
  std::advance(dCpyEnd, size);
  std::copy(dCpy, dCpyEnd, lBCpy);
}

/* merge sort for container of pairs, using iterators:
divide the container, sort left, sort right, then merge.
tmp is the beginning of a preallocated container of the same type and size, used
throughout the sorting to rearrange elements. This template can also handle
lists (which is why we use std::advance and std::distance istead of arithmetic
operators.)
*/
template <typename Iterator>
void sortPairs(Iterator begin, Iterator end, Iterator tmp) {
  if (std::distance(begin, end) < 2) return;
  int mid = std::distance(begin, end) / 2;
  Iterator midI = begin;
  std::advance(midI, mid);
  sortPairs(begin, midI, tmp);
  sortPairs(midI, end, tmp);
  merge<Iterator>(begin, midI, midI, end, tmp);
}

};  // namespace pme

#endif