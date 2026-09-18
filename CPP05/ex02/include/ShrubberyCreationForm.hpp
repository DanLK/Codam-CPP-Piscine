#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

  private:
    std::string m_target;

  public:

    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(ShrubberyCreationForm const & other );
    ~ShrubberyCreationForm() {};

    ShrubberyCreationForm& operator=( ShrubberyCreationForm const & other );

    void execute(Bureaucrat const & executor) const override;
};