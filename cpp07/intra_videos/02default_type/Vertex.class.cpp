#include <iostream>
#include <iomanip>

template<typename T = float > // float is the default type
class Vertex {
 public:
  Vertex(T const& x, T const& y, T const&z) : _x(x), _y(y), _z(z) {}
  ~Vertex() {}

  T const& getX() const { return _x; }
  T const& getY() const { return _y; }
  T const& getZ() const { return _z; }

  // Etc ...

 private:
  T const _x;
  T const _y;
  T const _z;

  Vertex();
};
/* the default type will be used when the programmer doesn't specify
 * otherwise. x, y and z will usually be floats, but the can be 
 * something else as well. */

template< typename T >
std::ostream& operator<<(std::ostream& o, Vertex<T> const& v) {
  std::cout.precision(1);
  o << std::setiosflags(std::ios::fixed);
  o << "Vertex(";
  o << v.getX() << ", ";
  o << v.getY() << ", ";
  o << v.getZ();
  o << ")";
  return o;
}
/* operator<<() overload template takes a reference to a Vertex
 * template of T type. This is now a nested template.
 */

/* The .tpp extension you can use to indicate that you are dealing with 
 * template classes. Some people hate this time of naming convention.
 * Discuss this convention with other people.
 * 
 */