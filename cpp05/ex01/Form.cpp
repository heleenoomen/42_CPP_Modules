
#include "Form.hpp"
#include "Layout.hpp"
#include <iostream>

static char const* insertionOverloadLayout = Layout::greenBold;

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
Form::Form()
  : name_("Default"),
    signed_(false),
    gradeRequiredToSign_(1),
    gradeRequiredToExecute_(1) {
  std::cout << Layout::grey << "Form default constructor called\n" << Layout::reset;
  gradeCheck();
}

Form::Form(std::string const& name, int gradeToSign, int gradeToExecute)
  : name_(name),
    signed_(false),
    gradeRequiredToSign_(gradeToSign),
    gradeRequiredToExecute_(gradeToExecute) {
  std::cout << Layout::grey << "Form parametric constructor called\n" << Layout::reset;
  gradeCheck();
}

/* Copy constructor */
Form::Form(Form const& src)
  : name_(src.getName()),
    gradeRequiredToSign_(src.getGradeRequiredToSign()),
    gradeRequiredToExecute_(src.getGradeRequiredToExecute()) {
  std::cout << Layout::grey << "Form copy constructor called\n" << Layout::reset;
  *this = src;
}

/* Copy assignment operator */
Form& Form::operator=(Form const& rhs) {
  std::cout << Layout::grey << "Form copy assignment operator called\n" << Layout::reset;
  if (this == &rhs)
    return *this;
  signed_ = rhs.isSigned();
  return *this;
}

/* Destructor */
Form::~Form() {
  std::cout << Layout::grey << "Form destructor called\n" << Layout::reset;
}

/* ************************************************************************** */
/* Getters                                                                    */
/* ************************************************************************** */

std::string const& Form::getName() const { return name_; }

bool Form::isSigned() const { return signed_; }

int Form::getGradeRequiredToSign() const { return gradeRequiredToSign_; }

int Form::getGradeRequiredToExecute() const { return gradeRequiredToExecute_; }

/* ************************************************************************** */
/* Setters                                                                    */
/* ************************************************************************** */

void Form::beSigned(Bureaucrat const& b) {
  if (gradeHighEnoughTooSign(b))
    signed_ = true;
  else
    throw(GradeTooLowException());
}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

/* ************************************************************************** */
/* Private methods                                                            */
/* ************************************************************************** */

bool Form::oneOrBothGradesTooHigh() const {
  if (gradeRequiredToExecute_ < Bureaucrat::maximumGrade)
    return true;
  if (gradeRequiredToSign_ < Bureaucrat::maximumGrade)
    return true;
  return false;
}

bool Form::oneOrBothGradesTooLow() const {
  if (gradeRequiredToExecute_ > Bureaucrat::minimumGrade)
    return true;
  if (gradeRequiredToSign_ > Bureaucrat::minimumGrade)
    return true;
  return false;
}

void Form::gradeCheck() const {
  if (oneOrBothGradesTooLow())
    throw (GradeTooLowException());
  if (oneOrBothGradesTooHigh())
    throw (GradeTooHighException());
}

bool Form::gradeHighEnoughTooSign(Bureaucrat const& b) const {
  if (b.getGrade() <= gradeRequiredToSign_)
    return true;
  return false;
}

/* ************************************************************************** */
/* Nested exception classes                                                   */
/* ************************************************************************** */

const char* Form::GradeTooHighException::what() const throw() {
  return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
  return "Grade too low";
}

Form::GradeTooHighException::GradeTooHighException() {
  std::cout << Layout::grey << "Form::GradeTooHighException default constructor\n" 
            << " called\n" << Layout::reset;
}

Form::GradeTooHighException::~GradeTooHighException() throw() {
  std::cout << Layout::grey << "Form::GradeTooHighException default destructor"
            << " called\n" << Layout::reset;
}

Form::GradeTooLowException::GradeTooLowException() {
  std::cout << Layout::grey << "Form::GradeTooLowException default constructor"
            << " called\n" << Layout::reset;
}

Form::GradeTooLowException::~GradeTooLowException() throw() {
  std::cout << Layout::grey << "Form::GradeTooLowException default destructor"
            << " called\n" << Layout::reset;
}

/* ************************************************************************** */
/* Insertion operator                                                         */
/* ************************************************************************** */

std::ostream& operator<<(std::ostream& o, Form const& f) {
  o << insertionOverloadLayout
    << "Form: " << f.getName() << ", "
    << "Signed: ";
  f.isSigned()? o << "yes\n": o << "no\n";
  o << "Grade required to sign: " << f.getGradeRequiredToSign() << ","
    << " Grade required to execute: " << f.getGradeRequiredToExecute()
    << Layout::reset;
  return o;
}
