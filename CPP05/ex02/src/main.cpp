// #include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {

  Bureaucrat harry = Bureaucrat("Harry", 13);
  ShrubberyCreationForm shrubbery = ShrubberyCreationForm("oak");

  harry.signForm(shrubbery);
  harry.executeForm(shrubbery);


  return 0;
}