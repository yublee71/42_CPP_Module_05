#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>

class Bureaucrat;

class AForm {
public:
  AForm();
  AForm(std::string name, bool is_signed, int grade_to_sign,
        int grade_to_execute);
  AForm(const AForm &other);
  ~AForm();

  AForm &operator=(const AForm &other);

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

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
