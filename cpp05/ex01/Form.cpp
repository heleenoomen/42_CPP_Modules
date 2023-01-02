
#include "Form.hpp"
#include <iostream>


#ifndef to_file
static char const* greenBold = "\033[32;1m";
static char const* resetLayout = "\033[0m";
static char const* grey = "\033[0;2m";
#else
static char const* greenBold = "";
static char const* resetLayout = "";
static char const* grey = "";
#endif

static char const* insertionOverloadLayout = greenBold;

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
Form::Form()
  : name_("Default"),
    signed_(false),
    gradeRequiredToSign_(1),
    gradeRequiredToExecute_(1) {
  std::cout << grey << "Form default constructor called\n" << resetLayout;
  gradeCheck();
}

Form::Form(std::string const& name, int gradeToSign, int gradeToExecute)
  : name_(name),
    signed_(false),
    gradeRequiredToSign_(gradeToSign),
    gradeRequiredToExecute_(gradeToExecute) {
  std::cout << grey << "Form parametric constructor called\n" << resetLayout;
  gradeCheck();
}

/* Copy constructor */
Form::Form(Form const& src)
  : name_(src.getName()),
    gradeRequiredToSign_(src.getGradeRequiredToSign()),
    gradeRequiredToExecute_(src.getGradeRequiredToExecute()) {
  std::cout << grey << "Form copy constructor called\n" << resetLayout;
  *this = src;
}

/* Copy assignment operator */
Form& Form::operator=(Form const& rhs) {
  std::cout << grey << "Form copy assignment operator called\n" << resetLayout;
  if (this == &rhs)
    return *this;
  signed_ = rhs.isSigned();
  return *this;
}

/* Destructor */
Form::~Form() {
  std::cout << grey << "Form destructor called\n" << resetLayout;
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
  std::cout << grey << "Form::GradeTooHighException default constructor\n" 
            << " called\n" << resetLayout;
}

Form::GradeTooHighException::~GradeTooHighException() throw() {
  std::cout << grey << "Form::GradeTooHighException default destructor"
            << " called\n" << resetLayout;
}

Form::GradeTooLowException::GradeTooLowException() {
  std::cout << grey << "Form::GradeTooLowException default constructor"
            << " called\n" << resetLayout;
}

Form::GradeTooLowException::~GradeTooLowException() throw() {
  std::cout << grey << "Form::GradeTooLowException default destructor"
            << " called\n" << resetLayout;
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
    << resetLayout;
  return o;
}
