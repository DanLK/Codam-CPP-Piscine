#include "AForm.hpp"

AForm::AForm() : m_name("Default form"), m_isSigned(false), m_gradeToSign(1), m_gradeToExecute(1) {}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : m_name(name),
  m_isSigned(false), m_gradeToSign(gradeToSign), m_gradeToExecute(gradeToExecute) {

  // try {
  //   if (gradeToSign < 1) {
  //     m_gradeToSign = 1;
  //     throw Form::GradeTooHighException();
  //   }
  //   if (gradeToSign > 150) {
  //     m_gradeToSign = 150;
  //     throw Form::GradeTooLowException();
  //   }
  //   else
  //     m_gradeToSign = gradeToSign;
  // }
  // catch (std::exception& e)
  // {
  //   std::cout << e.what() <<std::endl;
  // }
  // try {
  //   if (gradeToExecute < 1) {
  //     m_gradeToExecute = 1;
  //     throw Form::GradeTooHighException();
  //   }
  //   if (gradeToExecute > 150) {
  //     m_gradeToExecute = 150;
  //     throw Form::GradeTooLowException();
  //   }
  //   else
  //     m_gradeToExecute = gradeToExecute;
  // }
  // catch (std::exception& e)
  // {
  //   std::cout << e.what() <<std::endl;
  // }
}

AForm::AForm( AForm const & other ) : m_name(other.m_name), m_isSigned(other.m_isSigned),
    m_gradeToSign(other.m_gradeToSign), m_gradeToExecute(other.m_gradeToExecute) {}

// AForm::~AForm() {}

AForm& AForm::operator=( AForm const & other ) {

  if (this != &other){
    this->m_isSigned = other.m_isSigned;
    // Cannot copy other attributes because they're constant
  }

  return *this;

}

const std::string AForm::getName() const {return m_name;}
bool AForm::getIsSigned() const {return m_isSigned;}
int AForm::getGradeToSign() const {return m_gradeToSign;}
int AForm::getGradeToExecute() const {return m_gradeToExecute;}

void AForm::beSigned(Bureaucrat& bureaucrat) {
  // try {
    if (bureaucrat.getGrade() > m_gradeToSign) {
      throw AForm::GradeTooLowException();
    }
    else
      m_isSigned = true;
  // }
  // catch (std::exception& e)
  // {
  //   std::cout << e.what() <<std::endl;
  // }

}

bool AForm::checkRequirements(Bureaucrat const & executor) const {
  return executor.getGrade() <= m_gradeToExecute && m_isSigned;
    // throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& o, AForm const & form) {

  o << "AForm " << form.getName() << ", ";
  if (!form.getIsSigned())
    o << "NOT ";
  o << "signed. ";
  o << "Grade to sign: " << form.getGradeToSign() <<
    ". Grade to execute: " << form.getGradeToExecute();

  return o;
}