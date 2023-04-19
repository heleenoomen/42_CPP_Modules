#ifndef MERGESORT_HPP
#define MERGESORT_HPP

#include <utility>

/* Sorts a container of pairs */
namespace sortPairs {

  /* merge halves */
  template<typename Container<std::pair<int, int >> >
  typename Container merge(typename Container c) const {
    typename Container sorted;
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

  /* recursively split in halves & then call merge */
  template<typename Container<std::pair<int, int >> >
  typename Container mergesort(typename Container c) const {
    if (c.size() == 1) return c;
    int mid = c.size() / 2;
    typename Container left(c.begin(), c.begin() + mid);
    typename Container right(c.begin() + mid, c.end());
    return merge(sortPairs(left), sortPairs(right));
  }
}
