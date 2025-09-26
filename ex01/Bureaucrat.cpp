#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>
#include <string>

Bureaucrat::Bureaucrat() : name_("Unknown"), grade_(150) {
  std::cout << "Default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name) {
  std::cout << "Constructor called with name " << name_ << " and grade "
            << grade << std::endl;
  if (grade < 1)
    throw Bureaucrat::GradeTooHighException();
  else if (grade > 150)
    throw Bureaucrat::GradeTooLowException();
  else
    grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : name_(other.name_), grade_(other.grade_) {
  std::cout << "Copy constructor called." << std::endl;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  std::cout << "Copy assignment operator called." << std::endl;
  if (this != &other) {
    this->grade_ = other.grade_;
  }
  return (*this);
}

std::string Bureaucrat::getName() const { return (name_); }

int Bureaucrat::getGrade() const { return (grade_); }

void Bureaucrat::incrementGrade() {
  if (grade_ - 1 < 1)
    throw Bureaucrat::GradeTooLowException();
  else
    grade_--;
}

void Bureaucrat::decrementGrade() {
  if (grade_ + 1 > 150)
    throw Bureaucrat::GradeTooHighException();
  else
    grade_++;
}

void Bureaucrat::signForm(Form &form) const { form.beSigned(*this); }

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade()
     << "." << std::endl;
  return os;
}
