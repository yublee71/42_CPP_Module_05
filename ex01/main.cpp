#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>

int main() {
  std::string green = "\e[32m";
  std::string reset = "\e[0m";

  Bureaucrat b_a("Yubeen", 2);
  Form f_a;
  std::cout << green << "Form A before sign: " << reset << std::endl;
  std::cout << f_a;

  std::cout << green << "Try sign Form A: " << reset << std::endl;
  try {
    b_a.signForm(f_a);
  } catch (const Form::GradeTooHighException &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  } catch (const Form::GradeTooLowException &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }
  std::cout << green << "Form A after sign: " << reset << std::endl;
  std::cout << f_a;

  std::cout << std::endl;
  std::cout << std::endl;

  Form f_b("Register Form", false, 1, 1);
  std::cout << green << "Form B before sign: " << reset << std::endl;
  std::cout << f_b;
  std::cout << green << "Try sign Form B: " << reset << std::endl;
  b_a.signForm(f_b);
  std::cout << green << "Form B after sign: " << reset << std::endl;
  std::cout << f_b;

  b_a.incrementGrade();
  std::cout << green <<
      "Try sign Form B again after bureaucrat grade increments: " << reset <<
      std::endl;
  b_a.signForm(f_b);
  std::cout << green << "Form B after sign: " << reset << std::endl;
  std::cout << f_b;

  std::cout << std::endl;
  std::cout << std::endl;

  std::cout << green << "Try creating a from with grade 0: " << reset <<
      std::endl;
  try {
    Form f_c("Register Form", false, 0, 1);
  } catch (const Form::GradeTooHighException &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  } catch (const Form::GradeTooLowException &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }
  std::cout << std::endl;
  std::cout << std::endl;

  std::cout << green << "Try creating a from with grade 151: " << reset <<
      std::endl;
  try {
    Form f_d("Register Form", false, 1, 151);
  } catch (const Form::GradeTooHighException &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  } catch (const Form::GradeTooLowException &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }
}
