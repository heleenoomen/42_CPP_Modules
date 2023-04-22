#include <ctime>
#include <deque>
#include <list>
#include <set>
#include <utility>
#include <vector>

#include "PmergeMe.hpp"
#include "pme.hpp"

void check_duplicates(int argc, char** argv) {
  std::set<int> s;
  for (int i = 1; i < argc; ++i) {
    if ((s.insert(pme::stoi(argv[i]))).second == false)
      throw pme::invalidInputException();
  }
}

int main(int argc, char** argv) {
  long timeV;
  long timeL;

  typedef std::list<int> listInts;
  typedef std::list<std::pair<int, int> > listIntPairs;
  typedef std::vector<int> vectInts;
  typedef std::vector<std::pair<int, int> > vectIntPairs;

  PmergeMe<listInts, listIntPairs> sortList(argc, argv);
  PmergeMe<vectInts, vectIntPairs> sortVect(argc, argv);

  try {
    check_duplicates(argc, argv);
    {
      std::clock_t start = std::clock();
      sortVect.run();
      std::clock_t end = std::clock();
      timeL = (1000000) * (end - start) / CLOCKS_PER_SEC;
    }
    {
      std::clock_t start = std::clock();
      sortList.run();
      std::clock_t end = std::clock();
      timeV = (1000000) * (end - start) / CLOCKS_PER_SEC;
    }
  } catch (std::exception& e) {
    std::cerr << e.what() << "\n";
    return 1;
  }
  std::cout << "Before:\t";
  for (int i = 1; i < argc; ++i) std::cout << argv[i] << " ";
  std::cout << "\n";
  std::cout << "After:\t";
  sortVect.printAChain();
  std::cout << "\n";
  std::cout << "Time to process a range of " << argc - 1
            << " elements with std::vector : " << timeV << " ns\n";
  std::cout << "Time to process a range of " << argc - 1
            << " elements with std::list : " << timeL << " ns\n";
  return 0;
}
