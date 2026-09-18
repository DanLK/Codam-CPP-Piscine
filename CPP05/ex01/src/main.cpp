#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {

  Bureaucrat harry = Bureaucrat("Harry", 12);
  Form residence = Form("Residence permit", 10, 3);

  std::cout << harry << std::endl;
  std::cout << residence << std::endl;

  // residence.beSigned(harry);
  harry.signForm(residence);
  std::cout << residence << std::endl;



  return 0;
}