#include "Harl.hpp"

void Harl::complain( std::string level ){

  fnptr complaint = _levels_map[level];
  (this->*complaint)();
  
}

void Harl::debug( void ){
  std::cout << "This is some debug message" << std::endl;
}

void Harl::info( void ){
  std::cout << "This is some info" << std::endl;
}

void Harl::warning( void ){
  std::cout << "This is some warning" << std::endl;
}

void Harl::error( void ){
  std::cout << "This is some error" << std::endl;
}

std::map<std::string, Harl::fnptr> Harl::_levels_map = {
  {"debug", &Harl::debug},
  {"info", &Harl::info},
  {"warning", &Harl::warning},
  {"error", &Harl::error}};