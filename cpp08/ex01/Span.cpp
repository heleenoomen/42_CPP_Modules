#include "Span.hpp"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <numeric>

/* ************************************************************************** */
/* Constructors                                                               */
/* ************************************************************************** */

Span::Span() : elements_(std::vector<int>(0)), N_(0) {}

Span::Span(unsigned int n) : elements_(std::vector<int>(0)), N_(n) {}

/* ************************************************************************** */
/* Copy constructor                                                           */
/* ************************************************************************** */

Span::Span(Span const& src) : elements_(std::vector<int>(0)), N_(0) {
  *this = src;
}

/* ************************************************************************** */
/* Copy assingment operator                                                   */
/* ************************************************************************** */

Span& Span::operator=(Span const& rhs) {
  if (this == &rhs) return *this;
  elements_ = rhs.elements_;
  N_ = rhs.N_;
  sorted_ = rhs.sorted_;
  return *this;
}

/* ************************************************************************** */
/* Destructor                                                                 */
/* ************************************************************************** */

Span::~Span() {}

/* ************************************************************************** */
/* Private member functions                                                   */
/* ************************************************************************** */

void Span::sortElements_() {
  if (sorted_) return;
  std::sort(elements_.begin(), elements_.end());
  sorted_ = true;
}

/* ************************************************************************** */
/* Exceptions                                                                 */
/* ************************************************************************** */

char const* Span::SpanFullException::what() const throw() {
  return "Cannot add object: Span is full";
}

char const* Span::NoSpanFoundException::what() const throw() {
  return "Cannot find any span: Too few elements";
}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

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

/* Erase first element of result vector bcs the 1st element will
   just be the first value from elements_, NOT a differential value. See:
   https://cplusplus.com/reference/numeric/adjacent_difference/
 */
int Span::shortestSpan() {
  if (elements_.size() < 2) throw NoSpanFoundException();
  sortElements_();
  std::vector<int> result;
  std::adjacent_difference(elements_.begin(), elements_.end(),
                           std::back_inserter(result));
  result.erase(result.begin()); // 1st elem of result not relevant, see above
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


/* ************************************************************************** */
/* Insertion operator overload                                                */
/* ************************************************************************** */

/* print the elements in Span (for debugging)*/
std::ostream& operator<<(std::ostream& o, Span const& s) {
  std::vector<int> elements = s.getElements();
  for (std::vector<int>::iterator it = elements.begin(); it != elements.end();
       ++it)
    o << *it << '\n';
  return o;
}
