#include <deque>
#include <list>
#include <stack>
#include <utility>

#include "PmergeMe.hpp"
#include "pme.hpp"

int main(int argc, char** argv) {
  typedef std::list<int> vectInts;
  typedef std::list<std::pair<int, int> > vectPairs;
  PmergeMe<vectInts, vectPairs> m(argc, argv);
  m.run();
  return 0;
}
