#pragma once
#include <iostream>

class Bureaucrat {

  public:

    Bureaucrat( void );
    Bureaucrat( std::string name, int grade );
    Bureaucrat( Bureaucrat const & other );
    ~Bureaucrat( void );

    Bureaucrat& operator=( Bureaucrat const & other );

    std::string getName( void ) const;
    int getGrade( void ) const;
    void increaseGrade( void );
    void decreaseGrade( void );

    class GradeTooHighException : public std::exception {

      public:

        virtual const char* what() const throw() {
          return "Grade is too high. Grade must be at most 1.";
        }
    };

    class GradeTooLowException : public std::exception {

      public:
      
        virtual const char* what() const throw() {
          return "Grade is too low. Grade must be at least 150.";
        }
    };

  private:

    const std::string m_name;
    int m_grade;

};

std::ostream& operator<<(std::ostream & o, Bureaucrat const & bureaucrat ); 