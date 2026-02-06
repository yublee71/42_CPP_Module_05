#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name_("Unknown"), grade_(150) {
  std::cout << "Default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name_(name) {
  std::cout << "Constructor called with name " << name_ << " and grade " <<
      grade << std::endl;
  if (grade < 1) throw GradeTooHighException();
  if (grade > 150) throw GradeTooLowException();
  grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
  : name_(other.name_), grade_(other.grade_) {
  std::cout << "Copy constructor called." << std::endl;
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  std::cout << "Copy assignment operator called." << std::endl;
  if (this != &other) this->grade_ = other.grade_;
  return (*this);
}

std::string Bureaucrat::getName() const {
  return (name_);
}

int Bureaucrat::getGrade() const {
  return (grade_);
}

void Bureaucrat::incrementGrade() {
  if (grade_ - 1 < 1) throw GradeTooHighException();
  grade_--;
}

void Bureaucrat::decrementGrade() {
  if (grade_ + 1 > 150) throw GradeTooLowException();
  grade_++;
}

void Bureaucrat::signForm(AForm &form) const {
  try {
    form.beSigned(*this);
    std::cout << name_ << " signed " << form.getName() << "." << std::endl;
  } catch (AForm::GradeTooLowException &e) {
    std::cout << name_ << " couldn't sign " << form.getName() <<
        " because its grade is too low." << std::endl;
  }
}

void Bureaucrat::executeForm(const AForm &form) const {
  try {
    form.execute(*this);
    std::cout << name_ << " executed " << form.getName() << "." << std::endl;
  } catch (AForm::GradeTooLowException &e) {
    std::cout << name_ << " couldn't execute " << form.getName() <<
        " because its grade is too low." << std::endl;
  } catch (AForm::FormNotSignedException &e) {
    std::cout << name_ << " couldn't execute " << form.getName() <<
        " because it is not signed." << std::endl;
  }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade()
      << "." << std::endl;
  return os;
}
