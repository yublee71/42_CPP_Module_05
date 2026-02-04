#include "Bureaucrat.hpp"

int main() {
  Bureaucrat a;
  Bureaucrat b("Yubeen", 150);
  Bureaucrat c(b);
  Bureaucrat d = b;

  try {
    Bureaucrat e("Top student", 0);
  } catch (const Bureaucrat::GradeTooHighException &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  } catch (const Bureaucrat::GradeTooLowException &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }

  try {
    Bureaucrat f("Bottom student", 151);
  } catch (const Bureaucrat::GradeTooHighException &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  } catch (const Bureaucrat::GradeTooLowException &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }

  std::cout << a;
  std::cout << b;
  std::cout << c;
  std::cout << d;

  try {
    b.decrementGrade();
  } catch (const Bureaucrat::GradeTooHighException &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  } catch (const Bureaucrat::GradeTooLowException &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }
}
