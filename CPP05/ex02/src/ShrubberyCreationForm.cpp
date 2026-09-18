#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137),
  m_target("Default Target") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
  AForm("ShrubberyCreationForm", 145, 137), m_target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & other ) :
  AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()), m_target(other.m_target) {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
  
  if (!checkRequirements(executor))
    throw AForm::GradeTooLowException();
  std::cout << "tree" << std::endl;
  
}