#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : target_("Unknown") {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
  : target_(target) {
}

RobotomyRequestForm::RobotomyRequestForm(
  const RobotomyRequestForm &other) : AForm(other), target_(other.target_) {
}

RobotomyRequestForm &RobotomyRequestForm::operator=(
  const RobotomyRequestForm &other) {
  if (this != &other) {
    AForm::operator=(other);
    target_ = other.target_;
  }
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}
