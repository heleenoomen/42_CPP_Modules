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
  if (this == &rhs) return *this;
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
  return "Cannot add object: Span is full";
}

char const* Span::NoSpanFoundException::what() const throw() {
  return "Cannot find any span: Too few elements";
}

void Span::addNumber(int nbr) {
  if (elements_.size() == N_) throw SpanFullException();
  elements_.push_back(nbr);
  sorted_ = false;
}

void Span::addNumber(std::vector<int>::iterator const& begin,
                     std::vector<int>::iterator const& end) {
  if (std::distance(begin, end) + elements_.size() > N_)
    throw SpanFullException();
  elements_.insert(elements_.end(), begin, end);
  sorted_ = false;
}

/* NB erase first element from result because of how std::adjacent_difference
   works, see https://cplusplus.com/reference/numeric/adjacent_difference/
 */
int Span::shortestSpan() {
  if (elements_.size() < 2) throw NoSpanFoundException();
  sortElements_();
  std::vector<int> result;
  std::adjacent_difference(elements_.begin(), elements_.end(),
                           std::back_inserter(result));
  result.erase(result.begin());
  int (*intAbs)(int) = &std::abs;
  std::transform(result.begin(), result.end(), result.begin(), intAbs);
  return *std::min_element(result.begin(), result.end());
}

int Span::longestSpan() const {
  if (elements_.size() < 2) throw NoSpanFoundException();
  if (sorted_) return elements_.back() - elements_.front();
  return *std::max_element(elements_.begin(), elements_.end()) -
         *std::min_element(elements_.begin(), elements_.end());
}

std::vector<int> const& Span::getElements() const { return elements_; }

std::ostream& operator<<(std::ostream& o, Span const& s) {
  std::vector<int> elements = s.getElements();
  for (std::vector<int>::iterator it = elements.begin(); it != elements.end();
       ++it)
    o << *it << '\n';
  return o;
}
