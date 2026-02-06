#include "RobotomyRequestForm.hpp"

#include <iostream>
#include <ostream>

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

void RobotomyRequestForm::executeAction() const {
  std::cout << "Tdddddd....." << std::endl;
  srand(time(0));
  int i = rand() % 2;
  if (i == 0) std::cout << target_ << " has been robotomized." << std::endl;
  else std::cout << "Robotomization of " << target_ << " failed." << std::endl;
}
