#include <string>
#include <iostream>
#include <fstream>

std::string replace_string( std::string big, std::string s1, std::string s2 ){

  std::string result;
  std::size_t pos = big.find(s1);
  
  if (pos == std::string::npos){
    result = big;
    return result;
  }
  std::size_t i = 0;
  std::string before;
  while (pos != std::string::npos){
    before = big.substr(i, pos - i);
    result.append(before).append(s2);
    i = pos + s1.length();
    pos = big.find(s1, i + 1);
  }
  if (i != big.length()){
    std::string after = big.substr(i, big.length() - 1);
    result.append(after);
  }
  
  return result;
}


int main( int argc, char *argv[] ){

  if (argc != 4){
    std::cout << "Wrong number of parameters." << std::endl;
    std::cout << "Usage: ./string_replace <filename> <string1> <string2>" << std::endl;
    return 1;
  }

  
  std::string file_name = argv[1];
  std::string s1 = argv[2];
  if (s1.length() < 1){
    std::cout << "The string to look for must be non-empty" << std::endl;
    return 1;
  }
  std::string s2 = argv[3];

  std::string outfile_name = file_name + ".replace";

  std::ifstream filein(file_name);
  
  
  if (!filein.is_open()){
    std::cout << "Unable to open file." << std::endl;
    return 1;
  }
  std::ofstream fileout(outfile_name);
  if (!fileout.is_open()){
    std::cout << "Unable to create .replace file" << std::endl;
    filein.close();
    return 1;
  }

  std::string line;
  while (getline(filein, line)){
    std::string result = replace_string(line, s1, s2);
    fileout << result << std::endl;
  }

  filein.close();
  fileout.close();

  return 0;
}