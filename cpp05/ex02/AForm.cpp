
#include "AForm.hpp"
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
AForm::AForm()
  : name_("Default"),
    signed_(false),
    gradeRequiredToSign_(1),
    gradeRequiredToExecute_(1) {
  std::cout << grey << "AForm default constructor called\n" << resetLayout;
  checkGrade();
}

AForm::AForm(std::string const& name, int gradeToSign, int gradeToExecute)
  : name_(name),
    signed_(false),
    gradeRequiredToSign_(gradeToSign),
    gradeRequiredToExecute_(gradeToExecute) {
  std::cout << grey << "AForm parametric constructor called\n" << resetLayout;
  checkGrade();
}

/* Copy constructor */
AForm::AForm(AForm const& src)
  : name_(src.getName()),
    gradeRequiredToSign_(src.getGradeRequiredToSign()),
    gradeRequiredToExecute_(src.getGradeRequiredToExecute()) {
  std::cout << grey << "AForm copy constructor called\n" << resetLayout;
  *this = src;
}

/* Copy assignment operator */
AForm& AForm::operator=(AForm const& rhs) {
  std::cout << grey << "AForm copy assignment operator called\n" << resetLayout;
  if (this == &rhs)
    return *this;
  signed_ = rhs.isSigned();
  return *this;
}

/* Destructor */
AForm::~AForm() {
  std::cout << grey << "AForm destructor called\n" << resetLayout;
}

/* ************************************************************************** */
/* Getters                                                                    */
/* ************************************************************************** */

std::string const& AForm::getName() const { return name_; }

bool AForm::isSigned() const { return signed_; }

int AForm::getGradeRequiredToSign() const { return gradeRequiredToSign_; }

int AForm::getGradeRequiredToExecute() const { return gradeRequiredToExecute_; }

/* ************************************************************************** */
/* Setters                                                                    */
/* ************************************************************************** */

void AForm::beSigned(Bureaucrat const& b) {
  if (gradeHighEnoughToSign(b))
    signed_ = true;
  else
    throw(GradeTooLowException());
}

// void AForm::setGradeRequiredToExecute(int grade) {}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

void AForm::checkExecutionRequirements(Bureaucrat const& b) const {
  if (!signed_)
    throw(FormNotSignedException());
  else if (!gradeHighEnoughToExecute(b))
    throw(GradeTooLowException());
}

/* ************************************************************************** */
/* Private methods                                                            */
/* ************************************************************************** */

bool AForm::oneOrBothGradesTooHigh() const {
  if (gradeRequiredToExecute_ < Bureaucrat::maximumGrade)
    return true;
  if (gradeRequiredToSign_ < Bureaucrat::maximumGrade)
    return true;
  return false;
}

bool AForm::oneOrBothGradesTooLow() const {
  if (gradeRequiredToExecute_ > Bureaucrat::minimumGrade)
    return true;
  if (gradeRequiredToSign_ > Bureaucrat::minimumGrade)
    return true;
  return false;
}

void AForm::checkGrade() const {
  if (oneOrBothGradesTooLow())
    throw (GradeTooLowException());
  if (oneOrBothGradesTooHigh())
    throw (GradeTooHighException());
}

bool AForm::gradeHighEnoughToSign(Bureaucrat const& b) const {
  if (b.getGrade() <= gradeRequiredToSign_)
    return true;
  return false;
}

bool AForm::gradeHighEnoughToExecute(Bureaucrat const& b) const {
  if (b.getGrade() <= gradeRequiredToExecute_)
    return true;
  return false;
}

/* ************************************************************************** */
/* Nested exception classes                                                   */
/* ************************************************************************** */

const char* AForm::GradeTooHighException::what() const throw() {
  return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
  return "Grade too low";
}

AForm::GradeTooHighException::GradeTooHighException() {
  std::cout << grey << "AForm::GradeTooHighException default constructor\n" 
            << " called\n" << resetLayout;
}

AForm::GradeTooHighException::~GradeTooHighException() throw() {
  std::cout << grey << "AForm::GradeTooHighException destructor"
            << " called\n" << resetLayout;
}

AForm::GradeTooLowException::GradeTooLowException() {
  std::cout << grey << "AForm::GradeTooLowException default constructor"
            << " called\n" << resetLayout;
}

AForm::GradeTooLowException::~GradeTooLowException() throw() {
  std::cout << grey << "AForm::GradeTooLowException destructor"
            << " called\n" << resetLayout;
}

AForm::FormNotSignedException::FormNotSignedException() {
  std::cout << grey << "AForm::GradeTooLowException default constructor"
            << " called\n" << resetLayout;

}
AForm::FormNotSignedException::~FormNotSignedException() throw() {
  std::cout << grey << "AForm::GradeTooLowException destructor"
            << " called\n" << resetLayout;
}

const char* AForm::FormNotSignedException::what() const throw() {
  return "Form not signed";
}

/* ************************************************************************** */
/* Insertion operator                                                         */
/* ************************************************************************** */

std::ostream& operator<<(std::ostream& o, AForm const& f) {
  o << insertionOverloadLayout
    << "Form: " << f.getName() << ", "
    << "Signed: ";
  f.isSigned()? o << "yes\n": o << "no\n";
  o << "Grade required to sign: " << f.getGradeRequiredToSign() << ","
    << " Grade required to execute: " << f.getGradeRequiredToExecute()
    << resetLayout;
  return o;
}
