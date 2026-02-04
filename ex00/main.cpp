#include "Bureaucrat.hpp"

int main() {
  std::string green = "\e[32m";
  std::string reset = "\e[0m";

  std::cout << green << "Constructors test:" << reset << std::endl;
  Bureaucrat a;
  Bureaucrat b("Yubeen", 1);
  Bureaucrat c(b);
  Bureaucrat d = b;

  std::cout << a;
  std::cout << b;
  std::cout << c;
  std::cout << d;

  std::cout << green << "Try incrementing the grade:" << reset << std::endl;
  try {
    b.incrementGrade();
  } catch (const Bureaucrat::GradeTooHighException &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  } catch (const Bureaucrat::GradeTooLowException &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }

  std::cout << green << "Try creating with grade 0:" << reset << std::endl;
  try {
    Bureaucrat e("Top student", 0);
  } catch (const Bureaucrat::GradeTooHighException &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  } catch (const Bureaucrat::GradeTooLowException &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }

  std::cout << green << "Try creating with grade 151:" << reset << std::endl;
  try {
    Bureaucrat f("Bottom student", 151);
  } catch (const Bureaucrat::GradeTooHighException &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  } catch (const Bureaucrat::GradeTooLowException &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }
}
