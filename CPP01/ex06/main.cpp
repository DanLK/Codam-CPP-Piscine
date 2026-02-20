#include "Harl.hpp"

void ToUpperCase(std::string &s){
  for (std::size_t i = 0; i < s.length(); i++){
    s[i] = std::toupper(s[i]);
  }
}

int main( int argc, char *argv[] ){

  if (argc != 2){
    std::cout << "Wrong number of parameters." << std::endl;
    std::cout << "Usage: ./harlFilter <level>" << std::endl;
    return 1;
  }

  std::string level = argv[1];
  ToUpperCase(level);

  Harl harl;

  harl.complain(level);

  return 0;
}