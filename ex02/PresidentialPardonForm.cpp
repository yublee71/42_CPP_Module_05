#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm(
                                                     "PresidentialPardonForm",
                                                     false, 25, 5),
                                                   target_("Unknown") {
}

PresidentialPardonForm::PresidentialPardonForm(
  const std::string &target) : AForm("PresidentialPardonForm", false, 25, 5),
                               target_(target) {
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
