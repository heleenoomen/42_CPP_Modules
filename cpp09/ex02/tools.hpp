#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>
#include <utility>

namespace tools {
int strToInt(std::string& token);

int Jacobsthal(int n);

class invalidInputException : public std::exception {
 public:
  invalidInputException();
  ~invalidInputException() throw();
  virtual char const* what() const throw();
};

std::pair<int, int> makeSortedPair(int n1, int n2);

/* binary search */
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

/* merge sort (merge part) for container of pairs */
template <typename Container>
static Container merge(Container left, Container right) {
  Container sorted;
  while (left.size() && right.size()) {
    if (left.front().first < right.front().first) {
      sorted.push_back(left.front());
      left.erase(left.begin());
    } else {
      sorted.push_back(right.front());
      right.erase(right.begin());
    }
  }
  std::copy(left.begin(), left.end(), std::back_inserter(sorted));
  std::copy(right.begin(), right.end(), std::back_inserter(sorted));
  return sorted;
}

/* merge sort for container of pairs */
template <typename Container>
Container mergeSortPairs(Container& pairs) {
  if (pairs.size() == 1) return pairs;
  int mid = pairs.size() / 2;
  Container left(pairs.begin(), pairs.begin() + mid);
  Container right(pairs.begin() + mid, pairs.end());
  return merge<Container>(mergeSortPairs<Container>(left),
                          mergeSortPairs<Container>(right));
}
};  // namespace tools

#endif