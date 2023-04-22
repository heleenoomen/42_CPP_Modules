#include <algorithm>
#include <iostream>
#include <vector>

template <typename I>
void merge(I leftBegin, I leftEnd, I rightBegin, I rightEnd, I dest) {
  I lBCpy = leftBegin;
  I dCpy = dest;
  int size = (leftEnd - leftBegin) + (rightEnd - rightBegin);
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
  std::copy(dCpy, dCpy + size, lBCpy);
}

template <typename I>
void sortV(I begin, I end, I dest) {
  if (end - begin < 2) return;
  int mid = (end - begin) / 2;
  sortV(begin, begin + mid, dest);
  sortV(begin + mid, end, dest);
  merge(begin, begin + mid, begin + mid, end, dest);
}

int main() {
  std::vector<std::pair<int, int> > v;
  v.push_back(std::make_pair(3, 0));
  v.push_back(std::make_pair(9, 0));
  v.push_back(std::make_pair(1, 0));
  v.push_back(std::make_pair(17, 0));
  v.push_back(std::make_pair(8, 0));
  v.push_back(std::make_pair(2, 0));

  typedef std::vector<std::pair<int, int> >::iterator iterator;
  std::vector<std::pair<int, int> > d(v.size());
  sortV<iterator>(v.begin(), v.end(), d.begin());
  for (int i = 0; i < v.size(); ++i)
    std::cout << v[i].first << "/" << v[i].second << '\n';
}