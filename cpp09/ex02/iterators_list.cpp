#include <algorithm>
#include <iostream>
#include <list>

template <typename I>
void merge(I leftBegin, I leftEnd, I rightBegin, I rightEnd, I dest) {
  I lBCpy = leftBegin;
  I dCpy = dest;
  int size =
      std::distance(leftBegin, leftEnd) + std::distance(rightBegin, rightEnd);
  while (leftBegin != leftEnd && rightBegin != rightEnd) {
    if (*leftBegin <= *rightBegin) {
      *dest = *leftBegin;
      ++leftBegin;
    } else {
      *dest = *rightBegin;
      ++rightBegin;
    }
    ++dest;
  }
  I dEnd = dCpy;
  std::advance(dEnd, size);
  std::copy(leftBegin, leftEnd, dest);
  std::copy(rightBegin, rightEnd, dest);
  std::copy(dCpy, dEnd, lBCpy);
}

template <typename I>
void sortV(I begin, I end, I dest) {
  if (std::distance(begin, end) < 2) return;
  int mid = (std::distance(begin, end)) / 2;
  I midI = begin;
  std::advance(midI, mid);
  sortV(begin, midI, dest);
  sortV(midI, end, dest);
  merge(begin, midI, midI, end, dest);
}

int main() {
  std::list<int> v;
  v.push_back(3);
  v.push_back(9);
  v.push_back(1);
  v.push_back(17);
  v.push_back(8);
  v.push_back(2);

  typedef std::list<int>::iterator iterator;
  std::list<int> d(v.size());
  sortV<iterator>(v.begin(), v.end(), d.begin());
  for (std::list<int>::iterator it = v.begin(); it != v.end(); ++it)
    std::cout << *it << " ";
  // for (int i = 0; i < v.size(); ++i) std::cout << v[i] << " ";
  std::cout << "\n";
}