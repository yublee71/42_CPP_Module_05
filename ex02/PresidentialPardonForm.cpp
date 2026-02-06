#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : target_("Unknown") {
}

PresidentialPardonForm::PresidentialPardonForm(
  const std::string &target) : target_(target) {
}

PresidentialPardonForm::PresidentialPardonForm(
  const PresidentialPardonForm &other) : AForm(other), target_(other.target_) {
}

PresidentialPardonForm &PresidentialPardonForm::operator=(
  const PresidentialPardonForm &other) {
  if (this != &other) {
    AForm::operator=(other);
    target_ = other.target_;
  }
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}
