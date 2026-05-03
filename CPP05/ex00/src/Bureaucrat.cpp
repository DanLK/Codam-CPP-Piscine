#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : m_name("Default bureaucrat name"), m_grade(150) {

  // std::cout << "Bureaucrat default constuctor called" << std::endl;

}

Bureaucrat::Bureaucrat( std::string name, int grade ) : m_name(name) {

  // std::cout << "Bureaucrat parametrized constuctor called" << std::endl;
  try {
    if (grade > 150) {
      this->m_grade = 150;
      throw GradeTooLowException();
    }
    if (grade < 1) {
      this->m_grade = 1;
      throw GradeTooHighException();
    }
    else
      m_grade = grade;
  }
  catch (std::exception& e)
  {
    std::cout << e.what() <<std::endl;
  }
}

Bureaucrat::Bureaucrat( Bureaucrat const & other ) : m_name(other.m_name), m_grade(other.m_grade) {

  // std::cout << "Bureaucrat copy constuctor called" << std::endl;

}

Bureaucrat::~Bureaucrat( void ) {
  
  // std::cout << "Bureaucrat destructor called" << std::endl;

}

Bureaucrat& Bureaucrat::operator=( Bureaucrat const & other ) {

  // std::cout << "Bureaucrat copy assignment operator called" << std::endl;

  if (this != &other){
    this->m_grade = other.m_grade;
    // Cannot copy the name because it's constant
  }

  return *this;

}

std::string Bureaucrat::getName( void ) const {

  return this->m_name;

}

int Bureaucrat::getGrade( void ) const {

  return this->m_grade;

}

void Bureaucrat::increaseGrade( void ) {

  try {
    if (this->m_grade == 1) 
      throw GradeTooHighException();
    else
      this->m_grade--;
  }
  catch (std::exception& e) {
    std::cout << "Grade is already the highest (1). Unable to increase." << std::endl;
  }
}

void Bureaucrat::decreaseGrade( void ) {

  try {
    if (this->m_grade == 150) 
      throw GradeTooLowException();
    else
      this->m_grade++;
  }
  catch (std::exception& e) {
    std::cout << "Grade is already the lowest (150). Unable to decrease." << std::endl;
  }
}

std::ostream& operator<<(std::ostream & o, Bureaucrat const & bureaucrat ) {

  o <<  bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";

  return o;
}