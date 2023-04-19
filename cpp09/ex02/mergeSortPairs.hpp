#ifndef MERGESORT_HPP
#define MERGESORT_HPP

/* merge halves */
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

/* merge sort container of pairs */
template <typename Container>
Container mergeSortPairs(Container pairs) {
  if (pairs.size() == 1) return pairs;
  int mid = pairs.size() / 2;
  Container left(pairs.begin(), pairs.begin() + mid);
  Container right(pairs.begin() + mid, pairs.end());
  return merge<Container>(mergeSortPairs<Container>(left),
                          mergeSortPairs<Container>(right));
}

#endif