#ifndef ARRAY_H
#define ARRAY_H

template<typename T>
class Array {
 public:
  Array();
  Array(unsigned int n);
  Array(Array const& src);

  Array operator=(Array const& rhs);

  ~Array();
}

#endif