#pragma once
#include "Bureaucrat.hpp"
#include <iostream>

class AForm {

  private:

    const std::string m_name;
    bool m_isSigned;
    const int m_gradeToSign;
    const int m_gradeToExecute;

  public:

    AForm();
    AForm(std::string name, int gradeToSign, int gradeToExecute);
    AForm(AForm const & other );
    virtual ~AForm() = default;

    AForm& operator=( AForm const & other );

    const std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(Bureaucrat& bureaucrat);

    virtual void execute(Bureaucrat const & executor) const = 0;
    bool checkRequirements(Bureaucrat const & executor) const;

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

};

std::ostream& operator<<(std::ostream& o, AForm const & form);