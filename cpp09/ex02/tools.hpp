#ifndef TOOLS_HPP
#define TOOLS_HPP

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
  template<typename Iterator>
  Iterator binSearch(int i, Iterator begin, Iterator end) {
    if (end - begin == 1) {
      if (i <= *begin) return begin;
      return end;
    }
    if (end == begin) return begin;
    int mid = (end - begin) / 2;
    if (i <= *(begin + mid))
      return binSearch<Iterator>(i, begin, begin + mid);
    else
      return binSearch<Iterator>(i, begin + mid, end);
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
    while (left.size()) {
      sorted.push_back(left.front());
      left.erase(left.begin());
    }
    while (right.size()) {
      sorted.push_back(right.front());
      right.erase(right.begin());
    }
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
};

#endif