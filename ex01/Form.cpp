#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
  : name_("Unknown"), is_signed_(false), grade_to_sign_(150),
    grade_to_execute_(150) {
}

Form::Form(const std::string &name, bool is_signed, int grade_to_sign,
           int grade_to_execute)
  : name_(name), is_signed_(is_signed), grade_to_sign_(grade_to_sign),
    grade_to_execute_(grade_to_execute) {
  if (grade_to_sign_ < 1 || grade_to_execute_ < 1)
    throw GradeTooHighException();
  if (grade_to_sign_ > 150 || grade_to_execute_ > 150)
    throw GradeTooLowException();
}

Form::Form(const Form &other)
  : name_(other.name_), is_signed_(other.is_signed_),
    grade_to_sign_(other.grade_to_sign_),
    grade_to_execute_(other.grade_to_execute_) {
}

Form::~Form() {
}

Form &Form::operator=(const Form &other) {
  if (this != &other) {
    is_signed_ = other.is_signed_;
  }
  return (*this);
}

std::string Form::getName() const {
  return (name_);
}

bool Form::getIsSigned() const {
  return (is_signed_);
}

int Form::getGradeToSign() const {
  return (grade_to_sign_);
}

int Form::getGradeToExecute() const {
  return (grade_to_execute_);
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > grade_to_sign_) {
    throw GradeTooLowException();
  }
  is_signed_ = true;
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
  os << "Form " << form.getName();
  if (form.getIsSigned()) os << " is signed,";
  else os << " is not signed,";
  os << " and the grade required to sign it is " << form.getGradeToSign() <<
      ", and the grade required to execute it is " << form.getGradeToExecute()
      << "." << std::endl;
  return os;
}
