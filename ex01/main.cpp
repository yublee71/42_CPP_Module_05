#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>

int main() {
  Bureaucrat b_a("Yubeen", 150);
  Form f_a;
  Form f_b("Register Form", false, 1, 1);

  std::cout << f_a;

  try {
    Form f_b("Register Form", false, 0, 1);
  } catch (const Form::GradeTooHighException &excp) {
    std::cout << "Exception caught: " << excp.what() << std::endl;
  } catch (const Form::GradeTooLowException &excp) {
    std::cout << "Exception caught: " << excp.what() << std::endl;
  }
  try {
    Form f_c("Register Form", false, 1, 151);
  } catch (const Form::GradeTooHighException &excp) {
    std::cout << "Exception caught: " << excp.what() << std::endl;
  } catch (const Form::GradeTooLowException &excp) {
    std::cout << "Exception caught: " << excp.what() << std::endl;
  }
  try {
    f_a.beSigned(b_a);
  } catch (const Form::GradeTooHighException &excp) {
    std::cout << "Exception caught: " << excp.what() << std::endl;
  } catch (const Form::GradeTooLowException &excp) {
    std::cout << "Exception caught: " << excp.what() << std::endl;
  }
  std::cout << f_a;
  try {
    f_b.beSigned(b_a);
  } catch (const Form::GradeTooHighException &excp) {
    std::cout << "Exception caught: " << excp.what() << std::endl;
  } catch (const Form::GradeTooLowException &excp) {
    std::cout << "Exception caught: " << excp.what() << std::endl;
  }
  std::cout << f_b;
}
