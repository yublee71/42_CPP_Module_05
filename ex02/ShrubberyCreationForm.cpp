#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : target_("Unknown") {
}

ShrubberyCreationForm::ShrubberyCreationForm(
  const std::string &target) : target_(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(
  const ShrubberyCreationForm &other) : AForm(other), target_(other.target_) {
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
  const ShrubberyCreationForm &other) {
  if (this != &other) {
    AForm::operator=(other);
    target_ = other.target_;
  }
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}
