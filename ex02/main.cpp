#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include <iostream>

int main() {
  Bureaucrat b_a("Yubeen", 150);
  AForm f_a;
  AForm f_b("Register Form", false, 1, 1);

  std::cout << f_a;

  try {
    AForm f_b("Register Form", false, 0, 1);
  } catch (const AForm::GradeTooHighException &excp) {
    std::cout << "Exception caught: " << excp.what() << std::endl;
  } catch (const AForm::GradeTooLowException &excp) {
    std::cout << "Exception caught: " << excp.what() << std::endl;
  }
  try {
    AForm f_c("Register Form", false, 1, 151);
  } catch (const AForm::GradeTooHighException &excp) {
    std::cout << "Exception caught: " << excp.what() << std::endl;
  } catch (const AForm::GradeTooLowException &excp) {
    std::cout << "Exception caught: " << excp.what() << std::endl;
  }
  try {
    f_a.beSigned(b_a);
  } catch (const AForm::GradeTooHighException &excp) {
    std::cout << "Exception caught: " << excp.what() << std::endl;
  } catch (const AForm::GradeTooLowException &excp) {
    std::cout << "Exception caught: " << excp.what() << std::endl;
  }
  std::cout << f_a;
  try {
    f_b.beSigned(b_a);
  } catch (const AForm::GradeTooHighException &excp) {
    std::cout << "Exception caught: " << excp.what() << std::endl;
  } catch (const AForm::GradeTooLowException &excp) {
    std::cout << "Exception caught: " << excp.what() << std::endl;
  }
  std::cout << f_b;
}
