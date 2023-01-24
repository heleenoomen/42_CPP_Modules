#include <exception>
#include <iostream>
#include <vector>

class Span {
 private:
  std::vector<int> elements_;
  unsigned int N_;
  bool sorted_;

  void sortElements_();

 public:
  Span();
  Span(unsigned int N);

  /* Copy constructor */
  Span(Span const& src);

  /* Assignment operator */
  Span& operator=(Span const& rhs);

  /* Destructor */
  ~Span();

  /* Public methods */
  void addNumber(int nbr);
  void addNumber(std::vector<int>::iterator const& first,
                 std::vector<int>::iterator const& last);
  int shortestSpan();
  int longestSpan();
  std::vector<int> const& getElements() const;

  /* Exceptions */
  class SpanFullException : public std::exception {
   public:
    char const* what() const throw();
  };

  class NoSpanFoundException : public std::exception {
   public:
    char const* what() const throw();
  };
};

std::ostream& operator<<(std::ostream& o, Span const& s);
