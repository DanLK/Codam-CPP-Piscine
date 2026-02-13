#include <iostream>

int main( void ){

  std::string example = "HI THIS IS BRAIN";

  std::string* stringPTR = &example;
  std::string& stringREF = example;

  std::cout << "MEMORY ADDRESSES" << std::endl;
  std::cout << "string: " << stringPTR << std::endl;
  std::cout << "stringPTR: " << &stringPTR << std::endl;
  std::cout << "stringREF: " << &stringREF << std::endl << std::endl;

  std::cout << "VALUES" << std::endl;
  std::cout << "string: " << example << std::endl;
  std::cout << "stringPTR: " << *stringPTR << std::endl;
  std::cout << "stringREF: " << stringREF << std::endl;

  return 0;

}