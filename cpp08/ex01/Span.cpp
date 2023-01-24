#include "Span.hpp"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <numeric>

Span::Span() : elements_(std::vector<int>(0)), N_(0) {}

Span::Span(unsigned int n) : elements_(std::vector<int>(0)), N_(n) {}

Span::Span(Span const& src) : elements_(std::vector<int>(0)), N_(0) {
  *this = src;
}

Span& Span::operator=(Span const& rhs) {
  elements_ = rhs.elements_;
  N_ = rhs.N_;
  sorted_ = rhs.sorted_;
  return *this;
}

Span::~Span() {}

void Span::sortElements_() {
  if (sorted_) return;
  std::sort(elements_.begin(), elements_.end());
  sorted_ = true;
}

char const* Span::SpanFullException::what() const throw() {
  return "Cannot add number: No space left in span";
}

char const* Span::NoSpanFoundException::what() const throw() {
  return "Cannot find any span: Too few numbers";
}

void Span::addNumber(int nbr) {
  if (elements_.size() == N_) throw SpanFullException();
  elements_.push_back(nbr);
  sorted_ = false;
}

int Span::shortestSpan() {
  if (elements_.size() < 2) throw NoSpanFoundException();
  sortElements_();
  std::vector<int> tmp;
  std::adjacent_difference(elements_.begin(), elements_.end(),
                           std::back_inserter(tmp));
  int (*intAbs)(int) = &std::abs;
  std::transform(tmp.begin(), tmp.end(), tmp.begin(), intAbs);
  return *std::min_element(tmp.begin(), tmp.end());
}

int Span::longestSpan() {
  if (elements_.size() < 2) throw NoSpanFoundException();
  if (sorted_) return elements_.back() - elements_.front();
  return *std::max_element(elements_.begin(), elements_.end()) -
         *std::min_element(elements_.begin(), elements_.end());
}
