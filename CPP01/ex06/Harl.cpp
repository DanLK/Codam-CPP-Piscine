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
      this->debug();
    case INFO:
      this->info();
    case WARNING:
      this->warning();
    case ERROR:
      this->error();
      break;
    default:
      std::cout << "Invalid complain level." << std::endl;
  }
  
}

void Harl::debug( void ){
  std::cout << "[ DEBUG ]" << std::endl << "This is some debug message" << std::endl;
}

void Harl::info( void ){
  std::cout << "[ INFO ]" << std::endl << "This is some info" << std::endl;
}

void Harl::warning( void ){
  std::cout << "[ WARNING ]" << std::endl << "This is some warning" << std::endl;
}

void Harl::error( void ){
  std::cout << "[ ERROR ]" << std::endl << "This is some error" << std::endl;
}
