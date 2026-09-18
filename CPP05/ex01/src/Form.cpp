#include "Form.hpp"

Form::Form() : m_name("Default form"), m_isSigned(false), m_gradeToSign(1), m_gradeToExecute(1) {}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : m_name(name),
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

Form::Form( Form const & other ) : m_name(other.m_name), m_isSigned(other.m_isSigned),
    m_gradeToSign(other.m_gradeToSign), m_gradeToExecute(other.m_gradeToExecute) {}

Form::~Form() {}

Form& Form::operator=( Form const & other ) {

  if (this != &other){
    this->m_isSigned = other.m_isSigned;
    // Cannot copy other attributes because they're constant
  }

  return *this;

}

const std::string Form::getName() const {return m_name;}
bool Form::getIsSigned() const {return m_isSigned;}
int Form::getGradeToSign() const {return m_gradeToSign;}
int Form::getGradeToExecute() const {return m_gradeToExecute;}

void Form::beSigned(Bureaucrat& bureaucrat) {
  // try {
    if (bureaucrat.getGrade() > m_gradeToSign) {
      throw Form::GradeTooLowException();
    }
    else
      m_isSigned = true;
  // }
  // catch (std::exception& e)
  // {
  //   std::cout << e.what() <<std::endl;
  // }

}

std::ostream& operator<<(std::ostream& o, Form const & form) {

  o << "Form " << form.getName() << ", ";
  if (!form.getIsSigned())
    o << "NOT ";
  o << "signed. ";
  o << "Grade to sign: " << form.getGradeToSign() <<
    ". Grade to execute: " << form.getGradeToExecute();

  return o;
}