#include <iostream>

template <typename T> //introduce a 2nd type too
class List {
 public:
  List<T>(T const& content) {
    // Etc ...
  }
  List<T>(List<T> const& list) {
    // Etc ...
  }
  ~List<T>() {
    // Etc ...
  }
  // Etc ...

 private:
  T* _content;
  List<T>* _next;
};

int main() {
  List<int> a(42);
  List<float> b(3.14);
  List<List<int> > c(a);
}

/* Here we have a template class
 * A much better List class is defined in the Standard Template
 * Library (STL). You should use the STL one instead of fabricating your own
 */