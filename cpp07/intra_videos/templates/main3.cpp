#include <iostream>

template <typename T, typename U> //introduce a 2nd type too
class List {
 public:
  List<T, U>(T const& content, U const& content2) {
    // Etc ...
  }
  List<T, U>(List<T, U> const& list, U const& content2) {
    // Etc ...
  }
  ~List<T, U>() {
    // Etc ...
  }
  // Etc ...

 private:
  T* _content;
  List<T, U>* _next;
};

int main() {
  List<int, float> a(42, 3.14f);
  List<float, float> b(3.14f, 3.14f);
  List<List<int, float>, float > c(a, 3.14f);
}

/* Here we have a template class with 2 global types (T and U)
 */