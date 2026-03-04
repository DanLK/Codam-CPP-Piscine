#include "Harl.hpp"

Harl::_level Harl::getLevel( std::string input){
  if (input == "DEBUG") return DEBUG;
  if (input == "INFO") return INFO;
  if (input == "WARNING") return WARNING;
  if (input == "ERROR") return ERROR;
  return INVALID;
}

void Harl::complain( std::string level ){

  switch (getLevel(level))
  {
    case DEBUG:
      this->_debug();
    case INFO:
      this->_info();
    case WARNING:
      this->_warning();
    case ERROR:
      this->_error();
      break;
    default:
      std::cout << "Invalid complain level." << std::endl;
  }
  
}

void Harl::_debug( void ){
  std::cout << "[ DEBUG ]" << std::endl << "This is some debug message" << std::endl;
}

void Harl::_info( void ){
  std::cout << "[ INFO ]" << std::endl << "This is some info" << std::endl;
}

void Harl::_warning( void ){
  std::cout << "[ WARNING ]" << std::endl << "This is some warning" << std::endl;
}

void Harl::_error( void ){
  std::cout << "[ ERROR ]" << std::endl << "This is some error" << std::endl;
}
