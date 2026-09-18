#pragma once
#include "Bureaucrat.hpp"
#include <iostream>

class Form {

  private:

    const std::string m_name;
    bool m_isSigned;
    const int m_gradeToSign;
    const int m_gradeToExecute;

  public:

    Form();
    Form(std::string name, int gradeToSign, int gradeToExecute);
    Form(Form const & other );
    ~Form();

    Form& operator=( Form const & other );

    class GradeTooLowException : public std::exception {
      public:

        virtual const char* what() const throw() {
          return "Grade is too low. The grade of the bureaucrat must be higher.";
        }
    };

    class GradeTooHighException : public std::exception {
      public:

        virtual const char* what() const throw() {
          return "Grade is too high. The grade of the bureaucrat must be lower.";
        }
    };

    const std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(Bureaucrat& bureaucrat);

};

std::ostream& operator<<(std::ostream& o, Form const & form);