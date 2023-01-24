#include <exception>
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
  int shortestSpan();
  int longestSpan();

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
