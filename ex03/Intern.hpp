#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
private:
  static AForm *makeShrubberyForm(const std::string &target);
  static AForm *makeRobotomyForm(const std::string &target);
  static AForm *makePresidentialForm(const std::string &target);

public:
  Intern();
  Intern(const Intern &other);
  Intern &operator=(const Intern &other);
  ~Intern();
  AForm *makeForm(const std::string &form, const std::string &target);
};

#endif
