#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", false,
                                                   72, 45), target_("Unknown") {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
  : AForm("RobotomyRequestForm", false, 72, 45), target_(target) {
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
