#include "RobotomyRequestForm.hpp"
#include "Layout.hpp"
#include <cstdlib>
#include <climits>
#include <fstream>

static char const* insertionOverloadLayout = Layout::greenBold;
static int const nbrOfTrees = 10;

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Default", gradeRequiredToSign, gradeRequiredToExecute),
      target_("default") {
  std::cout << Layout::grey << "RobotomyRequestForm default constructor called\n" << Layout::reset;
  checkGrade();
}

/* Parametric constructors */
RobotomyRequestForm::RobotomyRequestForm(std::string const& name)
    : AForm(name, gradeRequiredToSign, gradeRequiredToExecute),
      target_("default") {
  std::cout << Layout::grey << "RobotomyRequestForm parametric constructor called\n" << Layout::reset;
  checkGrade();
}

RobotomyRequestForm::RobotomyRequestForm(std::string const& name, std::string const& target)
    : AForm(name, gradeRequiredToSign, gradeRequiredToExecute),
      target_(target) {
  std::cout << Layout::grey << "RobotomyRequestForm parametric constructor called\n" << Layout::reset;
  checkGrade();
}

/* Copy constructor */
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src)
    : AForm(src.getName(), gradeRequiredToSign, gradeRequiredToExecute),
      target_(src.target_) {
  std::cout << Layout::grey << "RobotomyRequestForm copy constructor called\n" << Layout::reset;
  *this = src;
}

/* Copy assignment operator */
RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& rhs) {
  std::cout << Layout::grey << "RobotomyRequestForm copy assignment operator called\n" << Layout::reset;
  if (this == &rhs)
    return *this;
  AForm::operator=(rhs);
  return *this;
}

/* Destructor */
RobotomyRequestForm::~RobotomyRequestForm() {
  std::cout << Layout::grey << "RobotomyRequestForm destructor called\n" << Layout::reset;
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

/* std::rand() is a poor quality PRNG. In c++11, the best option would be to 
   use the mersenne twister and seed it with the system clock */
void RobotomyRequestForm::executeRobotomyRequestForm() const {
  std::cout << Layout::magenta << "Robotomy of " << target_ << " in process... Random drilling noises: "
            << " #$%&((^$@!@@##$&\n"
            << Layout::reset;
  if (std::rand() % 2)
    std::cout << Layout::emojiRobot << " "
              << Layout::green << target_ << " has been robotomized succesfully\n"
              << Layout::reset;
  else
    std::cout << Layout::emojiSkull << " "
              << Layout::yellow << "Robotomy of " << target_ << " failed\n"
              << Layout::reset;
}
