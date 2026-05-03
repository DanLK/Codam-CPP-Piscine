#include "Bureaucrat.hpp"

int main( void ) {

  Bureaucrat bureau = Bureaucrat();
  Bureaucrat harry = Bureaucrat("Harry", 0);

  std::cout << bureau << std::endl;
  std::cout << harry << std::endl;

  harry.increaseGrade();
  std::cout << harry << std::endl;
  
  return 0;
}