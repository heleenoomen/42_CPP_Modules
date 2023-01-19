#include <iostream>

template< typename T> 
T const& max(T const& x, T const& y) {
  return (x >= y? x : y);
}

/* In max() T represents a global type, but it must be the same type
 * In line 3, we announce that we declare a template. Inside the 
 * braces, we declare a type T. It could be whatever we want.
 * We could also pass instance of classes to max() now, as long as the
 * operator>=() has been overloaded. If we want to pass classes, it is
 * better to pass T by reference. It will save a lot of memory.
 * We also make it const, so that max() will not accidentally change
 * T. As for the return type, it is also a good idea to pass T by
 * reference and make it const as well.
 * We are still able to pass simple types (int, float etc.) to max().
 */

int foo(int x) {
  std::cout << "Long computing time\n";
  return x;
}

int main() {
  int a(21);
  int b(42);

  std::cout << "Max of " << a << " and " << b << " is ";
  std::cout << max<int>(a, b) << '\n'; // explicit instantiation
  std::cout << "Max of " << a << " and " << b << " is ";
  std::cout << max( a, b) << '\n'; // implicit instantiation


  float c(-1.7f);
  float d(4.2f);

  std::cout << "Max of " << c << " and " << d << " is ";
  std::cout << max<float>(c, d) << '\n'; // explicit instantiation
  std::cout << "Max of " << c << " and " << d << " is ";
  std::cout << max(c, d) << '\n'; // implicit instantiation

  // No problem here...
  int ret = max<int>(foo(a), foo(b)); // explicit instantiation
  std::cout << "Max of " << a << " and " << b << " is ";
  std::cout << ret << '\n';
  return 0;
}

/* Templates must be instantiated.
 * In trivial cases, implicit instantiation will suffice.
 * In general though, explicit instantiation is preferred.