#include "ShrubberyCreationForm.hpp"

#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm",
                                                   false, 145, 137),
                                                 target_("Unknown") {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm(
  "ShrubberyCreationForm", false, 145, 137), target_(target) {
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

void ShrubberyCreationForm::executeAction() const {
  std::ofstream ofs((target_ + "_shrubbery").c_str());
  if (!ofs) {
    std::cout << "Failed to create file: " << target_ << "_shrubbery" <<
        std::endl;
    return;
  }

  ofs << "       _-_\n";
  ofs << "    /~~   ~~\\\n";
  ofs << " /~~         ~~\\\n";
  ofs << "{               }\n";
  ofs << " \\  _-     -_  /\n";
  ofs << "   ~  \\\\ //  ~\n";
  ofs << "_- -   | | _- _\n";
  ofs << "  _ -  | |   -_\n";
  ofs << "      // \\\n";

  ofs.close();
}
