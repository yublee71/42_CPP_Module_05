#include "Bureaucrat.hpp"
#include "Intern.hpp"

#include <iostream>

int main() {
  bool quit = false;
  const std::string form_names[3] = {
    "robotomy request", "shrubbery creation", "presidential pardon"
  };
  std::string form_name;

  while (!quit) {
    std::cout <<
        "Please enter the name of the form you want to create "
        "(shrubbery creation / robotomy request / presidential pardon)." <<
        std::endl;
    std::getline(std::cin, form_name);
    for (int i = 0; i < 3; i++) {
      if (form_name == form_names[i]) {
        quit = true;
      }
    }
    if (!quit) {
      std::cout << "Invalid form name. Please enter again." << std::endl;
    }
  }

  std::cout << "Please enter the target of the form." << std::endl;
  std::string target;
  std::getline(std::cin, target);

  Intern intern;
  AForm *form = intern.makeForm(form_name, target);
  Bureaucrat bureaucrat("Yubeen", 1);
  bureaucrat.signForm(*form);
  bureaucrat.executeForm(*form);
  delete form;
}
