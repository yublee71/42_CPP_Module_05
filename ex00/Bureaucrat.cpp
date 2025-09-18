#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

Bureaucrat::Bureaucrat() : name_("Unknown"), grade_(150) {
  std::cout << "Default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name) {
  std::cout << "Constructor called with name " << name_ << " and grade "
            << grade << std::endl;
  grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : name_(other.name_), grade_(other.grade_) {
  std::cout << "Copy constructor called." << std::endl;
};

Bureaucrat::~Bureaucrat() { std::cout << "Destructor called." << std::endl; }

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  std::cout << "Copy assignment operator called." << std::endl;
  if (this != &other) {
    this->grade_ = other.grade_;
  }
  return (*this);
};

std::string Bureaucrat::getName() const { return (name_); }

int Bureaucrat::getGrade() const { return (grade_); }

void Bureaucrat::incrementGrade() { grade_--; }

void Bureaucrat::decrementGrade() { grade_++; }

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade()
     << "." << std::endl;
  return os;
}
