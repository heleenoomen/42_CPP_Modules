#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <climits>
#include <fstream>

#ifndef to_file
static char const* greenBold = "\033[32;1m";
static char const* yellowBold = "\033[33;1m";
static char const* resetLayout = "\033[0m";
static char const* grey = "\033[0;2m";
#else
static char const* greenBold = "";
static char const* yellowBold = "";
static char const* resetLayout = "";
static char const* grey = "";
#endif

static char const* insertionOverloadLayout = greenBold;
static int const nbrOfTrees = 10;

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Default", gradeRequiredToSign, gradeRequiredToExecute),
      target_("default") {
  std::cout << grey << "RobotomyRequestForm default constructor called\n" << resetLayout;
  checkGrade();
}

/* Parametric constructors */
RobotomyRequestForm::RobotomyRequestForm(std::string const& name)
    : AForm(name, gradeRequiredToSign, gradeRequiredToExecute),
      target_("default") {
  std::cout << grey << "RobotomyRequestForm parametric constructor called\n" << resetLayout;
  checkGrade();
}

RobotomyRequestForm::RobotomyRequestForm(std::string const& name, std::string const& target)
    : AForm(name, gradeRequiredToSign, gradeRequiredToExecute),
      target_(target) {
  std::cout << grey << "RobotomyRequestForm parametric constructor called\n" << resetLayout;
  checkGrade();
}

/* Copy constructor */
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src)
    : AForm(src.getName(), gradeRequiredToSign, gradeRequiredToExecute),
      target_(src.target_) {
  std::cout << grey << "RobotomyRequestForm copy constructor called\n" << resetLayout;
  *this = src;
}

/* Copy assignment operator */
RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& rhs) {
  std::cout << grey << "RobotomyRequestForm copy assignment operator called\n" << resetLayout;
  if (this == &rhs)
    return *this;
  AForm::operator=(rhs);
  return *this;
}

/* Destructor */
RobotomyRequestForm::~RobotomyRequestForm() {
  std::cout << grey << "RobotomyRequestForm destructor called\n" << resetLayout;
}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

void RobotomyRequestForm::execute(Bureaucrat const& b) const {
  checkExecutionRequirements(b);
  executeRobotomyRequestForm();
}

/* ************************************************************************** */
/* Private                                                                    */
/* ************************************************************************** */

void RobotomyRequestForm::executeRobotomyRequestForm() const {
  if (std::rand() % 2)
    std::cout << greenBold << target_ << " has been robotomized succesfully\n"
              << resetLayout;
  else
    std::cout << yellowBold << "Robotomy of " << target_ << "failed\n"
              << resetLayout;
}
