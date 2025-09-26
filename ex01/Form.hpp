#ifndef FORM_HPP
#define FORM_HPP

#include <string>

class Bureaucrat;

class Form {
public:
  Form();
  Form(std::string name, bool is_signed, int grade_to_sign,
       int grade_to_execute);
  Form(const Form &other);
  ~Form();

  Form &operator=(const Form &other);

  std::string getName() const;
  bool getIsSigned() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;

  void beSigned(const Bureaucrat &bureaucrat);

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw() { return "Grade is too high."; };
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw() { return "Grade is too low."; };
  };

private:
  const std::string name_;
  bool is_signed_;
  const int grade_to_sign_;
  const int grade_to_execute_;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
