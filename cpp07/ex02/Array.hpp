#ifndef ARRAY_H
#define ARRAY_H

#include <cstdlib>
#include <stdexcept>
#include <string>

template <typename T>
class Array {
 private:
  T* array_;
  unsigned int size_;

 public:
  Array() : array_(NULL), size_(0) {}

  Array(unsigned int n) : array_(new T[n]()), size_(n) {}

  Array(Array const& src) : array_(NULL), size_(0) { *this = src; }

  Array& operator=(Array const& rhs) {
    if (this == &rhs) return *this;
    delete[] array_;
    array_ = new T[rhs.size_]();
    size_ = rhs.size_;
    for (unsigned int i = 0; i < size_; ++i) array_[i] = rhs.array_[i];
    return *this;
  }

  T& operator[](unsigned int index) const {
    if (index >= size_) throw IndexOutOfRangeException();
    return array_[index];
  }

  ~Array() { delete[] array_; }

  unsigned int size() const { return size_; };

  class IndexOutOfRangeException : public std::exception {
   public:
    IndexOutOfRangeException() {}
    ~IndexOutOfRangeException() throw() {}
    char const* what() const throw() { return "Index out of range"; }
  };
};

#endif