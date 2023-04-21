#include <algorithm>
#include <iostream>
#include <vector>

template <typename I>
void merge(I leftBegin, I leftEnd, I rightBegin, I rightEnd, I dest) {
  I lBCpy = leftBegin;
  I dCpy = dest;
  int size = (leftEnd - leftBegin) + (rightEnd - rightBegin);
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
  std::vector<int> v;
  v.push_back(3);
  v.push_back(9);
  v.push_back(1);
  v.push_back(17);
  v.push_back(8);
  v.push_back(2);

  typedef std::vector<int>::iterator iterator;
  std::vector<int> d(v.size());
  sortV<iterator>(v.begin(), v.end(), d.begin());
  for (int i = 0; i < v.size(); ++i) std::cout << v[i] << " ";
  std::cout << "\n";
}