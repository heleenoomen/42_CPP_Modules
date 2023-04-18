#include <vector>
#include <iostream>

typedef std::vector<int>::iterator vecIt;

void printVector(std::vector<int>& v) {
  for (vecIt it = v.begin(); it + 1 != v.end(); ++it) {
    std::cout << *it << ", ";
  }
  std::cout << v.back() << '\n';
}

std::vector<int> merge(std::vector<int> l, std::vector<int> r) {
  std::vector<int> sorted;
  while (l.size() && r.size()) {
    if (l.front() <= r.front()) {
      sorted.push_back(l.front());
      l.erase(l.begin());
    } else {
      sorted.push_back(r.front());
      r.erase(r.begin());
    }
  }
  while (l.size()) {
    sorted.push_back(l.front());
    l.erase(l.begin());
  }
  while (r.size()) {
    sorted.push_back(r.front());
    r.erase(r.begin());
  }
  return sorted;
}

std::vector<int> mergeSort(std::vector<int> v) {
  if (v.size() == 1)
    return v;
  int mid = v.size() / 2;
  std::vector<int> left(v.begin(), v.begin() + mid);
  std::vector<int> right(v.begin() + mid, v.end());
  return merge(mergeSort(left), mergeSort(right));
}

int main() {
  std::vector<int> v;

  v.push_back(7);
  v.push_back(9);
  v.push_back(3);
  v.push_back(8);
  v.push_back(4);
  v.push_back(5);
  v.push_back(2);
  v.push_back(1);
  v.push_back(6);
  v.push_back(-3);

  std::cout << "Unsorted vector: ";
  printVector(v);
  std::vector<int> sorted = mergeSort(v);
  std::cout << "Sorted vector: ";
  printVector(sorted);
  // std::vector<int> sorted = mergeSort(v);
}