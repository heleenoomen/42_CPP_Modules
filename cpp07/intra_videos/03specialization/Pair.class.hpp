#include <iostream>
#include <iomanip>
#include <ios>

template< typename T, typename U>
class Pair {
 public:
  Pair<T, U>(T const& lhs, U const& rhs) : _lhs(lhs), _rhs(rhs) {
    std::cout << "Generic template\n";
    return;
  }

  ~Pair<T, U>() {}

  T const& fst() const { return _lhs; }
  U const& snd() const { return _rhs; }

 private:
  T const& _lhs;
  U const& _rhs;

  Pair<T, U>();
};
/* The above is a generic template for a pair structure */

template< typename U> // only one variable of U type.
class Pair<int, U> { // in a specialization, define again which types are used
 public:
  Pair<int, U>(int lhs, U const& rhs) : _lhs(lhs), _rhs(rhs) {
    std::cout << "Int partial specialization\n";
    return;
  }

  ~Pair<int, U>() {};

  int fst() const { return _lhs; }
  U const& snd() const { return _rhs; }

 private:
  int _lhs;
  U const& _rhs;

  Pair<int, U>();
};
/* The above is a partial specialization of the generic pair
 * class template.
 * In this specialization, the first type will always be int.
 * If we pass an int as the first argument to the constructor,
 * the generic template is not used, but the partly specialized template
 * is used instead.
 */

template<>
class Pair<bool, bool> {
 public:
  Pair<bool, bool>(bool lhs, bool rhs) {
    std::cout << "Bool/bool specialization\n";
    _n = 0;
    _n = static_cast<int>(lhs) << 0;
    _n = static_cast<int>(rhs) << 1;
    return;
  }

  ~Pair<bool, bool>() {}

  bool fst() const { return (_n & 0x01); }
  bool snd() const { return (_n & 0x02); }

 private:
  int _n;

  Pair<bool, bool>();
};
/* The above is a full specialization.
 * Working with specializations can save some memory. 
 */

template<typename T, typename U>
std::ostream& operator<<(std::ostream& o, Pair<T, U>const& p) {
  o << "Pair(" << p.fst() << ", " << p.snd() << ")";
  return o;
}

std::ostream& operator<<(std::ostream& o, Pair<bool, bool>const& p) {
  o << std::boolalpha << "Pair(" << p.fst() << ", " << p.snd() << ")";
  return o;
}
