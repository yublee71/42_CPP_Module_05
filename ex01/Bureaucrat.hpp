#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {
public:
  Bureaucrat();
  Bureaucrat(std::string name, int grade);
  Bureaucrat(const Bureaucrat &other);
  ~Bureaucrat();

  Bureaucrat &operator=(const Bureaucrat &other);

  std::string getName() const;
  int getGrade() const;

  void incrementGrade();
  void decrementGrade();

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw() { return "Grade cannot go higher."; }
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw() { return "Grade cannot go lower."; }
  };

private:
  const std::string name_;
  int grade_;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
