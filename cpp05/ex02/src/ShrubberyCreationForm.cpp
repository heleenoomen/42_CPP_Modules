#include "ShrubberyCreationForm.hpp"

#include <climits>
#include <cstdlib>
#include <fstream>

#include "Layout.hpp"

static int const nbrOfTrees = 10;
std::string const ShrubberyCreationForm::formName = "Shrubbery Creation Form";

/* ************************************************************************** */
/* Orthodox canonical form                                                    */
/* ************************************************************************** */

/* Default constructor */
ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm(formName, gradeRequiredToSign, gradeRequiredToExecute),
      target_("default") {
  std::cout << Layout::grey
            << "ShrubberyCreationForm default constructor called\n"
            << Layout::reset;
  checkGrade();
}

/* Parametric constructors */
ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
    : AForm(formName, gradeRequiredToSign, gradeRequiredToExecute),
      target_(target) {
  std::cout << Layout::grey
            << "ShrubberyCreationForm parametric constructor called\n"
            << Layout::reset;
  checkGrade();
}

/* Copy constructor */
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src)
    : AForm(src.getName(), gradeRequiredToSign, gradeRequiredToExecute),
      target_(src.target_) {
  std::cout << Layout::grey << "ShrubberyCreationForm copy constructor called\n"
            << Layout::reset;
  *this = src;
}

/* Copy assignment operator */
ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    ShrubberyCreationForm const& rhs) {
  std::cout << Layout::grey
            << "ShrubberyCreationForm copy assignment operator called\n"
            << Layout::reset;
  if (this == &rhs) return *this;
  AForm::operator=(rhs);
  return *this;
}

/* Destructor */
ShrubberyCreationForm::~ShrubberyCreationForm() {
  std::cout << Layout::grey << "ShrubberyCreationForm destructor called\n"
            << Layout::reset;
}

/* ************************************************************************** */
/* Public methods                                                             */
/* ************************************************************************** */

void ShrubberyCreationForm::execute(Bureaucrat const& b) const {
  checkExecutionRequirements(b);
  executeShrubberyCreationForm();
}

/* ************************************************************************** */
/* Private                                                                    */
/* ************************************************************************** */

/* Unfortunately, we are not allowed to use std::to_string(), because it is
   part of c++11. Therefore, we created this simple imitation.
*/
std::string ShrubberyCreationForm::toString(int value) const {
  if (value == 0) return "0";
  long val = static_cast<long>(value);
  bool sign = false;
  if (val < 0) {
    sign = true;
    val = -val;
  }
  std::string s;
  while (val > 0) {
    int digit = val % 10;
    char digitChar = digit + '0';
    s.insert(0, 1, digitChar);
    val /= 10;
  }
  if (sign) s.insert(0, 1, '-');
  return s;
}

void ShrubberyCreationForm::openTargetFile(std::ofstream& targetFile) const {
  std::string targetFileName(target_ + "_shrubbery");
  targetFile.open(targetFileName.c_str(), std::ofstream::app);
  if (targetFile.fail())
    throw(std::runtime_error("Could not open file for writing: " +
                             targetFileName));
}

std::string ShrubberyCreationForm::pickRandomTreeFileName() const {
  int treeNbr(std::rand() % nbrOfTrees);
  return "./src/trees/tree" + toString(treeNbr);
}

void ShrubberyCreationForm::copyTreeFileToTargetFile(
    std::ifstream& treeFile, std::ofstream& targetFile) const {
  std::string line;
  while (!treeFile.eof()) {
    std::getline(treeFile, line);
    targetFile << line << '\n';
  }
}

void ShrubberyCreationForm::openTreeFile(std::ifstream& treeFile) const {
  std::string treeFileName(pickRandomTreeFileName());
  treeFile.open(treeFileName.c_str(), std::ifstream::in);
  if (treeFile.fail())
    throw(
        std::runtime_error("Could not open file for reading: " + treeFileName));
}

void ShrubberyCreationForm::executeShrubberyCreationForm() const {
  std::ifstream treeFile;
  openTreeFile(treeFile);
  std::ofstream targetFile;
  openTargetFile(targetFile);
  copyTreeFileToTargetFile(treeFile, targetFile);
}
