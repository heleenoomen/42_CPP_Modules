#include "PresidentialPardonForm.hpp"
#include "Layout.hpp"
#include <cstdlib>
#include <climits>
#include <fstream>

std::string const PresidentialPardonForm::formName = "Presidential Pardon";

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
PresidentialPardonForm::PresidentialPardonForm()
    : AForm(formName, gradeRequiredToSign, gradeRequiredToExecute),
      target_("default") {
  std::cout << Layout::grey << "PresidentialPardonForm default constructor called\n" << Layout::reset;
  checkGrade();
}

/* Parametric constructors */
PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
    : AForm(formName, gradeRequiredToSign, gradeRequiredToExecute),
      target_(target) {
  std::cout << Layout::grey << "PresidentialPardonForm parametric constructor called\n" << Layout::reset;
  checkGrade();
}

/* Copy constructor */
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src)
    : AForm(src.getName(), gradeRequiredToSign, gradeRequiredToExecute),
      target_(src.target_) {
  std::cout << Layout::grey << "PresidentialPardonForm copy constructor called\n" << Layout::reset;
  *this = src;
}

/* Copy assignment operator */
PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& rhs) {
  std::cout << Layout::grey << "PresidentialPardonForm copy assignment operator called\n" << Layout::reset;
  if (this == &rhs)
    return *this;
  AForm::operator=(rhs);
  return *this;
}

/* Destructor */
PresidentialPardonForm::~PresidentialPardonForm() {
  std::cout << Layout::grey << "PresidentialPardonForm destructor called\n" << Layout::reset;
}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

void PresidentialPardonForm::execute(Bureaucrat const& b) const {
  checkExecutionRequirements(b);
  executePresidentialPardonForm();
}

/* ************************************************************************** */
/* Private                                                                    */
/* ************************************************************************** */

void PresidentialPardonForm::executePresidentialPardonForm() const {
  std::cout << Layout::brightYellow
            << target_ << " has been pardoned by Zaphod Beeblebrox\n"
            << Layout::reset;
}

AForm* PresidentialPardonForm::newForm() const {
  PresidentialPardonForm* newForm = new PresidentialPardonForm(*this);
  return newForm;
}