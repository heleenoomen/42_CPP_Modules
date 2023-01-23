#include <algorithm>
#include <exception>

class NoOcurrenceFound : public std::exception {
 public:
  char const* what() const throw() { return "No occurrence found"; }
};

template <typename T>
typename T::iterator easyfind(T& container, int nbr) {
  typename T::iterator ret = std::find(container.begin(), container.end(), nbr);
  if (ret == container.end()) throw NoOcurrenceFound();
  return ret;
}
