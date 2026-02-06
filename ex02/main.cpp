#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include <iostream>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  std::string green = "\e[32m";
  std::string reset = "\e[0m";

  Bureaucrat bureaucrat1("b1", 138);

  std::cout << green << "Shrubbery form creation: " << reset << std::endl;
  ShrubberyCreationForm shrubbery_creation_form("home");
  bureaucrat1.signForm(shrubbery_creation_form);
  bureaucrat1.executeForm(shrubbery_creation_form);
  bureaucrat1.incrementGrade();
  std::cout << green << "After incrementing the grade: " << reset << std::endl;
  bureaucrat1.executeForm(shrubbery_creation_form);

  std::cout << std::endl;
  std::cout << std::endl;

  Bureaucrat bureaucrat2("b2", 1);
  std::cout << green << "Robotomy form creation: " << reset << std::endl;
  RobotomyRequestForm robotomy_request_form("robot");
  bureaucrat2.signForm(robotomy_request_form);
  bureaucrat2.executeForm(robotomy_request_form);

  std::cout << std::endl;
  std::cout << std::endl;

  std::cout << green << "President form creation: " << reset << std::endl;
  PresidentialPardonForm presidential_pardon_form("president");
  bureaucrat2.executeForm(presidential_pardon_form);
  bureaucrat2.signForm(presidential_pardon_form);
  bureaucrat2.executeForm(presidential_pardon_form);
}
