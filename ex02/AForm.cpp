#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    : name_("Unknown"), is_signed_(false), grade_to_sign_(150),
      grade_to_execute_(150) {}

AForm::AForm(std::string name, bool is_signed, int grade_to_sign,
             int grade_to_execute)
    : name_(name), is_signed_(is_signed), grade_to_sign_(grade_to_sign),
      grade_to_execute_(grade_to_execute) {
  if (grade_to_sign_ < 1 || grade_to_execute_ < 1)
    throw AForm::GradeTooHighException();
  else if (grade_to_sign_ > 150 || grade_to_execute_ > 150)
    throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : name_(other.name_), is_signed_(other.is_signed_),
      grade_to_sign_(other.grade_to_sign_),
      grade_to_execute_(other.grade_to_execute_) {} // Throw an exception?

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &other) {
  if (this != &other) {
    is_signed_ = other.is_signed_;
  }
  return (*this);
}

std::string AForm::getName() const { return (name_); }

bool AForm::getIsSigned() const { return (is_signed_); }

int AForm::getGradeToSign() const { return (grade_to_sign_); }

int AForm::getGradeToExecute() const { return (grade_to_execute_); }

void AForm::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > grade_to_sign_) {
    std::cout << bureaucrat.getName() << " couldn't sign " << name_
              << " because the grade is too low." << std::endl;
    throw AForm::GradeTooLowException();
  } else {
    is_signed_ = true;
    std::cout << bureaucrat.getName() << " signed " << name_ << "."
              << std::endl;
  }
}

std::ostream &operator<<(std::ostream &os, const AForm &aform) {
  os << "AForm " << aform.getName();
  if (aform.getIsSigned())
    os << " is signed,";
  else
    os << " is not signed,";
  os << " and the grade required to sign it is " << aform.getGradeToSign()
     << ", and the grade required to execute it is "
     << aform.getGradeToExecute() << "." << std::endl;
  return os;
}
