#include "Intern.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern &other) {
  (void) other;
}

Intern &Intern::operator=(const Intern &other) {
  (void) other;
  return *this;
}

Intern::~Intern() {
}

AForm *Intern::makeForm(const std::string &form, const std::string &target) {
  const std::string form_names[3] = {
    "shrubbery creation", "robotomy request", "presidential pardon"
  };

  AForm *(*funcs[3])(const std::string &) = {
    &Intern::makeShrubberyForm,
    &Intern::makeRobotomyForm,
    &Intern::makePresidentialForm
  };

  for (int i = 0; i < 3; i++) {
    if (form_names[i] == form) {
      std::cout << "Intern creates " << form << std::endl;
      return funcs[i](target);
    }
  }
  std::cout << "Intern couldn't create " << form << std::endl;
  return NULL;
}

AForm *Intern::makeShrubberyForm(const std::string &target) {
  return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomyForm(const std::string &target) {
  return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidentialForm(const std::string &target) {
  return new PresidentialPardonForm(target);
}

