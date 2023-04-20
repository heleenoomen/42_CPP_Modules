#include <vector>
#include <iostream>

template<typename I>
void merge(I leftBegin, I leftEnd, I rightBegin, I rightEnd, I dest) {
  // std::vector<int> d;
  // int size = 0;
  while (leftBegin != leftEnd && rightBegin != rightEnd) {
    *dest = *leftBegin >= *rightBegin ? *leftBegin : *rightBegin;
    // int nb = *leftBegin >= *rightBegin ? *leftBegin : *rightBegin;
    // d.push_back(nb);
    ++dest;
    ++leftBegin;
    ++rightBegin;
    // ++size;
  }
  // std::copy(leftBegin, leftEnd, std::back_inserter(d));
  // std::copy(rightBegin, rightEnd, std::back_inserter(d));
  std::copy(leftBegin, leftEnd, dest);
  std::copy(rightBegin, rightEnd, dest);
  // size += leftE
  // int size = (leftEnd - leftBegin) + left
}

template<typename I>
void sortV(I begin, I end, I dest) {
  static int i;
  if (i < 10)
    std::cout << *begin << " " << *(end - 1) << "\n";
  if (end - begin < 2)
    return ;
  int mid = (end - begin) / 2;
  I leftBegin = begin;
  I leftEnd = begin + mid;
  I rightBegin = begin + mid;
  I rightEnd = end;
  if (i < 10 )
    std::cout << "left: " << *leftBegin << " " << *(leftEnd - 1) << "\n";
  if (i < 10 )
    std::cout << "right: " << *rightBegin << " " << *(rightEnd - 1) << "\n";
  ++i;
  sortV(leftBegin, leftEnd, dest);
  sortV(rightBegin, rightEnd, dest);
  merge(leftBegin, leftEnd, rightBegin, rightEnd, dest);
}


int main() {
  std::vector<int> v;
  v.push_back(3);
  v.push_back(9);
  v.push_back(1);
  v.push_back(4);

  typedef std::vector<int>::iterator iterator;
  std::vector<int> d(v.size());
  sortV<iterator>(v.begin(), v.end(), d.begin());
  for (int i = 0; i < d.size(); ++i)
    std::cout << d[i] << " ";
  std::cout << "\n";
}